/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_compare.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 22:25:59 by dda-silv          #+#    #+#             */
/*   Updated: 2021/09/08 22:27:13 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUSTOM_COMPARE_HPP
# define CUSTOM_COMPARE_HPP

template<class Arg1,
	class Arg2,
	class Result>
struct binary_function
{
	typedef Arg1	first_argument_type;
	typedef Arg2	second_argument_type;
	typedef Result	result_type;
};

template<class T>
struct greater : binary_function<T, T, bool>
{
	bool
	operator()(T const& x, T const& y) const
	{
		return x > y;
	}
};

#endif
