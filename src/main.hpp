/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 10:52:50 by dda-silv          #+#    #+#             */
/*   Updated: 2021/08/19 10:58:10 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HPP
# define MAIN_HPP

# include <iostream>	// std::cout
# include <string>		// std::string
# include <typeinfo>	// std::typeid
# include <deque>		// std::deque
# include <stdlib.h>	// EXIT_FAILURE, EXIT_SUCCESS, rand(), srand()

# ifdef IS_TEST
	#  include <map>			// std::map
	#  include <stack>			// std::stack
	#  include <vector>			// std::vector
	#  include <iterator>		// std::iterator_traits, std::reverse_iterator
	namespace ft = std;
# else
	//#  include "map.hpp"
	//#  include "stack.hpp"
	#  include "containers/vector.hpp"
	#  include "iterators/iterator_traits.hpp"
	#  include "iterators/reverse_iterator.hpp"
	#  include "utils/distance.hpp"
	#  include "utils/enable_if.hpp"
	#  include "utils/is_integral.hpp"
	#  include "utils/is_const.hpp"
# endif

# define MAX_RAM 4294967296
# define BUFFER_SIZE 4096

struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};

# define COUNT (MAX_RAM / (int)sizeof(Buffer))

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
