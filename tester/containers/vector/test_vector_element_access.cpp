/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector_element_access.cpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 23:10:01 by dda-silv          #+#    #+#             */
/*   Updated: 2021/08/28 09:59:42 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_vector_element_access.hpp"

void
test_vector_element_access_brackets()
{
	ft::vector<int> vec;

	for (int i = 0; i < 10; i++)
	{
		vec.push_back(i);
	}
	print_vec_info(vec);

	std::cout << vec[2] << std::endl;
	vec[2] = 42;
	std::cout << vec[2] << std::endl;
}

void
test_vector_element_access_const_brackets()
{
	ft::vector<int> const vec(10, 42);
	print_vec_info(vec);

	std::cout << vec[2] << std::endl;
}

void
test_vector_element_access_brackets_out_of_range()
{
	ft::vector<int> const vec(10, 42);
	print_vec_info(vec);

	//std::cout << vec[10] << std::endl;
}

void
test_vector_element_access_at()
{
	ft::vector<int> vec;

	for (int i = 0; i < 10; i++)
	{
		vec.push_back(i);
	}
	print_vec_info(vec);

	std::cout << vec.at(2) << std::endl;
	vec.at(2) = 42;
	std::cout << vec.at(2) << std::endl;
}

void
test_vector_element_access_const_at()
{
	ft::vector<int> const vec(10, 42);
	print_vec_info(vec);

	std::cout << vec.at(2) << std::endl;
}

void
test_vector_element_access_at_out_of_range()
{
	ft::vector<int> const vec(10, 42);
	print_vec_info(vec);

	std::cout << vec.at(10) << std::endl;
}

void
test_vector_element_access_front()
{
	ft::vector<int> vec(10, 10);
	print_vec_info(vec);

	vec.front() = 42;
	print_vec_info(vec);
}

void
test_vector_element_access_back()
{
	ft::vector<int> vec(10, 10);
	print_vec_info(vec);

	vec.back() = 42;
	print_vec_info(vec);
}

void
test_vector_element_access_front_back_mix()
{
	ft::vector<int> myvector;

	myvector.push_back(78);
	myvector.push_back(16);

	myvector.front() -= myvector.back();

	std::cout << "myvector.front() is now " << myvector.front() << std::endl;
}

void
test_vector_element_access()
{
	test_wrapper(test_vector_element_access_brackets, "brackets");
	test_wrapper(test_vector_element_access_const_brackets, "const brackets");
	test_wrapper(test_vector_element_access_brackets_out_of_range, "brackets out of range");
	test_wrapper(test_vector_element_access_at, "at");
	test_wrapper(test_vector_element_access_const_at, "const at");
	test_wrapper(test_vector_element_access_at_out_of_range, "at out of range");
	test_wrapper(test_vector_element_access_front, "front");
	test_wrapper(test_vector_element_access_back, "back");
	test_wrapper(test_vector_element_access_front_back_mix, "front back mix");
}
