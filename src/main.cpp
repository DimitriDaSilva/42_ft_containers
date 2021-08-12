/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 11:06:15 by dda-silv          #+#    #+#             */
/*   Updated: 2021/08/12 12:09:46 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

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
	return EXIT_SUCCESS;
}

void test_vector_capacity(void) {
	std::cout << "*** test_vector_capacity ***" << std::endl;

	ft::vector<int> vector;

	std::cout << vector.size() << std::endl;
	std::cout << vector.empty() << std::endl;

	vector.push_back(4);
	vector.push_back(2);

	std::cout << vector.size() << std::endl;
	std::cout << vector.empty() << std::endl;
	std::cout << vector.capacity() << std::endl;
	std::cout << vector.max_size() << std::endl;

	vector.resize(1);

	std::cout << vector.size() << std::endl;
	std::cout << vector.capacity() << std::endl;

	for (int i = 0; i < 50; i++) {
		vector.push_back(i);
	}

	std::cout << vector.size() << std::endl;
	std::cout << vector.capacity() << std::endl;

	vector.resize(20);
	vector.reserve(20);
	vector.reserve(0);

	try {
		vector.reserve(vector.max_size() + 1);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << vector.size() << std::endl;
	std::cout << vector.capacity() << std::endl;
}

void test_vector_iterators(void) {
	std::cout << "*** test_vector_iterators ***" << std::endl;

	typedef ft::vector<int>::iterator iterator;
	typedef ft::vector<int>::const_iterator const_iterator;

	ft::vector<int> vec;

	iterator begin;
	iterator end;

	begin = vec.begin();
	end = vec.end();

	for (int i = 0; i < 10; i++) {
		vec.push_back(rand() % 100);
	}

	for (iterator it = vec.begin(); it != vec.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	ft::vector<int> const_vec;

	for (int i = 0; i < 10; i++) {
		const_vec.push_back(rand() % 100);
	}

	const_iterator cbegin = const_vec.begin();

	//for (const_iterator it = const_vec.begin(); it != const_vec.end(); it++) {
		//std::cout << *it << " ";
	//}
	std::cout << std::endl;
}

void test_utils_iterator_traits(void) {
	std::cout << "*** test_utils_iterator_traits ***" << std::endl;

	typedef ft::iterator_traits<ft::vector<int>::iterator > t1;

	if (typeid(t1::iterator_category) == typeid(std::random_access_iterator_tag)) {
		std::cout << "ft::vector<int> is a random-access iterator" << std::endl;
	}

	if (typeid(t1::value_type) == typeid(int)) {
		std::cout << "ft::vector<int> has a value_type of int" << std::endl;
	}

	typedef ft::iterator_traits<ft::vector<int>::const_iterator > t2;

	if (typeid(t2::iterator_category) == typeid(std::random_access_iterator_tag)) {
		std::cout << "ft::vector<int> is a random-access iterator" << std::endl;
	}

	if (typeid(t2::value_type) == typeid(const int)) {
		std::cout << "ft::vector<int> has a value_type of const int" << std::endl;
	}

	if (std::is_same<t2::value_type, const int *>::value) {
		std::cout << "t2 has pointer const int *" << std::endl;
	} else {
		std::cout << "t2 has pointer int *" << std::endl;
	}
}

int main(int argc, char* argv[]) {
	if (test_subject(argc, argv) != EXIT_SUCCESS) {
		return (EXIT_FAILURE);
	}
	test_vector_capacity();
	test_vector_iterators();
	test_utils_iterator_traits();

	return (EXIT_SUCCESS);
}
