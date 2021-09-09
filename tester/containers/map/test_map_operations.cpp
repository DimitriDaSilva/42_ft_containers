/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map_operations.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 16:28:40 by dda-silv          #+#    #+#             */
/*   Updated: 2021/09/09 10:46:45 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_map_operations.hpp"

void
test_map_operations_find()
{
	ft::map<char, int> map;
	ft::map<char, int>::iterator it;

	for (char i = '0'; i <= '9'; i++)
		map.insert(ft::make_pair(i, i));

	print_map_info(map);

	if ((it = map.find('4')) != map.end())
		map.erase(it);

	if ((it = map.find('4')) != map.end())
		map.erase(it);

	if ((it = map.find('2')) != map.end())
		map.erase(it);

	print_map_info(map);
}

void
test_map_operations_count()
{
	ft::map<int, int> map;

	for (int i = 0; i < 20; i++)
	{
		if (i % 2 == 0)
			map.insert(ft::make_pair(i, i));
	}

	for (int i = 0; i < 20; i++)
		std::cout << (map.count(i) == 1 ? " In " : " Not in ");
	std::cout << std::endl;
}

void
test_map_operations_lower_bound()
{
	ft::map<char, int> map;
	ft::map<char, int>::iterator it;
	ft::map<char, int>::const_iterator const_it;

	for (char i = '0'; i <= '9'; i++)
		map.insert(ft::make_pair(i, i));

	it = map.lower_bound('0');
	if (it != map.end())
		std::cout << " [" << it->first << "] = " << it->second << std::endl;
	else
		std::cout << "end()" << std::endl;

	it = map.lower_bound('!');
	if (it != map.end())
		std::cout << " [" << it->first << "] = " << it->second << std::endl;
	else
		std::cout << "end()" << std::endl;

	const_it = map.lower_bound('?');
	if (const_it != map.end())
		std::cout << " [" << const_it->first << "] = " << const_it->second << std::endl;
	else
		std::cout << "end()" << std::endl;

	const_it = map.lower_bound('-');
	if (const_it != map.end())
		std::cout << " [" << const_it->first << "] = " << const_it->second << std::endl;
	else
		std::cout << "end()" << std::endl;
}

void
test_map_operations_upper_bound()
{
	ft::map<char, int> map;
	ft::map<char, int>::iterator it;
	ft::map<char, int>::const_iterator const_it;

	for (char i = '0'; i <= '9'; i++)
		map.insert(ft::make_pair(i, i));

	it = map.upper_bound('0');
	if (it != map.end())
		std::cout << " [" << it->first << "] = " << it->second << std::endl;
	else
		std::cout << "end()" << std::endl;

	it = map.upper_bound('!');
	if (it != map.end())
		std::cout << " [" << it->first << "] = " << it->second << std::endl;
	else
		std::cout << "end()" << std::endl;

	const_it = map.upper_bound('?');
	if (const_it != map.end())
		std::cout << " [" << const_it->first << "] = " << const_it->second << std::endl;
	else
		std::cout << "end()" << std::endl;

	const_it = map.upper_bound('-');
	if (const_it != map.end())
		std::cout << " [" << const_it->first << "] = " << const_it->second << std::endl;
	else
		std::cout << "end()" << std::endl;
}

void
test_map_operations_lower_upper_bound()
{
	ft::map<char, int> mymap;
	ft::map<char, int>::iterator itlow, itup;

	mymap['a'] = 20;
	mymap['b'] = 40;
	mymap['c'] = 60;
	mymap['d'] = 80;
	mymap['e'] = 100;

	itlow = mymap.lower_bound('b');
	itup = mymap.upper_bound('d');

	print_map_info(mymap);

	mymap.erase(itlow, itup);

	print_map_info(mymap);
}

void
test_map_operations_equal_range_match()
{
	ft::map<char, int> mymap;

	mymap['a'] = 10;
	mymap['b'] = 20;
	mymap['d'] = 30;

	ft::pair<ft::map<char, int>::iterator, ft::map<char, int>::iterator> ret;
	ret = mymap.equal_range('b');

	std::cout << "lower bound points to: ";
	std::cout << " [" << ret.first->first << "] = " << ret.first->second << std::endl;

	std::cout << "upper bound points to: ";
	std::cout << " [" << ret.second->first << "] = " << ret.second->second << std::endl;
}

void
test_map_operations_equal_range_no_match()
{
	ft::map<char, int> mymap;

	mymap['a'] = 10;
	mymap['b'] = 20;
	mymap['d'] = 30;

	ft::pair<ft::map<char, int>::iterator, ft::map<char, int>::iterator> ret;
	ret = mymap.equal_range('c');
	std::cout << "lower bound points to: ";
	std::cout << " [" << ret.first->first << "] = " << ret.first->second << std::endl;
	std::cout << "upper bound points to: ";
	std::cout << " [" << ret.second->first << "] = " << ret.second->second << std::endl;

	ret = mymap.equal_range('@');
	std::cout << "lower bound points to: ";
	std::cout << " [" << ret.first->first << "] = " << ret.first->second << std::endl;
	std::cout << "upper bound points to: ";
	std::cout << " [" << ret.second->first << "] = " << ret.second->second << std::endl;
}

void
test_map_operations()
{
	test_wrapper(test_map_operations_find, "find");
	test_wrapper(test_map_operations_count, "count");
	test_wrapper(test_map_operations_lower_bound, "lower_bound");
	test_wrapper(test_map_operations_upper_bound, "upper_bound");
	test_wrapper(test_map_operations_lower_upper_bound, "lower_upper_bound");
	test_wrapper(test_map_operations_equal_range_match, "equal_range_match");
	test_wrapper(test_map_operations_equal_range_no_match, "equal_range_no_match");
}
