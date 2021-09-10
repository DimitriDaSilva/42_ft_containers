/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 11:14:19 by dda-silv          #+#    #+#             */
/*   Updated: 2021/09/10 14:02:53 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

# include <cstddef>		// NULL, std::size_t, std::ptrdiff_t
# include <limits>		// std::numeric_limits
# include <memory>		// std::allocator
# include <iostream>	// std::cout

# include "bidirectional_iterator.hpp"
# include "reverse_iterator.hpp"
# include "pair.hpp"
# include "less.hpp"

namespace ft
{
	enum color {red, black};

	template<class T>
	struct red_black_tree_node
	{
		typedef	T value_type;

		value_type				data;
		red_black_tree_node*	parent;
		red_black_tree_node*	left;
		red_black_tree_node*	right;
		color					color;

		red_black_tree_node(value_type data,
				red_black_tree_node* parent,
				red_black_tree_node* left,
				red_black_tree_node* right,
				enum color color) :
			data(data),
			parent(parent),
			left(left),
			right(right),
			color(color) {}
	};

	template<class Key,
		class T,
		class Compare = ft::less<Key>,
		class Alloc = std::allocator<red_black_tree_node<T> >
			>
	class red_black_tree
	{
	public:
/******************************************************************************/
/*                   	        MEMBER TYPES					              */
/******************************************************************************/

		typedef Key											key_type;
		typedef T											value_type;
		typedef Compare										key_compare;
		typedef Alloc										allocator_type;

		typedef red_black_tree_node<value_type>				node_type;
		typedef red_black_tree_node<value_type>*			node_pointer;

		typedef value_type&									reference;
		typedef value_type const&							const_reference;
		typedef value_type*									pointer;
		typedef value_type const*							const_pointer;

		typedef ft::bidirectional_iterator<node_type>		iterator;
		typedef ft::bidirectional_iterator<node_type const>	const_iterator;
		typedef ft::reverse_iterator<iterator>				reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;

		typedef std::ptrdiff_t								difference_type;
		typedef std::size_t									size_type;

/******************************************************************************/
/*                   	        MEMBER FUNCTIONS                              */
/******************************************************************************/
/******************************************************************************/
/*                   	 CONSTRUCTORS & DESTRUCTORS                           */
/******************************************************************************/

/*                                Constructors                                */

		// Empty (default)
		explicit
		red_black_tree(key_compare const& comp = key_compare(),
						allocator_type const& alloc = allocator_type()) :
			_root(NULL),
			_nil(value_type(), NULL, NULL, NULL, black),
			_size(0),
			_comp(comp),
			_alloc(alloc)
		{
			// All leaf nodes will point to &_nil and _nil is a black node
			// Set root pointing to _nil for an empty tree
			_root = &_nil;
		}

		// Range
		template<class InputIterator>
		red_black_tree(InputIterator first,
				InputIterator last,
				key_compare const& comp = key_compare(),
				allocator_type const& alloc = allocator_type()) :
			_root(NULL),
			_nil(value_type(), NULL, NULL, NULL, black),
			_size(0),
			_comp(comp),
			_alloc(alloc)
		{
			insert(first, last);
		}

		// Copy
		red_black_tree(red_black_tree const& rhs) :
			_root(NULL),
			_nil(rhs._nil),
			_size(0),
			_comp(rhs._comp),
			_alloc(rhs._alloc)
		{
			*this = rhs;
		}

/*                                Destructors                                 */

		virtual
		~red_black_tree()
		{
			clear();
		}

/******************************************************************************/
/*                   	   OVERLOADING OPERATORS                              */
/******************************************************************************/

/*                                Assignement                                 */

		red_black_tree&
		operator=(red_black_tree const& rhs)
		{
			// Self-assignement check
			if (this == &rhs)
				return *this;

			// Clear current
			if (_root != NULL)
				clear();
			copy_helper(_root, rhs._root, NULL, rhs._nil);

			_size = rhs._size;

			return *this;
		}

/******************************************************************************/
/*                   	    OTHER MEMBER FUNCTIONS                            */
/******************************************************************************/

/*                                 Iterators                                  */

		iterator
		begin()
		{
			return iterator(minimum(), _root, &_nil);
		}

		const_iterator
		begin() const
		{
			return const_iterator(minimum(), _root, &_nil);
		}

		iterator
		end()
		{
			if (empty())
				return begin();
			return iterator(&_nil, _root, &_nil);
		}

		const_iterator
		end() const
		{
			if (empty())
				return begin();
			return const_iterator(&_nil, _root, &_nil);
		}

		reverse_iterator
		rbegin()
		{
			iterator it = iterator(&_nil, _root, &_nil);
			return reverse_iterator(it);
		}

		const_reverse_iterator
		rbegin() const
		{
			const_iterator it = const_iterator(&_nil, _root, &_nil);
			return const_reverse_iterator(it);
		}

		reverse_iterator
		rend()
		{
			if (empty())
				return rbegin();

			iterator it = iterator(minimum(), _root, &_nil);
			return reverse_iterator(it);
		}

		const_reverse_iterator
		rend() const
		{
			if (empty())
				return rbegin();

			const_iterator it = const_iterator(minimum(), _root, &_nil);
			return const_reverse_iterator(it);
		}

/*                                  Capacity                                  */

		bool
		empty() const
		{
			return _size == 0;
		}

		size_type
		size() const
		{
			return _size;
		}

		size_type
		max_size() const
		{
			return _alloc.max_size();
		}

/*                                  Modifiers                                 */

		// Single element
		ft::pair<iterator, bool>
		insert(value_type const& val)
		{
			// Ignore duplicates keys
			iterator it = find(get_key_from_val(val));

			if (it != end())
				return ft::make_pair(it, false);

			// New nodes are necessarily red and leaf nodes so they point
			// to _nil
			node_pointer node = _alloc.allocate(1);
			_alloc.construct(node, node_type(val, NULL, &_nil, &_nil, red));

			it = iterator(insert_helper(node, _root), _root, &_nil);

			_size++;

			return ft::make_pair(it, true);
		}

		// With hint
		iterator
		insert(iterator hint, value_type const& val)
		{
			node_pointer successor = get_successor(hint._ptr);
			node_pointer node;

			// Check if position is correct
			if (_comp(get_key_from_iterator(hint), get_key_from_val(val))
					&& _comp(get_key_from_val(val), get_key_from_val(successor->data)))
			{
				// New nodes are necessarily red and leaf nodes so they point
				// to _nil
				node = _alloc.allocate(1);
				_alloc.construct(node, node_type(val, NULL, &_nil, &_nil, red));

				_size++;

				return iterator(insert_helper(node, hint._ptr), _root, &_nil);
			}
			else
				return insert(val).first;
		}

		// Range
		template<class InputIterator>
		void
		insert(InputIterator first, InputIterator last)
		{
			while (first != last)
				insert(*first++);
		}

		// With position
		void
		erase(iterator position)
		{
			if (position == end())
				return;

			erase_helper(position._ptr);
			_size--;
		}

		// With key
		size_type
		erase(key_type const& key)
		{
			iterator it = find(key);

			// Val not found in tree so nothing erased
			if (it == end())
				return 0;

			erase(it);
			return 1;
		}

		// Range
		void
		erase(iterator first, iterator last)
		{
			while (first != last)
				erase(first++);
		}

		void
		clear()
		{
			clear_helper(_root);
			_root = &_nil;
		}

/*                                Observers                                   */

		key_compare
		key_comp() const
		{
			return key_compare();
		}

/*                                Operations                                  */

		iterator
		find(key_type const& key)
		{
			node_pointer position = find_helper(key, _root);

			if (!position)
				return end();
			else
				return iterator(position, _root, &(_nil));
		}

		const_iterator
		find(key_type const& key) const
		{
			node_pointer position = find_helper(key, _root);

			if (!position)
				return end();
			else
				return const_iterator(position, _root, &(_nil));
		}

		size_type
		count(key_type const& key) const
		{
			return (find(key) != end());
		}

		iterator
		lower_bound(key_type const& k)
		{
			iterator begin = this->begin();
			iterator end = this->end();

			while (begin != end)
			{
				if (_comp(k, get_key_from_iterator(begin))
						|| k == get_key_from_iterator(begin))
					return begin;
				begin++;
			}

			return end;
		}

		const_iterator
		lower_bound(key_type const& k) const
		{
			const_iterator begin = begin();
			const_iterator end = end();

			while (begin != end)
			{
				if (_comp(k, get_key_from_const_iterator(begin))
						|| k == get_key_from_const_iterator(begin))
					return begin;
				begin++;
			}

			return end;
		}

		iterator
		upper_bound(key_type const& k)
		{
			iterator begin = this->begin();
			iterator end = this->end();

			while (begin != end)
			{
				if (_comp(k, get_key_from_iterator(begin)))
					return begin;
				begin++;
			}

			return end;
		}

		const_iterator
		upper_bound(key_type const& k) const
		{
			const_iterator begin = begin();
			const_iterator end = end();

			while (begin != end)
			{
				if (_comp(k, get_key_from_const_iterator(begin)))
					return begin;
				begin++;
			}

			return end;
		}

		ft::pair<iterator,iterator>
		equal_range(key_type const& k)
		{
			return ft::pair<iterator, iterator>
				(lower_bound(k), upper_bound(k));
		}

		ft::pair<const_iterator, const_iterator>
		equal_range(key_type const& k) const
		{
			return ft::pair<const_iterator, const_iterator>
				(lower_bound(k), upper_bound(k));
		}

	protected:
/******************************************************************************/
/*                   	 HELPERS FOR PUBLIC FUNCTIONS                         */
/******************************************************************************/

/*                            Compare helpers                                 */

		// Allows to have one insert for red_black_tree that works for
		// both set and map
		// This function is defined in each set (return val) and
		// map (return val.first)
		virtual	key_type
		get_key_from_val(value_type const& val) const = 0;

		virtual	key_type
		get_key_from_iterator(iterator it) const = 0;

		virtual	key_type
		get_key_from_const_iterator(const_iterator it) const = 0;

/*                            Finding helpers                                 */

		node_pointer
		find_helper(key_type const& key, node_pointer const& node) const
		{
			// Base case of recursion
			if (node == &(_nil))
				return NULL;
			else if (get_key_from_val(node->data) == key)
				return node;

			if (_comp(key, get_key_from_val(node->data)))
				return find_helper(key, node->left);
			else
				return find_helper(key, node->right);
		}

/*                              Print helpers                                 */

		void
		print_tree() const
		{
			if (_root == &_nil)
				return;

			std::cout
				<< (_root->color == red ? "\033[1;31m" : "")
				<< _root->data
				<< "\033[0m"
				<< std::endl;
			print_tree_helper(_root, "");
			std::cout << std::endl;
		}

		void
		print_tree_helper(node_pointer node, std::string prefix) const
		{
			// Base of recursion
			if (node == &_nil)
				return;

			bool has_left = (node->left != &_nil);
			bool has_right = (node->right != &_nil);

			if (!has_left && !has_right)
				return;

			std::cout << prefix;
			std::cout << ((has_left && has_right) ? "├── " : "");
			std::cout << ((!has_left && has_right) ? "└── " : "");

			if (has_right)
			{
				bool print_strand = (has_left && has_right
						&& (node->right->right != NULL || node->right->left != NULL));
				std::string new_prefix = prefix + (print_strand ? "│   " : "    ");
				std::cout
					<< (node->right->color == red ? "\033[0;31m" : "")
					<< node->right->data
					<< "\033[0m"
					<< std::endl;
				print_tree_helper(node->right, new_prefix);
			}

			if (has_left)
			{
				std::cout << (has_right ? prefix : "") << "└── "
					<< (node->left->color == red ? "\033[0;31m" : "")
					<< node->left->data
					<< "\033[0m"
					<< std::endl;
				print_tree_helper(node->left, prefix + "    ");
			}
		}

		void
		print_inorder() const
		{
			print_inorder_helper(_root);
			std::cout << std::endl;
		}

		void
		print_inorder_helper(node_pointer const& node) const
		{
			// Base case of recursion
			if (node == &_nil)
				return;

			print_inorder_helper(node->left);
			std::cout
				<< node->data << " "
				<< "[" << (node->color == black ?
						"B" :
						"\033[0;31mR\033[0m") << "] ";
			print_inorder_helper(node->right);
		}

/*                             Copying helper                                 */

		void
		copy_helper(node_pointer& lhs,
				node_pointer rhs,
				node_pointer parent,
				node_type const& nil_rhs)
		{
			// Base case of the recursion
			if (rhs == &nil_rhs)
			{
				lhs = &_nil;
				return;
			}

			lhs = _alloc.allocate(1);
			_alloc.construct(lhs, *rhs);
			// Parent is the previously created node pased as argument
			lhs->parent = parent;

			copy_helper(lhs->left, rhs->left, lhs, nil_rhs);
			copy_helper(lhs->right, rhs->right, lhs, nil_rhs);
		}

/*                           Insertion helpers                                */

		node_pointer
		insert_helper(node_pointer node, node_pointer hint)
		{
			node->parent = find_right_position(node, hint);

			// Set node in the position found. Either left or right
			// If parent NULL then it means we are at the root of the tree
			// so we can retrun
			if (node->parent == NULL)
			{
				_root = node;
				_root->color = black;

				return _root;
			}
			else if (_comp(get_key_from_val(node->data), get_key_from_val(node->parent->data)))
				node->parent->left = node;
			else
				node->parent->right = node;

			// If parent is _root then we are at level 1 of the tree
			// so we can't be unbalancing the tree
			// Else the new node could have unbalanced the red-black tree
			// so we need to check after each insert
			if (node->parent != _root)
				check_insert(node);

			return node;
		}

		// Returns the parent where the new node will go
		// The hint will only be a real hint if
		// insert(iterator hint, value_type const& val) is called
		// Else it's _root
		node_pointer
		find_right_position(node_pointer node, node_pointer hint)
		{
			node_pointer	parent = NULL;
			node_pointer	child = hint;

			while (child != &_nil)
			{
				parent = child;
				if (_comp(get_key_from_val(node->data), get_key_from_val(child->data)))
					child = child->left;
				else
					child = child->right;
			}

			return parent;
		}

		void
		check_insert(node_pointer& node)
		{
			node_pointer parent = node->parent;
			node_pointer grandparent;
			node_pointer uncle;

			// Base case of recursion
			if (parent->color == black)
				return;

			grandparent = parent->parent;
			uncle = grandparent->left == parent ?
					grandparent->right :
					grandparent->left;

			if (uncle->color == black)
			{
				// Rotate && recolor
				// Right - right situation
				if (parent->right == node && grandparent->right == parent)
				{
					rotate_left(parent);
					recolor(parent->color);
					recolor(parent->left->color);
				}
				// Right - left situation
				else if (parent->right == node && grandparent->left == parent)
				{
					rotate_left(node);
					rotate_right(node);
					recolor(node->color);
					recolor(node->right->color);
				}
				// Left - left situation
				else if (parent->left == node && grandparent->left == parent)
				{
					rotate_right(parent);
					recolor(parent->color);
					recolor(parent->right->color);
				}
				// Left - right situation
				else if (parent->left == node && grandparent->right == parent)
				{
					rotate_right(node);
					rotate_left(node);
					recolor(node->color);
					recolor(node->left->color);
				}
			}
			else if (uncle->color == red)
			{
				// Recolor parent and uncle
				recolor(parent->color);
				recolor(uncle->color);

				// If grandparent of new_node is not root node
				// recolor it and recheck
				if (grandparent != _root)
				{
					// Recolor
					recolor(grandparent->color);
					// Recheck with grandparent as node
					check_insert(grandparent);
				}
			}
		}

		void
		recolor(color& color)
		{
			color = color == red ? black : red;
		}

		void
		rotate_left(node_pointer& node)
		{
			node_pointer grandparent = node->parent->parent;
			node_pointer parent = node->parent;
			node_pointer tmp = &_nil;

			// Update grandparent
			if (grandparent == NULL)
				_root = node;
			else if (grandparent->left == parent)
				grandparent->left = node;
			else
				grandparent->right = node;

			// Save node to the left of node before overwritting it
			if (node->left != &_nil)
			{
				tmp = node->left;
				tmp->parent = parent;
			}

			// Update node itself
			node->left = parent;
			if (node == _root)
				node->parent = NULL;
			else
				node->parent = grandparent;

			// Update parent
			parent->parent = node;
			parent->right = tmp;
		}

		void
		rotate_right(node_pointer& node)
		{
			node_pointer grandparent = node->parent->parent;
			node_pointer parent = node->parent;
			node_pointer tmp = &_nil;

			// Update grandparent
			if (grandparent == NULL)
				_root = node;
			else if (grandparent->left == parent)
				grandparent->left = node;
			else
				grandparent->right = node;

			// Save node to the right of node before overwritting it
			// and set its new parent
			if (node->right != &_nil)
			{
				tmp = node->right;
				tmp->parent = parent;
			}

			// Update node itself
			node->right = parent;
			if (node == _root)
				node->parent = NULL;
			else
				node->parent = grandparent;

			// Update parent
			parent->parent = node;
			parent->left = tmp;
		}

		// Get previous node in order
		node_pointer
		get_predecessor(node_pointer node)
		{
			node_pointer predecessor;

			// If node has a left child, it's predecessor is the maximum
			// of its left subtree
			if (node->left != &_nil)
				return maximum(node->left);

			// If not, we need to go look for it in it's parent left side
			// The predecessor will be the first node that has its
			// left child that isn't also an ancestor of the base node
			predecessor = node->parent;
			while (node != _root && node == predecessor->left)
			{
				node = predecessor;
				predecessor = predecessor->parent;
			}

			// If node is _root then successor is NULL
			return predecessor;
		}

		// Get next node in order
		node_pointer
		get_successor(node_pointer node)
		{
			node_pointer successor;

			// If node has a right child, it's successor is the minimum
			// of its right subtree
			if (node->right != &_nil)
				return minimum(node->right);

			// If not, we need to go look for it in it's parent right side
			// The successor will be the first node that has its
			// right child that isn't also an ancestor of the base node
			successor = node->parent;
			while (node != _root && node == successor->right)
			{
				node = successor;
				successor = successor->parent;
			}

			// If node is _root then successor is NULL
			return successor;
		}

		node_pointer
		maximum() const
		{
			node_pointer node = _root;

			if (empty())
				return NULL;

			while (node->right != &_nil)
				node = node->right;

			return node;
		}

		node_pointer
		maximum(node_pointer node) const
		{
			if (empty())
				return NULL;

			while (node->right != &_nil)
				node = node->right;

			return node;
		}

		node_pointer
		minimum() const
		{
			node_pointer node = _root;

			if (empty())
				return NULL;

			while (node->left != &_nil)
				node = node->left;

			return node;
		}

		node_pointer
		minimum(node_pointer node) const
		{
			if (empty())
				return NULL;

			while (node->left != &_nil)
				node = node->left;

			return node;
		}

/*                           Erasing helpers                                  */

		void
		erase_helper(node_pointer node)
		{
			node_pointer	tmp;

			// Case: leaf node (base case of the recursion)
			// We only delete leaf nodes. Internal nodes are replaced
			if (node->left == &_nil && node->right == &_nil)
			{
				// Fix double black case. If we delete a black leaf node
				// we are violating the rule that states that all paths
				// in a red-black tree have the same number of black nodes
				if (node->color == black)
					fix_double_black(node);

				// Update parent
				if (node == _root)
					_root = &_nil;
				else if (node->parent->left == node)
					node->parent->left = &_nil;
				else
					node->parent->right = &_nil;

				_alloc.destroy(node);
				_alloc.deallocate(node, 1);

			}
			// Case: node one or two childs
			// If two childs, we get successor
			else
			{
				// Find predecessor or successor
				if (node->right != &_nil)
					tmp = get_successor(node);
				else
					tmp = get_predecessor(node);

				// Swap nodes but they switch colors and node gets tmp's data
				// but tmp keeps it's data
				swap_nodes(node, tmp);

				// Recursively replace and delete node
				erase_helper(node);
			}
		}

		// Swap nodes but not strict swap:
		// - They take each other's colors
		// - Node a get's b's data but b keeps its data
		void
		swap_nodes(node_pointer a, node_pointer b)
		{
			node_type		tmp = *b;
			node_pointer	old_root = _root;

			// Update parentage
			// a's parent points to b
			if (_root == a)
				_root = b;
			else if (a->parent->left == a)
				a->parent->left = b;
			else if (a->parent->right == a)
				a->parent->right = b;
			// and b points at a's parent
			b->parent = a->parent;

			// b's parent (via tmp) points to a
			// If root changed it means that _root was originally a and
			// was changed to b
			if (old_root == _root && _root == b)
				_root = a;
			else if (tmp.parent->left == b)
				tmp.parent->left = a;
			else if (tmp.parent->right == b)
				tmp.parent->right = a;
			// and a points back at b's parent
			a->parent = tmp.parent;

			// Update children
			b->left = a->left;
			if (b->left != &_nil)
				b->left->parent = b;
			b->right = a->right;
			if (b->right != &_nil)
				b->right->parent = b;

			a->left = tmp.left;
			if (a->left != &_nil)
				a->left->parent = a;
			a->right = tmp.right;
			if (a->right != &_nil)
				a->right->parent = a;

			// Update colors
			swap_color(a, b);

			// Update data
			a->data = b->data;
		}

		void
		fix_double_black(node_pointer node)
		{
			node_pointer parent;
			node_pointer sibling;

			// Base case of recursion: if DB is root, nothing to do
			if (node == _root)
				return;

			parent = node->parent;

			// Get double black's sibling. If it's a double black, it
			// necessarily has one
			if (parent->left == node)
				sibling = parent->right;
			else
				sibling = parent->left;

			// Case: DB's sibling is black and its children are black
			if (sibling->color == black
					&& sibling->left->color == black
					&& sibling->right->color == black)
			{
				// DB gives blackness to parent and sibling
				// gets mad (ie becomes red)
				if (parent->color == red)
				{
					parent->color = black;
					sibling->color = red;
				}
				else if (parent->color == black)
				{
					sibling->color = red;
					// If parent is already black it carries double-blackness
					fix_double_black(parent);
				}
			}
			// Case: DB's sibling is red
			else if (sibling->color == red)
			{
				parent->color = red;
				sibling->color = black;

				// Rotate towards the direction of the node we want to delete
				if (parent->left == node)
					rotate_left(sibling);
				else
					rotate_right(sibling);

				// Double black case still exists but the sibling of the node
				// we want to delete has changed
				fix_double_black(node);
			}
			// Case: DB's sibling is black and nearest sibling's child is red
			// and furthest from DB is black
			else if (sibling->color == black
					&& ((sibling == parent->right
						&& sibling->left->color == red
						&& sibling->right->color == black)
						|| (sibling == parent->left
							&& sibling->left->color == black
							&& sibling->right->color == red)))
			{
				if (sibling == parent->right)
				{
					swap_color(sibling, sibling->left);
					rotate_right(sibling->left);
				}
				else
				{
					swap_color(sibling, sibling->right);
					rotate_left(sibling->right);
				}

				// Double black case still exists but the sibling of the node
				// we want to delete has changed
				fix_double_black(node);
			}
			// Case: DB's sibling is black and furthest sibling's child is red
			else if (sibling->color == black
					&& ((sibling == parent->right
						&& sibling->right->color == red)
						|| (sibling == parent->left
							&& sibling->left->color == red)))
			{
				swap_color(parent, sibling);

				// Rotate parent towards DB
				if (sibling == parent->right)
				{
					rotate_left(sibling);
					sibling->right->color = black;
				}
				else
				{
					rotate_right(sibling);
					sibling->left->color = black;
				}
			}
		}

		void
		swap_color(node_pointer a, node_pointer b)
		{
			color tmp = b->color;
			b->color = a->color;
			a->color = tmp;
		}

		void
		clear_helper(node_pointer const& node)
		{
			// Base case of recursion
			if (node == &_nil)
				return;

			// Clear all nodes to the left and right of it
			clear_helper(node->left);
			clear_helper(node->right);

			// Clear the node itself
			_alloc.destroy(node);
			_alloc.deallocate(node, 1);

			_size--;
		}

/******************************************************************************/
/*                   	        PRIVATE DATA                                  */
/******************************************************************************/

		node_pointer	_root;
		node_type		_nil;
		size_type		_size;
		key_compare		_comp;
		allocator_type	_alloc;
	};

}

#endif
