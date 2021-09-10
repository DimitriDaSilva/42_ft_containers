/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_set_modifiers.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 19:21:16 by dda-silv          #+#    #+#             */
/*   Updated: 2021/09/10 10:43:25 by dda-silv         ###   ########.fr       */
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

	print_set_info(set); }

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
test_set_modifiers_insert_iterators_validity()
{
	ft::set<int> set;
	ft::set<int>::iterator it;

	set.insert(42);
	it = set.find(42);

	for (int i = 0; i < 20; i++)
		set.insert(i);

	print_set_info(set);

	if (it == set.find(42))
		std::cout << "correct" << std::endl;
}

void
test_set_modifiers_insert_cplusplus()
{
	ft::set<int> myset;
	ft::set<int>::iterator it;
	ft::pair<ft::set<int>::iterator, bool> ret;

	for (int i = 1; i <= 5; ++i)
		myset.insert(i * 10);

	ret = myset.insert(20);

	if (ret.second == false)
		it = ret.first;

	myset.insert(it,25);
	myset.insert(it,24);
	myset.insert(it,26);

	int myints[] = {5, 10, 15};
	myset.insert(myints, myints + 3);

	std::cout << "myset contains:";
	for (it = myset.begin(); it != myset.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
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

	print_set_info(set);

	set.erase(set.find(4), set.end());

	print_set_info(set);
}

void
test_set_modifiers_erase_iterators_validity()
{
	ft::set<int> set;
	ft::set<int>::iterator it;

	for (int i = 0; i < 10; i++)
		set.insert(i);

	print_set_info(set);

	it = set.find(9);

	for (int i = 0; i < 9; i++)
		set.erase(i);

	if (it == set.find(9))
		std::cout << "correct" << std::endl;

	print_set_info(set);
}

void
test_set_modifiers_erase_cplusplus()
{
	ft::set<int>			myset;
	ft::set<int>::iterator	it;

	for (int i = 1; i < 10; i++)
		myset.insert(i * 10);

	print_set_info(myset);

	it = myset.begin();
	++it;

	myset.erase(it);

	print_set_info(myset);

	myset.erase(40);

	print_set_info(myset);

	it = myset.find(60);
	myset.erase(it, myset.end());

	print_set_info(myset);
}

void
test_set_modifiers_swap()
{
	int myints[] = {12, 75, 10, 32, 20, 25};
	ft::set<int> first(myints, myints + 3);
	ft::set<int> second(myints + 3, myints+ 6);

	print_set_info(first);
	print_set_info(second);

	first.swap(second);

	print_set_info(first);
	print_set_info(second);
}

void
test_set_modifiers_clear_int()
{
	ft::set<int> myset;

	myset.insert(100);
	myset.insert(200);
	myset.insert(300);

	print_set_info(myset);

	myset.clear();

	print_set_info(myset);

	myset.insert(1101);
	myset.insert(2202);

	print_set_info(myset);
}

void
test_set_modifiers_clear_string()
{
	ft::set<std::string> myset;

	myset.insert("hello");
	myset.insert("world");
	myset.insert("!");

	print_set_info(myset);

	myset.clear();

	print_set_info(myset);

	myset.insert("this is");
	myset.insert("a test");

	print_set_info(myset);
}

void
test_set_modifiers()
{
	test_wrapper(test_set_modifiers_insert_single_element_int, "insert_single_element_int");
	test_wrapper(test_set_modifiers_insert_single_element_string, "insert_single_element_string");
	test_wrapper(test_set_modifiers_insert_with_hint, "insert_with_hint");
	test_wrapper(test_set_modifiers_insert_range, "insert_range");
	test_wrapper(test_set_modifiers_insert_iterators_validity, "insert_iterators_validity");
	test_wrapper(test_set_modifiers_insert_cplusplus, "insert_cplusplus");
	test_wrapper(test_set_modifiers_erase_position, "erase_position");
	test_wrapper(test_set_modifiers_erase_value, "erase_value");
	test_wrapper(test_set_modifiers_erase_range, "erase_range");
	test_wrapper(test_set_modifiers_erase_iterators_validity, "erase_iterators_validity");
	test_wrapper(test_set_modifiers_erase_cplusplus, "erase_cplusplus");
	test_wrapper(test_set_modifiers_swap, "swap");
	test_wrapper(test_set_modifiers_clear_int, "clear_int");
	test_wrapper(test_set_modifiers_clear_string, "clear_string");
}
