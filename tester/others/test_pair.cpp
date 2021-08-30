/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pair.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 10:49:22 by dda-silv          #+#    #+#             */
/*   Updated: 2021/08/30 11:16:46 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_pair.hpp"

void
test_pair_constructors()
{
	ft::pair<std::string, double> product1;
	ft::pair<std::string, double> product2("tomatoes", 2.30);
	ft::pair<std::string, double> product3(product2);

	product2.first = "shoes";
	product2.second = 39.90;

	std::cout << "The price of " << product1.first << " is $" << product1.second << std::endl;
	std::cout << "The price of " << product2.first << " is $" << product2.second << std::endl;
	std::cout << "The price of " << product3.first << " is $" << product3.second << std::endl;

	{
		ft::pair<std::string, double> cpy1 = product1;
		ft::pair<std::string, double> cpy2 = product2;
		ft::pair<std::string, double> cpy3 = product3;
	}
}

void
test_pair_assignement_overload()
{
	ft::pair<std::string, int> planet, homeplanet;

	planet.first = "Earth";
	planet.second = 6371;

	std::cout << "Planet: " << planet.first << std::endl;
	std::cout << "Planet size: " << planet.second << std::endl;

	homeplanet = planet;

	std::cout << "Home planet: " << homeplanet.first << std::endl;
	std::cout << "Home planet size: " << homeplanet.second << std::endl;

	{
		ft::pair<std::string, int> cpy1 = planet;
		ft::pair<std::string, int> cpy2 = homeplanet;
	}
}

void
test_pair_relational_operators()
{
	ft::pair<int, char> foo(10, 'z');
	ft::pair<int, char> bar(90, 'a');

	if (foo == bar) std::cout << "foo and bar are equal" << std::endl;
	if (foo != bar) std::cout << "foo and bar are not equal" << std::endl;
	if (foo < bar) std::cout << "foo is less than bar" << std::endl;
	if (foo > bar) std::cout << "foo is greater than bar" << std::endl;
	if (foo <= bar) std::cout << "foo is less than or equal to bar" << std::endl;
	if (foo >= bar) std::cout << "foo is greater than or equal to bar" << std::endl;
}

void
test_pair_make_pair()
{
	ft::pair<int, int> foo;
	ft::pair<int, int> bar;

	foo = ft::make_pair(10, 20);
	bar = ft::make_pair(10.5, 'A');

	std::cout << "foo: " << foo.first << ", " << foo.second << std::endl;
	std::cout << "bar: " << bar.first << ", " << bar.second << std::endl;

	{
		ft::pair<int, int> cpy1 = foo;
		(void)cpy1;
		ft::pair<int, int> cpy2 = bar;
		(void)cpy2;
	}
}

void
test_pair()
{
	test_wrapper(test_pair_constructors, "constructors");
	test_wrapper(test_pair_assignement_overload, "assignement overload");
	test_wrapper(test_pair_relational_operators, "relational operators");
	test_wrapper(test_pair_make_pair, "make_pair");
}
