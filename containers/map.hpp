/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 11:13:07 by dda-silv          #+#    #+#             */
/*   Updated: 2021/09/09 13:34:43 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <memory>		// std::allocator
# include <stdexcept>	// std::out_of_range
# include <cstddef>		// std::size_t

# include "red_black_tree.hpp"
# include "iterator_traits.hpp"
# include "pair.hpp"
# include "less.hpp"

namespace ft
{
	template<class Key,
		class T,
		class Compare = ft::less<Key>,
		class Alloc = std::allocator<ft::pair<Key const, T> >
		>
	class map : public ft::red_black_tree<Key, ft::pair<Key const, T>, Compare>
	{
	public:
/******************************************************************************/
/*                   	        MEMBER TYPES					              */
/******************************************************************************/

		// Typedef the abstract class to inherit from its member types
		typedef ft::red_black_tree<Key, ft::pair<Key const, T>, Compare> tree_type;

		// In map, we need to have pointers to the nodes, not just
		// the pair<> value_type
		typedef typename tree_type::node_type				node_type;
		typedef typename tree_type::node_pointer			node_pointer;

		typedef typename tree_type::key_type				key_type;
		typedef T											mapped_type;
		typedef typename tree_type::value_type				value_type;
		typedef typename tree_type::key_compare				key_compare;

		// Returns a comparison object that can be used to compare two elements
		class value_compare : ft::binary_function<value_type, value_type, bool>
		{
		friend class map;

		public:
			bool
			operator() (value_type const& x, value_type const& y) const
			{
				return comp(x.first, y.first);
			}

		protected:
			Compare comp;
			value_compare(Compare c) : comp(c) {}
		};

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
		map(key_compare const& comp = key_compare(),
			allocator_type const& alloc = allocator_type()) :
			tree_type(comp),
			_value_alloc(alloc) {}

		// Range
		template<class InputIterator>
		map(InputIterator first,
				InputIterator last,
				key_compare const& comp = key_compare(),
				allocator_type const& alloc = allocator_type()) :
			tree_type(comp),
			_value_alloc(alloc)
		{
			this->insert(first, last);
		}

		// Copy
		map(map const& rhs) : tree_type(rhs) {}

/*                                Destructors                                 */

		virtual
		~map() {}

/******************************************************************************/
/*                   	   OVERLOADING OPERATORS                              */
/******************************************************************************/

/*                                Assignement                                 */

		map&
		operator=(map const& rhs)
		{
			// Self-assignement check
			if (this == &rhs)
				return *this;

			// Clear current
			if (this->_root != NULL)
				this->clear();
			this->copy_helper(this->_root, rhs._root, NULL, rhs._nil);

			this->_size = rhs._size;
			this->_max_size = rhs._max_size;

			return *this;
		}

/******************************************************************************/
/*                   	    OTHER MEMBER FUNCTIONS                            */
/******************************************************************************/

/*                               Element access                               */

		mapped_type&
		operator[] (key_type const& k)
		{
			//return (*((this->insert(ft::make_pair(k, mapped_type()))).first)).second;
			node_pointer position = this->find_helper(k, this->_root);

			// Match
			if (position)
				return position->data.second;
			// No match
			else
			{
				ft::pair<iterator, bool> pr;

				pr = this->insert(ft::make_pair(k, mapped_type()));

				iterator it = pr.first;

				return it._ptr->data.second;
			}
		}

		mapped_type&
		at(key_type const& k)
		{
			(void)k;
		}

		mapped_type const&
		at(key_type const& k) const
		{
			(void)k;
		}

/*                                  Modifiers                                 */

		// Single element
		ft::pair<iterator, bool>
		insert(value_type const& val)
		{
			// Ignore duplicates keys
			iterator it = this->find(val.first);

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
			if (this->_comp(hint->first, val.first) && this->_comp(val.first, successor->data.first))
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
		swap(map& rhs)
		{
			map tmp(rhs);

			rhs = *this;
			*this = tmp;
		}

/*                                Observers                                   */

		value_compare
		value_comp() const
		{
			return value_compare(key_compare());
		}

/*                                  Operations                                */

		iterator
		lower_bound(key_type const& k)
		{
			iterator begin = this->begin();
			iterator end = this->end();

			while (begin != end)
			{
				if (this->_comp(k, begin->first) || k == begin->first)
					return begin;
				begin++;
			}

			return end;
		}

		const_iterator
		lower_bound(key_type const& k) const
		{
			const_iterator begin = this->begin();
			const_iterator end = this->end();

			while (begin != end)
			{
				if (this->_comp(k, begin->first) || k == begin->first)
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
				if (this->_comp(k, begin->first))
					return begin;
				begin++;
			}

			return end;
		}

		const_iterator
		upper_bound(key_type const& k) const
		{
			const_iterator begin = this->begin();
			const_iterator end = this->end();

			while (begin != end)
			{
				if (this->_comp(k, begin->first))
					return begin;
				begin++;
			}

			return end;
		}

		ft::pair<iterator,iterator>
		equal_range(key_type const& k)
		{
			return ft::pair<iterator, iterator>
				(this->lower_bound(k), this->upper_bound(k));
		}

		ft::pair<const_iterator, const_iterator>
		equal_range(key_type const& k) const
		{
			return ft::pair<const_iterator, const_iterator>
				(this->lower_bound(k), this->upper_bound(k));
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
			else if (node->data.first == key)
				return node;

			if (this->_comp(key, node->data.first))
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
			else if (this->_comp(node->data.first, node->parent->data.first))
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
				if (this->_comp(node->data.first, child->data.first))
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

	template<class Key, class T, class Compare, class Alloc>
	bool
	operator==(map<Key, T, Compare, Alloc> const& lhs, map<Key, T, Compare, Alloc> const& rhs)
	{
		if (lhs.size() != rhs.size())
			return false;

		return equal(lhs.begin(), lhs.end(), rhs.begin());
	}

	template<class Key, class T, class Compare, class Alloc>
	bool
	operator!=(map<Key, T, Compare, Alloc> const& lhs, map<Key, T, Compare, Alloc> const& rhs)
	{
		return !(lhs == rhs);
	}

	template<class Key, class T, class Compare, class Alloc>
	bool
	operator<(map<Key, T, Compare, Alloc> const& lhs, map<Key, T, Compare, Alloc> const& rhs)
	{
		return lexicographical_compare(lhs.begin(),
										lhs.end(),
										rhs.begin(),
										rhs.end());
	}

	template<class Key, class T, class Compare, class Alloc>
	bool
	operator<=(map<Key, T, Compare, Alloc> const& lhs, map<Key, T, Compare, Alloc> const& rhs)
	{
		return !(rhs < lhs);
	}

	template<class Key, class T, class Compare, class Alloc>
	bool
	operator>(map<Key, T, Compare, Alloc> const& lhs, map<Key, T, Compare, Alloc> const& rhs)
	{
		return rhs < lhs;
	}

	template<class Key, class T, class Compare, class Alloc>
	bool
	operator>=(map<Key, T, Compare, Alloc> const& lhs, map<Key, T, Compare, Alloc> const& rhs)
	{
		return !(lhs < rhs);
	}

/*                                  Swap                                      */

	template<class Key, class T, class Compare, class Alloc>
	void
	swap(ft::map<Key, T, Compare, Alloc>& lhs, ft::map<Key, T, Compare, Alloc>& rhs)
	{
		lhs.swap(rhs);
	}
}

#endif
