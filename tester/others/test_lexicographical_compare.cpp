/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lexicographical_compare.cpp                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 09:30:21 by dda-silv          #+#    #+#             */
/*   Updated: 2021/08/26 09:45:35 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_lexicographical_compare.hpp"

bool
mycomp(char c1, char c2)
{
    return std::tolower(c1) < std::tolower(c2);
}

void
test_lexicographical_compare()
{
    char foo[] = "Apple";
    char bar[] = "apartment";

    std::cout << std::boolalpha;

    std::cout << "Comparing foo and bar lexicographically (foo < bar):" << std::endl;

    std::cout << "Using default comparison (operator<): ";
    std::cout << std::lexicographical_compare(foo, foo + 5, bar, bar + 9);
    std::cout << std::endl;

    std::cout << "Using mycomp as comparison object: ";
    std::cout << std::lexicographical_compare(foo, foo + 5, bar, bar + 9, mycomp);
    std::cout << std::endl;
}
