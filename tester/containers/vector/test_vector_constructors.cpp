/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector_constructors.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 10:04:41 by dda-silv          #+#    #+#             */
/*   Updated: 2021/08/21 22:09:45 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_vector_constructors.hpp"

void
test_vector_constructors_empty()
{
	ft::vector<int> vec;
	print_vec_info(vec);
}

void
test_vector_constructors_fill_standard()
{
	ft::vector<int> vec(6, 42);
	print_vec_info(vec);

	// Because fill constructor only allocates exact needed memory
	// we test if push_back triggers same memory allocation as std
	vec.push_back(4);
	print_vec_info(vec);
}

void
test_vector_constructors_range_standard()
{
	ft::vector<int> vec_fill(6, 42);
	ft::vector<int> vec_range(vec_fill.begin(), vec_fill.end());
	print_vec_info(vec_range);
}

void
test_vector_constructors_custom_allocator()
{
	ft::vector<int, custom_allocator<int> > vec(6, 42);
	print_vec_info(vec);

	vec.push_back(4);
	print_vec_info(vec);
}

void
test_vector_constructors_copy()
{
	ft::vector<int> vec(42, 42);
	print_vec_info(vec);

	ft::vector<int> cpy = vec;
	print_vec_info(cpy);
}

void
test_vector_constructors_deepness()
{
	ft::vector<int> vec(42, 42);
	print_vec_info(vec);

	{
		ft::vector<int> cpy1(vec);
		print_vec_info(cpy1);
		ft::vector<int> cpy2 = vec;
		print_vec_info(cpy2);
	}
}

void
test_vector_constructors_strings()
{
	ft::vector<std::string> vec(42, "test");
	print_vec_info(vec);

	{
		ft::vector<std::string> cpy1(vec);
		print_vec_info(cpy1);
		ft::vector<std::string> cpy2 = vec;
		print_vec_info(cpy2);
	}
}

void
test_vector_constructors_strings_custom_allocator()
{
	ft::vector<std::string, custom_allocator<std::string> > vec(42, "test");
	print_vec_info(vec);
}

void
test_vector_constructors_copy_const()
{
	ft::vector<int> vec(6, 42);
	print_vec_info(vec);

	ft::vector<int> const const_vec1(vec);
	print_vec_info(const_vec1);

	ft::vector<int> const const_vec2 = vec;
	print_vec_info(const_vec2);
}

void
test_vector_constructors()
{
	test_wrapper(test_vector_constructors_empty, "empty");
	test_wrapper(test_vector_constructors_fill_standard, "fill standard");
	test_wrapper(test_vector_constructors_range_standard, "range standard");
	test_wrapper(test_vector_constructors_custom_allocator, "custom_allocator");
	test_wrapper(test_vector_constructors_copy, "copy");
	test_wrapper(test_vector_constructors_deepness, "deepness");
	test_wrapper(test_vector_constructors_strings, "strings");
	test_wrapper(test_vector_constructors_strings_custom_allocator, "strings_custom_allocator");
	test_wrapper(test_vector_constructors_copy_const, "copy const");
}
