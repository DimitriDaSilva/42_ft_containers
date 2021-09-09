/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map_constructors.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 10:00:35 by dda-silv          #+#    #+#             */
/*   Updated: 2021/09/09 11:48:07 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_MAP_CONSTRUCTORS_HPP
# define TEST_MAP_CONSTRUCTORS_HPP

# include <string>	// std::string

# include "main.hpp"
# include "custom_compare.hpp"
# include "containers.hpp"
# include "test_wrappers.hpp"
# include "print_containers_info.hpp"

bool fncomp(char lhs, char rhs) {return lhs<rhs;}

struct classcomp
{
	bool
	operator()(char const& lhs, char const& rhs) const {return lhs < rhs;}
};

void test_map_constructors();

#endif
