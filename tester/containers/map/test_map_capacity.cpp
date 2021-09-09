/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map_capacity.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 14:59:11 by dda-silv          #+#    #+#             */
/*   Updated: 2021/09/09 09:30:35 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_map_capacity.hpp"

void
test_map_capacity()
{
	ft::map<int, int> map;

	std::cout << "Empty: " << map.empty() << std::endl;
	std::cout << "Size: " << map.size() << std::endl;
	std::cout << "Max size: " << map.max_size() << std::endl;

	srand(g_seed);

	for (int i = 0; i < 42; i++)
		map.insert(ft::make_pair(rand() % 100 - 50, rand() % 100 - 50));

	std::cout << "Empty: " << map.empty() << std::endl;
	std::cout << "Size: " << map.size() << std::endl;
	std::cout << "Max size: " << map.max_size() << std::endl;
}
