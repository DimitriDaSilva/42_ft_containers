/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_set.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 09:59:24 by dda-silv          #+#    #+#             */
/*   Updated: 2021/09/08 16:39:06 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_set.hpp"

void
test_set()
{
	subsection_wrapper(test_set_constructors, "set_constructors");
	subsection_wrapper(test_set_iterators, "set_iterators");
	subsection_wrapper(test_set_reverse_iterators, "set_reverse_iterators");
	subsection_wrapper(test_set_capacity, "set_capacity");
	subsection_wrapper(test_set_modifiers, "set_modifiers");
	subsection_wrapper(test_set_observers, "set_observers");
	subsection_wrapper(test_set_operations, "set_operations");
	subsection_wrapper(test_set_allocator, "set_allocator");
	subsection_wrapper(test_set_non_member_overloads, "set_non_member_overloads");
}
