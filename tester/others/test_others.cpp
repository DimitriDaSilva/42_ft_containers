/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_others.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 11:41:38 by dda-silv          #+#    #+#             */
/*   Updated: 2021/08/21 23:01:03 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_others.hpp"

void
test_others()
{

	test_wrapper(test_distance, "distance");
	test_wrapper(test_is_const, "is_const");
	test_wrapper(test_is_integral, "is_integral");
	test_wrapper(test_iterator_traits, "iterator_traits");
}
