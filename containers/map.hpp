/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 11:13:07 by dda-silv          #+#    #+#             */
/*   Updated: 2021/09/05 01:53:55 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <memory>		// std::allocator
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
	class map
	{
	public:
/******************************************************************************/
/*                   	        MEMBER TYPES					              */
/******************************************************************************/

		typedef Key									key_type;
		typedef T									mapped_type;
		typedef pair<key_type const, mapped_type>	value_type;
		typedef Compare								key_compare;

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

		typedef Alloc											allocator_type;
		typedef typename allocator_type::reference				reference;
		typedef typename allocator_type::const_reference		const_reference;
		typedef typename allocator_type::pointer				pointer;
		typedef typename allocator_type::const_pointer			const_pointer;

		typedef typename ft::red_black_tree<key_type,
										mapped_type,
										key_compare,
										allocator_type>::iterator iterator;
		typedef typename ft::red_black_tree<key_type,
										mapped_type,
										key_compare,
										allocator_type>::const_iterator const_iterator;
		typedef typename ft::red_black_tree<key_type,
										mapped_type,
										key_compare,
										allocator_type>::reverse_iterator reverse_iterator;
		typedef typename ft::red_black_tree<key_type,
										mapped_type,
										key_compare,
										allocator_type>::const_reverse_iterator const_reverse_iterator;

		typedef typename
			ft::iterator_traits<iterator>::difference_type		difference_type;
		typedef std::size_t										size_type;

/******************************************************************************/
/*                   	        MEMBER FUNCTIONS                              */
/******************************************************************************/
/******************************************************************************/
/*                   	 CONSTRUCTORS & DESTRUCTORS                           */
/******************************************************************************/

/*                                Constructors                                */

		explicit
		map(key_compare const& comp = key_compare(),
			allocator_type const& alloc = allocator_type()) :
			_tree(comp, alloc),
			_comp(comp),
			_alloc(alloc) {}

		template<class InputIterator>
		map(InputIterator first,
				InputIterator last,
				key_compare const& comp = key_compare(),
				allocator_type const& alloc = allocator_type()) :
			_tree(comp, alloc),
			_comp(comp),
			_alloc(alloc)
		{
			_tree.insert(first, last);
		}

		map(map const& rhs) :
			_tree(rhs._tree),
			_comp(rhs._comp),
			_alloc(rhs._alloc)
		{}

/*                                Destructors                                 */

		virtual
		~map()
		{
			_tree.clear();
		}

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

			_tree = rhs._tree;
		}

/******************************************************************************/
/*                   	    OTHER MEMBER FUNCTIONS                            */
/******************************************************************************/

/*                                 Iterators                                  */

		iterator
		begin()
		{
			return _tree.begin();
		}

		const_iterator
		begin() const
		{
			return _tree.begin();
		}

		iterator
		end()
		{
			if (empty())
				return begin();
			return _tree.end();
		}

		const_iterator
		end() const
		{
			if (empty())
				return begin();
			return _tree.end();
		}

/*                                  Capacity                                  */

		bool
		empty() const
		{
			return size() == 0;
		}

		size_type
		size() const
		{
			return _tree.size();
		}

		size_type
		max_size() const
		{
			return _tree.max_size();
		}

/*                               Element access                               */

		mapped_type&
		operator[] (key_type const& k)
		{
			return _tree.find(k)->data.second;
		}

	private:
/******************************************************************************/
/*                   	        PRIVATE DATA                                  */
/******************************************************************************/

		red_black_tree<key_type,
						mapped_type,
						key_compare,
						allocator_type>	_tree;
		key_compare						_comp;
		allocator_type					_alloc;

	};
}

#endif
