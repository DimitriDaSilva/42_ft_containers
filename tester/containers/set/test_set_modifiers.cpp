/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_set_modifiers.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 19:21:16 by dda-silv          #+#    #+#             */
/*   Updated: 2021/09/06 17:17:47 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_set_modifiers.hpp"

template<typename Set>
void
print_set_info(Set const& set)
{
	std::cout << "Size: " << set.size() << std::endl;

	if (set.empty()) {
		std::cout << "Set is empty" << std::endl;
	} else {
		std::cout << "Values: ";
		for (typename Set::const_iterator it = set.begin(); it != set.end(); it++) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}
}

void
test_set_modifiers_insert_single_element()
{
	ft::set<int> set;
	ft::set<int>::iterator it;

	print_set_info(set);

	set.insert(42);
	set.insert(60);

	print_set_info(set);

	//it = set.end();
	//std::cout << *it << std::endl;
	//it--;
	//std::cout << *it << std::endl;
}

void
test_set_modifiers()
{
	test_wrapper(test_set_modifiers_insert_single_element, "insert_single_element");
}
