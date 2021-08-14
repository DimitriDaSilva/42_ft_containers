/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 14:34:06 by dda-silv          #+#    #+#             */
/*   Updated: 2021/08/14 15:57:36 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "./iterator_traits.hpp"	// ft::iterator_traits

namespace ft {

	template<class Iterator>
	class reverse_iterator {

		public:
/******************************************************************************/
/*                   	        MEMBER TYPES					              */
/******************************************************************************/
			typedef Iterator iterator_type; 
			typedef 
				typename iterator_traits<Iterator>::iterator_category
				iterator_category;
			typedef 
				typename iterator_traits<Iterator>::value_type
				value_type;
			typedef 
				typename iterator_traits<Iterator>::difference_type
				difference_type;
			typedef 
				typename iterator_traits<Iterator>::reference
				reference;
			typedef 
				typename iterator_traits<Iterator>::pointer
				pointer;

/******************************************************************************/
/*                   	 CONSTRUCTORS & DESTRUCTORS                           */
/******************************************************************************/

/*                                Constructors                                */

			// Default
			reverse_iterator(void) : _ptr(NULL) {};

			// Type specific
			reverse_iterator(pointer ptr) : _ptr(ptr) {};

			// Copy
			reverse_iterator(reverse_iterator const& rhs)
				: _ptr(rhs._ptr) {};

/*                                Destructors                                 */

			// Default
			virtual ~reverse_iterator(void) {}

		private:
/******************************************************************************/
/*                   	        PRIVATE DATA                                  */
/******************************************************************************/

			pointer _ptr;
	};
}

#endif
