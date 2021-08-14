/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 14:34:06 by dda-silv          #+#    #+#             */
/*   Updated: 2021/08/14 16:34:09 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "./iterator_traits.hpp"	// ft::iterator_traits
# include <stdlib.h>				// NULL

namespace ft {

	template<class Iter>
	class reverse_iterator {

		public:
/******************************************************************************/
/*                   	        MEMBER TYPES					              */
/******************************************************************************/
			typedef Iter iterator_type; 
			typedef 
				typename iterator_traits<Iter>::iterator_category
				iterator_category;
			typedef 
				typename iterator_traits<Iter>::value_type
				value_type;
			typedef 
				typename iterator_traits<Iter>::difference_type
				difference_type;
			typedef 
				typename iterator_traits<Iter>::pointer
				pointer;
			typedef 
				typename iterator_traits<Iter>::reference
				reference;

/******************************************************************************/
/*                   	 CONSTRUCTORS & DESTRUCTORS                           */
/******************************************************************************/

/*                                Constructors                                */

			// Default
			reverse_iterator(void) : _ptr(NULL) {};

			// Initialization
			explicit reverse_iterator(iterator_type it) : _it(it) {};

			// Copy
			reverse_iterator(reverse_iterator const& rhs)
				: _it(rhs._it) {};

/*                                Destructors                                 */

			// Default
			virtual ~reverse_iterator(void) {}

/******************************************************************************/
/*                   	   OVERLOADING OPERATORS                              */
/******************************************************************************/

/*                                Assignement                                 */

			reverse_iterator& operator=(reverse_iterator const& rhs) {
				_ptr = rhs._ptr;
				_it = rhs._it;

				return *this;
			}

			// Overload called when trying to copy construct a const_iterator
			// based on an iterator
			operator reverse_iterator<Iter const>(void) const
			{
				return reverse_iterator<Iter const>(_ptr);
			}

/******************************************************************************/
/*                   	    GETTERS & SETTERS                                 */
/******************************************************************************/

			iterator_type base() const {
				return _it;
			}

		private:
/******************************************************************************/
/*                   	        PRIVATE DATA                                  */
/******************************************************************************/

			pointer			_ptr;
			iterator_type	_it;
	};
}

#endif
