/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_containers.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 11:11:55 by dda-silv          #+#    #+#             */
/*   Updated: 2021/09/10 11:48:02 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_containers.hpp"

void
test_containers()
{
	test_wrapper(test_subject, "subject");
	subsection_wrapper(test_vector, "vector");
	subsection_wrapper(test_stack, "stack");
	subsection_wrapper(test_map, "map");
	subsection_wrapper(test_set, "set");
}
