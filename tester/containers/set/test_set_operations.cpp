/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_set_operations.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 16:28:40 by dda-silv          #+#    #+#             */
/*   Updated: 2021/09/08 22:13:41 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_set_operations.hpp"

void
test_set_operations_find()
{
	ft::set<int> set;
	ft::set<int>::iterator it;

	for (int i = 1; i <= 5; i++)
		set.insert(i);

	print_set_info(set);

	if ((it = set.find(4)) != set.end())
		set.erase(it);

	if ((it = set.find(2)) != set.end())
		set.erase(it);

	if ((it = set.find(42)) != set.end())
		set.erase(it);

	print_set_info(set);
}

void
test_set_operations_count()
{
	ft::set<int> set;

	for (int i = 0; i < 20; i++)
	{
		if (i % 2 == 0)
			set.insert(i);
	}

	for (int i = 0; i < 20; i++)
		std::cout << (set.count(i) == 1 ? " In " : " Not in ");
	std::cout << std::endl;
}

void
test_set_operations_lower_bound()
{
	ft::set<int> set;
	//ft::set<int>::iterator it;
	ft::set<int>::const_iterator const_it;

	for (int i = 0; i < 10; i++)
		set.insert(i * 10);

	const_it = set.lower_bound(20);
	if (const_it != set.end())
		std::cout << *const_it << std::endl;
	else
		std::cout << "end()" << std::endl;

	const_it = set.lower_bound(42);
	if (const_it != set.end())
		std::cout << *const_it << std::endl;
	else
		std::cout << "end()" << std::endl;

	const_it = set.lower_bound(142);
	if (const_it != set.end())
		std::cout << *const_it << std::endl;
	else
		std::cout << "end()" << std::endl;

	const_it = set.lower_bound(-42);
	if (const_it != set.end())
		std::cout << *const_it << std::endl;
	else
		std::cout << "end()" << std::endl;
}

void
test_set_operations_upper_bound()
{
	ft::set<int> set;
	ft::set<int>::iterator it;

	for (int i = 0; i < 10; i++)
		set.insert(i * 10);

	it = set.upper_bound(20);
	if (it != set.end())
		std::cout << *it << std::endl;
	else
		std::cout << "end()" << std::endl;

	it = set.upper_bound(42);
	if (it != set.end())
		std::cout << *it << std::endl;
	else
		std::cout << "end()" << std::endl;

	it = set.upper_bound(142);
	if (it != set.end())
		std::cout << *it << std::endl;
	else
		std::cout << "end()" << std::endl;

	it = set.upper_bound(-42);
	if (it != set.end())
		std::cout << *it << std::endl;
	else
		std::cout << "end()" << std::endl;
}

void
test_set_operations_lower_upper_bound()
{
	ft::set<int> set;
	ft::set<int>::iterator itlow, itup;

	for (int i = 1; i < 10; i++)
		set.insert(i * 10);

	itlow = set.lower_bound(30);
	itup = set.upper_bound(60);

	print_set_info(set);

	set.erase(itlow, itup);

	print_set_info(set);
}

void
test_set_operations_equal_range_match()
{
	ft::set<int> set;
	typedef ft::set<int>::const_iterator const_iterator;

	for (int i = 1; i <= 5; i++)
		set.insert(i * 10);

	ft::pair<const_iterator, const_iterator> ret;
	ret = set.equal_range(30);

	std::cout << "the lower bound points to: " << *ret.first << '\n';
	std::cout << "the upper bound points to: " << *ret.second << '\n';
}

void
test_set_operations_equal_range_no_match()
{
	ft::set<int> set;
	typedef ft::set<int>::const_iterator const_iterator;

	for (int i = 1; i <= 5; i++)
		set.insert(i * 10);

	ft::pair<const_iterator, const_iterator> ret;
	ret = set.equal_range(25);
	std::cout << "the lower bound points to: " << *ret.first << '\n';
	std::cout << "the upper bound points to: " << *ret.second << '\n';

	ret = set.equal_range(-42);
	std::cout << "the lower bound points to: " << *ret.first << '\n';
	std::cout << "the upper bound points to: " << *ret.second << '\n';
}

void
test_set_operations()
{
	test_wrapper(test_set_operations_find, "find");
	test_wrapper(test_set_operations_count, "count");
	test_wrapper(test_set_operations_lower_bound, "lower_bound");
	test_wrapper(test_set_operations_upper_bound, "upper_bound");
	test_wrapper(test_set_operations_lower_upper_bound, "lower_upper_bound");
	test_wrapper(test_set_operations_equal_range_match, "equal_range_match");
	test_wrapper(test_set_operations_equal_range_no_match, "equal_range_no_match");
}
