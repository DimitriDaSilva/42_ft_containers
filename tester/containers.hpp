/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   containers.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 10:52:50 by dda-silv          #+#    #+#             */
/*   Updated: 2021/08/30 10:52:45 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTAINERS_HPP
# define CONTAINERS_HPP

# include <iostream>	// std::cout
# include <string>		// std::string
# include <typeinfo>	// std::typeid
# include <stdlib.h>	// EXIT_FAILURE, EXIT_SUCCESS, rand(), srand()
# include <deque>		// std::deque
# include <list>		// std::list

# ifdef IS_TEST
	#  include <map>			// std::map
	#  include <stack>			// std::stack
	#  include <vector>			// std::vector
	#  include <iterator>		// std::iterator_traits, std::reverse_iterator
	#  include <algorithm>		// std::equal, std::lexicographical_compare
	# include <utility>			// std::pair, std::make_pair
	namespace ft = std;
# else
	//#  include "map.hpp"
	#  include "stack.hpp"
	#  include "vector.hpp"
	#  include "iterator_traits.hpp"
	#  include "reverse_iterator.hpp"
	#  include "distance.hpp"
	#  include "enable_if.hpp"
	#  include "is_integral.hpp"
	#  include "is_const.hpp"
	#  include "equal.hpp"
	#  include "pair.hpp"
	#  include "lexicographical_compare.hpp"
# endif

#endif
