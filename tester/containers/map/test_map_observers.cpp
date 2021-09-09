/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map_observers.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 16:23:58 by dda-silv          #+#    #+#             */
/*   Updated: 2021/09/09 10:26:24 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_map_observers.hpp"

void
test_map_observers_key_comp()
{
	ft::map<char, int> mymap;

	ft::map<char, int>::key_compare mycomp = mymap.key_comp();

	mymap['a'] = 100;
	mymap['b'] = 200;
	mymap['c'] = 300;

	std::cout << "mymap contains:";

	char highest = mymap.rbegin()->first;

	ft::map<char, int>::iterator it = mymap.begin();
	do
	{
		std::cout << " [" << it->first << "] = " << it->second;
	} while (mycomp((*it++).first, highest));
	std::cout << std::endl;
}

void
test_map_observers_value_comp()
{
	ft::map<char, int> mymap;

	mymap['x'] = 1001;
	mymap['y'] = 2002;
	mymap['z'] = 3003;

	std::cout << "mymap contains:\n";

	ft::pair<char, int> highest = *mymap.rbegin();          // last element

	ft::map<char, int>::iterator it = mymap.begin();
	do {
		std::cout << " [" << it->first << "] = " << it->second;
	} while ( mymap.value_comp()(*it++, highest) );
	std::cout << std::endl;
}

void
test_map_observers()
{
	test_wrapper(test_map_observers_key_comp, "observers_key_comp");
	test_wrapper(test_map_observers_value_comp, "observers_value_comp");
}
