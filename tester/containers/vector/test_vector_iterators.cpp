/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector_iterators.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 10:32:33 by dda-silv          #+#    #+#             */
/*   Updated: 2021/08/20 10:32:54 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_vector_iterators.hpp"

void test_vector_iterators(void) {
	std::cout << "*** test_vector_iterators ***" << std::endl;

	typedef ft::vector<int>::iterator iterator;
	typedef ft::vector<int>::const_iterator const_iterator;

	ft::vector<int> vec;
	ft::vector<int> const const_vec;

	// Testing getting iterator for an empty vector
	//if (vec.begin() == vec.end() && vec.rbegin() == vec.rend()) {
		//std::cout << "correct" << std::endl;
	//}
	if (const_vec.begin() == const_vec.end()) {
		std::cout << "correct" << std::endl;
	}

	// Testing iterator
	for (int i = 0; i < 10; i++) {
		vec.push_back(rand() % 100);
	}
	for (iterator it = vec.begin(); it != vec.end(); it++) {
		std::cout << *it << " ";
	}

	// Testing const_iterator
	for (const_iterator it = const_vec.begin(); it != const_vec.end(); it++) {
		std::cout << *it << " ";
	}

	// Testing copy constructor
	iterator it;
	const_iterator const_it(it);

	std::cout << std::endl;
}
