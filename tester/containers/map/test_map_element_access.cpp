/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map_element_access.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 08:49:12 by dda-silv          #+#    #+#             */
/*   Updated: 2021/09/09 15:08:39 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_map_element_access.hpp"

void
test_map_element_access_operator_brackets()
{
	ft::map<char, std::string> mymap;

	mymap['a'] = "an element";
	mymap['b'] = "another element";
	mymap['c'] = mymap['b'];

	std::cout << "mymap['a'] is " << mymap['a'] << std::endl;
	std::cout << "mymap['b'] is " << mymap['b'] << std::endl;
	std::cout << "mymap['c'] is " << mymap['c'] << std::endl;
	std::cout << "mymap['d'] is " << mymap['d'] << std::endl;

	std::cout << "mymap now contains " << mymap.size() << " elements." << std::endl;
}

void
test_map_element_access_at()
{
	ft::map<std::string, int> mymap;
	mymap.insert(ft::make_pair("alpha", 0));
	mymap.insert(ft::make_pair("beta", 0));
	mymap.insert(ft::make_pair("gamma", 0));

	mymap.at("alpha") = 10;
	mymap.at("beta") = 20;
	mymap.at("gamma") = 30;

	print_map_info(mymap);

	mymap.at("delta") = 30;
}

void
test_map_element_access()
{
	test_wrapper(test_map_element_access_operator_brackets, "operator[]");
	test_wrapper(test_map_element_access_at, "at");
}
