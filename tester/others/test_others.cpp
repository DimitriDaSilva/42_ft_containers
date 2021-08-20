/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_others.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 11:41:38 by dda-silv          #+#    #+#             */
/*   Updated: 2021/08/20 12:07:37 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_others.hpp"

void test_others(void) {

	subsection_wrapper(test_distance, "distance");
	subsection_wrapper(test_is_const, "is_const");
	subsection_wrapper(test_is_integral, "is_integral");
	subsection_wrapper(test_iterator_traits, "iterator_traits");
	subsection_wrapper(test_reverse_iterator, "reverse_iterator");
}
