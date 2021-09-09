/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map_non_member_overloads.cpp                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 16:36:47 by dda-silv          #+#    #+#             */
/*   Updated: 2021/09/09 10:21:54 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_map_non_member_overloads.hpp"

void
test_map_non_member_overloads_relation_operators()
{
	ft::map<char, int> foo, bar;
	foo['a'] = 100;
	foo['b'] = 200;
	bar['a'] = 10;
	bar['z'] = 1000;

	if (foo == bar) std::cout << "foo and bar are equal" << std::endl;
	if (foo != bar) std::cout << "foo and bar are not equal" << std::endl;
	if (foo < bar) std::cout << "foo is less than bar" << std::endl;
	if (foo > bar) std::cout << "foo is greater than bar" << std::endl;
	if (foo <= bar) std::cout << "foo is less than or equal to bar" << std::endl;
	if (foo >= bar) std::cout << "foo is greater than or equal to bar" << std::endl;
}

void
test_map_non_member_overloads_swap()
{
	ft::map<char, int> first, second;

	first['x'] = 100;
	first['y'] = 200;

	second['a'] = 11;
	second['b'] = 22;
	second['c'] = 33;

	first.swap(second);

	print_map_info(first);
	print_map_info(second);

	swap(first, second);

	print_map_info(first);
	print_map_info(second);
}

void
test_map_non_member_overloads()
{
	test_wrapper(test_map_non_member_overloads_relation_operators, "relation operators");
	test_wrapper(test_map_non_member_overloads_swap, "swap");
}
