/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_set_capacity.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 14:59:11 by dda-silv          #+#    #+#             */
/*   Updated: 2021/09/07 15:01:25 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_set_capacity.hpp"

void
test_set_capacity()
{
	ft::set<int> set;

	std::cout << "Empty: " << set.empty() << std::endl;
	std::cout << "Size: " << set.size() << std::endl;
	std::cout << "Max size: " << set.max_size() << std::endl;

	for (int i = 0; i < 42; i++)
		set.insert(i);

	std::cout << "Empty: " << set.empty() << std::endl;
	std::cout << "Size: " << set.size() << std::endl;
	std::cout << "Max size: " << set.max_size() << std::endl;
}
