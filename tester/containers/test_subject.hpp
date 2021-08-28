/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_subject.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 10:10:15 by dda-silv          #+#    #+#             */
/*   Updated: 2021/08/28 09:48:29 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_SUBJECT_HPP
# define TEST_SUBJECT_HPP

# include <iostream>	// std::cout
# include <exception>	// std::exception
# include <string>		// std::string
# include <deque>		// std::deque
# include <stdlib.h>	// EXIT_FAILURE, EXIT_SUCCESS, rand(), srand()

# include "containers.hpp"
# include "main.hpp"

# define MAX_RAM 4294967296
# define BUFFER_SIZE 4096

struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};

# define COUNT (MAX_RAM / (int)sizeof(Buffer))

template<typename T>
class MutantStack : public ft::stack<T>
{
public:
	MutantStack() {}
	MutantStack(const MutantStack<T>& src) { *this = src; }
	MutantStack<T>& operator=(const MutantStack<T>& rhs)
	{
		this->c = rhs.c;
		return *this;
	}
	~MutantStack() {}

	typedef typename ft::stack<T>::container_type::iterator iterator;

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
};

void test_subject();

#endif
