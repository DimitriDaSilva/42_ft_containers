/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector_constructors.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 10:04:41 by dda-silv          #+#    #+#             */
/*   Updated: 2021/08/20 12:30:03 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_vector_constructors.hpp"

void test_vector_constructors(void) {
	// Test empty (default constructor)
	ft::vector<int> vec_empty;
	print_vec_info(vec_empty);

	// Test fill
	ft::vector<int> vec_fill1(6, 42);
	print_vec_info(vec_fill1);

	std::cout << std::endl;

	// Because fill constructor only allocates exact needed memory
	// we test if push_back triggers same memory allocation as std
	vec_fill1.push_back(4);
	print_vec_info(vec_fill1);

	// Test range
	ft::vector<int> vec_range(vec_fill1.begin(), vec_fill1.end());
	print_vec_info(vec_range);
}
