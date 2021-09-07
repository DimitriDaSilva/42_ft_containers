/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector_allocator.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 22:44:46 by dda-silv          #+#    #+#             */
/*   Updated: 2021/09/07 10:32:11 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_vector_allocator.hpp"

void
test_vector_allocator_cplusplus()
{
	ft::vector<int> myvector;
	int* p;
	unsigned int i;

	// allocate an array with space for 5 elements using vector's allocator:
	p = myvector.get_allocator().allocate(5);

	// construct values in-place on the array:
	for (i = 0; i < 5; i++)
		myvector.get_allocator().construct(&p[i], i);

	std::cout << "The allocated array contains:";
	for (i = 0; i < 5; i++)
		std::cout << ' ' << p[i];
	std::cout << std::endl;

	// destroy and deallocate:
	for (i = 0; i < 5; i++)
		myvector.get_allocator().destroy(&p[i]);
	myvector.get_allocator().deallocate(p, 5);
}

void
test_vector_allocator_custom_allocator()
{
	ft::vector<int, custom_allocator<int> > vec(6, 42);
	print_vec_info(vec);

	vec.push_back(4);
	print_vec_info(vec);
}

void
test_vector_allocator_strings_custom_allocator()
{
	ft::vector<std::string, custom_allocator<std::string> > vec(42, "test");
	print_vec_info(vec);
}

void
test_vector_allocator()
{
	test_wrapper(test_vector_allocator_cplusplus, "cplusplus");
	test_wrapper(test_vector_allocator_custom_allocator, "custom_allocator");
	test_wrapper(test_vector_allocator_strings_custom_allocator, "strings_custom_allocator");
}
