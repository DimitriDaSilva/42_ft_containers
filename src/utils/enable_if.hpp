/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 10:33:42 by dda-silv          #+#    #+#             */
/*   Updated: 2021/08/12 10:41:54 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF_HPP
# define ENABLE_IF_HPP

namespace ft {
	template<bool B, class T = void> struct enable_if {};
	template<class T> struct enable_if<true, T> { typedef T type; };
}

#endif
