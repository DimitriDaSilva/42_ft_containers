/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_vec_info.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 10:07:40 by dda-silv          #+#    #+#             */
/*   Updated: 2021/08/22 10:20:40 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_VEC_INFO_HPP
# define PRINT_VEC_INFO_HPP

# include <iostream>	// std::cout

# include "containers.hpp"

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

#endif
