/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_wrappers.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 10:21:50 by dda-silv          #+#    #+#             */
/*   Updated: 2021/08/20 11:59:27 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_WRAPPERS_HPP
# define TEST_WRAPPERS_HPP

# include <iostream>	// std::cout
# include <string>		// std::string
# include <exception>	// std::exception

void section_wrapper(void f(), std::string section_name);
void subsection_wrapper(void f(), std::string subsection_name);
void test_wrapper(void f(), std::string test_name);

#endif
