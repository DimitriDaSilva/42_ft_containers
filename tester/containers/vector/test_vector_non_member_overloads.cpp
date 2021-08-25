/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector_non_member_overloads.cpp               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 17:59:33 by dda-silv          #+#    #+#             */
/*   Updated: 2021/08/25 18:04:10 by dda-silv         ###   ########.fr       */
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
test_vector_non_member_overloads()
{
	test_wrapper(test_vector_non_member_overloads_swap_ints, "swap ints");
	test_wrapper(test_vector_non_member_overloads_swap_strings, "swap strings");
}
