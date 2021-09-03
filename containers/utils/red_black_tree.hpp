/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 11:14:19 by dda-silv          #+#    #+#             */
/*   Updated: 2021/09/03 19:35:18 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

# include <stddef.h>	// NULL
# include <memory>		// std::allocator
# include <iostream>	// std::cout

# include "pair.hpp"
# include "less.hpp"

namespace ft
{
	enum color { red, black };

	template<class T>
	struct rbt_node
	{
		T				data;
		rbt_node<T>*	parent;
		rbt_node<T>*	left;
		rbt_node<T>*	right;
		color			color;
	};

	template<class T,
		class Compare = ft::less<T>,
		class Alloc = std::allocator<rbt_node<T> >
			>
	class rbt
	{
	public:
/******************************************************************************/
/*                   	        MEMBER TYPES					              */
/******************************************************************************/

		typedef T						value_type;
		typedef Compare					value_compare;
		typedef Alloc					allocator_type;
		typedef rbt_node<value_type>	node_t;
		typedef rbt_node<value_type>*	node_pointer;

/******************************************************************************/
/*                   	        MEMBER FUNCTIONS                              */
/******************************************************************************/
/******************************************************************************/
/*                   	 CONSTRUCTORS & DESTRUCTORS                           */
/******************************************************************************/

/*                                Constructors                                */

		explicit rbt(value_compare const& comp = value_compare(),
				allocator_type const& alloc = allocator_type()) :
			_root(NULL),
			_comp(comp),
			_alloc(alloc)
		{
			// All leaf nodes will point to _nil. This will allow us to
			// check if _nil
			_nil.data = value_type();
			_nil.parent = NULL;
			_nil.left = NULL;
			_nil.right = NULL;
			_nil.color = black;

			// Set root pointing to _nil. Empty tree
			_root = &_nil;
		}

		// Copy
		rbt(rbt const& rhs) :
			_root(NULL),
			_nil(rhs._nil),
			_comp(rhs._comp),
			_alloc(rhs._alloc)
		{
			*this = rhs;
		}

/*                                Destructors                                 */

		virtual
		~rbt() {}

/******************************************************************************/
/*                   	   OVERLOADING OPERATORS                              */
/******************************************************************************/

/*                                Assignement                                 */

		rbt&
		operator=(rbt const& rhs)
		{
			// Self-assignement check
			if (this == &rhs)
				return *this;

			// Clear current
			if (_root != NULL)
				clear();
			copy_helper(_root, rhs._root, NULL, rhs._nil);

			return *this;
		}

/******************************************************************************/
/*                   	    OTHER MEMBER FUNCTIONS                            */
/******************************************************************************/

		void
		insert(value_type const& val)
		{
			// Ignore duplicates
			if (find(val))
				return;

			// Allocate new node on the base of _nil
			node_pointer new_node = _alloc.allocate(1);
			_alloc.construct(new_node, _nil);
			new_node->parent = NULL;
			new_node->data = val;
			new_node->left = &_nil;
			new_node->right = &_nil;

			// New node always are red
			new_node->color = red;

			node_pointer parent = NULL;
			node_pointer child = _root;

			// Find right position for the new node
			while (child != &_nil)
			{
				parent = child;
				if (_comp(new_node->data, child->data))
					child = child->left;
				else
					child = child->right;
			}

			new_node->parent = parent;

			// Set node in the position found. Either left or right
			// If parent NULL then it means we are at the root of the tree
			// so we can retrun
			if (new_node->parent == NULL)
			{
				_root = new_node;
				_root->color = black;
				return;
			}
			else if (_comp(new_node->data, parent->data))
				parent->left = new_node;
			else
				parent->right = new_node;

			// If parent is _root then we are at level 1 of the tree
			// so we can't be unbalancing the tree
			if (parent == _root)
				return;
			// Else the new node could have unbalanced the red-black tree
			// so we need to check after each insert
			else
				check_insert(new_node);
		}

		node_pointer
		find(value_type const& val) const
		{
			return find_helper(val, _root);
		}

		void
		print_tree() const
		{
			if (_root == NULL)
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
		print_inorder() const
		{
			print_inorder_helper(_root);
			std::cout << std::endl;
		}

		void
		erase(value_type const& val)
		{
			node_pointer node = find(val);

			// Don't do nothing if val not found
			if (!node)
				return;

			erase_helper(node);
		}

		void
		clear()
		{
			clear_helper(_root);
		}

		node_pointer
		maximum(node_pointer node)
		{
			while (node->right != &_nil)
				node = node->right;

			return node;
		}

		node_pointer
		minimum(node_pointer node)
		{
			while (node->left != &_nil)
				node = node->left;

			return node;
		}

		node_pointer
		predecessor(node_pointer node)
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

		node_pointer
		successor(node_pointer node)
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

	private:
/******************************************************************************/
/*                   	 HELPERS FOR PUBLIC FUNCTIONS                         */
/******************************************************************************/

		void
		copy_helper(node_pointer& lhs,
				node_pointer rhs,
				node_pointer parent,
				node_t const& nil_rhs)
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

		node_pointer
		find_helper(value_type const& val, node_pointer const& node) const
		{
			// Base case of recursion
			if (node == &_nil)
				return NULL;
			else if (node->data == val)
				return node;

			if (_comp(val, node->data))
				return find_helper(val, node->left);
			else
				return find_helper(val, node->right);
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
		print_inorder_helper(node_pointer const& node) const
		{
			// Base case of recursion
			if (node == &_nil)
				return;

			print_inorder_helper(node->left);
			std::cout << node->data << " "
				<< "[" << (node->color == black ?
						"B" :
						"\033[0;31mR\033[0m") << "] ";
			print_inorder_helper(node->right);
		}

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
				if (node->parent->left == node)
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
					tmp = successor(node);
				else
					tmp = predecessor(node);

				// Only copy data. The color stays the same
				node->data = tmp->data;

				// Recursively replace and delete node
				erase_helper(tmp);
			}
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

			// Get double black's sibling if it exists
			if (parent->left == node && parent->right != &_nil)
				sibling = parent->right;
			else if (parent->right == node && parent->left != &_nil)
				sibling = parent->left;
			else
				sibling = NULL;

			// Case: DB's doesn't have sibling
			if (!sibling)
			{
			}
			// Case: DB's sibling is black and its children are black
			else if (sibling->color == black
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
			// and nearest from DB is black
			else if (sibling->color == black
					&& ((sibling == parent->right
						&& sibling->left->color == black
						&& sibling->right->color == red)
						|| (sibling == parent->left
							&& sibling->left->color == red
							&& sibling->right->color == black)))
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
		}

/******************************************************************************/
/*                   	        PRIVATE DATA                                  */
/******************************************************************************/

		node_pointer	_root;
		node_t			_nil;
		value_compare	_comp;
		allocator_type	_alloc;
	};
}

#endif
