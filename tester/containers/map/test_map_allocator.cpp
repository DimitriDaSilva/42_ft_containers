/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map_allocator.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 16:29:38 by dda-silv          #+#    #+#             */
/*   Updated: 2021/09/09 13:42:16 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_map_allocator.hpp"

void
test_map_allocator_cplusplus()
{
	int psize;
	ft::map<char, int> mymap;
	ft::pair<char const,int>* p;

	// allocate an array of 5 elements using mymap's allocator:
	p=mymap.get_allocator().allocate(5);

	// assign some values to array
	psize = sizeof(ft::map<char, int>::value_type) * 5;

	std::cout << "The allocated array has a size of " << psize << " bytes." << std::endl;

	mymap.get_allocator().deallocate(p, 5);
}

void
test_map_allocator_custom_allocator()
{
	ft::map<int, char, ft::less<int>, custom_allocator<ft::pair<int const, char> > > map;

	map.insert(ft::make_pair(-42, 'z'));
	map.insert(ft::make_pair(0, 'd'));
	map.insert(ft::make_pair(42, 'a'));

	print_map_info(map);
}

void
test_map_allocator_strings_custom_allocator()
{
	ft::map<std::string, std::string, ft::less<std::string>, custom_allocator<ft::pair<std::string const, std::string> > > map;

	map.insert(ft::make_pair("hello", "h"));
	map.insert(ft::make_pair("world", "w"));
	map.insert(ft::make_pair("! :)", "!"));

	print_map_info(map);
}

void
test_map_allocator()
{
	test_wrapper(test_map_allocator_cplusplus, "cplusplus");
	test_wrapper(test_map_allocator_custom_allocator, "custom_allocator");
	test_wrapper(test_map_allocator_strings_custom_allocator, "strings_custom_allocator");
}
