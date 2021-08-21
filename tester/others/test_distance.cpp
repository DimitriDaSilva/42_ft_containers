/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_distance.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 10:51:48 by dda-silv          #+#    #+#             */
/*   Updated: 2021/08/21 22:36:08 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_distance.hpp"

void
test_distance()
{
	ft::vector<int> vec(5, 42);

	std::cout << vec.end() - vec.begin() << std::endl;
	std::cout <<
		ft::distance<ft::vector<int>::iterator>(vec.begin(), vec.end())
		<< std::endl;
}
