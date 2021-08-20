/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_is_const.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 10:40:09 by dda-silv          #+#    #+#             */
/*   Updated: 2021/08/20 10:51:14 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_is_const.hpp"

void test_is_const(void) {
	std::cout << ft::is_const<int>::value << std::endl
		<< ft::is_const<int const>::value << std::endl
		<< ft::is_const<char>::value << std::endl
		<< ft::is_const<char const>::value << std::endl;
}
