/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 11:13:07 by dda-silv          #+#    #+#             */
/*   Updated: 2021/09/07 10:49:34 by dda-silv         ###   ########.fr       */
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

		// In set, we often need to have pointers to the nodes, not just
		// the pair<> value_type
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
			this->tree_type::operator=(rhs);
		}

/******************************************************************************/
/*                   	    OTHER MEMBER FUNCTIONS                            */
/******************************************************************************/

/*                                  Modifiers                                 */

		// Erase by key
		void
		erase(value_type const& key)
		{
			node_pointer node = find(key);

			// Don't do nothing if val not found
			if (!node)
				return;

			erase_helper(node);
		}

		iterator
		find(value_type const& val)
		{
			node_pointer position = find_helper(val, this->_root);
			if (!position)
				return this->end();
			else
				return iterator(position, this->_root, &(this->_nil));
		}

		const_iterator
		find(value_type const& val) const
		{
			node_pointer position = find_helper(val, this->_root);
			if (!position)
				return this->end();
			else
				return const_iterator(position, this->_root, &(this->_nil));
		}

	private:
/******************************************************************************/
/*                   	 HELPERS FOR PUBLIC FUNCTIONS                         */
/******************************************************************************/
		node_pointer
		find_helper(value_type const& val, node_pointer const& node) const
		{
			// Base case of recursion
			if (node == &(this->_nil))
				return NULL;
			else if (node->data == val)
				return node;

			if (this->_comp(val, node->data))
				return find_helper(val, node->left);
			else
				return find_helper(val, node->right);
		}

/******************************************************************************/
/*                   	        PRIVATE DATA                                  */
/******************************************************************************/

		allocator_type	_value_alloc;
	};
}

#endif
