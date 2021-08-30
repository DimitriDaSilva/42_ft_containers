/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 11:14:19 by dda-silv          #+#    #+#             */
/*   Updated: 2021/08/30 18:51:01 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

# include <stddef.h>	// NULL
# include <memory>		// std::allocator

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
		class Alloc = std::allocator<T>	>
	class rbt
	{
	public:
/******************************************************************************/
/*                   	        MEMBER TYPES					              */
/******************************************************************************/

		typedef T value_type;
		typedef Compare value_compare;
		typedef Alloc allocator_type;
		typedef rbt_node<value_type>* node_pointer;
		//typedef typename A::reference reference;
		//typedef typename A::const_reference const_reference;
		//typedef typename A::pointer pointer;
		//typedef typename A::const_pointer const_pointer;
		//typedef typename A::difference_type difference_type;
		//typedef typename A::size_type size_type;


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
			_nil = _alloc.allocate(1);
			_nil->data = value_type();
			_nil->parent = NULL;
			_nil->left = _nil;
			_nil->right = _nil;
			_nil->color = black;
			_root = _nil;
		}

		void
		insert(value_type const& val)
		{
			// Allocate new node
			// New node always are red
			node_pointer new_node = _alloc.allocate(1);
			_alloc.construct(new_node, _nil);
			new_node->data = val;
			new_node->color = red;

			node_pointer parent = NULL;
			node_pointer child = _root;

			// Find right position for the new node
			while (child != _nil)
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
				return ;
			}
			else if (_comp(new_node->data, parent->data))
				parent->left = new_node;
			else
				parent->right = new_node;

			// If parent's parent is NULL then we are at level 1 of the tree
			// so we can't be unbalancing the tree
			if (new_node->parent->parent == NULL)
				return;
			// Else the new node could have unbalanced the red-black tree
			// so we need to check after each insert
			else
				check_insert(new_node);
			}

	private:
/******************************************************************************/
/*                   	        PRIVATE DATA                                  */
/******************************************************************************/

		node_pointer	_root;
		node_pointer	_nil;
		value_compare	_comp;
		allocator_type	_alloc;

/******************************************************************************/
/*                   	 HELPERS FOR PUBLIC FUNCTIONS                         */
/******************************************************************************/

		
		node_pointer
		get_uncle(node_pointer node)
		{
			node_pointer grandparent = node->parent->parent;
			node_pointer parent = node>parent;

			if (grandparent->left == parent)
				return grandparent->right;
			else
				return grandparent->left;
		}

		void
		check_insert(node_pointer node)
		{
			node_pointer parent;
			node_pointer uncle;

			if (node->parent->color == black)
				return;
			else
			{
				parent = node->parent;
				uncle = get_uncle(node);
				if (uncle->color == black)
				{
					// Rotate && recolor
					if (parent->right == node)
					{
						// left rotation

					}
					else
					{
						// right rotation
					}
				}
				else
				{
					// Recolor parent and uncle
					parent->color = black;
					uncle->color = black;
					// If parent's parent of new_node is not root node
					// recolor it and recheck
					if (parent->parent != NULL)
					{
						// recolor
						// recheck
					}

				}
			}
		}

		void
		rotate_left(node_pointer node)
		{

		}

		void
		rotate_right(node_pointer node)
		{

		}

	};
}

#endif
