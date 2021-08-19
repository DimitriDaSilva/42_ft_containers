/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 11:06:15 by dda-silv          #+#    #+#             */
/*   Updated: 2021/08/19 17:26:11 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

template<typename Vector>
void print_vec_info(Vector vec) {
	std::cout << "Size: " << vec.size() << std::endl;
	std::cout << "Capacity: " << vec.capacity() << std::endl;

	if (vec.empty()) {
		std::cout << "Vector is empty" << std::endl;
	} else {
		std::cout << "Values: ";
		for (typename Vector::iterator it = vec.begin(); it != vec.end(); it++) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}
}

int test_subject(int argc, char* argv[]) {
	std::cout << "*** test_subject ***" << std::endl;

	if (argc != 2)
	{
		std::cerr << "Usage: ./test seed" << std::endl;
		std::cerr << "Provide a seed please" << std::endl;
		std::cerr << "Count value:" << COUNT << std::endl;
		return EXIT_FAILURE;
	}
	const int seed = atoi(argv[1]);
	srand(seed);

	ft::vector<std::string> vector_str;
	ft::vector<int> vector_int;
	//ft::stack<int> stack_int;
	ft::vector<Buffer> vector_buffer;
	//ft::stack<Buffer, std::deque<int> > stack_deq_buffer;
	//ft::map<int, int> map_int;

	for (int i = 0; i < COUNT; i++)
	{
		vector_buffer.push_back(Buffer());
	}

	//for (int i = 0; i < COUNT; i++)
	//{
		//const int idx = rand() % COUNT;
		//vector_buffer[idx].idx = 5;
	//}
	//ft::vector<Buffer>().swap(vector_buffer);

	//try
	//{
		//for (int i = 0; i < COUNT; i++)
		//{
			//const int idx = rand() % COUNT;
			//vector_buffer.at(idx);
			//std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
		//}
	//}
	//catch(const std::exception& e)
	//{
		////NORMAL ! :P
	//}

	//for (int i = 0; i < COUNT; ++i)
	//{
		//map_int.insert(ft::make_pair(rand(), rand()));
	//}

	//int sum = 0;
	//for (int i = 0; i < 10000; i++)
	//{
		//int access = rand();
		//sum += map_int[access];
	//}
	//std::cout << "should be constant with the same seed: " << sum << std::endl;

	//{
		//ft::map<int, int> copy = map_int;
	//}
	//MutantStack<char> iterable_stack;
	//for (char letter = 'a'; letter <= 'z'; letter++)
		//iterable_stack.push(letter);
	//for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
	//{
		//std::cout << *it;
	//}
	//std::cout << std::endl;
	std::cout << std::endl;
	return EXIT_SUCCESS;
}

void test_vector_constructors(void) {
	std::cout << "*** test_vector_constructors ***" << std::endl;

	// Test empty (default constructor)
	ft::vector<int> vec_empty;

	print_vec_info(vec_empty);

	// Test fill
	ft::vector<int> vec_fill(6, 42);

	print_vec_info(vec_fill);

	std::cout << std::endl;

	// Because fill constructor only allocates exact needed memory
	// we test if push_back triggers same memory allocation as std
	vec_fill.push_back(4);

	print_vec_info(vec_fill);

	// Test range
	ft::vector<int> vec_range(vec_fill.begin(), vec_fill.end());

	print_vec_info(vec_range);

	std::cout << std::endl;
}

void test_vector_capacity(void) {
	std::cout << "*** test_vector_capacity ***" << std::endl;

	ft::vector<int> vec;

	print_vec_info(vec);
	std::cout << "Max size: " << vec.max_size() << std::endl;

	//vec.push_back(4);
	//vec.push_back(2);

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

void test_vector_iterators(void) {
	std::cout << "*** test_vector_iterators ***" << std::endl;

	typedef ft::vector<int>::iterator iterator;
	typedef ft::vector<int>::const_iterator const_iterator;

	ft::vector<int> vec;
	ft::vector<int> const const_vec;

	// Testing getting iterator for an empty vector
	//if (vec.begin() == vec.end() && vec.rbegin() == vec.rend()) {
		//std::cout << "correct" << std::endl;
	//}
	if (const_vec.begin() == const_vec.end()) {
		std::cout << "correct" << std::endl;
	}

	// Testing iterator
	for (int i = 0; i < 10; i++) {
		vec.push_back(rand() % 100);
	}
	for (iterator it = vec.begin(); it != vec.end(); it++) {
		std::cout << *it << " ";
	}

	// Testing const_iterator
	for (const_iterator it = const_vec.begin(); it != const_vec.end(); it++) {
		std::cout << *it << " ";
	}

	// Testing copy constructor
	iterator it;
	const_iterator const_it(it);

	std::cout << std::endl;
}

void test_vector_modifiers(void) {
	std::cout << "*** test_vector_modifiers ***" << std::endl;

	// Test assign range
	//ft::vector<int> vec(5, 42);
	//ft::vector<int> new_vec;

	//new_vec.assign(vec.begin(), vec.end());
}

template<
	typename it,
	typename diff_type,
	typename value_types,
	typename ptr,
	typename ref,
	typename cat
	>
void test_single_iterator_traits(void) {
	if (!(typeid(typename it::difference_type) == typeid(diff_type))) {
		std::cout << "difference_type invalid" << std::endl;
	} else if (!(typeid(typename it::value_type) == typeid(value_types))) {
		std::cout << "value_type invalid" << std::endl;
	} else if (!(typeid(typename it::pointer) == typeid(ptr))) {
		std::cout << "pointer invalid" << std::endl;
	} else if (!(typeid(typename it::reference) == typeid(ref))) {
		std::cout << "reference invalid" << std::endl;
	} else if (!(typeid(typename it::iterator_category) == typeid(cat))) {
		std::cout << "iterator_category invalid" << std::endl;
	} else {
		std::cout << "all valid" << std::endl;
	}
}

void test_iterator_traits(void) {
	std::cout << "*** test_utils_iterator_traits ***" << std::endl;

	test_single_iterator_traits<
		ft::iterator_traits<ft::vector<int>::iterator>,
		std::ptrdiff_t,
		int,
		int*,
		int&,
		std::random_access_iterator_tag>();
	test_single_iterator_traits<
		ft::iterator_traits<ft::vector<std::string>::iterator>,
		std::ptrdiff_t,
		std::string,
		std::string*,
		std::string&,
		std::random_access_iterator_tag>();
	test_single_iterator_traits<
		ft::iterator_traits<ft::vector<char>::iterator>,
		std::ptrdiff_t,
		char,
		char*,
		char&,
		std::random_access_iterator_tag>();

	std::cout << std::endl;
}

void test_reverse_iterator(void) {
	std::cout << "*** test_reverse_iterator ***" << std::endl;

	//ft::vector<int> v = { 0, 1, 2, 3, 4, 5 };
	//typedef ft::reverse_iterator<ft::vector<int>::iterator> rev_it;

	//ft::vector<int> vec;
}

template<typename T>
void test_single_is_integral(std::string const& type_tested) {
	int value = ft::is_integral<T>::value;
	typedef typename ft::is_integral<T>::value_type value_type;
	typedef typename ft::is_integral<T>::type type;

	if (value
			&& typeid(value_type) == typeid(bool)
			&& typeid(type) == typeid(ft::true_type)
			&& ft::is_integral<T>() == value) {
		std::cout << type_tested << " is integral" << std::endl;
	} else {
		std::cout << type_tested << " is not integral" << std::endl;
	}
}

void test_is_integral(void) {
	std::cout << "*** test_utils_is_integral ***" << std::endl;

	// correct ones
	test_single_is_integral<bool>("bool");
	test_single_is_integral<char>("char");
	test_single_is_integral<wchar_t>("wchar_t");
	test_single_is_integral<signed char>("signed char");
	test_single_is_integral<short int>("short int");
	test_single_is_integral<long int>("long int");
	test_single_is_integral<long long int>("long long int");
	test_single_is_integral<unsigned char>("unsigned char");
	test_single_is_integral<unsigned short int>("unsigned short int");
	test_single_is_integral<unsigned int>("unsigned int");
	test_single_is_integral<unsigned long int>("unsigned long int");
	test_single_is_integral<unsigned long long int>("unsigned long long int");

	// wrong ones
	test_single_is_integral<int *>("int *");
	test_single_is_integral<std::string>("std::string");
	test_single_is_integral<char *>("char *");

	std::cout << std::endl;
}

void test_other_utils(void) {
	std::cout << "*** test_other_utils ***" << std::endl;

	std::cout << ft::is_const<int>::value << std::endl
		<< ft::is_const<int const>::value << std::endl
		<< ft::is_const<char>::value << std::endl
		<< ft::is_const<char const>::value << std::endl;

	ft::vector<int> vec(5, 42);

	std::cout << vec.end() - vec.begin() << std::endl;
	std::cout << ft::distance<ft::vector<int>::iterator>(vec.begin(), vec.end()) << std::endl;

	std::cout << std::endl;
}

int main(int argc, char* argv[]) {
	if (test_subject(argc, argv) != EXIT_SUCCESS) {
		return (EXIT_FAILURE);
	}
	test_vector_constructors();
	test_vector_capacity();
	test_vector_iterators();
	test_vector_modifiers();
	test_iterator_traits();
	test_reverse_iterator();
	test_is_integral();
	test_other_utils();

	return (EXIT_SUCCESS);
}
