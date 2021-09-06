/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 17:07:06 by dda-silv          #+#    #+#             */
/*   Updated: 2021/09/06 17:19:11 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTIONAL_ITERATOR_HPP
# define BIDIRECTIONAL_ITERATOR_HPP

# include <iterator>	// std::bidirectional_iterator_tag
# include <cstddef>		// std::ptrdiff_t

namespace ft
{
	template<class Node_type, class Value_type>
	class bidirectional_iterator
	{
	public:
/******************************************************************************/
/*                   	        MEMBER TYPES					              */
/******************************************************************************/

		typedef Node_type						node_type;
		typedef node_type*						node_pointer;
		typedef Value_type						value_type;
		typedef value_type&						reference;
		typedef value_type const&				const_reference;
		typedef value_type*						pointer;
		typedef value_type const*				const_pointer;
		typedef std::bidirectional_iterator_tag	iterator_category;
		typedef typename std::ptrdiff_t			difference_type;

/******************************************************************************/
/*                   	 CONSTRUCTORS & DESTRUCTORS                           */
/******************************************************************************/

/*                                Constructors                                */

		// Default
		bidirectional_iterator() : _ptr(NULL), _root(NULL), _nil(NULL) {}

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

			return *this;
		}

		// Overload called when trying to copy construct a const_iterator
		// based on an iterator
		operator bidirectional_iterator<node_type const, value_type const>() const
		{
			return bidirectional_iterator<node_type const, value_type const>(_ptr);
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
			_ptr = successor(_ptr);

			return *this;
		}

		// Post-increment
		bidirectional_iterator
		operator++(int)
		{
			bidirectional_iterator tmp(*this);

			_ptr = successor(_ptr);

			return tmp;
		}

		// Pre-decrement
		bidirectional_iterator&
		operator--()
		{
			_ptr = predecessor(_ptr);

			return *this;
		}

		// Post-decrement
		bidirectional_iterator
		operator--(int)
		{
			bidirectional_iterator tmp(*this);

			_ptr = predecessor(_ptr);

			return tmp;
		}

/*                                 Access                                     */

		reference
		operator*()
		{
			return _ptr->data;
		}

		node_pointer
		operator->() const
		{
			return _ptr;
		}

	private:
/******************************************************************************/
/*                   	 HELPERS FOR PUBLIC FUNCTIONS                         */
/******************************************************************************/

		node_pointer
		maximum(node_pointer node)
		{
			while (node->right->right != NULL)
				node = node->right;

			return node;
		}

		node_pointer
		minimum(node_pointer node)
		{
			while (node->left->left != NULL)
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
			if (node->left->left != NULL)
				return maximum(node->left);

			// If not, we need to go look for it in it's parent left side
			// The predecessor will be the first node that has its
			// left child that isn't also an ancestor of the base node
			predecessor = node->parent;
			while (node->parent != NULL && node == predecessor->left)
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
			if (node->right->right != NULL)
				return minimum(node->right);

			// If not, we need to go look for it in it's parent right side
			// The successor will be the first node that has its
			// right child that isn't also an ancestor of the base node
			successor = node->parent;
			while (node->parent != NULL && node == successor->right)
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

/******************************************************************************/
/*                   	        PRIVATE DATA                                  */
/******************************************************************************/

		node_pointer _ptr;
		node_pointer _root;
		node_pointer _nil;
	};
}

#endif
