/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 11:20:45 by dda-silv          #+#    #+#             */
/*   Updated: 2021/08/23 09:51:00 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_vector.hpp"

void test_vector()
{
	subsection_wrapper(test_vector_constructors, "vector_constructors");
	subsection_wrapper(test_vector_capacity, "vector_capacity");
	subsection_wrapper(test_vector_iterators, "vector_iterators");
	subsection_wrapper(test_vector_reverse_iterators, "vector_reverse_iterators");
	subsection_wrapper(test_vector_element_access, "vector_element_access");
	subsection_wrapper(test_vector_modifiers, "vector_modifiers");
}
