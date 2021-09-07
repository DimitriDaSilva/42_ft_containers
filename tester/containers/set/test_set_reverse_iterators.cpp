/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_set_reverse_iterators.cpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 11:02:35 by dda-silv          #+#    #+#             */
/*   Updated: 2021/09/07 13:30:17 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_set_reverse_iterators.hpp"

void
test_set_reverse_iterators_constructors_base()
{
	ft::set<int> myset;

	for (int i = 0; i < 10; i++)
		myset.insert(i);

	typedef ft::set<int>::iterator iter_type;
	typedef ft::set<int>::reverse_iterator rev_iter_type;

	iter_type from(myset.begin());
	iter_type until(myset.end());

	rev_iter_type rev_until(from);
	rev_iter_type rev_from(until);

	iter_type it_end = rev_until.base();
	iter_type it_begin = rev_from.base();

	if (it_end == from && it_begin == until)
		std::cout << "valid" << std::endl;
}

void
test_set_reverse_iterators_operator_star()
{
	ft::set<int> myset;

	for (int i = 0; i < 10; i++)
		myset.insert(i);

	typedef ft::set<int>::iterator iter_type;
	typedef ft::set<int>::reverse_iterator rev_iter_type;

	iter_type until(myset.end());

	rev_iter_type rev_from(until);

	std::cout << *rev_from << std::endl;
}

void
test_set_reverse_iterators_operator_increment()
{
	ft::set<int> myset;

	for (int i  = 0; i < 10; i++)
		myset.insert(i);

	typedef ft::set<int>::iterator iter_type;

	iter_type from(myset.begin());
	iter_type until(myset.end());

	ft::reverse_iterator<iter_type> rev_until(from);
	ft::reverse_iterator<iter_type> rev_from(until);

	std::cout << "myset:";
	while (rev_from != rev_until)
	{
		std::cout << ' ' << *rev_from;
		++rev_from;
	}

	std::cout << std::endl;
}

void
test_set_reverse_iterators_operator_decrement()
{
	ft::set<int> myset;

	for (int i = 0 ; i < 10; i++)
		myset.insert(i);

	typedef ft::set<int>::iterator iter_type;

	ft::reverse_iterator<iter_type> rev_begin(myset.end());
	ft::reverse_iterator<iter_type> rev_end(myset.begin());

	ft::reverse_iterator<iter_type> rev_iterator = rev_begin;
	while (rev_iterator != rev_end)
		std::cout << *rev_iterator++ << ' ';
	std::cout << std::endl;

	while (rev_iterator != rev_begin)
		std::cout << *(--rev_iterator) << ' ';
	std::cout << std::endl;

}

void
test_set_reverse_iterators_empty_sets()
{
	ft::set<int> set;
	ft::set<int> const const_set;

	if (set.rbegin() == set.rend())
		std::cout << "correct" << std::endl;

	if (const_set.rbegin() == const_set.rend())
		std::cout << "correct" << std::endl;
}

void
test_set_reverse_iterators_100_size_set()
{
	typedef ft::set<int>::reverse_iterator reverse_iterator;

	ft::set<int> set;

	srand(g_seed);
	for (int i = 0; i < 10; i++)
		set.insert(rand() % 100 - 50);

	for (reverse_iterator it = set.rbegin(); it != set.rend(); it++)
		std::cout << *it << " ";
}

void
test_set_reverse_iterators_100_size_const_set()
{
	typedef ft::set<int>::const_reverse_iterator const_reverse_iterator;

	ft::set<int> set;

	srand(g_seed);
	for (int i = 0; i < 10; i++)
		set.insert(rand() % 100 - 50);

	ft::set<int> const const_set(set.begin(), set.end());

	for (const_reverse_iterator it = const_set.rbegin(); it != const_set.rend(); it++)
		std::cout << *it << " ";
}

void
test_set_reverse_iterators_copy()
{
	typedef ft::set<int>::reverse_iterator reverse_iterator;
	typedef ft::set<int>::const_reverse_iterator const_reverse_iterator;

	ft::set<int> set;

	srand(g_seed);
	for (int i = 0; i < 10; i++)
		set.insert(rand() % 100 - 50);

	reverse_iterator it(set.rbegin());
	const_reverse_iterator const_it(it);

	for (const_reverse_iterator it = const_it; it != set.rend(); it++)
		std::cout << *it << " ";
}

void
test_set_reverse_iterators()
{
	test_wrapper(test_set_reverse_iterators_constructors_base, "constructors base");
	test_wrapper(test_set_reverse_iterators_operator_star, "operator*()");
	test_wrapper(test_set_reverse_iterators_operator_increment, "operator++()");
	test_wrapper(test_set_reverse_iterators_operator_decrement, "operator--()");
	test_wrapper(test_set_reverse_iterators_empty_sets, "empty sets");
	test_wrapper(test_set_reverse_iterators_100_size_set, "100 size set");
	test_wrapper(test_set_reverse_iterators_100_size_const_set, "100 size const set");
	test_wrapper(test_set_reverse_iterators_copy, "copy");
}
