/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_red_black_tree.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 08:53:44 by dda-silv          #+#    #+#             */
/*   Updated: 2021/09/01 17:45:22 by dda-silv         ###   ########.fr       */
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

	{
		ft::rbt<int> cpy = rbt;
		cpy.print_inorder();
		cpy.clear();
	}

	rbt.clear();
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

	rbt.insert("marc");
	rbt.print_inorder();
	std::cout << std::endl;

	rbt.insert("zebra");
	rbt.print_inorder();
	std::cout << std::endl;

	{
		ft::rbt<std::string> cpy = rbt;
		cpy.print_inorder();
		cpy.clear();
	}

	rbt.clear();
}

void
test_red_black_tree_find()
{
	ft::rbt<int> rbt;

	for (int i = 0; i < 13; i++) rbt.insert(i);

	for (int i = -1; i < 14; i++)
	{
		if (!rbt.find(i))
			std::cout << "Can't find it" << std::endl;
		else
			std::cout << "Found it" << std::endl;
	}

	rbt.print_inorder();

	{
		ft::rbt<int> cpy = rbt;
		cpy.print_inorder();
		cpy.clear();
	}

	rbt.clear();
}

void
test_red_black_tree_predecessor()
{
	ft::rbt<int> rbt;
	ft::rbt<int>::node_pointer predecessor;

	rbt.insert(10);
	rbt.insert(9);
	rbt.insert(15);
	rbt.insert(12);
	rbt.insert(20);

	rbt.print_inorder();

	if ((predecessor = rbt.predecessor(rbt.find(10))))
		std::cout << "Predecessor of 10 is " << predecessor->data << std::endl;

	if ((predecessor = rbt.predecessor(rbt.find(12))))
		std::cout << "Predecessor of 12 is " << predecessor->data << std::endl;

	if ((predecessor = rbt.predecessor(rbt.find(9))))
		std::cout << "Predecessor of 9 is " << predecessor->data << std::endl;
	else
		std::cout << "9 is the minimum in the tree" << std::endl;

	rbt.clear();
}

void
test_red_black_tree_successor()
{
	ft::rbt<int> rbt;
	ft::rbt<int>::node_pointer successor;

	rbt.insert(10);
	rbt.insert(9);
	rbt.insert(15);
	rbt.insert(12);
	rbt.insert(20);

	rbt.print_inorder();

	if ((successor = rbt.successor(rbt.find(10))))
		std::cout << "Successor of 10 is " << successor->data << std::endl;

	if ((successor = rbt.successor(rbt.find(9))))
		std::cout << "Successor of 9 is " << successor->data << std::endl;

	if ((successor = rbt.successor(rbt.find(20))))
		std::cout << "Successor of 20 is " << successor->data << std::endl;
	else
		std::cout << "20 is the maximum in the tree" << std::endl;

	rbt.clear();
}

void
test_red_black_tree_erase_red_leaf_node()
{
	ft::rbt<int> rbt;

	rbt.insert(10);
	rbt.insert(100);
	rbt.insert(42);

	rbt.print_inorder();

	rbt.erase(10);
	rbt.erase(100);

	rbt.print_inorder();

	{
		ft::rbt<int> cpy = rbt;
		cpy.print_inorder();
		cpy.clear();
	}

	rbt.clear();
}

void
test_red_black_tree_erase_red_node_one_child()
{
	ft::rbt<int> rbt;

	rbt.insert(10);
	rbt.insert(7);
	rbt.insert(15);
	rbt.insert(12);
	rbt.insert(20);
	rbt.insert(9);

	rbt.print_inorder();

	rbt.erase(9);

	rbt.print_inorder();

	{
		ft::rbt<int> cpy = rbt;
		cpy.print_inorder();
		cpy.clear();
	}

	rbt.clear();
}

void
test_red_black_tree_erase_black_node_one_child()
{
	ft::rbt<int> rbt;

	rbt.insert(10);
	rbt.insert(7);
	rbt.insert(20);
	rbt.insert(30);

	rbt.print_inorder();

	rbt.erase(20);

	rbt.print_inorder();

	rbt.insert(2);
	rbt.insert(25);
	rbt.insert(9);
	rbt.insert(40);
	rbt.insert(38);

	rbt.print_inorder();

	rbt.erase(30);

	rbt.print_inorder();

	rbt.clear();
}

void test_red_black_tree()
{
	test_wrapper(test_red_black_tree_insertion_jenny, "insertion jenny");
	test_wrapper(test_red_black_tree_insertion_string, "insertion string");
	test_wrapper(test_red_black_tree_find, "find");
	test_wrapper(test_red_black_tree_predecessor, "predecessor");
	test_wrapper(test_red_black_tree_successor, "successor");
	test_wrapper(test_red_black_tree_erase_red_leaf_node, "erase red leaf node");
	test_wrapper(test_red_black_tree_erase_red_node_one_child, "erase red one child");
	test_wrapper(test_red_black_tree_erase_black_node_one_child, "erase black one child");
}
