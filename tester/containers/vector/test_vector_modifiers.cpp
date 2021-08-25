/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector_modifiers.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 10:33:35 by dda-silv          #+#    #+#             */
/*   Updated: 2021/08/25 12:12:05 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_vector_modifiers.hpp"

void
test_vector_modifiers_assign_range_empty_dest()
{
	ft::vector<std::string> vec(5, "test");
	ft::vector<std::string> new_vec;
	ft::vector<std::string>::iterator it = new_vec.begin();

	new_vec.assign(vec.begin(), vec.end());
	print_vec_info(vec);
	print_vec_info(new_vec);

	ft::vector<std::string>::iterator new_it = new_vec.begin();
	if (&*it != &*new_it)
	{
		std::cout << "Reallocation occurred" << std::endl;
	}

	{
		ft::vector<std::string> cpy1 = new_vec;
		print_vec_info(cpy1);
		ft::vector<std::string> cpy2(new_vec);
		print_vec_info(cpy2);
	}
}

void
test_vector_modifiers_assign_range_not_empty_dest1()
{
	ft::vector<std::string> vec(5, "test");
	ft::vector<std::string> new_vec(2, "42");
	ft::vector<std::string>::iterator it = new_vec.begin();

	print_vec_info(new_vec);
	new_vec.assign(vec.begin(), vec.end());
	print_vec_info(vec);
	print_vec_info(new_vec);

	ft::vector<std::string>::iterator new_it = new_vec.begin();
	if (&*it != &*new_it)
	{
		std::cout << "Reallocation occurred" << std::endl;
	}

	{
		ft::vector<std::string> cpy1 = new_vec;
		print_vec_info(cpy1);
		ft::vector<std::string> cpy2(new_vec);
		print_vec_info(cpy2);
	}
}

void
test_vector_modifiers_assign_range_not_empty_dest2()
{
	ft::vector<std::string> vec(5, "test");
	ft::vector<std::string> new_vec(5, "42");
	ft::vector<std::string>::iterator it = new_vec.begin();

	print_vec_info(new_vec);
	new_vec.assign(vec.begin(), vec.end());
	print_vec_info(vec);
	print_vec_info(new_vec);

	ft::vector<std::string>::iterator new_it = new_vec.begin();
	if (&*it != &*new_it)
	{
		std::cout << "Reallocation occurred" << std::endl;
	}

	{
		ft::vector<std::string> cpy1 = new_vec;
		print_vec_info(cpy1);
		ft::vector<std::string> cpy2(new_vec);
		print_vec_info(cpy2);
	}
}

void
test_vector_modifiers_assign_range_not_empty_dest3()
{
	ft::vector<std::string> vec(5, "test");
	ft::vector<std::string> new_vec(100, "42");
	ft::vector<std::string>::iterator it = new_vec.begin();

	print_vec_info(new_vec);
	new_vec.assign(vec.begin(), vec.end());
	print_vec_info(vec);
	print_vec_info(new_vec);

	ft::vector<std::string>::iterator new_it = new_vec.begin();
	if (&*it != &*new_it)
	{
		std::cout << "Reallocation occurred" << std::endl;
	}

	{
		ft::vector<std::string> cpy1 = new_vec;
		print_vec_info(cpy1);
		ft::vector<std::string> cpy2(new_vec);
		print_vec_info(cpy2);
	}
}

void
test_vector_modifiers_assign_range_empty_src()
{
	ft::vector<std::string> vec;
	ft::vector<std::string> new_vec;
	ft::vector<std::string>::iterator it = new_vec.begin();

	new_vec.assign(vec.begin(), vec.end());
	print_vec_info(vec);
	print_vec_info(new_vec);

	ft::vector<std::string>::iterator new_it = new_vec.begin();
	if (&*it != &*new_it)
	{
		std::cout << "Reallocation occurred" << std::endl;
	}

	{
		ft::vector<std::string> cpy1 = new_vec;
		print_vec_info(cpy1);
		ft::vector<std::string> cpy2(new_vec);
		print_vec_info(cpy2);
	}
}

void
test_vector_modifiers_assign_range_wrong_iterators()
{
	ft::vector<std::string> vec;
	ft::vector<std::string> new_vec;

	new_vec.assign(vec.end(), vec.begin());
	print_vec_info(vec);
	print_vec_info(new_vec);
}

void
test_vector_modifiers_assign_fill_empty()
{
	ft::vector<std::string> vec;

	print_vec_info(vec);
	vec.assign(5, "42");
	print_vec_info(vec);
}

void
test_vector_modifiers_assign_fill1()
{
	ft::vector<std::string> vec(5, "test");

	print_vec_info(vec);
	vec.assign(0, "42");
	print_vec_info(vec);
}

void
test_vector_modifiers_assign_fill2()
{
	ft::vector<std::string> vec(10, "test");

	print_vec_info(vec);
	vec.assign(10, "42");
	print_vec_info(vec);
}

void
test_vector_modifiers_assign_fill3()
{
	ft::vector<std::string> vec(10, "test");

	print_vec_info(vec);
	vec.assign(20, "42");
	print_vec_info(vec);
}

void
test_vector_modifiers_assign_cplusplus()
{
	ft::vector<int> first;
	ft::vector<int> second;
	ft::vector<int> third;

	first.assign(7, 100);             // 7 ints with a value of 100

	ft::vector<int>::iterator it;
	it = first.begin() + 1;

	second.assign(it, first.end() - 1); // the 5 central values of first

	int myints[] = {1776, 7, 4};
	third.assign(myints, myints + 3);   // assigning from array.

	std::cout << "Size of first: " << int (first.size()) << std::endl;
	std::cout << "Size of second: " << int (second.size()) << std::endl;
	std::cout << "Size of third: " << int (third.size()) << std::endl;
}

void
test_vector_modifiers_push_back1()
{
	srand(g_seed);

	ft::vector<int> vec;
	int const size = 1;

	vec.push_back(rand() % size - size / 2);
	print_vec_info(vec);
}

void
test_vector_modifiers_push_back()
{

	srand(g_seed);

	for (int i = 1; i < 100; i *= 10)
	{
		ft::vector<int> vec;

		for (int j = 0; j < i; j++)
		{
			vec.push_back(rand() % 100 - 100 / 2);
			print_vec_info(vec);
		}
	}
}

void
test_vector_modifiers_pop_back()
{
	ft::vector<std::string> vec(100, "test");

	while (!vec.empty())
	{
		print_vec_info(vec);
		vec.pop_back();
	}
}

void
test_vector_modifiers_insert_single_begin_w_realloc()
{
	ft::vector<std::string> vec(100, "test");
	ft::vector<std::string>::iterator tmp;

	print_vec_info(vec);
	tmp = vec.insert(vec.begin(), "42");
	print_vec_info(vec);

	if (vec.begin() == tmp)
		std::cout << "valid" << std::endl;

	ft::vector<std::string> empty;

	print_vec_info(empty);
	tmp = empty.insert(empty.begin(), "42");
	print_vec_info(empty);

	if (tmp == empty.begin())
		std::cout << "valid" << std::endl;

	{
		ft::vector<std::string> cpy1 = vec;
		ft::vector<std::string> cpy2 = empty;
	}
}

void
test_vector_modifiers_insert_single_begin_wo_realloc()
{
	ft::vector<std::string> vec(100, "test");
	ft::vector<std::string>::iterator tmp;

	vec.reserve(101);

	print_vec_info(vec);
	tmp = vec.insert(vec.begin(), "42");
	print_vec_info(vec);

	if (vec.begin() == tmp)
		std::cout << "valid" << std::endl;

	ft::vector<std::string> empty;

	vec.reserve(1);

	print_vec_info(empty);
	tmp = empty.insert(empty.begin(), "42");
	print_vec_info(empty);

	if (tmp == empty.begin())
		std::cout << "valid" << std::endl;

	{
		ft::vector<std::string> cpy1 = vec;
		ft::vector<std::string> cpy2 = empty;
	}
}

void
test_vector_modifiers_insert_single_middle_w_realloc()
{
	ft::vector<std::string> vec(100, "test");
	ft::vector<std::string>::iterator it = vec.begin();
	ft::vector<std::string>::iterator tmp;

	print_vec_info(vec);
	tmp = vec.insert(it + 50, "42");
	print_vec_info(vec);

	it = vec.begin();
	if (tmp == it + 50)
		std::cout << "valid" << std::endl;

	{
		ft::vector<std::string> cpy1 = vec;
	}
}

void
test_vector_modifiers_insert_single_middle_wo_realloc()
{
	ft::vector<std::string> vec(100, "test");
	ft::vector<std::string>::iterator it = vec.begin();
	ft::vector<std::string>::iterator tmp;

	vec.reserve(101);

	print_vec_info(vec);
	it = vec.begin();
	tmp = vec.insert(it + 50, "42");
	print_vec_info(vec);

	it = vec.begin();
	if (tmp == it + 50)
		std::cout << "valid" << std::endl;

	{
		ft::vector<std::string> cpy1 = vec;
	}
}

void
test_vector_modifiers_insert_single_end_w_realloc()
{
	ft::vector<std::string> vec(100, "test");
	ft::vector<std::string>::iterator it = vec.end();
	ft::vector<std::string>::iterator tmp;

	print_vec_info(vec);
	tmp = vec.insert(it, "42");
	print_vec_info(vec);

	it = vec.begin();
	if (tmp == it + 100)
		std::cout << "valid" << std::endl;

	{
		ft::vector<std::string> cpy1 = vec;
	}
}

void
test_vector_modifiers_insert_single_end_wo_realloc()
{
	ft::vector<std::string> vec(100, "test");
	ft::vector<std::string>::iterator it;
	ft::vector<std::string>::iterator tmp;

	vec.reserve(101);

	print_vec_info(vec);
	it = vec.end();
	tmp = vec.insert(it, "42");
	print_vec_info(vec);

	it = vec.end();
	if (tmp == it)
		std::cout << "valid" << std::endl;

	{
		ft::vector<std::string> cpy1 = vec;
	}
}

void
test_vector_modifiers_insert_fill_begin_w_realloc()
{
	ft::vector<std::string> vec(100, "test");

	print_vec_info(vec);
	vec.insert(vec.begin(), 5, "42");
	print_vec_info(vec);

	ft::vector<std::string> empty;

	print_vec_info(empty);
	empty.insert(empty.begin(), 5, "42");
	print_vec_info(empty);

	{
		ft::vector<std::string> cpy1 = vec;
		ft::vector<std::string> cpy2 = empty;
	}
}

void
test_vector_modifiers_insert_cplusplus()
{
	ft::vector<int> myvector (3, 100);
	ft::vector<int>::iterator it;

	it = myvector.begin();
	it = myvector.insert(it, 200);

	myvector.insert(it, 2, 300);

	// "it" no longer valid, get a new one:
	it = myvector.begin();

	ft::vector<int> anothervector(2, 400);
	myvector.insert(it + 2, anothervector.begin(), anothervector.end());

	int myarray[] = {501, 502, 503};
	myvector.insert(myvector.begin(), myarray, myarray + 3);

	std::cout << "myvector contains:";
	for (it = myvector.begin(); it < myvector.end(); it++)
		std::cout << ' ' << *it;
	std::cout << std::endl;
}

void
test_vector_modifiers()
{
	test_wrapper(test_vector_modifiers_assign_range_empty_dest, "assign range empty dest");
	test_wrapper(test_vector_modifiers_assign_range_not_empty_dest1, "assign range not empty dest 1");
	test_wrapper(test_vector_modifiers_assign_range_not_empty_dest2, "assign range not empty dest 2");
	test_wrapper(test_vector_modifiers_assign_range_not_empty_dest3, "assign range not empty dest 3");
	test_wrapper(test_vector_modifiers_assign_range_empty_src, "assign range empty src");
	test_wrapper(test_vector_modifiers_assign_range_wrong_iterators, "assign range wrong iterators");
	test_wrapper(test_vector_modifiers_assign_fill_empty, "assign fill empty");
	test_wrapper(test_vector_modifiers_assign_fill1, "assign fill1");
	test_wrapper(test_vector_modifiers_assign_fill2, "assign fill2");
	test_wrapper(test_vector_modifiers_assign_fill3, "assign fill3");
	test_wrapper(test_vector_modifiers_assign_cplusplus, "assign cplusplus");
	test_wrapper(test_vector_modifiers_push_back1, "push back size 1");
	test_wrapper(test_vector_modifiers_push_back, "push back");
	test_wrapper(test_vector_modifiers_pop_back, "pop back");
	test_wrapper(test_vector_modifiers_insert_single_begin_w_realloc, "insert single begin with realloc");
	test_wrapper(test_vector_modifiers_insert_single_begin_wo_realloc, "insert single begin without realloc");
	test_wrapper(test_vector_modifiers_insert_single_middle_w_realloc, "insert single middle with realloc");
	test_wrapper(test_vector_modifiers_insert_single_middle_wo_realloc, "insert single middle without realloc");
	test_wrapper(test_vector_modifiers_insert_single_end_w_realloc, "insert single end with realloc");
	test_wrapper(test_vector_modifiers_insert_single_end_wo_realloc, "insert single end without realloc");
	test_wrapper(test_vector_modifiers_insert_fill_begin_w_realloc, "insert fill begin with realloc");
	//test_wrapper(test_vector_modifiers_insert_cplusplus, "insert cplusplus");
}
