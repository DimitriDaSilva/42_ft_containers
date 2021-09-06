/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_set_modifiers.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 19:21:16 by dda-silv          #+#    #+#             */
/*   Updated: 2021/09/06 19:21:00 by dda-silv         ###   ########.fr       */
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
test_set_modifiers()
{
	test_wrapper(test_set_modifiers_insert_single_element_int, "insert_single_element_int");
	test_wrapper(test_set_modifiers_insert_single_element_string, "insert_single_element_string");
	test_wrapper(test_set_modifiers_insert_range, "insert_range");
}
