/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 11:14:19 by dda-silv          #+#    #+#             */
/*   Updated: 2021/08/30 12:01:32 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

# include <stdlib.h>	// NULL
# include <functional>	// std::less
# include <memory>		// std::allocator
# include <utility>		// std::pair

# include "pair.hpp"
# include "less.hpp"

namespace ft
{

	template<class T>
	class rbt_node
	{
	public:
/******************************************************************************/
/*                   	        MEMBER TYPES					              */
/******************************************************************************/

		typedef T value_type;
		typedef rbt_node<T>* pointer;
		enum color { red, black };

/******************************************************************************/
/*                   	 CONSTRUCTORS & DESTRUCTORS                           */
/******************************************************************************/

/*                                Constructors                                */

		rbt_node(value_type const& val = value_type()) :
			_data(val),
			_left(NULL),
			_right(NULL),
			_color(red) {}

	private:
		value_type	_data;
		pointer		_left;
		pointer		_right;
		color		_color;
	};

	template<class T,
		class Compare = ft::less<T>,
		class Alloc = std::allocator<ft::pair<T const, T> >
		>
	class rbt
	{
	public:

	};
}

#endif
