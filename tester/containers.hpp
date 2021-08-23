/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   containers.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 10:52:50 by dda-silv          #+#    #+#             */
/*   Updated: 2021/08/23 22:39:40 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTAINERS_HPP
# define CONTAINERS_HPP

# include <iostream>	// std::cout
# include <string>		// std::string
# include <typeinfo>	// std::typeid
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
	#  include "vector.hpp"
	#  include "iterator_traits.hpp"
	#  include "reverse_iterator.hpp"
	#  include "distance.hpp"
	#  include "enable_if.hpp"
	#  include "is_integral.hpp"
	#  include "is_const.hpp"
# endif

#endif
