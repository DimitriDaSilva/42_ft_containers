/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_const.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 11:29:40 by dda-silv          #+#    #+#             */
/*   Updated: 2021/08/14 16:02:02 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_CONST_HPP
# define IS_CONST_HPP

# include "is_integral.hpp"	// ft::false_type, ft::true_type

namespace ft {
	template<class T> struct is_const : ft::false_type {};
	template<class T> struct is_const<const T> : ft::true_type {};
}

#endif
