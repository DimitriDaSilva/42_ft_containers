/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_set_allocator.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 16:29:38 by dda-silv          #+#    #+#             */
/*   Updated: 2021/09/08 22:23:36 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_set_allocator.hpp"

void
test_set_allocator_cplusplus()
{
	ft::set<int> set;
	int* p;
	unsigned int i;

	// allocate an array with space for 5 elements using set's allocator:
	p = set.get_allocator().allocate(5);

	// construct values in-place on the array:
	for (i = 0; i < 5; i++)
		set.get_allocator().construct(&p[i], i);

	std::cout << "The allocated array contains:";
	for (i = 0; i < 5; i++)
		std::cout << ' ' << p[i];
	std::cout << std::endl;

	// destroy and deallocate:
	for (i = 0; i < 5; i++)
		set.get_allocator().destroy(&p[i]);
	set.get_allocator().deallocate(p, 5);
}

void
test_set_allocator_custom_allocator()
{
	ft::set<int, ft::less<int>, custom_allocator<int> > set;

	set.insert(-42);
	set.insert(0);
	set.insert(42);

	print_set_info(set);
}

void
test_set_allocator_strings_custom_allocator()
{
	ft::set<std::string, ft::less<std::string>, custom_allocator<std::string> > set;

	set.insert("hello");
	set.insert("world");
	set.insert("! :)");

	print_set_info(set);
}

void
test_set_allocator()
{
	test_wrapper(test_set_allocator_cplusplus, "cplusplus");
	test_wrapper(test_set_allocator_custom_allocator, "custom_allocator");
	test_wrapper(test_set_allocator_strings_custom_allocator, "strings_custom_allocator");
}
