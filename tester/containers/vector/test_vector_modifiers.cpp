/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector_modifiers.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 10:33:35 by dda-silv          #+#    #+#             */
/*   Updated: 2021/08/25 17:39:08 by dda-silv         ###   ########.fr       */
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
		std::cout << "Reallocation occurred" << std::endl;

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
		std::cout << "Reallocation occurred" << std::endl;

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
		std::cout << "Reallocation occurred" << std::endl;

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
		std::cout << "Reallocation occurred" << std::endl;

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
		std::cout << "Reallocation occurred" << std::endl;

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
test_vector_modifiers_insert_fill_begin_wo_realloc()
{
	ft::vector<std::string> vec(100, "test");

	vec.reserve(105);

	print_vec_info(vec);
	vec.insert(vec.begin(), 5, "42");
	print_vec_info(vec);

	ft::vector<std::string> empty;

	empty.reserve(5);

	print_vec_info(empty);
	empty.insert(empty.begin(), 5, "42");
	print_vec_info(empty);

	{
		ft::vector<std::string> cpy1 = vec;
		ft::vector<std::string> cpy2 = empty;
	}
}

void
test_vector_modifiers_insert_fill_middle_w_realloc()
{
	ft::vector<std::string> vec(100, "test");

	print_vec_info(vec);
	vec.insert(vec.begin() + 50, 5, "42");
	print_vec_info(vec);

	{
		ft::vector<std::string> cpy1 = vec;
	}
}

void
test_vector_modifiers_insert_fill_middle_wo_realloc()
{
	ft::vector<std::string> vec(100, "test");

	vec.reserve(105);

	print_vec_info(vec);
	vec.insert(vec.begin() + 50, 5, "42");
	print_vec_info(vec);

	{
		ft::vector<std::string> cpy1 = vec;
	}
}

void
test_vector_modifiers_insert_fill_end_w_realloc()
{
	ft::vector<std::string> vec(100, "test");

	print_vec_info(vec);
	vec.insert(vec.end(), 5, "42");
	print_vec_info(vec);

	{
		ft::vector<std::string> cpy1 = vec;
	}
}

void
test_vector_modifiers_insert_fill_end_wo_realloc()
{
	ft::vector<std::string> vec(100, "test");

	vec.reserve(105);

	print_vec_info(vec);
	vec.insert(vec.end(), 5, "42");
	print_vec_info(vec);

	{
		ft::vector<std::string> cpy1 = vec;
	}
}

void
test_vector_modifiers_insert_fill_extra()
{
	ft::vector<std::string> vec(1, "test");

	vec.reserve(6);

	print_vec_info(vec);
	vec.insert(vec.end(), 5, "42");
	print_vec_info(vec);

	{
		ft::vector<std::string> cpy1 = vec;
	}
}

void
test_vector_modifiers_insert_fill_middle_w_realloc_rand()
{
	ft::vector<int> vec;
	for (int i = 1; i <= 50; i++)
		vec.push_back(i);

	print_vec_info(vec);
	vec.insert(vec.begin() + 25, 5, 42);
	print_vec_info(vec);

	{
		ft::vector<int> cpy1 = vec;
	}
}

void
test_vector_modifiers_insert_fill_middle_wo_realloc_rand()
{
	ft::vector<int> vec;
	for (int i = 1; i <= 50; i++)
		vec.push_back(i);

	vec.reserve(55);

	print_vec_info(vec);
	vec.insert(vec.begin() + 25, 5, 42);
	print_vec_info(vec);

	{
		ft::vector<int> cpy1 = vec;
	}
}

void
test_vector_modifiers_insert_range_begin_w_realloc()
{
	ft::vector<int> vec_random;

	srand(g_seed);

	for (int i = 0; i < 50; i++)
		vec_random.push_back(rand() % 100 - 100 / 2);

	ft::vector<int> vec(50, 42);

	print_vec_info(vec);
	vec.insert(vec.begin(), vec_random.begin(), vec_random.end());
	print_vec_info(vec);

	ft::vector<int> empty;

	print_vec_info(empty);
	empty.insert(empty.begin(), vec_random.begin(), vec_random.end());
	print_vec_info(empty);

	{
		ft::vector<int> cpy1 = vec;
		ft::vector<int> cpy2 = empty;
	}
}

void
test_vector_modifiers_insert_range_begin_wo_realloc()
{
	ft::vector<int> vec_random;

	srand(g_seed);

	for (int i = 0; i < 50; i++)
		vec_random.push_back(rand() % 100 - 100 / 2);

	ft::vector<int> vec(50, 42);

	vec.reserve(100);

	print_vec_info(vec);
	vec.insert(vec.begin(), vec_random.begin(), vec_random.end());
	print_vec_info(vec);

	ft::vector<int> empty;

	vec.reserve(50);

	print_vec_info(empty);
	empty.insert(empty.begin(), vec_random.begin(), vec_random.end());
	print_vec_info(empty);

	{
		ft::vector<int> cpy1 = vec;
		ft::vector<int> cpy2 = empty;
	}
}

void
test_vector_modifiers_insert_range_middle_w_realloc()
{
	ft::vector<int> vec_random;

	srand(g_seed);

	for (int i = 0; i < 50; i++)
		vec_random.push_back(rand() % 100 - 100 / 2);

	ft::vector<int> vec;
	for (int i = 1; i <= 50; i++)
		vec.push_back(i);

	print_vec_info(vec);
	vec.insert(vec.begin() + 25, vec_random.begin(), vec_random.end());
	print_vec_info(vec);

	{
		ft::vector<int> cpy1 = vec;
	}
}

void
test_vector_modifiers_insert_range_middle_wo_realloc()
{
	ft::vector<int> vec_random;

	srand(g_seed);

	for (int i = 0; i < 50; i++)
		vec_random.push_back(rand() % 100 - 100 / 2);

	ft::vector<int> vec;
	for (int i = 1; i <= 50; i++)
		vec.push_back(i);

	vec.reserve(100);

	print_vec_info(vec);
	vec.insert(vec.begin() + 25, vec_random.begin(), vec_random.end());
	print_vec_info(vec);

	{
		ft::vector<int> cpy1 = vec;
	}
}

void
test_vector_modifiers_insert_range_end_w_realloc()
{
	ft::vector<int> vec_random;

	srand(g_seed);

	for (int i = 0; i < 50; i++)
		vec_random.push_back(rand() % 100 - 100 / 2);

	ft::vector<int> vec;
	for (int i = 1; i <= 50; i++)
		vec.push_back(i);

	print_vec_info(vec);
	vec.insert(vec.end(), vec_random.begin(), vec_random.end());
	print_vec_info(vec);

	{
		ft::vector<int> cpy1 = vec;
	}
}

void
test_vector_modifiers_insert_range_end_wo_realloc()
{
	ft::vector<int> vec_random;

	srand(g_seed);

	for (int i = 0; i < 50; i++)
		vec_random.push_back(rand() % 100 - 100 / 2);

	ft::vector<int> vec(50, 42);

	vec.reserve(100);

	print_vec_info(vec);
	vec.insert(vec.end(), vec_random.begin(), vec_random.end());
	print_vec_info(vec);

	{
		ft::vector<int> cpy1 = vec;
	}
}

void
test_vector_modifiers_insert_cplusplus()
{
	ft::vector<int> myvector(3, 100);
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
test_vector_modifiers_erase_single_begin()
{
	srand(g_seed);

	ft::vector<int> vec;
	ft::vector<int>::iterator it;

	for (int i = 0; i < 100; i++)
		vec.push_back(rand() % 100 - 100 / 2);

	print_vec_info(vec);
	it = vec.erase(vec.begin());
	print_vec_info(vec);

	if (it == vec.begin())
		std::cout << "valid" << std::endl;
}

void
test_vector_modifiers_erase_single_middle()
{
	srand(g_seed);

	ft::vector<int> vec;
	ft::vector<int>::iterator it;

	for (int i = 0; i < 100; i++)
		vec.push_back(rand() % 100 - 100 / 2);

	print_vec_info(vec);
	it = vec.erase(vec.begin() + 50);
	print_vec_info(vec);

	if (it == vec.begin() + 50)
		std::cout << "valid" << std::endl;
}

void
test_vector_modifiers_erase_single_end()
{
	srand(g_seed);

	ft::vector<int> vec;
	ft::vector<int>::iterator it;

	for (int i = 0; i < 100; i++)
		vec.push_back(rand() % 100 - 100 / 2);

	print_vec_info(vec);
	it = vec.erase(vec.end() - 1);
	print_vec_info(vec);

	if (it == vec.end())
		std::cout << "valid" << std::endl;
}


void
test_vector_modifiers_erase_single_string()
{
	ft::vector<std::string> vec(100, "42");
	ft::vector<std::string>::iterator it;


	print_vec_info(vec);
	it = vec.erase(vec.begin() + 50);
	print_vec_info(vec);

	if (it == vec.begin() + 50)
		std::cout << "valid" << std::endl;
}

void
test_vector_modifiers_erase_range_begin()
{
	srand(g_seed);

	ft::vector<int> vec;
	ft::vector<int>::iterator it;

	for (int i = 0; i < 100; i++)
		vec.push_back(rand() % 100 - 100 / 2);

	print_vec_info(vec);
	it = vec.erase(vec.begin(), vec.begin() + 50);
	print_vec_info(vec);

	if (it == vec.begin())
		std::cout << "valid" << std::endl;
}

void
test_vector_modifiers_erase_range_middle()
{
	srand(g_seed);

	ft::vector<int> vec;
	ft::vector<int>::iterator it;

	for (int i = 0; i < 100; i++)
		vec.push_back(rand() % 100 - 100 / 2);

	print_vec_info(vec);
	it = vec.erase(vec.begin() + 25, vec.begin() + 75);
	print_vec_info(vec);

	if (it == vec.begin() + 25)
		std::cout << "valid" << std::endl;
}

void
test_vector_modifiers_erase_range_end()
{
	srand(g_seed);

	ft::vector<int> vec;
	ft::vector<int>::iterator it;

	for (int i = 0; i < 100; i++)
		vec.push_back(rand() % 100 - 100 / 2);

	print_vec_info(vec);
	it = vec.erase(vec.begin() + 50, vec.end());
	print_vec_info(vec);

	if (it == vec.end())
		std::cout << "valid" << std::endl;
}

void
test_vector_modifiers_erase_range_string()
{
	ft::vector<std::string> vec(100, "42");
	ft::vector<std::string>::iterator it;

	print_vec_info(vec);
	it = vec.erase(vec.begin() + 25, vec.begin() + 75);
	print_vec_info(vec);

	if (it == vec.begin() + 25)
		std::cout << "valid" << std::endl;
}

void
test_vector_modifiers_erase_cplusplus()
{
	ft::vector<int> myvector;

	// set some values (from 1 to 10)
	for (int i = 1; i <= 10; i++)
		myvector.push_back(i);

	// erase the 6th element
	myvector.erase(myvector.begin() + 5);

	// erase the first 3 elements:
	myvector.erase(myvector.begin(), myvector.begin() + 3);

	std::cout << "myvector contains:";
	for (unsigned i = 0; i < myvector.size(); ++i)
		std::cout << ' ' << myvector[i];
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
	test_wrapper(test_vector_modifiers_insert_fill_begin_wo_realloc, "insert fill begin without realloc");
	test_wrapper(test_vector_modifiers_insert_fill_middle_w_realloc, "insert fill middle with realloc");
	test_wrapper(test_vector_modifiers_insert_fill_middle_wo_realloc, "insert fill middle without realloc");
	test_wrapper(test_vector_modifiers_insert_fill_end_w_realloc, "insert fill end with realloc");
	test_wrapper(test_vector_modifiers_insert_fill_end_wo_realloc, "insert fill end without realloc");
	test_wrapper(test_vector_modifiers_insert_fill_extra, "insert fill extra");
	test_wrapper(test_vector_modifiers_insert_fill_middle_w_realloc_rand, "insert fill middle with realloc rand ints");
	test_wrapper(test_vector_modifiers_insert_fill_middle_wo_realloc_rand, "insert fill middle without realloc rand ints");
	test_wrapper(test_vector_modifiers_insert_range_begin_w_realloc, "insert range begin with realloc");
	test_wrapper(test_vector_modifiers_insert_range_begin_wo_realloc, "insert range begin without realloc");
	test_wrapper(test_vector_modifiers_insert_range_middle_w_realloc, "insert range middle with realloc");
	test_wrapper(test_vector_modifiers_insert_range_middle_wo_realloc, "insert range middle without realloc");
	test_wrapper(test_vector_modifiers_insert_range_end_w_realloc, "insert range end with realloc");
	test_wrapper(test_vector_modifiers_insert_range_end_wo_realloc, "insert range end without realloc");
	test_wrapper(test_vector_modifiers_insert_cplusplus, "insert cplusplus");
	test_wrapper(test_vector_modifiers_erase_single_begin, "erase single begin");
	test_wrapper(test_vector_modifiers_erase_single_middle, "erase single middle");
	test_wrapper(test_vector_modifiers_erase_single_end, "erase single end");
	test_wrapper(test_vector_modifiers_erase_single_string, "erase single string");
	test_wrapper(test_vector_modifiers_erase_range_begin, "erase range begin");
	test_wrapper(test_vector_modifiers_erase_range_middle, "erase range middle");
	test_wrapper(test_vector_modifiers_erase_range_end, "erase range end");
	test_wrapper(test_vector_modifiers_erase_range_string, "erase range string");
	test_wrapper(test_vector_modifiers_erase_cplusplus, "erase cplusplus");
}
