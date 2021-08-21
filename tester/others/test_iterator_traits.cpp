/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_iterator_traits.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 10:36:33 by dda-silv          #+#    #+#             */
/*   Updated: 2021/08/21 22:40:37 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_iterator_traits.hpp"

template<
	typename it,
	typename diff_type,
	typename value_types,
	typename ptr,
	typename ref,
	typename cat
	>
void
test_single_iterator_traits()
{
	if (!(typeid(typename it::difference_type) == typeid(diff_type))) {
		std::cout << "difference_type invalid" << std::endl;
	} else if (!(typeid(typename it::value_type) == typeid(value_types))) {
		std::cout << "value_type invalid" << std::endl;
	} else if (!(typeid(typename it::pointer) == typeid(ptr))) {
		std::cout << "pointer invalid" << std::endl;
	} else if (!(typeid(typename it::reference) == typeid(ref))) {
		std::cout << "reference invalid" << std::endl;
	} else if (!(typeid(typename it::iterator_category) == typeid(cat))) {
		std::cout << "iterator_category invalid" << std::endl;
	} else {
		std::cout << "all valid" << std::endl;
	}
}

void
test_iterator_traits()
{
	test_single_iterator_traits<
		ft::iterator_traits<ft::vector<int>::iterator>,
		std::ptrdiff_t,
		int,
		int*,
		int&,
		std::random_access_iterator_tag>();
	test_single_iterator_traits<
		ft::iterator_traits<ft::vector<std::string>::iterator>,
		std::ptrdiff_t,
		std::string,
		std::string*,
		std::string&,
		std::random_access_iterator_tag>();
	test_single_iterator_traits<
		ft::iterator_traits<ft::vector<char>::iterator>,
		std::ptrdiff_t,
		char,
		char*,
		char&,
		std::random_access_iterator_tag>();
}

