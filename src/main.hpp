/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 10:52:50 by dda-silv          #+#    #+#             */
/*   Updated: 2021/08/12 17:12:37 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HPP
# define MAIN_HPP

#include <iostream>
#include <string>
#include <typeinfo>
#include <deque>
#ifdef IS_TEST
	#include <map>
	#include <stack>
	#include <vector>
	#include <iterator>
	#include <type_traits>
	namespace ft = std;
#else
	//#include "map.hpp"
	//#include "stack.hpp"
	#include "containers/vector.hpp"
	#include "utils/enable_if.hpp"
	#include "utils/is_integral.hpp"
	#include "utils/iterator_traits.hpp"
#endif

#include <stdlib.h>
#include <unistd.h>

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096
struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};

#define COUNT (MAX_RAM / (int)sizeof(Buffer))

//template<typename T>
//class MutantStack : public ft::stack<T>
//{
//public:
	//MutantStack() {}
	//MutantStack(const MutantStack<T>& src) { *this = src; }
	//MutantStack<T>& operator=(const MutantStack<T>& rhs) 
	//{
		//this->c = rhs.c;
		//return *this;
	//}
	//~MutantStack() {}

	//typedef typename ft::stack<T>::container_type::iterator iterator;

	//iterator begin() { return this->c.begin(); }
	//iterator end() { return this->c.end(); }
//};

#endif
