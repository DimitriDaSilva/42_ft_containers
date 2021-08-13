/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConstIterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 17:07:06 by dda-silv          #+#    #+#             */
/*   Updated: 2021/08/13 17:32:25 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTITERATOR_HPP
# define CONSTITERATOR_HPP

# include "../main.hpp"
# include "Iterator.hpp"
# include <iostream>
# include <string>
# include <iterator>

namespace ft {

	template<class T>
	class ConstIterator {

		public:
/******************************************************************************/
/*                   	        MEMBER TYPES					              */
/******************************************************************************/

			typedef T value_type; 
			typedef typename std::ptrdiff_t difference_type;
			typedef const value_type& reference;
			typedef const value_type* pointer;
			typedef std::random_access_iterator_tag iterator_category;

/******************************************************************************/
/*                   	        PUBLIC DATA                                   */
/******************************************************************************/


/******************************************************************************/
/*                   	 CONSTRUCTORS & DESTRUCTORS                           */
/******************************************************************************/

/*                                Constructors                                */

			// Default
			ConstIterator(void) : _ptr(NULL) {};

			// Type specific
			ConstIterator(pointer ptr) : _ptr(ptr) {};

			// Copy
			ConstIterator(ConstIterator const& rhs)
				: _ptr(rhs._ptr) {};

			ConstIterator(ft::Iterator<T> const& rhs)
				: _ptr(rhs._ptr) {};


/*                                Destructors                                 */

			// Default
			virtual ~ConstIterator(void) {}


/******************************************************************************/
/*                   	    GETTERS & SETTERS                                 */
/******************************************************************************/


/******************************************************************************/
/*                   	   OTHER CLASS FUNCTIONS                              */
/******************************************************************************/

/******************************************************************************/
/*                   	   OVERLOADING OPERATORS                              */
/******************************************************************************/


/*                                Assignement                                 */

			ConstIterator& operator=(ConstIterator const& rhs) {
				_ptr = rhs._ptr;

				return *this;
			}

/*                                Comparison                                  */

			bool operator==(ConstIterator const& rhs) const {
				return _ptr == rhs._ptr;
			}

			bool operator!=(ConstIterator const& rhs) const {
				return _ptr != rhs._ptr;
			}

			bool operator<(ConstIterator const& rhs) const {
				return _ptr < rhs._ptr;
			}

			bool operator>(ConstIterator const& rhs) const {
				return _ptr > rhs._ptr;
			}
			
			bool operator<=(ConstIterator const& rhs) const {
				return _ptr <= rhs._ptr;
			}

			bool operator>=(ConstIterator const& rhs) const {
				return _ptr >= rhs._ptr;
			}

/*                        Increment / decrement                               */

			// Pre-increment
			ConstIterator& operator++() {
				_ptr++;

				return *this;
			}

			// Post-increment
			ConstIterator operator++(int) {
				ConstIterator<T> tmp(*this);

				_ptr++;

				return tmp;
			}

			// Pre-decrement
			ConstIterator& operator--() {
				_ptr--;

				return *this;
			}

			// Post-decrement
			ConstIterator operator--(int) {
				ConstIterator<T> tmp(*this);

				_ptr--;

				return tmp;
			}

/*                                Arithmetic                                  */

			ConstIterator operator+(difference_type val) const {
				return ConstIterator<T>(_ptr + val);
			}

			ConstIterator operator-(difference_type val) const {
				return ConstIterator<T>(_ptr - val);
			}

			ConstIterator& operator+=(difference_type val) {
				_ptr += val;

				return *this;
			}

			ConstIterator& operator-=(difference_type val) {
				_ptr -= val;

				return *this;
			}

/*                                 Access                                     */

			reference operator*(void) const {
				return *_ptr;
			}

			pointer operator->(void) const {
				return _ptr;
			}

			reference operator[](difference_type val) const {
				return *(_ptr + val);
			}

			pointer _ptr;
		private:
/******************************************************************************/
/*                   	        PRIVATE DATA                                  */
/******************************************************************************/

	};
}

#endif
