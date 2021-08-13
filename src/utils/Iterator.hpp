/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 17:07:06 by dda-silv          #+#    #+#             */
/*   Updated: 2021/08/13 17:32:25 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include "../main.hpp"
# include <iostream>
# include <string>
# include <iterator>

namespace ft {

	template<class T>
	class Iterator {

		public:
/******************************************************************************/
/*                   	        MEMBER TYPES					              */
/******************************************************************************/

			typedef T value_type; 
			typedef typename std::ptrdiff_t difference_type;
			typedef value_type& reference;
			typedef value_type* pointer;
			typedef std::random_access_iterator_tag iterator_category;

/******************************************************************************/
/*                   	        PUBLIC DATA                                   */
/******************************************************************************/


/******************************************************************************/
/*                   	 CONSTRUCTORS & DESTRUCTORS                           */
/******************************************************************************/

/*                                Constructors                                */

			// Default
			Iterator(void) : _ptr(NULL) {};

			// Type specific
			Iterator(pointer ptr) : _ptr(ptr) {};

			// Copy
			Iterator(Iterator const& rhs)
				: _ptr(rhs._ptr) {};


/*                                Destructors                                 */

			// Default
			virtual ~Iterator(void) {}


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

			Iterator& operator=(Iterator const& rhs) {
				_ptr = rhs._ptr;

				return *this;
			}

/*                                Comparison                                  */

			bool operator==(Iterator const& rhs) const {
				return _ptr == rhs._ptr;
			}

			bool operator!=(Iterator const& rhs) const {
				return _ptr != rhs._ptr;
			}

			bool operator<(Iterator const& rhs) const {
				return _ptr < rhs._ptr;
			}

			bool operator>(Iterator const& rhs) const {
				return _ptr > rhs._ptr;
			}
			
			bool operator<=(Iterator const& rhs) const {
				return _ptr <= rhs._ptr;
			}

			bool operator>=(Iterator const& rhs) const {
				return _ptr >= rhs._ptr;
			}

/*                        Increment / decrement                               */

			// Pre-increment
			Iterator& operator++() {
				_ptr++;

				return *this;
			}

			// Post-increment
			Iterator operator++(int) {
				Iterator<T> tmp(*this);

				_ptr++;

				return tmp;
			}

			// Pre-decrement
			Iterator& operator--() {
				_ptr--;

				return *this;
			}

			// Post-decrement
			Iterator operator--(int) {
				Iterator<T> tmp(*this);

				_ptr--;

				return tmp;
			}

/*                                Arithmetic                                  */

			Iterator operator+(difference_type val) const {
				return Iterator<T>(_ptr + val);
			}

			Iterator operator-(difference_type val) const {
				return Iterator<T>(_ptr - val);
			}

			Iterator& operator+=(difference_type val) {
				_ptr += val;

				return *this;
			}

			Iterator& operator-=(difference_type val) {
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
