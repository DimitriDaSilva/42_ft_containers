/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map_reverse_iterators.cpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 11:02:35 by dda-silv          #+#    #+#             */
/*   Updated: 2021/09/09 11:41:13 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_map_reverse_iterators.hpp"

void
test_map_reverse_iterators_constructors_base()
{
	ft::map<int, char> map;

	for (int i = 48; i < 58; i++)
		map.insert(ft::make_pair(i, i));

	typedef ft::map<int, char>::iterator iter_type;
	typedef ft::map<int, char>::reverse_iterator rev_iter_type;

	iter_type from(map.begin());
	iter_type until(map.end());

	rev_iter_type rev_until(from);
	rev_iter_type rev_from(until);

	iter_type it_end = rev_until.base();
	iter_type it_begin = rev_from.base();

	if (it_end == from && it_begin == until)
		std::cout << "valid" << std::endl;
}

void
test_map_reverse_iterators_operator_star()
{
	ft::map<int, char> map;

	for (int i = 48; i < 58; i++)
		map.insert(ft::make_pair(i, i));

	typedef ft::map<int, char>::iterator iter_type;
	typedef ft::map<int, char>::reverse_iterator rev_iter_type;

	iter_type until(map.end());

	rev_iter_type rev_from(until);

	std::cout << "[" << rev_from->first << "] = " << rev_from->second << std::endl;
}

void
test_map_reverse_iterators_operator_increment()
{
	ft::map<int, char> map;

	for (int i = 48; i < 58; i++)
		map.insert(ft::make_pair(i, i));

	typedef ft::map<int, char>::iterator iter_type;


	iter_type from(map.begin());
	iter_type until(map.end());

	ft::reverse_iterator<iter_type> rev_until(from);
	ft::reverse_iterator<iter_type> rev_from(until);

	std::cout << "mymap:";
	while (rev_from != rev_until)
	{
		std::cout << "[" << rev_from->first << "] = " << rev_from->second << std::endl;
		++rev_from;
	}

	std::cout << std::endl;
}

void
test_map_reverse_iterators_operator_decrement()
{
	ft::map<int, char> map;

	for (int i = 48; i < 58; i++)
		map.insert(ft::make_pair(i, i));

	typedef ft::map<int, char>::iterator iter_type;

	ft::reverse_iterator<iter_type> rev_begin(map.end());
	ft::reverse_iterator<iter_type> rev_end(map.begin());

	ft::reverse_iterator<iter_type> rev_iterator = rev_begin;

	while (rev_iterator != rev_end)
		std::cout << "[" << rev_iterator->first << "] = " << (rev_iterator++)->second << std::endl;
	std::cout << std::endl;

	while (rev_iterator != rev_begin)
		std::cout << " [" << (--rev_iterator)->first << "] = " << rev_iterator->second;
	std::cout << std::endl;

}

void
test_map_reverse_iterators_empty_maps()
{
	ft::map<int, int> map;
	ft::map<int, int> const const_map;

	if (map.rbegin() == map.rend())
		std::cout << "correct" << std::endl;

	if (const_map.rbegin() == const_map.rend())
		std::cout << "correct" << std::endl;
}

void
test_map_reverse_iterators_100_size_map()
{
	typedef ft::map<int, int>::reverse_iterator reverse_iterator;

	ft::map<int, int> map;

	srand(g_seed);

	for (int i = 0; i < 100; i++)
		map.insert(ft::make_pair(i, rand() % 100 - 50));

	for (reverse_iterator it = map.rbegin(); it != map.rend(); it++)
		std::cout << " [" << it->first << "] = " << it->second;
	std::cout << std::endl;
}

void
test_map_reverse_iterators_100_size_const_map()
{
	typedef ft::map<int, int>::const_reverse_iterator const_reverse_iterator;

	ft::map<int, int> map;

	srand(g_seed);

	for (int i = 0; i < 100; i++)
		map.insert(ft::make_pair(i, rand() % 100 - 50));

	for (const_reverse_iterator it = map.rbegin(); it != map.rend(); it++)
		std::cout << " [" << it->first << "] = " << it->second;
	std::cout << std::endl;
}

void
test_map_reverse_iterators_copy()
{
	typedef ft::map<int, int>::reverse_iterator reverse_iterator;
	typedef ft::map<int, int>::const_reverse_iterator const_reverse_iterator;

	ft::map<int, int> map;

	srand(g_seed);
	for (int i = 0; i < 10; i++)
		map.insert(ft::make_pair(i, rand() % 100 - 50));

	reverse_iterator it(map.rbegin());
	const_reverse_iterator const_it(it);

	for (const_reverse_iterator it = const_it; it != map.rend(); it++)
		std::cout << " [" << it->first << "] = " << it->second;
}

void
test_map_reverse_iterators()
{
	test_wrapper(test_map_reverse_iterators_constructors_base, "constructors base");
	test_wrapper(test_map_reverse_iterators_operator_star, "operator*()");
	test_wrapper(test_map_reverse_iterators_operator_increment, "operator++()");
	test_wrapper(test_map_reverse_iterators_operator_decrement, "operator--()");
	test_wrapper(test_map_reverse_iterators_empty_maps, "empty maps");
	test_wrapper(test_map_reverse_iterators_100_size_map, "100 size map");
	test_wrapper(test_map_reverse_iterators_100_size_const_map, "100 size const map");
	test_wrapper(test_map_reverse_iterators_copy, "copy");
}
