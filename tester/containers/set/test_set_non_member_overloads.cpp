/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_set_non_member_overloads.cpp                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 16:36:47 by dda-silv          #+#    #+#             */
/*   Updated: 2021/09/08 22:45:47 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_set_non_member_overloads.hpp"

void
test_set_non_member_overloads_relation_operators()
{
	ft::set<int> foo, bar;

	foo.insert(10);
	bar.insert(20);
	bar.insert(30);
	foo.insert(40);

	// foo ({10,40}) vs bar ({20,30}):
	if (foo == bar) std::cout << "foo and bar are equal" << std::endl;
	if (foo != bar) std::cout << "foo and bar are not equal" << std::endl;
	if (foo < bar) std::cout << "foo is less than bar" << std::endl;
	if (foo > bar) std::cout << "foo is greater than bar" << std::endl;
	if (foo <= bar) std::cout << "foo is less than or equal to bar" << std::endl;
	if (foo >= bar) std::cout << "foo is greater than or equal to bar" << std::endl;
}

void
test_set_non_member_overloads_swap()
{
	int myints[] = {12, 75, 10, 32, 20, 25};
	ft::set<int> first(myints, myints + 3);
	ft::set<int> second(myints + 3, myints+ 6);

	print_set_info(first);
	print_set_info(second);

	swap(first, second);

	print_set_info(first);
	print_set_info(second);
}

void
test_set_non_member_overloads()
{
	test_wrapper(test_set_non_member_overloads_relation_operators, "relation operators");
	test_wrapper(test_set_non_member_overloads_swap, "swap");
}
