/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 15:14:06 by dda-silv          #+#    #+#             */
/*   Updated: 2021/08/16 20:48:54 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISTANCE_HPP
# define DISTANCE_HPP

# include "../iterators/iterator_traits.hpp"

# include <iterator>	// iterator tags
# include <typeinfo>	// std::typeid
# include <exception>	// std::exception

namespace ft {

	//template<class InputIterator>
	//static typename ft::iterator_traits<InputIterator>::difference_type
	//distance(InputIterator first, InputIterator last) {

		//typedef typename ft::iterator_traits<InputIterator>::difference_type difference_type;

		//if (typeid(typename ft::iterator_traits<InputIterator>::iterator_category)
				//== typeid(std::output_iterator_tag)) {
			//throw std::exception();
		//} else if (typeid(typename ft::iterator_traits<InputIterator>::iterator_category)
				//== typeid(std::random_access_iterator_tag)) {
			//return last - first;
		//} else {
			//difference_type diff = 0;

			//for (InputIterator it = first; it != last; it++) {
				//diff++;
			//}

			//return diff;
		//}
	//}

	// random access iterator optimization
	template <typename RAIt>
	typename ft::iterator_traits<RAIt>::difference_type distance(RAIt first, RAIt last, std::random_access_iterator_tag)
	{
		return last - first;
	}

	// non random access iterator implementation
	template <typename It>
	typename ft::iterator_traits<It>::difference_type distance(It first, It last, std::input_iterator_tag)
	{
		typename ft::iterator_traits<It>::difference_type dist = 0;
		for (; first != last; ++first)
			dist++;
		return dist;
	}

	template <typename InputIt>
	typename ft::iterator_traits<InputIt>::difference_type distance(InputIt first, InputIt last)
	{
		return ft::distance(first, last, typename ft::iterator_traits<InputIt>::iterator_category());
	}

}

#endif
