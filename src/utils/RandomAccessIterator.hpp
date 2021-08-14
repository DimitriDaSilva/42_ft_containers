/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RandomAccessIterator.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 17:07:06 by dda-silv          #+#    #+#             */
/*   Updated: 2021/08/14 11:47:57 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOMACCESSITERATOR_HPP
# define RANDOMACCESSITERATOR_HPP

# include "../main.hpp"
# include <iostream>
# include <string>
# include <iterator>

namespace ft {

	template<class T>
	class RandomAccessIterator {

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
			RandomAccessIterator(void) : _ptr(NULL) {};

			// Type specific
			RandomAccessIterator(pointer ptr) : _ptr(ptr) {};

			// Copy
			RandomAccessIterator(RandomAccessIterator const& rhs)
				: _ptr(rhs._ptr) {};

/*                                Destructors                                 */

			// Default
			virtual ~RandomAccessIterator(void) {}

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

			RandomAccessIterator& operator=(RandomAccessIterator const& rhs) {
				_ptr = rhs._ptr;

				return *this;
			}

			// Overload called when trying to copy construct a const_iterator
			// based on an iterator
			operator RandomAccessIterator<T const>(void) const
			{
				return RandomAccessIterator<T const>(_ptr);
			}

/*                                Comparison                                  */

			bool operator==(RandomAccessIterator const& rhs) const {
				return _ptr == rhs._ptr;
			}

			bool operator!=(RandomAccessIterator const& rhs) const {
				return _ptr != rhs._ptr;
			}

			bool operator<(RandomAccessIterator const& rhs) const {
				return _ptr < rhs._ptr;
			}

			bool operator>(RandomAccessIterator const& rhs) const {
				return _ptr > rhs._ptr;
			}
			
			bool operator<=(RandomAccessIterator const& rhs) const {
				return _ptr <= rhs._ptr;
			}

			bool operator>=(RandomAccessIterator const& rhs) const {
				return _ptr >= rhs._ptr;
			}

/*                        Increment / decrement                               */

			// Pre-increment
			RandomAccessIterator& operator++() {
				_ptr++;

				return *this;
			}

			// Post-increment
			RandomAccessIterator operator++(int) {
				RandomAccessIterator<T> tmp(*this);

				_ptr++;

				return tmp;
			}

			// Pre-decrement
			RandomAccessIterator& operator--() {
				_ptr--;

				return *this;
			}

			// Post-decrement
			RandomAccessIterator operator--(int) {
				RandomAccessIterator<T> tmp(*this);

				_ptr--;

				return tmp;
			}

/*                                Arithmetic                                  */

			RandomAccessIterator operator+(difference_type val) const {
				return RandomAccessIterator<T>(_ptr + val);
			}

			RandomAccessIterator operator-(difference_type val) const {
				return RandomAccessIterator<T>(_ptr - val);
			}

			RandomAccessIterator& operator+=(difference_type val) {
				_ptr += val;

				return *this;
			}

			RandomAccessIterator& operator-=(difference_type val) {
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

		private:
/******************************************************************************/
/*                   	        PRIVATE DATA                                  */
/******************************************************************************/

			pointer _ptr;
	};
}

#endif
