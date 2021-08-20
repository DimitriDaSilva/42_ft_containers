/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_wrappers.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 10:20:27 by dda-silv          #+#    #+#             */
/*   Updated: 2021/08/20 11:59:27 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "test_wrappers.hpp"

void section_wrapper(void f(), std::string section_name) {
	std::cout << "====== test_" << section_name << " ======" << std::endl;

	try {
		f();
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
}

void subsection_wrapper(void f(), std::string subsection_name) {
	std::cout << "*** test_" << subsection_name << " ***" << std::endl;

	try {
		f();
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
}

void test_wrapper(void f(), std::string test_name) {
	std::cout << "# test_" << test_name << ": " << std::endl;

	try {
		f();
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
}
