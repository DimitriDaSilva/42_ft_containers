/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 11:56:20 by dda-silv          #+#    #+#             */
/*   Updated: 2021/08/30 12:00:45 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LESS_HPP
# define LESS_HPP

namespace ft
{
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
	struct less : binary_function<T, T, bool>
	{
		bool
		operator()(T const& x, T const& y) const
		{
			return x < y;
		}
	};
}

#endif
