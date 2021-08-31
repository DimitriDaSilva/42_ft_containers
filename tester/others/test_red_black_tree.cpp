/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_red_black_tree.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 08:53:44 by dda-silv          #+#    #+#             */
/*   Updated: 2021/08/31 15:16:48 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_red_black_tree.hpp"

void
test_red_black_tree_insertion_jenny()
{
	ft::rbt<int> rbt;

	rbt.insert(10);
	rbt.print_inorder();
	std::cout << std::endl;

	rbt.insert(18);
	rbt.print_inorder();
	std::cout << std::endl;

	rbt.insert(7);
	rbt.print_inorder();
	std::cout << std::endl;

	rbt.insert(15);
	rbt.print_inorder();
	std::cout << std::endl;

	rbt.insert(16);
	rbt.print_inorder();
	std::cout << std::endl;

	rbt.insert(30);
	rbt.print_inorder();
	std::cout << std::endl;

	rbt.insert(25);
	rbt.print_inorder();
	std::cout << std::endl;

	rbt.insert(40);
	rbt.print_inorder();
	std::cout << std::endl;

	rbt.insert(60);
	rbt.print_inorder();
	std::cout << std::endl;

	rbt.insert(2);
	rbt.print_inorder();
	std::cout << std::endl;

	rbt.insert(1);
	rbt.print_inorder();
	std::cout << std::endl;

	rbt.insert(70);
	rbt.print_inorder();
	std::cout << std::endl;
}

void
test_red_black_tree_insertion_string()
{
	ft::rbt<std::string> rbt;

	rbt.insert("test");
	rbt.print_inorder();
	std::cout << std::endl;

	rbt.insert("hello");
	rbt.print_inorder();
	std::cout << std::endl;
}

void test_red_black_tree()
{
	test_wrapper(test_red_black_tree_insertion_jenny, "insertion jenny");
	//test_wrapper(test_red_black_tree_insertion_string, "insertion string");
}
