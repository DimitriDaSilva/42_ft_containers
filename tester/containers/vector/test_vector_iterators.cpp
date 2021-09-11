/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector_iterators.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 10:32:33 by dda-silv          #+#    #+#             */
/*   Updated: 2021/09/11 18:15:07 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_vector_iterators.hpp"

void
test_vector_iterators_constructors_base()
{
	ft::vector<int> myvector;

	for (int i = 0; i < 10; i++)
		myvector.push_back(i);

	typedef ft::vector<int>::iterator iter_type;

	iter_type from(myvector.begin());
	iter_type cpy(from);

	if (from == cpy)
		std::cout << "valid" << std::endl;
}

void
test_vector_iterators_operator_star()
{
	ft::vector<int> myvector;

	for (int i = 0; i < 10; i++)
		myvector.push_back(i);

	typedef ft::vector<int>::iterator iter_type;

	iter_type from(myvector.begin());

	std::cout << *from << std::endl;
}

void
test_vector_iterators_operator_brackets()
{
	ft::vector<int> myvector;
	for (int i = 0; i < 10; i++)
		myvector.push_back(i);

	typedef ft::vector<int>::iterator iter_type;

	iter_type it = myvector.begin();

	std::cout << "The fourth element from the begin is: " << it[3] << std::endl;
}

void
test_vector_iterators_operator_plus()
{
	ft::vector<int> myvector;
	for (int i = 0; i < 10; i++)
		myvector.push_back(i);

	typedef ft::vector<int>::iterator iter_type;

	iter_type it = 3 + myvector.begin();

	std::cout << "The fourth element from the begin is: " << *it << std::endl;

	it = myvector.begin() + 3;

	std::cout << "The fourth element from the begin is: " << *it << std::endl;
}

void
test_vector_iterators_operator_minus()
{
	ft::vector<int> myvector;
	for (int i = 0; i < 10; i++)
		myvector.push_back(i);

	typedef ft::vector<int>::iterator iter_type;

	iter_type it = myvector.end() - 3;

	std::cout << "myvector.end() - 3 points to: " << *it << std::endl;

	iter_type const from = myvector.begin();
	iter_type until = myvector.end();

	std::cout << "myvector has " << (until - from) << " elements." << std::endl;
}

void
test_vector_iterators_operator_increment()
{
	ft::vector<int> myvector;

	for (int i  = 0; i < 10; i++)
		myvector.push_back(i);

	typedef ft::vector<int>::iterator iter_type;

	iter_type from(myvector.begin());
	iter_type until(myvector.end());

	std::cout << "myvector:";
	while (from != until)
	{
		std::cout << ' ' << *from;
		++from;
	}

	std::cout << std::endl;
}

void
test_vector_iterators_operator_decrement()
{
	ft::vector<int> myvector;

	for (int i = 0 ; i < 10; i++)
		myvector.push_back(i);

	typedef ft::vector<int>::iterator iter_type;

	iter_type begin (myvector.begin());
	iter_type end (myvector.end());

	iter_type it(begin);
	while (it != end)
		std::cout << *it++ << ' ';
	std::cout << std::endl;

	while (it != begin)
		std::cout << *(--it) << ' ';
	std::cout << std::endl;

}

void
test_vector_iterators_operator_plus_equal()
{
	ft::vector<int> myvector;

	for (int i = 0; i < 10; i++)
		myvector.push_back(i);

	typedef ft::vector<int>::iterator iter_type;

	iter_type it = myvector.begin();

	it += 2;

	std::cout << "The third element from the begin is: " << *it << std::endl;
}

void
test_vector_iterators_operator_minus_equal()
{
	ft::vector<int> myvector;

	for (int i = 0; i < 10; i++)
		myvector.push_back(i);

	typedef ft::vector<int>::iterator iter_type;

	iter_type it = myvector.end();

	it -= 4;

	std::cout <<  "rev_iterator now points to: " << *it << std::endl;
}

void
test_vector_iterators_empty_vectors()
{
	ft::vector<int> vec;
	ft::vector<int> const const_vec;

	if (vec.begin() == vec.end())
		std::cout << "correct" << std::endl;

	if (const_vec.begin() == const_vec.end())
		std::cout << "correct" << std::endl;
}

void
test_vector_iterators_100_size_vector()
{
	typedef ft::vector<int>::iterator iterator;

	ft::vector<int> vec;

	srand(g_seed);

	for (int i = 0; i < 10; i++)
		vec.push_back(rand() % 100 - 50);

	for (iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << " ";
}

void
test_vector_iterators_100_size_const_vector()
{
	typedef ft::vector<int>::const_iterator const_iterator;

	ft::vector<int> const const_vec(100, 42);

	for (const_iterator it = const_vec.begin(); it != const_vec.end(); it++)
		std::cout << *it << " ";
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
		std::cout << *it << " ";
}

void
test_vector_iterators_compare_const()
{
	typedef ft::vector<int>::iterator iterator;
	typedef ft::vector<int>::const_iterator const_iterator;

	ft::vector<int> vec(6, 42);

	iterator it(vec.begin());
	*it = 3;
	*(it + 1) = 4;
	const_iterator const_it(it);

	std::cout << (it == const_it) << std::endl;
	std::cout << (it != const_it) << std::endl;
	std::cout << (it < const_it) << std::endl;
	std::cout << (it > const_it) << std::endl;
	std::cout << (it <= const_it) << std::endl;
	std::cout << (it >= const_it) << std::endl;
}

void
test_vector_iterators()
{
	test_wrapper(test_vector_iterators_constructors_base, "constructors base");
	test_wrapper(test_vector_iterators_operator_star, "operator*()");
	test_wrapper(test_vector_iterators_operator_brackets, "operator[]()");
	test_wrapper(test_vector_iterators_operator_plus, "operator+()");
	test_wrapper(test_vector_iterators_operator_minus, "operator-()");
	test_wrapper(test_vector_iterators_operator_increment, "operator++()");
	test_wrapper(test_vector_iterators_operator_decrement, "operator--()");
	test_wrapper(test_vector_iterators_operator_plus_equal, "operator+=()");
	test_wrapper(test_vector_iterators_operator_minus_equal, "operator-=()");
	test_wrapper(test_vector_iterators_empty_vectors, "empty vectors");
	test_wrapper(test_vector_iterators_100_size_vector, "100 size vector");
	test_wrapper(test_vector_iterators_100_size_const_vector, "100 size const vector");
	test_wrapper(test_vector_iterators_copy, "copy");
	test_wrapper(test_vector_iterators_compare_const, "compare");
}
