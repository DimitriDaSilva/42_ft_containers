/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexicographical_compare.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 09:07:31 by dda-silv          #+#    #+#             */
/*   Updated: 2021/08/26 09:45:17 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXICOGRAPHICAL_COMPARE_HPP
# define LEXICOGRAPHICAL_COMPARE_HPP

namespace ft
{
	// Default operator <
	template<class InputIterator1, class InputIterator2>
	bool
	lexicographical_compare(InputIterator1 first1,
							InputIterator1 last1,
							InputIterator2 first2,
							InputIterator2 last2)
	{
		// Parse 1st container
		while (first1 != last1)
		{
			// Return false if reach end of 2nd container or
			// if 2nd elem < 1st elem
			if (first2 == last2 || *first2 < *first1)
				return false;
			// Return true if 1st elem < 2nd elem
			else if (*first1 < *first2)
				return true;
			first1++;
			first2++;
		}
		// Reached end of 1st container

		// Return true if we also reached end of 2nd container
		// Return false else
		return (first2 != last2);
	}

	// Custom compare
	template <class InputIterator1, class InputIterator2, class Compare>
	bool
	lexicographical_compare(InputIterator1 first1,
							InputIterator1 last1,
							InputIterator2 first2,
							InputIterator2 last2,
							Compare comp)
	{
		// Parse 1st container
		while (first1 != last1)
		{
			// Return false if reach end of 2nd container or
			// if 2nd elem < 1st elem
			if (first2 == last2 || comp(*first2, *first1))
				return false;
			// Return true if 1st elem < 2nd elem
			else if (comp(*first1, *first2))
				return true;
			first1++;
			first2++;
		}
		// Reached end of 1st container

		// Return true if we also reached end of 2nd container
		// Return false else
		return (first2 != last2);
	}
}

#endif
