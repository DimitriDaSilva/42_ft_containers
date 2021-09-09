/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 09:59:24 by dda-silv          #+#    #+#             */
/*   Updated: 2021/09/09 08:48:33 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_map.hpp"

void
test_map()
{
	subsection_wrapper(test_map_constructors, "map_constructors");
	subsection_wrapper(test_map_iterators, "map_iterators");
	subsection_wrapper(test_map_reverse_iterators, "map_reverse_iterators");
	subsection_wrapper(test_map_capacity, "map_capacity");
	subsection_wrapper(test_map_element_access, "map_element_access");
	subsection_wrapper(test_map_modifiers, "map_modifiers");
	subsection_wrapper(test_map_observers, "map_observers");
	subsection_wrapper(test_map_operations, "map_operations");
	subsection_wrapper(test_map_allocator, "map_allocator");
	subsection_wrapper(test_map_non_member_overloads, "map_non_member_overloads");
}
