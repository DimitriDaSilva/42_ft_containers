/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_set_constructors.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 10:00:22 by dda-silv          #+#    #+#             */
/*   Updated: 2021/09/05 10:13:17 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_set_constructors.hpp"

void
test_set_constructors_empty()
{
	ft::set<int> set;
	(void)set;
}

void
test_set_constructors()
{
	test_wrapper(test_set_constructors_empty, "empty");
}
