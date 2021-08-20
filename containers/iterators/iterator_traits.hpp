/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 11:06:17 by dda-silv          #+#    #+#             */
/*   Updated: 2021/08/16 20:59:18 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

# include <iterator>	// std::random_access_iterator_tag

namespace ft {
	
	template<class Iterator>
	class iterator_traits {
		public:
			typedef typename Iterator::iterator_category	iterator_category; 
			typedef typename Iterator::value_type			value_type; 
			typedef typename Iterator::difference_type		difference_type; 
			typedef typename Iterator::pointer				pointer; 
			typedef typename Iterator::reference			reference; 
	};

	template<class T>
	class iterator_traits<T*> {
		public:
			typedef std::random_access_iterator_tag iterator_category;
			typedef T				value_type;
			typedef std::ptrdiff_t	difference_type;
			typedef T*				pointer;
			typedef T&				reference;
	};

	template<class T>
	class iterator_traits<T const*> {
		public:
			typedef std::random_access_iterator_tag iterator_category;
			typedef T				value_type;
			typedef std::ptrdiff_t	difference_type;
			typedef T const*		pointer;
			typedef T const&		reference;
	};
}

#endif
