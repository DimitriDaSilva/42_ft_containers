/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_containers_info.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 10:07:40 by dda-silv          #+#    #+#             */
/*   Updated: 2021/09/06 19:22:42 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_VEC_INFO_HPP
# define PRINT_VEC_INFO_HPP

# include <iostream>	// std::cout

# include "containers.hpp"

template<typename Vector>
void print_vec_info(Vector const& vec) {
	std::cout << "Size: " << vec.size() << std::endl;
	std::cout << "Capacity: " << vec.capacity() << std::endl;

	if (vec.empty()) {
		std::cout << "Vector is empty" << std::endl;
	} else {
		std::cout << "Values: ";
		for (typename Vector::const_iterator it = vec.begin(); it != vec.end(); it++) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}
}

template<typename Set>
void
print_set_info(Set const& set)
{
	std::cout << "Size: " << set.size() << std::endl;

	if (set.empty()) {
		std::cout << "Set is empty" << std::endl;
	} else {
		std::cout << "Values: ";
		for (typename Set::const_iterator it = set.begin(); it != set.end(); it++) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}
}


#endif
