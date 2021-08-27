/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 15:22:11 by dda-silv          #+#    #+#             */
/*   Updated: 2021/08/27 19:31:35 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_stack.hpp"

void
test_stack_constructors()
{
	std::deque<int> mydeque(3, 100);
	std::list<int> mylist(3, 100);
	ft::vector<int> myvector(2, 200);

	ft::stack<int> first;
	ft::stack<int, std::deque<int> > second(mydeque);

	ft::stack<int, std::deque<int> > third;
	ft::stack<int, ft::vector<int> > fourth(myvector);
	ft::stack<int, std::list<int> > fifht(mylist);
}

void
test_stack_empty()
{
	ft::vector<int> vec(5, 42);
	ft::stack<int, ft::vector<int> > stack(vec);
	ft::stack<int> empty;

	if (!stack.empty())
		std::cout << "Valid" << std::endl;
	if (empty.empty())
		std::cout << "Valid" << std::endl;
}

void
test_stack_size()
{
	ft::vector<int> vec(5, 42);
	ft::stack<int, ft::vector<int> > stack(vec);
	ft::stack<int> empty;

	std::cout << stack.size() << std::endl;
	std::cout << empty.size() << std::endl;
}

void
test_stack_top()
{
	ft::vector<int> vec;

	for (int i = 0; i < 100; i++) vec.push_back(i);

	ft::stack<int, ft::vector<int> > stack(vec);

	std::cout << stack.top() << std::endl;
	stack.top() = 42;
	std::cout << stack.top() << std::endl;
}

void
test_stack_push_pop()
{
	ft::stack<int> stack;

	for (int i = 0; i < 5; i++)
	{
		stack.push(i);
		std::cout << stack.top() << std::endl;
	}

	std::cout << "Popping out elements...";
	while (!stack.empty())
	{
		std::cout << stack.top() << std::endl;
		stack.pop();
	}
}

void
test_stack_relational_operators()
{
	ft::stack<int, ft::vector<int> > stack1;
	ft::stack<int, ft::vector<int> > stack2;

	for (int i = 0; i < 10; i++) stack1.push(i);
	for (int i = 0; i < 5; i++) stack2.push(i);

	std::cout << (stack1 == stack2) << std::endl;
	std::cout << (stack1 != stack2) << std::endl;
	std::cout << (stack1 < stack2) << std::endl;
	std::cout << (stack1 <= stack2) << std::endl;
	std::cout << (stack1 > stack2) << std::endl;
	std::cout << (stack1 >= stack2) << std::endl;
}

void
test_stack()
{
	test_wrapper(test_stack_constructors, "stack_constructors");
	test_wrapper(test_stack_empty, "stack_empty");
	test_wrapper(test_stack_size, "stack_size");
	test_wrapper(test_stack_top, "stack_top");
	test_wrapper(test_stack_push_pop, "stack_push & pop");
	test_wrapper(test_stack_relational_operators, "stack_relational_operators");
}
