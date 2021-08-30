/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_less.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 12:02:48 by dda-silv          #+#    #+#             */
/*   Updated: 2021/08/30 12:07:20 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_less.hpp"

void test_less()
{
	int foo[]={10, 20, 5, 15, 25};
	int bar[]={15, 10, 20};
	std::sort(foo, foo + 5, ft::less<int>());  // 5 10 15 20 25
	std::sort(bar, bar + 3, ft::less<int>());  //   10 15 20
	if (std::includes (foo, foo + 5, bar, bar + 3, ft::less<int>()))
		std::cout << "foo includes bar." << std::endl;
}
