/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_equal.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 09:52:17 by dda-silv          #+#    #+#             */
/*   Updated: 2021/08/26 09:57:30 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_equal.hpp"

bool
mypredicate(int i, int j)
{
	return (i == j);
}

void
test_equal()
{
	int myints[] = {20, 40, 60, 80, 100};
	ft::vector<int> myvector(myints, myints + 5);

	// using default comparison:
	if (ft::equal(myvector.begin(), myvector.end(), myints))
		std::cout << "The contents of both sequences are equal." << std::endl;
	else
		std::cout << "The contents of both sequences differ." << std::endl;

	myvector[3] = 81;

	// using predicate comparison:
	if (std::equal (myvector.begin(), myvector.end(), myints, mypredicate))
		std::cout << "The contents of both sequences are equal." << std::endl;
	else
		std::cout << "The contents of both sequences differ." << std::endl;
}
