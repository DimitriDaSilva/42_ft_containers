/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector_reverse_iterators.cpp                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 10:32:33 by dda-silv          #+#    #+#             */
/*   Updated: 2021/09/07 11:23:04 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_vector_reverse_iterators.hpp"

void
test_vector_reverse_iterators_constructors_base()
{
	ft::vector<int> myvector;

	for (int i = 0; i < 10; i++)
		myvector.push_back(i);

	typedef ft::vector<int>::iterator iter_type;
	typedef ft::vector<int>::reverse_iterator rev_iter_type;

	iter_type from(myvector.begin());
	iter_type until(myvector.end());

	rev_iter_type rev_until(from);
	rev_iter_type rev_from(until);

	iter_type it_end = rev_until.base();
	iter_type it_begin = rev_from.base();

	if (it_end == from && it_begin == until)
		std::cout << "valid" << std::endl;
}

void
test_vector_reverse_iterators_operator_star()
{
	ft::vector<int> myvector;

	for (int i = 0; i < 10; i++)
		myvector.push_back(i);

	typedef ft::vector<int>::iterator iter_type;
	typedef ft::vector<int>::reverse_iterator rev_iter_type;

	iter_type until(myvector.end());

	rev_iter_type rev_from(until);

	std::cout << *rev_from << std::endl;
}

void
test_vector_reverse_iterators_operator_brackets()
{
	ft::vector<int> myvector;
	for (int i = 0; i < 10; i++)
		myvector.push_back(i);

	typedef ft::vector<int>::iterator iter_type;

	ft::reverse_iterator<iter_type> rev_it;

	rev_it = myvector.rbegin();

	std::cout << "The fourth element from the end is: " << rev_it[3] << std::endl;
}

void
test_vector_reverse_iterators_operator_plus()
{
	ft::vector<int> myvector;
	for (int i = 0; i < 10; i++)
		myvector.push_back(i);

	typedef ft::vector<int>::iterator iter_type;

	ft::reverse_iterator<iter_type> rev_it;

	rev_it = 3 + myvector.rbegin();

	std::cout << "The fourth element from the end is: " << *rev_it << std::endl;

	rev_it = myvector.rbegin() + 3;

	std::cout << "The fourth element from the end is: " << *rev_it << std::endl;
}

void
test_vector_reverse_iterators_operator_minus()
{
	ft::vector<int> myvector;
	for (int i = 0; i < 10; i++)
		myvector.push_back(i);

	typedef ft::vector<int>::iterator iter_type;

	ft::reverse_iterator<iter_type> rev_it;

	rev_it = myvector.rend() - 3;

	std::cout << "myvector.rend() - 3 points to: " << *rev_it << std::endl;

	ft::reverse_iterator<iter_type> from, until;

	from = myvector.rbegin();
	until = myvector.rend();

	std::cout << "myvector has " << (until - from) << " elements." << std::endl;
}

void
test_vector_reverse_iterators_operator_increment()
{
	ft::vector<int> myvector;

	for (int i  = 0; i < 10; i++)
		myvector.push_back(i);

	typedef ft::vector<int>::iterator iter_type;

	iter_type from(myvector.begin());
	iter_type until(myvector.end());

	ft::reverse_iterator<iter_type> rev_until(from);
	ft::reverse_iterator<iter_type> rev_from(until);

	std::cout << "myvector:";
	while (rev_from != rev_until)
	{
		std::cout << ' ' << *rev_from;
		++rev_from;
	}

	std::cout << std::endl;
}

void
test_vector_reverse_iterators_operator_decrement()
{
	ft::vector<int> myvector;

	for (int i = 0 ; i < 10; i++)
		myvector.push_back(i);

	typedef ft::vector<int>::iterator iter_type;

	ft::reverse_iterator<iter_type> rev_begin (myvector.end());
	ft::reverse_iterator<iter_type> rev_end (myvector.begin());

	ft::reverse_iterator<iter_type> rev_iterator = rev_begin;
	while (rev_iterator != rev_end)
		std::cout << *rev_iterator++ << ' ';
	std::cout << std::endl;

	while (rev_iterator != rev_begin)
		std::cout << *(--rev_iterator) << ' ';
	std::cout << std::endl;

}

void
test_vector_reverse_iterators_operator_plus_equal()
{
	ft::vector<int> myvector;

	for (int i = 0; i < 10; i++)
		myvector.push_back(i);

	typedef ft::vector<int>::iterator iter_type;

	ft::reverse_iterator<iter_type> rev_iterator = myvector.rbegin();

	rev_iterator += 2;

	std::cout << "The third element from the end is: " << *rev_iterator << std::endl;
}

void
test_vector_reverse_iterators_operator_minus_equal()
{
	ft::vector<int> myvector;

	for (int i = 0; i < 10; i++)
		myvector.push_back(i);

	typedef ft::vector<int>::iterator iter_type;

	ft::reverse_iterator<iter_type> rev_iterator = myvector.rend();

	rev_iterator -= 4;

	std::cout <<  "rev_iterator now points to: " << *rev_iterator << std::endl;
}

void
test_vector_reverse_iterators_empty_vectors()
{
	ft::vector<int> vec;
	ft::vector<int> const const_vec;

	if (vec.rbegin() == vec.rend())
		std::cout << "correct" << std::endl;

	if (const_vec.rbegin() == const_vec.rend())
		std::cout << "correct" << std::endl;
}

void
test_vector_reverse_iterators_100_size_vector()
{
	typedef ft::vector<int>::reverse_iterator reverse_iterator;

	ft::vector<int> vec;

	srand(g_seed);

	for (int i = 0; i < 10; i++)
		vec.push_back(rand() % 100 - 50);

	for (reverse_iterator it = vec.rbegin(); it != vec.rend(); it++)
		std::cout << *it << " ";
}

void
test_vector_reverse_iterators_100_size_const_vector()
{
	typedef ft::vector<int>::const_reverse_iterator const_reverse_iterator;

	ft::vector<int> const const_vec(100, 42);

	for (const_reverse_iterator it = const_vec.rbegin(); it != const_vec.rend(); it++)
		std::cout << *it << " ";
}

void
test_vector_reverse_iterators_copy()
{
	typedef ft::vector<int>::reverse_iterator reverse_iterator;
	typedef ft::vector<int>::const_reverse_iterator const_reverse_iterator;

	ft::vector<int> vec(6, 42);

	reverse_iterator it(vec.rbegin());
	*it = 3;
	*(it + 1) = 4;
	const_reverse_iterator const_it(it);

	for (const_reverse_iterator it = const_it; it != vec.rend(); it++)
		std::cout << *it << " ";
}

void
test_vector_reverse_iterators()
{
	test_wrapper(test_vector_reverse_iterators_constructors_base, "constructors base");
	test_wrapper(test_vector_reverse_iterators_operator_star, "operator*()");
	test_wrapper(test_vector_reverse_iterators_operator_brackets, "operator[]()");
	test_wrapper(test_vector_reverse_iterators_operator_plus, "operator+()");
	test_wrapper(test_vector_reverse_iterators_operator_minus, "operator-()");
	test_wrapper(test_vector_reverse_iterators_operator_increment, "operator++()");
	test_wrapper(test_vector_reverse_iterators_operator_decrement, "operator--()");
	test_wrapper(test_vector_reverse_iterators_operator_plus_equal, "operator+=()");
	test_wrapper(test_vector_reverse_iterators_operator_minus_equal, "operator-=()");
	test_wrapper(test_vector_reverse_iterators_empty_vectors, "empty vectors");
	test_wrapper(test_vector_reverse_iterators_100_size_vector, "100 size vector");
	test_wrapper(test_vector_reverse_iterators_100_size_const_vector, "100 size const vector");
	test_wrapper(test_vector_reverse_iterators_copy, "copy");
}
