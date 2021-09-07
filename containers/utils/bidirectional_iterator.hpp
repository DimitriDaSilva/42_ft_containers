/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 17:07:06 by dda-silv          #+#    #+#             */
/*   Updated: 2021/09/07 16:16:27 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTIONAL_ITERATOR_HPP
# define BIDIRECTIONAL_ITERATOR_HPP

# include <iterator>	// std::bidirectional_iterator_tag
# include <cstddef>		// std::ptrdiff_t, NULL

namespace ft
{
	template<class Node_type>
	class bidirectional_iterator
	{
	public:
/******************************************************************************/
/*                   	        MEMBER TYPES					              */
/******************************************************************************/

		// To comply with iterator_traits<> standards, value_type represents
		// the type of the node and data_type represents the data in the node
		typedef Node_type								value_type;
		typedef value_type*								node_pointer;

		typedef typename Node_type::value_type const	data_type;
		typedef data_type&								reference;
		typedef data_type const&						const_reference;
		typedef data_type*								pointer;
		typedef data_type const*						const_pointer;

		typedef typename std::ptrdiff_t					difference_type;
		typedef std::bidirectional_iterator_tag			iterator_category;

/******************************************************************************/
/*                   	        PUBLIC DATA                                   */
/******************************************************************************/

		// Weird, right? Well in the STL implementation of iterators is a struct
		// so the underlying pointer to the node is freely accessible with
		// the name _M_node
		// So if it works for them, it works for me :)
		node_pointer _ptr;
		node_pointer _root;
		node_pointer _nil;

/******************************************************************************/
/*                   	 CONSTRUCTORS & DESTRUCTORS                           */
/******************************************************************************/

/*                                Constructors                                */

		// Default
		bidirectional_iterator() :
			_ptr(NULL), _root(NULL), _nil(NULL) {}

		// Type specific
		bidirectional_iterator(node_pointer ptr,
				node_pointer root,
				node_pointer nil) :
			_ptr(ptr), _root(root), _nil(nil) {}

		// Copy
		bidirectional_iterator(bidirectional_iterator const& rhs) :
			_ptr(rhs._ptr), _root(rhs._root), _nil(rhs._nil) {}

/*                                Destructors                                 */

		// Default
		virtual
		~bidirectional_iterator() {}

/******************************************************************************/
/*                   	   OVERLOADING OPERATORS                              */
/******************************************************************************/

/*                                Assignement                                 */

		bidirectional_iterator&
		operator=(bidirectional_iterator const& rhs)
		{
			// Self-assignement check
			if (this == &rhs)
				return *this;

			_ptr = rhs._ptr;
			_root = rhs._root;
			_nil = rhs._nil;

			return *this;
		}

		// Overload called when trying to copy construct a const_iterator
		// based on an iterator
		operator bidirectional_iterator<value_type const>() const
		{
			return bidirectional_iterator<value_type const>(_ptr, _root, _nil);
		}

/*                            Relational operators                            */

		bool
		operator==(bidirectional_iterator const& rhs) const
		{
			return _ptr == rhs._ptr;
		}

		bool
		operator!=(bidirectional_iterator const& rhs) const
		{
			return _ptr != rhs._ptr;
		}

/*                        Increment / decrement                               */

		// Pre-increment
		bidirectional_iterator&
		operator++()
		{
			if (_ptr == maximum(_root))
				_ptr = _nil;
			else if (_ptr != _nil)
				_ptr = successor(_ptr);

			return *this;
		}

		// Post-increment
		bidirectional_iterator
		operator++(int)
		{
			bidirectional_iterator tmp(*this);

			operator++();

			return tmp;
		}

		// Pre-decrement
		bidirectional_iterator&
		operator--()
		{
			if (_ptr == minimum(_root))
				_ptr = _nil;
			else if (_ptr == _nil)
				_ptr = maximum(_root);
			else
				_ptr = predecessor(_ptr);

			return *this;
		}

		// Post-decrement
		bidirectional_iterator
		operator--(int)
		{
			bidirectional_iterator tmp(*this);

			operator--();

			return tmp;
		}

/*                                 Access                                     */

		reference
		operator*() const
		{
			return _ptr->data;
		}

		pointer
		operator->() const
		{
			return &(operator*());
		}

	private:
/******************************************************************************/
/*                   	 HELPERS FOR PUBLIC FUNCTIONS                         */
/******************************************************************************/

		node_pointer
		maximum(node_pointer node)
		{
			while (node->right != _nil)
				node = node->right;

			return node;
		}

		node_pointer
		minimum(node_pointer node)
		{
			while (node->left != _nil)
				node = node->left;

			return node;
		}

		// Get previous node in order
		node_pointer
		predecessor(node_pointer node)
		{
			node_pointer predecessor;

			// If node has a left child, it's predecessor is the maximum
			// of its left subtree
			if (node->left != _nil)
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
			if (!predecessor)
				return _nil;
			else
				return predecessor;
		}

		// Get next node in order
		node_pointer
		successor(node_pointer node)
		{
			node_pointer successor;

			// If node has a right child, it's successor is the minimum
			// of its right subtree
			if (node->right != _nil)
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
			if (!successor)
				return _nil;
			else
				return successor;
		}

	};
}

#endif
