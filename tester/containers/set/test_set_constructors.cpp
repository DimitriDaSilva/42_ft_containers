/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_set_constructors.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 10:00:22 by dda-silv          #+#    #+#             */
/*   Updated: 2021/09/10 09:52:42 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_set_constructors.hpp"

void
test_set_constructors_empty()
{
	ft::set<int> set;
}

void
test_set_constructors_range()
{
	ft::set<int> set;
	ft::set<int> range1(set.begin(), set.end());

	print_set_info(set);
	print_set_info(range1);

	srand(g_seed);

	for (int i = 0; i < 100; i++)
		set.insert(rand() % 10000 - 10000 / 2);

	ft::set<int> range2(set.begin(), set.end());

	print_set_info(set);
	print_set_info(range2);
}

void
test_set_constructors_copy_int()
{
	ft::set<int> set;

	srand(g_seed);

	for (int i = 0; i < 100; i++)
		set.insert(rand() % 10000 - 10000 / 2);

	{
		ft::set<int> cpy1 = set;
		ft::set<int> cpy2(cpy1);

		print_set_info(set);
		print_set_info(cpy1);
		print_set_info(cpy2);
	}
}

void
test_set_constructors_copy_string()
{
	ft::set<std::string> set;

	srand(g_seed);

	for (int i = 0; i < 100; i++)
		set.insert(ft_itoa(rand() % 10000 - 10000 / 2));

	{
		ft::set<std::string> cpy1 = set;
		ft::set<std::string> cpy2(set);

		print_set_info(set);
		print_set_info(cpy1);
		print_set_info(cpy2);
	}
}

void
test_set_constructors_custom_compare_int()
{
	ft::set<int, greater<int> > set;

	srand(g_seed);

	for (int i = 0; i < 100; i++)
		set.insert(rand() % 10000 - 10000 / 2);

	print_set_info(set);
}

void
test_set_constructors_custom_compare_string()
{
	ft::set<std::string, greater<std::string> > set;

	srand(g_seed);

	for (int i = 0; i < 100; i++)
		set.insert(ft_itoa(rand() % 10000 - 10000 / 2));

	print_set_info(set);
}


void
test_set_constructors()
{
	test_wrapper(test_set_constructors_empty, "empty");
	test_wrapper(test_set_constructors_range, "range");
	test_wrapper(test_set_constructors_copy_int, "copy int");
	test_wrapper(test_set_constructors_copy_string, "copy string");
	test_wrapper(test_set_constructors_custom_compare_int, "custom_compare_int");
	test_wrapper(test_set_constructors_custom_compare_string, "custom_compare_string");
}
