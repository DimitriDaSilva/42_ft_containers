/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector_iterators.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 10:32:33 by dda-silv          #+#    #+#             */
/*   Updated: 2021/08/21 21:50:51 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_vector_iterators.hpp"

void
test_vector_iterators_empty_vectors()
{
	ft::vector<int> vec;
	ft::vector<int> const const_vec;

	if (vec.begin() == vec.end())
	{
		std::cout << "correct" << std::endl;
	}

	if (const_vec.begin() == const_vec.end())
	{
		std::cout << "correct" << std::endl;
	}
}

void
test_vector_iterators_100_size_vector()
{
	typedef ft::vector<int>::iterator iterator;

	ft::vector<int> vec;

	for (int i = 0; i < 10; i++)
	{
		vec.push_back(rand() % 100 - 50);
	}
	for (iterator it = vec.begin(); it != vec.end(); it++)
	{
		std::cout << *it << " ";
	}
}

void
test_vector_iterators_100_size_const_vector()
{
	typedef ft::vector<int>::const_iterator const_iterator;

	ft::vector<int> const const_vec(100, 42);

	for (const_iterator it = const_vec.begin(); it != const_vec.end(); it++)
	{
		std::cout << *it << " ";
	}
}

void
test_vector_iterators_copy()
{
	typedef ft::vector<int>::iterator iterator;
	typedef ft::vector<int>::const_iterator const_iterator;

	ft::vector<int> vec(6, 42);

	iterator it(vec.begin());
	*it = 3;
	*(it + 1) = 4;
	const_iterator const_it(it);

	for (const_iterator it = const_it; it != vec.end(); it++)
	{
		std::cout << *it << " ";
	}
}

void
test_vector_iterators()
{
	test_wrapper(test_vector_iterators_empty_vectors, "empty vectors");
	test_wrapper(test_vector_iterators_100_size_vector, "100 size vector");
	test_wrapper(test_vector_iterators_100_size_const_vector, "100 size const vector");
	test_wrapper(test_vector_iterators_copy, "copy");
}
