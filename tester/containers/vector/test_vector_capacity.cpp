/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector_capacity.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 10:30:11 by dda-silv          #+#    #+#             */
/*   Updated: 2021/08/21 22:30:26 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_vector_capacity.hpp"

void
test_vector_capacity_max_size()
{
	ft::vector<int> vec;
	std::cout << "Max size: " << vec.max_size() << std::endl;
}

void
test_vector_capacity_empty()
{
	ft::vector<int> vec;
	print_vec_info(vec);
	std::cout << "Is empty?: " << vec.empty() << std::endl;
}

void
test_vector_capacity_full_vector()
{
	ft::vector<int> vec(6, 42);
	print_vec_info(vec);
}

void
test_vector_capacity_not_full_vector()
{
	ft::vector<int> vec(6, 42);
	print_vec_info(vec);

	vec.push_back(4);
	vec.push_back(2);
	print_vec_info(vec);
}

void
test_vector_capacity_resize_smaller()
{
	ft::vector<int> vec(6, 42);
	print_vec_info(vec);

	vec.resize(3);

	print_vec_info(vec);
}

void
test_vector_capacity_resize_equal()
{
	ft::vector<int> vec(6, 42);
	print_vec_info(vec);

	vec.resize(6);

	print_vec_info(vec);
}

void
test_vector_capacity_resize_bigger_size()
{
	ft::vector<int> vec(6, 42);
	print_vec_info(vec);

	vec.resize(7);

	print_vec_info(vec);
}

void
test_vector_capacity_resize_bigger_size_val()
{
	ft::vector<std::string> vec(6, "test");
	print_vec_info(vec);

	vec.resize(7, "new test");

	{
		ft::vector<std::string> cpy1(vec);
		print_vec_info(cpy1);
		ft::vector<std::string> cpy2 = vec;
		print_vec_info(cpy2);
	}
}

void
test_vector_capacity_resize_bigger_capacity()
{
	ft::vector<int> vec(6, 42);
	print_vec_info(vec);

	vec.resize(10);

	print_vec_info(vec);
}

void
test_vector_capacity_resize_bigger_capacity_val()
{
	ft::vector<int> vec(6, 42);
	print_vec_info(vec);

	vec.resize(10, 100);

	print_vec_info(vec);
}

void
test_vector_capacity_reserve_bigger_capacity()
{
	ft::vector<int> vec(6, 42);

	print_vec_info(vec);
	vec.reserve(100);
	print_vec_info(vec);
}

void
test_vector_capacity_reserve_smaller_capacity()
{
	ft::vector<int> vec(6, 42);

	print_vec_info(vec);
	vec.reserve(-1);
	print_vec_info(vec);
	vec.reserve(1);
	print_vec_info(vec);
	vec.reserve(6);
	print_vec_info(vec);
}

void
test_vector_capacity_reserve_max_size()
{
	ft::vector<int> vec(6, 42);
	vec.reserve(vec.max_size() + 1);
}

void
test_vector_capacity()
{
	test_wrapper(test_vector_capacity_max_size, "max size");
	test_wrapper(test_vector_capacity_empty, "empty");
	test_wrapper(test_vector_capacity_full_vector, "full vector");
	test_wrapper(test_vector_capacity_not_full_vector, "not full vector");
	test_wrapper(test_vector_capacity_resize_smaller, "resize smaller");
	test_wrapper(test_vector_capacity_resize_equal, "resize equal");
	test_wrapper(test_vector_capacity_resize_bigger_size, "resize bigger than size");
	test_wrapper(test_vector_capacity_resize_bigger_size_val, "resize bigger than size with a val");
	test_wrapper(test_vector_capacity_resize_bigger_capacity, "resize bigger than capacity");
	test_wrapper(test_vector_capacity_resize_bigger_capacity_val, "resize bigger than capacity with a val");
	test_wrapper(test_vector_capacity_reserve_bigger_capacity, "reserve bigger capacity");
	test_wrapper(test_vector_capacity_reserve_smaller_capacity, "reserve smaller capacity");
	test_wrapper(test_vector_capacity_reserve_max_size, "reserve above max size");
}
