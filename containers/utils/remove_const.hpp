/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_const.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 10:50:43 by dda-silv          #+#    #+#             */
/*   Updated: 2021/09/04 10:58:28 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REMOVE_CONST_HPP
# define REMOVE_CONST_HPP

namespace ft
{
	template<class T> struct remove_const          {typedef T type;};
	template<class T> struct remove_const<T const> {typedef T type;};
}

#endif
