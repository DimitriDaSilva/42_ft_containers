/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map_iterators.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 10:54:07 by dda-silv          #+#    #+#             */
/*   Updated: 2021/09/09 09:48:07 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_map_iterators.hpp"

void
test_map_iterators_constructors_base()
{
	ft::map<int, char> map;

	for (int i = 48; i < 58; i++)
		map.insert(ft::make_pair(i, i));

	typedef ft::map<int, char>::iterator iter_type;

	iter_type from(map.begin());
	iter_type cpy(from);

	if (from == cpy)
		std::cout << "valid" << std::endl;
}

void
test_map_iterators_operator_star()
{
	ft::map<int, char> map;

	for (int i = 48; i < 58; i++)
		map.insert(ft::make_pair(i, i));

	typedef ft::map<int, char>::iterator iter_type;

	iter_type from(map.begin());

	std::cout << "[" << from->first << "] = " << from->second << std::endl;
}

void
test_map_iterators_operator_increment()
{
	ft::map<int, char> map;

	for (int i = 48; i < 58; i++)
		map.insert(ft::make_pair(i, i));

	typedef ft::map<int, char>::iterator iter_type;

	iter_type from(map.begin());
	iter_type until(map.end());

	std::cout << "map:";
	while (from != until)
	{
		std::cout << " [" << from->first << "] = " << from->second;
		from++;
	}
	std::cout << std::endl;
}

void
test_map_iterators_operator_decrement()
{
	ft::map<int, char> map;

	for (int i = 48; i < 58; i++)
		map.insert(ft::make_pair(i, i));

	typedef ft::map<int, char>::iterator iter_type;

	iter_type begin(map.begin());
	iter_type end(map.end());

	iter_type it(begin);
	while (it != end)
		std::cout << " [" << it->first << "] = " << (it++)->second;
	std::cout << std::endl;

	while (it != begin)
		std::cout << " [" << (--it)->first << "] = " << it->second;
	std::cout << std::endl;

}

void
test_map_iterators_empty_maps()
{
	ft::map<int, int> map;
	ft::map<int, int> const const_map;

	if (map.begin() == map.end())
		std::cout << "correct" << std::endl;

	if (const_map.begin() == const_map.end())
		std::cout << "correct" << std::endl;
}

void
test_map_iterators_100_size_map()
{
	typedef ft::map<int, int>::iterator iterator;

	ft::map<int, int> map;

	srand(g_seed);

	for (int i = 0; i < 100; i++)
		map.insert(ft::make_pair(i, rand() % 100 - 50));

	for (iterator it = map.begin(); it != map.end(); it++)
		std::cout << " [" << it->first << "] = " << it->second;
	std::cout << std::endl;
}

void
test_map_iterators_100_size_const_map()
{
	typedef ft::map<int, int>::const_iterator const_iterator;

	ft::map<int, int> const_map;

	srand(g_seed);

	for (int i = 0; i < 100; i++)
		const_map.insert(ft::make_pair(i, rand() % 100 - 50));

	for (const_iterator it = const_map.begin(); it != const_map.end(); it++)
		std::cout << " [" << it->first << "] = " << it->second;
	std::cout << std::endl;
}

void
test_map_iterators_copy()
{
	typedef ft::map<int, int>::iterator iterator;
	typedef ft::map<int, int>::const_iterator const_iterator;

	ft::map<int, int> map;

	srand(g_seed);

	for (int i = 0; i < 10; i++)
		map.insert(ft::make_pair(i, rand() % 100 - 50));

	iterator it(map.begin());
	const_iterator const_it(it);

	for (const_iterator it = const_it; it != map.end(); it++)
		std::cout << " [" << it->first << "] = " << it->second;
	std::cout << std::endl;
}

void
test_map_iterators()
{
	test_wrapper(test_map_iterators_constructors_base, "constructors base");
	test_wrapper(test_map_iterators_operator_star, "operator*()");
	test_wrapper(test_map_iterators_operator_increment, "operator++()");
	test_wrapper(test_map_iterators_operator_decrement, "operator--()");
	test_wrapper(test_map_iterators_empty_maps, "empty maps");
	test_wrapper(test_map_iterators_100_size_map, "100 size map");
	test_wrapper(test_map_iterators_100_size_const_map, "100 size const map");
	test_wrapper(test_map_iterators_copy, "copy");
}
