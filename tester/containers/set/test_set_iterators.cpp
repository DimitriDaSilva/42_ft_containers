/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_set_iterators.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 10:54:07 by dda-silv          #+#    #+#             */
/*   Updated: 2021/09/07 11:24:53 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_set_iterators.hpp"

void
test_set_iterators_constructors_base()
{
	ft::set<int> myset;

	for (int i = 0; i < 10; i++)
		myset.insert(i);

	typedef ft::set<int>::iterator iter_type;

	iter_type from(myset.begin());
	iter_type cpy(from);

	if (from == cpy)
		std::cout << "valid" << std::endl;
}

void
test_set_iterators_operator_star()
{
	ft::set<int> myset;

	for (int i = 0; i < 10; i++)
		myset.insert(i);

	typedef ft::set<int>::iterator iter_type;

	iter_type from(myset.begin());

	std::cout << *from << std::endl;
}

void
test_set_iterators_operator_increment()
{
	ft::set<int> myset;

	for (int i  = 0; i < 10; i++)
		myset.insert(i);

	typedef ft::set<int>::iterator iter_type;

	iter_type from(myset.begin());
	iter_type until(myset.end());

	std::cout << "myset:";
	while (from != until)
	{
		std::cout << ' ' << *from;
		++from;
	}

	std::cout << std::endl;
}

void
test_set_iterators_operator_decrement()
{
	ft::set<int> myset;

	for (int i = 0 ; i < 10; i++)
		myset.insert(i);

	typedef ft::set<int>::iterator iter_type;

	iter_type begin (myset.begin());
	iter_type end (myset.end());

	iter_type it(begin);
	while (it != end)
		std::cout << *it++ << ' ';
	std::cout << std::endl;

	while (it != begin)
		std::cout << *(--it) << ' ';
	std::cout << std::endl;

}

void
test_set_iterators_empty_sets()
{
	ft::set<int> set;
	ft::set<int> const const_set;

	if (set.begin() == set.end())
		std::cout << "correct" << std::endl;

	if (const_set.begin() == const_set.end())
		std::cout << "correct" << std::endl;
}

void
test_set_iterators_100_size_set()
{
	typedef ft::set<int>::iterator iterator;

	ft::set<int> set;

	srand(g_seed);

	for (int i = 0; i < 10; i++)
		set.insert(rand() % 100 - 50);

	for (iterator it = set.begin(); it != set.end(); it++)
		std::cout << *it << " ";
}

void
test_set_iterators_100_size_const_set()
{
	typedef ft::set<int>::const_iterator const_iterator;

	ft::set<int> set;

	srand(g_seed);
	for (int i = 0; i < 10; i++)
		set.insert(rand() % 100 - 50);

	ft::set<int> const const_set(set.begin(), set.end());

	for (const_iterator it = const_set.begin(); it != const_set.end(); it++)
		std::cout << *it << " ";
}

void
test_set_iterators_copy()
{
	typedef ft::set<int>::iterator iterator;
	typedef ft::set<int>::const_iterator const_iterator;

	ft::set<int> set;

	srand(g_seed);
	for (int i = 0; i < 10; i++)
		set.insert(rand() % 100 - 50);

	iterator it(set.begin());
	const_iterator const_it(it);

	for (const_iterator it = const_it; it != set.end(); it++)
		std::cout << *it << " ";
}

void
test_set_iterators()
{
	test_wrapper(test_set_iterators_constructors_base, "constructors base");
	test_wrapper(test_set_iterators_operator_star, "operator*()");
	test_wrapper(test_set_iterators_operator_increment, "operator++()");
	test_wrapper(test_set_iterators_operator_decrement, "operator--()");
	test_wrapper(test_set_iterators_empty_sets, "empty sets");
	test_wrapper(test_set_iterators_100_size_set, "100 size set");
	test_wrapper(test_set_iterators_100_size_const_set, "100 size const set");
	test_wrapper(test_set_iterators_copy, "copy");
}
