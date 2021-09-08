/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_set_observers.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 16:23:58 by dda-silv          #+#    #+#             */
/*   Updated: 2021/09/08 16:35:13 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_set_observers.hpp"

void
test_set_observers_key_comp()
{
	ft::set<int> myset;
	int highest;

	ft::set<int>::key_compare mycomp = myset.key_comp();

	for (int i = 0; i <= 5; i++)
		myset.insert(i);

	std::cout << "myset contains:";

	highest = *myset.rbegin();

	ft::set<int>::iterator it = myset.begin();
	do
	{
		std::cout << ' ' << *it;
	} while (mycomp(*(++it), highest));

	std::cout << std::endl;
}

void
test_set_observers_value_comp()
{
	ft::set<int> myset;
	int highest;

	ft::set<int>::value_compare mycomp = myset.value_comp();

	for (int i = 0; i <= 5; i++)
		myset.insert(i);

	std::cout << "myset contains:";

	highest = *myset.rbegin();

	ft::set<int>::iterator it = myset.begin();
	do
	{
		std::cout << ' ' << *it;
	} while (mycomp(*(++it), highest));

	std::cout << std::endl;
}

void
test_set_observers()
{
	test_wrapper(test_set_observers_key_comp, "observers_key_comp");
	test_wrapper(test_set_observers_value_comp, "observers_value_comp");
}
