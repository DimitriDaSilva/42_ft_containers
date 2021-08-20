/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_iterator_traits.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 12:05:29 by dda-silv          #+#    #+#             */
/*   Updated: 2021/08/20 12:06:11 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_ITERATOR_TRAITS_HPP
# define TEST_ITERATOR_TRAITS_HPP

# include <iostream>	// std::cout

# include "containers.hpp"

template<
	typename it,
	typename diff_type,
	typename value_types,
	typename ptr,
	typename ref,
	typename cat
	>
void test_single_iterator_traits(void);
void test_iterator_traits(void);

#endif
