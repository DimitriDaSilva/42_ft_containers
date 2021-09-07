/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_set_modifiers.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 19:21:16 by dda-silv          #+#    #+#             */
/*   Updated: 2021/09/07 20:31:02 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_set_modifiers.hpp"

void
test_set_modifiers_insert_single_element_int()
{
	ft::set<int> set;
	ft::pair<ft::set<int>::iterator, bool> ret;

	print_set_info(set);

	ret = set.insert(42);
	std::cout << "Return: " << *ret.first << " " << ret.second << std::endl;

	ret = set.insert(42);
	std::cout << "Return: " << *ret.first << " " << ret.second << std::endl;

	ret = set.insert(60);
	std::cout << "Return: " << *ret.first << " " << ret.second << std::endl;

	ret = set.insert(-42);
	std::cout << "Return: " << *ret.first << " " << ret.second << std::endl;

	print_set_info(set);
}

void
test_set_modifiers_insert_single_element_string()
{
	ft::set<std::string> set;
	ft::pair<ft::set<std::string>::iterator, bool> ret;

	print_set_info(set);

	ret = set.insert("hello");
	std::cout << "Return: " << *ret.first << " " << ret.second << std::endl;

	ret = set.insert("hello");
	std::cout << "Return: " << *ret.first << " " << ret.second << std::endl;

	ret = set.insert("world");
	std::cout << "Return: " << *ret.first << " " << ret.second << std::endl;

	ret = set.insert("dimitri");
	std::cout << "Return: " << *ret.first << " " << ret.second << std::endl;

	print_set_info(set);
}

void
test_set_modifiers_insert_with_hint()
{
	ft::set<int> set;
	ft::set<int>::iterator hint;
	ft::set<int>::iterator ret;

	set.insert(10);
	set.insert(100);
	set.insert(60);

	hint = set.find(10);
	ret = set.insert(hint, 42);
	std::cout << "Return: " << *ret << std::endl;
	print_set_info(set);

	ret = set.insert(set.begin(), 0);
	std::cout << "Return: " << *ret << std::endl;
	print_set_info(set);
}

void
test_set_modifiers_insert_range()
{
	ft::set<int> set1;
	ft::set<int> set2;

	set2.insert(set1.begin(), set1.end());

	print_set_info(set1);
	print_set_info(set2);

	srand(g_seed);

	for (int i = 0; i < 100; i++)
		set1.insert(rand() % 1000 - 1000 / 2);
	set2.insert(set1.begin(), set1.end());

	print_set_info(set1);
	print_set_info(set2);
}

void
test_set_modifiers_erase_position()
{
	ft::set<int> set;

	for (int i = 0; i < 10; i++)
		set.insert(i);

	print_set_info(set);

	set.erase(set.find(4));
	set.erase(set.find(2));

	print_set_info(set);

	while (!set.empty())
		set.erase(set.begin());

	print_set_info(set);
}

void
test_set_modifiers_erase_value()
{
	ft::set<int> set;

	for (int i = 0; i < 10; i++)
		set.insert(i);

	print_set_info(set);

	std::cout << set.erase(4) << std::endl;
	std::cout << set.erase(4) << std::endl;
	std::cout << set.erase(2) << std::endl;

	print_set_info(set);
}

void
test_set_modifiers_erase_range()
{
	ft::set<int> set;
	ft::set<int>::iterator it;

	for (int i = 0; i < 10; i++)
		set.insert(i);

	it = set.find(9);

	std::cout << *it << " at address: " << it._M_node << std::endl;

	for (int i = 0; i < 9; i++)
		set.erase(i);
	
	std::cout << *it << " at address: " << it._M_node << std::endl;

	//print_set_info(set);

	//set.print_tree();

	//set.erase(set.find(4), set.end());

	//set.print_tree();

	//print_set_info(set);
}

void
test_set_modifiers()
{
	test_wrapper(test_set_modifiers_insert_single_element_int, "insert_single_element_int");
	test_wrapper(test_set_modifiers_insert_single_element_string, "insert_single_element_string");
	test_wrapper(test_set_modifiers_insert_with_hint, "insert_with_hint");
	test_wrapper(test_set_modifiers_insert_range, "insert_range");
	test_wrapper(test_set_modifiers_erase_position, "erase_position");
	test_wrapper(test_set_modifiers_erase_value, "erase_value");
	test_wrapper(test_set_modifiers_erase_range, "erase_range");
}
