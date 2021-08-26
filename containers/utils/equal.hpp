/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 09:44:41 by dda-silv          #+#    #+#             */
/*   Updated: 2021/08/26 09:51:12 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EQUAL_HPP
# define EQUAL_HPP

namespace ft
{
	// Default
	template<class InputIterator1, class InputIterator2>
	bool
	equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
	{
		while (first1 != last1)
		{
			if (*first1 != *first2)
				return false;
			first1++;
			first2++;
		}

		return true;
	}

	// Predicate
	template<class InputIterator1, class InputIterator2, class BinaryPredicate>
	bool
	equal(InputIterator1 first1,
			InputIterator1 last1,
			InputIterator2 first2,
			BinaryPredicate pred)
	{
		while (first1 != last1)
		{
			if (!pred(*first1, *first2))
				return false;
			first1++;
			first2++;
		}

		return true;
	}
}

#endif
