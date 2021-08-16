/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 15:14:06 by dda-silv          #+#    #+#             */
/*   Updated: 2021/08/16 18:27:16 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISTANCE_HPP
# define DISTANCE_HPP

# include "../iterators/iterator_traits.hpp"

# include <iterator>	// iterator tags
# include <typeinfo>	// std::typeid
# include <exception>	// std::exception

namespace ft {

	template<class InputIterator>
	static typename ft::iterator_traits<InputIterator>::difference_type
	distance(InputIterator first, InputIterator last) {

		typedef typename ft::iterator_traits<InputIterator>::difference_type difference_type;

		if (typeid(typename ft::iterator_traits<InputIterator>::iterator_category)
				== typeid(std::output_iterator_tag)) {
			throw std::exception();
		} else if (typeid(typename ft::iterator_traits<InputIterator>::iterator_category)
				== typeid(std::random_access_iterator_tag)) {
			return last - first;
		} else {
			difference_type diff = 0;

			for (InputIterator it = first; it != last; it++) {
				diff++;
			}

			return diff;
		}
	}

}

#endif
