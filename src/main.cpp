/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 11:06:15 by dda-silv          #+#    #+#             */
/*   Updated: 2021/08/08 15:11:49 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int main(int argc, char* argv[]) {
	if (argc != 2)
	{
		std::cerr << "Usage: ./test seed" << std::endl;
		std::cerr << "Provide a seed please" << std::endl;
		std::cerr << "Count value:" << COUNT << std::endl;
		return 1;
	}
	const int seed = atoi(argv[1]);
	srand(seed);

	usleep(3 * 1000 * 1000);

	ft::vector<std::string> vector_str;
	ft::vector<int> vector_int;
	//ft::stack<int> stack_int;
	ft::vector<Buffer> vector_buffer;
	//ft::stack<Buffer, std::deque<int> > stack_deq_buffer;
	//ft::map<int, int> map_int;

	//for (int i = 0; i < COUNT; i++)
	//{
		//vector_buffer.push_back(Buffer());
	//}

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
	return (0);
}
