/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 11:13:07 by dda-silv          #+#    #+#             */
/*   Updated: 2021/09/06 08:41:35 by dda-silv         ###   ########.fr       */
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
	class map : ft::red_black_tree<Key, ft::pair<Key const, T>, Compare, Alloc>
	{
	public:
/******************************************************************************/
/*                   	        MEMBER TYPES					              */
/******************************************************************************/

		// Typedef the abstract class to inherit from its member types
		typedef
			ft::red_black_tree<Key, ft::pair<Key const, T>, Compare, Alloc>
			tree_type;

		// In map, we often need to have pointers to the nodes, not just
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

		explicit
		map(key_compare const& comp = key_compare(),
			allocator_type const& alloc = allocator_type()) :
			_comp(comp),
			_alloc(alloc) {}

		template<class InputIterator>
		map(InputIterator first,
				InputIterator last,
				key_compare const& comp = key_compare(),
				allocator_type const& alloc = allocator_type()) :
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

/*                               Element access                               */

		mapped_type&
		operator[] (key_type const& k)
		{
			(void)k;
			//return _tree.find(k)->data.second;
		}

/*                                  Modifiers                                 */

		// Single element
		void
		insert(value_type const& val)
		{
			// Ignore duplicates keys
			if (find(val.first))
				return;

			// Allocate new node on the base of _nil
			node_pointer new_node = _alloc.allocate(1);
			node_type	tmp = {
					val,
					NULL,
					&_nil,
					&_nil,
					red,
			};
			_alloc.construct(new_node, tmp);

			insert_helper(new_node);
		}

		// With hint
		iterator
		insert(iterator position, value_type const& val)
		{
			(void)position;
			(void)val;
		}

		// Erase by pair
		void
		erase(value_type const& val)
		{
			node_pointer node = find(val.first);

			// Don't do nothing if val not found
			if (!node)
				return;

			erase_helper(node);
		}

		node_pointer
		find(value_type const& val) const
		{
			node_pointer position = find_helper(val, _root);
		}
		node_pointer
		find_helper(key_type const& key, node_pointer const& node) const
		{
			// Base case of recursion
			if (node == &_nil)
				return NULL;
			else if (node->data.first == key)
				return node;

			if (_comp(key, node->data.first))
				return find_helper(key, node->left);
			else
				return find_helper(key, node->right);
		}


	};
}

#endif
