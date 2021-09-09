/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map_modifiers.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 19:21:16 by dda-silv          #+#    #+#             */
/*   Updated: 2021/09/09 10:20:16 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_map_modifiers.hpp"

void
test_map_modifiers_insert_single_element_int()
{
	ft::map<int, int> map;
	ft::pair<ft::map<int, int>::iterator, bool> ret;

	print_map_info(map);

	ret = map.insert(ft::make_pair(42, 42));
	std::cout << "Return: "
		<< "[" << ret.first->first << "] = " << ret.first->second
		<< " " << ret.second << std::endl;

	ret = map.insert(ft::make_pair(42, 42));
	std::cout << "Return: "
		<< "[" << ret.first->first << "] = " << ret.first->second
		<< " " << ret.second << std::endl;

	ret = map.insert(ft::make_pair(60, 42));
	std::cout << "Return: "
		<< "[" << ret.first->first << "] = " << ret.first->second
		<< " " << ret.second << std::endl;

	ret = map.insert(ft::make_pair(-42, 0));
	std::cout << "Return: "
		<< "[" << ret.first->first << "] = " << ret.first->second
		<< " " << ret.second << std::endl;

	print_map_info(map);
}

void
test_map_modifiers_insert_single_element_string()
{
	ft::map<int, std::string> map;
	ft::pair<ft::map<int, std::string>::iterator, bool> ret;

	print_map_info(map);

	ret = map.insert(ft::make_pair(42, "hello world"));
	std::cout << "Return: "
		<< "[" << ret.first->first << "] = " << ret.first->second
		<< " " << ret.second << std::endl;

	ret = map.insert(ft::make_pair(42, "hello world"));
	std::cout << "Return: "
		<< "[" << ret.first->first << "] = " << ret.first->second
		<< " " << ret.second << std::endl;

	ret = map.insert(ft::make_pair(60, "hello world"));
	std::cout << "Return: "
		<< "[" << ret.first->first << "] = " << ret.first->second
		<< " " << ret.second << std::endl;

	ret = map.insert(ft::make_pair(-42, "test"));
	std::cout << "Return: "
		<< "[" << ret.first->first << "] = " << ret.first->second
		<< " " << ret.second << std::endl;

	print_map_info(map);
}

void
test_map_modifiers_insert_with_hint()
{
	ft::map<int, int> map;
	ft::map<int, int>::iterator hint;
	ft::map<int, int>::iterator ret;

	map.insert(ft::make_pair(10, 42));
	map.insert(ft::make_pair(100, 42));
	map.insert(ft::make_pair(60, 42));

	hint = map.find(10);
	ret = map.insert(hint, ft::make_pair(42, -42));
	std::cout << "Return: " << "[" << ret->first << "] = " << ret->second << std::endl;
	print_map_info(map);

	ret = map.insert(map.begin(), ft::make_pair(0, 42));
	std::cout << "Return: " << "[" << ret->first << "] = " << ret->second << std::endl;
	print_map_info(map);
}

void
test_map_modifiers_insert_range()
{
	ft::map<int, int> map1;
	ft::map<int, int> map2;

	map2.insert(map1.begin(), map1.end());

	print_map_info(map1);
	print_map_info(map2);

	srand(g_seed);

	for (int i = 0; i < 100; i++)
		map1.insert(ft::make_pair(i, rand() % 100 - 50));

	map2.insert(map1.begin(), map1.end());

	print_map_info(map1);
	print_map_info(map2);
}

void
test_map_modifiers_insert_iterators_validity()
{
	ft::map<int, int> map;
	ft::map<int, int>::iterator it;

	map.insert(ft::make_pair(42, 0));
	it = map.find(42);

	for (int i = 0; i < 20; i++)
		map.insert(ft::make_pair(i, rand() % 100 - 50));

	print_map_info(map);

	if (it == map.find(42))
		std::cout << "correct" << std::endl;
}

void
test_map_modifiers_insert_cplusplus()
{
	ft::map<char, int> mymap;

	// first insert function version (single parameter):
	mymap.insert(ft::pair<char, int>('a', 100) );
	mymap.insert(ft::pair<char, int>('z', 200) );

	ft::pair<ft::map<char, int>::iterator, bool> ret;

	ret = mymap.insert(ft::pair<char, int>('z', 500));
	if (ret.second == false)
	{
		std::cout << "element 'z' already existed";
		std::cout << " with a value of " << ret.first->second << std::endl;
	}

	// second insert function version (with hint position):
	ft::map<char, int>::iterator it = mymap.begin();
	mymap.insert(it, ft::pair<char, int>('b', 300));  // max efficiency inserting
	mymap.insert(it, ft::pair<char, int>('c', 400));  // no max efficiency inserting

	// third insert function version (range insertion):
	ft::map<char, int> anothermap;
	anothermap.insert(mymap.begin(), mymap.find('c'));

	print_map_info(mymap);
	print_map_info(anothermap);
}

void
test_map_modifiers_erase_position()
{
	ft::map<int, int> map;

	srand(g_seed);

	for (int i = 0; i < 100; i++)
		map.insert(ft::make_pair(i, rand() % 100 - 50));

	print_map_info(map);

	map.erase(map.find(42));
	map.erase(map.find(20));

	print_map_info(map);

	while (!map.empty())
		map.erase(map.begin());

	print_map_info(map);
}

void
test_map_modifiers_erase_value()
{
	ft::map<int, int> map;

	srand(g_seed);

	for (int i = 0; i < 100; i++)
		map.insert(ft::make_pair(i, rand() % 100 - 50));

	print_map_info(map);

	std::cout << map.erase(4) << std::endl;
	std::cout << map.erase(4) << std::endl;
	std::cout << map.erase(2) << std::endl;

	print_map_info(map);
}

void
test_map_modifiers_erase_range()
{
	ft::map<int, int> map;
	ft::map<int, int>::iterator it;

	srand(g_seed);

	for (int i = 0; i < 100; i++)
		map.insert(ft::make_pair(i, rand() % 100 - 50));

	print_map_info(map);

	map.erase(map.find(42), map.end());

	print_map_info(map);
}

void
test_map_modifiers_erase_iterators_validity()
{
	ft::map<int, int> map;
	ft::map<int, int>::iterator it;

	for (int i = 0; i < 10; i++)
		map.insert(ft::make_pair(i, rand() % 100 - 50));

	print_map_info(map);

	it = map.find(9);

	for (int i = 0; i < 9; i++)
		map.erase(i);

	if (it == map.find(9))
		std::cout << "correct" << std::endl;

	print_map_info(map);
}

void
test_map_modifiers_erase_cplusplus()
{
	ft::map<char, int> mymap;
	ft::map<char, int>::iterator it;

	// insert some values:
	mymap['a'] = 10;
	mymap['b'] = 20;
	mymap['c'] = 30;
	mymap['d'] = 40;
	mymap['e'] = 50;
	mymap['f'] = 60;

	it = mymap.find('b');
	mymap.erase (it);                   // erasing by iterator

	mymap.erase ('c');                  // erasing by key

	it = mymap.find ('e');
	mymap.erase(it, mymap.end());    // erasing by range

	// show content:
	for (it = mymap.begin(); it != mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
}

void
test_map_modifiers_swap()
{
	ft::map<char, int> first, second;

	first['x'] = 100;
	first['y'] = 200;

	second['a'] = 11;
	second['b'] = 22;
	second['c'] = 33;

	first.swap(second);

	print_map_info(first);
	print_map_info(second);

	first.swap(second);

	print_map_info(first);
	print_map_info(second);
}

void
test_map_modifiers_clear_int()
{
	ft::map<int, int> mymap;

	mymap[42] = 42;
	mymap[0] = 3;
	mymap[-42] = 100;

	print_map_info(mymap);

	mymap.clear();

	print_map_info(mymap);

	mymap[-42] = 42;
	mymap[-1] = 3;

	print_map_info(mymap);
}

void
test_map_modifiers_clear_string()
{
	ft::map<int, std::string> mymap;

	mymap[42] = "test";
	mymap[0] = "hello";
	mymap[-42] = "world";

	print_map_info(mymap);

	mymap.clear();

	print_map_info(mymap);

	mymap[-42] = "hi";
	mymap[-1] = "there";

	print_map_info(mymap);
}

void
test_map_modifiers()
{
	test_wrapper(test_map_modifiers_insert_single_element_int, "insert_single_element_int");
	test_wrapper(test_map_modifiers_insert_single_element_string, "insert_single_element_string");
	test_wrapper(test_map_modifiers_insert_with_hint, "insert_with_hint");
	test_wrapper(test_map_modifiers_insert_range, "insert_range");
	test_wrapper(test_map_modifiers_insert_iterators_validity, "insert_iterators_validity");
	test_wrapper(test_map_modifiers_insert_cplusplus, "insert_cplusplus");
	test_wrapper(test_map_modifiers_erase_position, "erase_position");
	test_wrapper(test_map_modifiers_erase_value, "erase_value");
	test_wrapper(test_map_modifiers_erase_range, "erase_range");
	test_wrapper(test_map_modifiers_erase_iterators_validity, "erase_iterators_validity");
	test_wrapper(test_map_modifiers_erase_cplusplus, "erase_cplusplus");
	test_wrapper(test_map_modifiers_swap, "swap");
	test_wrapper(test_map_modifiers_clear_int, "clear_int");
	test_wrapper(test_map_modifiers_clear_string, "clear_string");
}
