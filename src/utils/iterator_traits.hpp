/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 11:06:17 by dda-silv          #+#    #+#             */
/*   Updated: 2021/08/12 11:18:21 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

namespace ft {
	template <class Iterator>
	class iterator_traits {
		public:
			typedef typename Iterator::difference_type difference_type; 
			typedef typename Iterator::value_type value_type; 
			typedef typename Iterator::pointer pointer; 
			typedef typename Iterator::reference reference; 
			typedef typename Iterator::iterator_category iterator_category; 
	};
}

#endif
