/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector_non_member_overloads.cpp               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 17:59:33 by dda-silv          #+#    #+#             */
/*   Updated: 2021/08/26 09:39:30 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_vector_non_member_overloads.hpp"

void
test_vector_non_member_overloads_swap_ints()
{
	ft::vector<int> v1(5, 42), v2(100, -42);

	print_vec_info(v1);
	print_vec_info(v2);

	swap(v1, v2);

	print_vec_info(v1);
	print_vec_info(v2);
}

void
test_vector_non_member_overloads_swap_strings()
{
	ft::vector<std::string> v1(5, "42"), v2(100, "-42");

	print_vec_info(v1);
	print_vec_info(v2);

	v1.swap(v2);

	print_vec_info(v1);
	print_vec_info(v2);
}

void
test_vector_non_member_overloads_relation_operators()
{

	ft::vector<int> foo (3,100);   // three ints with a value of 100
	ft::vector<int> bar (2,200);   // two ints with a value of 200

	if (foo == bar) std::cout << "foo and bar are equal" << std::endl;
	if (foo != bar) std::cout << "foo and bar are not equal" << std::endl;
	if (foo < bar) std::cout << "foo is less than bar" << std::endl;
	if (foo > bar) std::cout << "foo is greater than bar" << std::endl;
	if (foo <= bar) std::cout << "foo is less than or equal to bar" << std::endl;
	if (foo >= bar) std::cout << "foo is greater than or equal to bar" << std::endl;
}

void
test_vector_non_member_overloads()
{
	test_wrapper(test_vector_non_member_overloads_relation_operators, "relation operators");
	test_wrapper(test_vector_non_member_overloads_swap_ints, "swap ints");
	test_wrapper(test_vector_non_member_overloads_swap_strings, "swap strings");
}
