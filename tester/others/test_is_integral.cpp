/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_is_integral.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 10:39:08 by dda-silv          #+#    #+#             */
/*   Updated: 2021/08/20 10:39:30 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_is_integral.hpp"

template<typename T>
void test_single_is_integral(std::string const& type_tested) {
	int value = ft::is_integral<T>::value;
	typedef typename ft::is_integral<T>::value_type value_type;
	typedef typename ft::is_integral<T>::type type;

	if (value
			&& typeid(value_type) == typeid(bool)
			&& typeid(type) == typeid(ft::true_type)
			&& ft::is_integral<T>() == value) {
		std::cout << type_tested << " is integral" << std::endl;
	} else {
		std::cout << type_tested << " is not integral" << std::endl;
	}
}

void test_is_integral(void) {
	std::cout << "*** test_utils_is_integral ***" << std::endl;

	// correct ones
	test_single_is_integral<bool>("bool");
	test_single_is_integral<char>("char");
	test_single_is_integral<wchar_t>("wchar_t");
	test_single_is_integral<signed char>("signed char");
	test_single_is_integral<short int>("short int");
	test_single_is_integral<long int>("long int");
	test_single_is_integral<long long int>("long long int");
	test_single_is_integral<unsigned char>("unsigned char");
	test_single_is_integral<unsigned short int>("unsigned short int");
	test_single_is_integral<unsigned int>("unsigned int");
	test_single_is_integral<unsigned long int>("unsigned long int");
	test_single_is_integral<unsigned long long int>("unsigned long long int");

	// wrong ones
	test_single_is_integral<int *>("int *");
	test_single_is_integral<std::string>("std::string");
	test_single_is_integral<char *>("char *");

	std::cout << std::endl;
}
