/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector_capacity.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 10:30:11 by dda-silv          #+#    #+#             */
/*   Updated: 2021/08/20 10:33:08 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_vector_capacity.hpp"

void test_vector_capacity(void) {
	std::cout << "*** test_vector_capacity ***" << std::endl;

	ft::vector<int> vec;
	print_vec_info(vec);

	std::cout << "Max size: " << vec.max_size() << std::endl;

	vec.push_back(4);
	vec.push_back(2);
	print_vec_info(vec);

	vec.resize(1);
	print_vec_info(vec);

	for (int i = 0; i < 50; i++) {
		vec.push_back(i);
	}
	print_vec_info(vec);

	vec.resize(20);
	vec.reserve(20);
	vec.reserve(0);

	try {
		vec.reserve(vec.max_size() + 1);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	print_vec_info(vec);

	std::cout << std::endl;
}
