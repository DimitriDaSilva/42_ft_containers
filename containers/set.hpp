/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 11:13:07 by dda-silv          #+#    #+#             */
/*   Updated: 2021/09/10 10:23:34 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
# define SET_HPP

# include <memory>		// std::allocator
# include <cstddef>		// std::size_t

# include "red_black_tree.hpp"
# include "iterator_traits.hpp"
# include "pair.hpp"
# include "less.hpp"
# include "lexicographical_compare.hpp"
# include "equal.hpp"

namespace ft
{
	template<class T,
		class Compare = ft::less<T>,
		class Alloc = std::allocator<T>
		>
	class set : public ft::red_black_tree<T, T, Compare>
	{
	public:
/******************************************************************************/
/*                   	        MEMBER TYPES					              */
/******************************************************************************/

		// Typedef the abstract class to inherit from its member types
		typedef ft::red_black_tree<T, T, Compare>			tree_type;

		// In set, we need to have pointers to the nodes, not just
		// the value_type
		typedef typename tree_type::node_type				node_type;
		typedef typename tree_type::node_pointer			node_pointer;

		typedef typename tree_type::key_type				key_type;
		typedef typename tree_type::value_type				value_type;
		typedef typename tree_type::key_compare				key_compare;
		typedef typename tree_type::key_compare				value_compare;

		typedef Alloc										allocator_type;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;

		typedef typename tree_type::iterator				iterator;
		typedef typename tree_type::const_iterator			const_iterator;
		typedef typename tree_type::reverse_iterator		reverse_iterator;
		typedef typename tree_type::const_reverse_iterator	const_reverse_iterator;

		typedef typename tree_type::difference_type			difference_type;
		typedef typename tree_type::size_type				size_type;

/******************************************************************************/
/*                   	        MEMBER FUNCTIONS                              */
/******************************************************************************/
/******************************************************************************/
/*                   	 CONSTRUCTORS & DESTRUCTORS                           */
/******************************************************************************/

/*                                Constructors                                */

		// Empty (default)
		explicit
		set(key_compare const& comp = key_compare(),
			allocator_type const& alloc = allocator_type()) :
			tree_type(comp),
			_value_alloc(alloc) {}

		// Range
		template<class InputIterator>
		set(InputIterator first,
				InputIterator last,
				key_compare const& comp = key_compare(),
				allocator_type const& alloc = allocator_type()) :
			tree_type(comp),
			_value_alloc(alloc)
		{
			this->insert(first, last);
		}

		// Copy
		set(set const& rhs) : tree_type(rhs) {}

/*                                Destructors                                 */

		virtual
		~set() {}

/******************************************************************************/
/*                   	   OVERLOADING OPERATORS                              */
/******************************************************************************/

/*                                Assignement                                 */

		set&
		operator=(set const& rhs)
		{
			// Self-assignement check
			if (this == &rhs)
				return *this;

			// Clear current
			if (this->_root != NULL)
				this->clear();
			this->copy_helper(this->_root, rhs._root, NULL, rhs._nil);

			this->_size = rhs._size;

			return *this;
		}

/******************************************************************************/
/*                   	    OTHER MEMBER FUNCTIONS                            */
/******************************************************************************/

/*                                  Modifiers                                 */

		// Single element
		ft::pair<iterator, bool>
		insert(value_type const& val)
		{
			// Ignore duplicates keys
			iterator it = this->find(val);

			if (it != this->end())
				return ft::make_pair(it, false);

			// New nodes are necessarily red and leaf nodes so they point
			// to _nil
			node_pointer node = this->_alloc.allocate(1);
			this->_alloc.construct(node, node_type(val, NULL, &this->_nil, &this->_nil, red));

			it = iterator(insert_helper(node, this->_root), this->_root, &this->_nil);

			this->_size++;

			return ft::make_pair(it, true);
		}

		// With hint
		iterator
		insert(iterator hint, value_type const& val)
		{
			node_pointer successor = this->successor(hint._ptr);
			node_pointer node;

			// Check if position is correct
			if (this->_comp(*hint, val) && this->_comp(val, successor->data))
			{
				// New nodes are necessarily red and leaf nodes so they point
				// to _nil
				node = this->_alloc.allocate(1);
				this->_alloc.construct(node, node_type(val, NULL, &this->_nil, &this->_nil, red));

				this->_size++;

				return iterator(insert_helper(node, hint._ptr), this->_root, &this->_nil);
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

		void
		swap(set& rhs)
		{
			set tmp(rhs);

			rhs = *this;
			*this = tmp;
		}

/*                                Observers                                   */

		value_compare
		value_comp() const
		{
			return value_compare();
		}

/*                                  Operations                                */

		iterator
		lower_bound(value_type const& val)
		{
			iterator begin = this->begin();
			iterator end = this->end();

			while (begin != end)
			{
				if (this->_comp(val, *begin) || val == *begin)
					return begin;
				begin++;
			}

			return end;
		}

		const_iterator
		lower_bound(value_type const& val) const
		{
			const_iterator begin = this->begin();
			const_iterator end = this->end();

			while (begin != end)
			{
				if (this->_comp(val, *begin) || val == *begin)
					return begin;
				begin++;
			}

			return end;
		}

		iterator
		upper_bound(value_type const& val)
		{
			iterator begin = this->begin();
			iterator end = this->end();

			while (begin != end)
			{
				if (this->_comp(val, *begin))
					return begin;
				begin++;
			}

			return end;
		}

		const_iterator
		upper_bound(value_type const& val) const
		{
			const_iterator begin = this->begin();
			const_iterator end = this->end();

			while (begin != end)
			{
				if (this->_comp(val, *begin))
					return begin;
				begin++;
			}

			return end;
		}

		ft::pair<iterator,iterator>
		equal_range(value_type const& val)
		{
			return ft::pair<iterator, iterator>
				(this->lower_bound(val), this->upper_bound(val));
		}

		ft::pair<const_iterator, const_iterator>
		equal_range(value_type const& val) const
		{
			return ft::pair<const_iterator, const_iterator>
				(this->lower_bound(val), this->upper_bound(val));
		}

/*                                  Allocator                                 */

		allocator_type
		get_allocator() const
		{
			return _value_alloc;
		}

	private:
/******************************************************************************/
/*                   	 HELPERS FOR PUBLIC FUNCTIONS                         */
/******************************************************************************/

/*                            Finding helpers                                 */

		node_pointer
		find_helper(key_type const& key, node_pointer const& node) const
		{
			// Base case of recursion
			if (node == &(this->_nil))
				return NULL;
			else if (node->data == key)
				return node;

			if (this->_comp(key, node->data))
				return find_helper(key, node->left);
			else
				return find_helper(key, node->right);
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
				this->_root = node;
				this->_root->color = black;

				return this->_root;
			}
			else if (this->_comp(node->data, node->parent->data))
				node->parent->left = node;
			else
				node->parent->right = node;

			// If parent is _root then we are at level 1 of the tree
			// so we can't be unbalancing the tree
			// Else the new node could have unbalanced the red-black tree
			// so we need to check after each insert
			if (node->parent != this->_root)
				this->check_insert(node);

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

			while (child != &this->_nil)
			{
				parent = child;
				if (this->_comp(node->data, child->data))
					child = child->left;
				else
					child = child->right;
			}

			return parent;
		}

/******************************************************************************/
/*                   	        PRIVATE DATA                                  */
/******************************************************************************/

		allocator_type	_value_alloc;
	};

/******************************************************************************/
/*                        NON-MEMBER FUNCTION OVERLOADS                       */
/******************************************************************************/

/*                              Relational operators                          */

	template<class T, class Compare, class Alloc>
	bool
	operator==(set<T, Compare, Alloc> const& lhs, set<T, Compare, Alloc> const& rhs)
	{
		if (lhs.size() != rhs.size())
			return false;

		return equal(lhs.begin(), lhs.end(), rhs.begin());
	}

	template<class T, class Compare, class Alloc>
	bool
	operator!=(set<T, Compare, Alloc> const& lhs, set<T, Compare, Alloc> const& rhs)
	{
		return !(lhs == rhs);
	}

	template<class T, class Compare, class Alloc>
	bool
	operator<(set<T, Compare, Alloc> const& lhs, set<T, Compare, Alloc> const& rhs)
	{
		return lexicographical_compare(lhs.begin(),
										lhs.end(),
										rhs.begin(),
										rhs.end());
	}

	template<class T, class Compare, class Alloc>
	bool
	operator<=(set<T, Compare, Alloc> const& lhs, set<T, Compare, Alloc> const& rhs)
	{
		return !(rhs < lhs);
	}

	template<class T, class Compare, class Alloc>
	bool
	operator>(set<T, Compare, Alloc> const& lhs, set<T, Compare, Alloc> const& rhs)
	{
		return rhs < lhs;
	}

	template<class T, class Compare, class Alloc>
	bool
	operator>=(set<T, Compare, Alloc> const& lhs, set<T, Compare, Alloc> const& rhs)
	{
		return !(lhs < rhs);
	}

/*                                  Swap                                      */

	template<class T, class Compare, class Alloc>
	void
	swap(ft::set<T, Compare, Alloc>& lhs, ft::set<T, Compare, Alloc>& rhs)
	{
		lhs.swap(rhs);
	}
}

#endif
