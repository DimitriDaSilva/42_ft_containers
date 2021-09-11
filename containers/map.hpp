/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 11:13:07 by dda-silv          #+#    #+#             */
/*   Updated: 2021/09/11 19:30:49 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <memory>		// std::allocator
# include <stdexcept>	// std::out_of_range

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
	class map : public ft::red_black_tree<Key,
						ft::pair<Key const, T>,
						Compare,
						typename Alloc::template
							rebind<ft::red_black_tree_node<ft::pair<Key const, T> > >::other >
	{
	public:
/******************************************************************************/
/*                   	        MEMBER TYPES					              */
/******************************************************************************/

		typedef Alloc										allocator_type;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;

		// We are rebinding the allocator to have nodes instead of pair<>
		typedef typename allocator_type::template
			rebind<typename ft::red_black_tree_node<
				ft::pair<Key const, T> > >::other			node_allocator_type;

		// Typedef the abstract class to inherit from its member types
		typedef ft::red_black_tree<Key,
					ft::pair<Key const, T>,
					Compare,
					node_allocator_type>					tree_type;

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

			return *this;
		}

/******************************************************************************/
/*                   	    OTHER MEMBER FUNCTIONS                            */
/******************************************************************************/

/*                               Element access                               */

		mapped_type&
		operator[] (key_type const& k)
		{
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
			node_pointer position = this->find_helper(k, this->_root);

			// Match
			if (position)
				return position->data.second;
			// No match
			else
				throw std::out_of_range("at:: out of range index");
		}

		mapped_type const&
		at(key_type const& k) const
		{
			node_pointer position = this->find_helper(k, this->_root);

			// Match
			if (position)
				return position->data.second;
			// No match
			else
				throw std::out_of_range("at:: out of range index");
		}

/*                                  Modifiers                                 */

		void
		swap(map& rhs)
		{
			// Swao root
			node_pointer tmp_root = this->_root;
			this->_root = rhs._root;
			rhs._root = tmp_root;

			// Swao nil
			node_pointer tmp_nil = this->_nil;
			this->_nil = rhs._nil;
			rhs._nil = tmp_nil;

			// Swao size
			size_type tmp_size = this->_size;
			this->_size = rhs._size;
			rhs._size = tmp_size;
		}

/*                                Observers                                   */

		value_compare
		value_comp() const
		{
			return value_compare(key_compare());
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

/*                            Compare helpers                                 */

		// Allows to have one insert for red_black_tree that works for
		// both set and map
		key_type
		get_key_from_val(value_type const& val) const
		{
			return val.first;
		}

		key_type
		get_key_from_iterator(iterator it) const
		{
			return it->first;
		}

		key_type
		get_key_from_const_iterator(const_iterator it) const
		{
			return it->first;
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
