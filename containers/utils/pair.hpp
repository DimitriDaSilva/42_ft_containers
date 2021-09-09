/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 10:39:25 by dda-silv          #+#    #+#             */
/*   Updated: 2021/09/09 13:12:25 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

# include "remove_const.hpp"

namespace ft
{
	template<class T1, class T2>
	struct pair
	{
/******************************************************************************/
/*                   	        MEMBER TYPES					              */
/******************************************************************************/

		typedef typename ft::remove_const<T1>::type	first_type;
		//typedef T1	first_type;
		typedef T2	second_type;

/******************************************************************************/
/*                   	         CONSTRUCTORS                                 */
/******************************************************************************/

		// Default
		pair() : first(first_type()), second(second_type()) {}

		// Copy
		template<class U, class V>
		pair(pair<U, V> const& pr) : first(pr.first), second(pr.second) {}

		// Initialization
		pair(first_type const& a, second_type const& b) : first(a), second(b) {}

/******************************************************************************/
/*                   	   OVERLOADING OPERATORS                              */
/******************************************************************************/

/*                                Assignement                                 */

		pair& operator=(pair const& pr) {
			first = pr.first;
			second = pr.second;

			return *this;
		};

/******************************************************************************/
/*                   	           DATA                                       */
/******************************************************************************/

		first_type first;
		second_type second;

	};

/******************************************************************************/
/*                        NON-MEMBER FUNCTION OVERLOADS                       */
/******************************************************************************/

	template<class T1, class T2>
	bool
	operator==(pair<T1, T2> const& lhs, pair<T1, T2> const& rhs)
	{
		return lhs.first == rhs.first && lhs.second == rhs.second;
	}

	template<class T1, class T2>
	bool
	operator!=(pair<T1, T2> const& lhs, pair<T1, T2> const& rhs)
	{
		return !(lhs == rhs);
	}

	template<class T1, class T2>
	bool
	operator<(pair<T1, T2> const& lhs, pair<T1, T2> const& rhs)
	{
		return lhs.first < rhs.first
				|| (!(rhs.first < lhs.first) && lhs.second < rhs.second);
	}

	template<class T1, class T2>
	bool
	operator<=(pair<T1, T2> const& lhs, pair<T1, T2> const& rhs)
	{
		return !(rhs < lhs);
	}

	template<class T1, class T2>
	bool
	operator>(pair<T1, T2> const& lhs, pair<T1, T2> const& rhs)
	{
		return rhs < lhs;
	}

	template<class T1, class T2>
	bool
	operator>=(pair<T1, T2> const& lhs, pair<T1, T2> const& rhs)
	{
		return !(lhs < rhs);
	}

	template<class T1, class T2>
	ft::pair<T1, T2>
	make_pair(T1 x, T2 y)
	{
		return ft::pair<T1, T2>(x, y);
	}
}

#endif
