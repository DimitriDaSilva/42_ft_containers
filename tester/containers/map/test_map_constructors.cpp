/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map_constructors.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 10:00:22 by dda-silv          #+#    #+#             */
/*   Updated: 2021/09/09 09:48:07 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_map_constructors.hpp"

void
test_map_constructors_empty()
{
	ft::map<int, int> map;
}

void
test_map_constructors_range()
{
	ft::map<char, int> map;

	srand(g_seed);

	for (char i = 'a'; i <= 'z'; i++)
		map.insert(ft::make_pair(i, rand() % 10000 - 10000 / 2));

	ft::map<char, int> range(map.begin(), map.end());

	print_map_info(map);
	print_map_info(range);
} void
test_map_constructors_copy_int()
{
	ft::map<char, int> map;

	srand(g_seed);

	for (char i = 'a'; i <= 'z'; i++)
		map.insert(ft::make_pair(i, rand() % 10000 - 10000 / 2));

	{
		ft::map<char, int> cpy1(map);
		ft::map<char, int> cpy2 = map;

		print_map_info(map);
		print_map_info(cpy1);
		print_map_info(cpy2);
	}
}

void
test_map_constructors_copy_string()
{
	ft::map<char, std::string> map;

	srand(g_seed);

	for (char i = 'a'; i <= 'z'; i++)
		map.insert(ft::make_pair(i, SSTR(rand() % 10000 - 10000 / 2)));

	{
		ft::map<char, std::string> cpy1(map);
		ft::map<char, std::string> cpy2 = map;

		print_map_info(map);
		print_map_info(cpy1);
		print_map_info(cpy2);
	}
}

void
test_map_constructors_custom_compare_char()
{
	ft::map<char, int, greater<char> > map;

	srand(g_seed);

	for (char i = 'a'; i <= 'z'; i++)
		map.insert(ft::make_pair(i, rand() % 10000 - 10000 / 2));

	print_map_info(map);
}

void
test_map_constructors_custom_compare_string()
{
	ft::map<std::string, char, greater<std::string> > map;

	srand(g_seed);

	for (char i = 'a'; i <= 'z'; i++)
		map.insert(ft::make_pair(rand() % 10000 - 10000 / 2, i));

	print_map_info(map);
}

void
test_map_constructors_cplusplus()
{
	ft::map<char, int> first;

	first['a'] = 10;
	first['b'] = 30;
	first['c'] = 50;
	first['d'] = 70;

	ft::map<char, int> second(first.begin(), first.end());

	ft::map<char, int> third(second);

	ft::map<char, int, classcomp> fourth;

	bool(*fn_pt)(char, char) = fncomp;
	ft::map<char, int, bool(*)(char, char)> fifth(fn_pt);
}

void
test_map_constructors()
{
	test_wrapper(test_map_constructors_empty, "empty");
	test_wrapper(test_map_constructors_range, "range");
	test_wrapper(test_map_constructors_copy_int, "copy int");
	test_wrapper(test_map_constructors_copy_string, "copy string");
	test_wrapper(test_map_constructors_custom_compare_char, "custom_compare_int");
	test_wrapper(test_map_constructors_custom_compare_string, "custom_compare_string");
	test_wrapper(test_map_constructors_cplusplus, "cplusplus");
}
