/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RandomAccessIteratorConst.hpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 17:07:06 by dda-silv          #+#    #+#             */
/*   Updated: 2021/08/13 15:22:51 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOMACCESSITERATORCONST_HPP
# define RANDOMACCESSITERATORCONST_HPP

# include "../main.hpp"
# include <iostream>
# include <string>
# include <iterator>

namespace ft {

	template<class T>
	class RandomAccessIteratorConst {

		public:
/******************************************************************************/
/*                   	        MEMBER TYPES					              */
/******************************************************************************/

			typedef T value_type; 
			typedef typename std::ptrdiff_t difference_type;
			typedef const T& reference;
			typedef const T* pointer;
			typedef std::random_access_iterator_tag iterator_category;

/******************************************************************************/
/*                   	        PUBLIC DATA                                   */
/******************************************************************************/


/******************************************************************************/
/*                   	 CONSTRUCTORS & DESTRUCTORS                           */
/******************************************************************************/

/*                                Constructors                                */

			// Default
			RandomAccessIteratorConst(void) : _ptr(NULL) {};

			// Type specific
			RandomAccessIteratorConst(pointer ptr) : _ptr(ptr) {};

			// Copy
			RandomAccessIteratorConst(RandomAccessIteratorConst& rhs)
				: _ptr(rhs._ptr) {};
			RandomAccessIteratorConst(RandomAccessIteratorConst const& rhs)
				: _ptr(rhs._ptr) {};

/*                                Destructors                                 */

			// Default
			virtual ~RandomAccessIteratorConst(void) {}


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

			RandomAccessIteratorConst& operator=(RandomAccessIteratorConst const& rhs) {
				_ptr = rhs._ptr;

				return *this;
			}

/*                                Comparison                                  */

			bool operator==(RandomAccessIteratorConst const& rhs) const {
				return _ptr == rhs._ptr;
			}

			bool operator!=(RandomAccessIteratorConst const& rhs) const {
				return _ptr != rhs._ptr;
			}

			bool operator<(RandomAccessIteratorConst const& rhs) const {
				return _ptr < rhs._ptr;
			}

			bool operator>(RandomAccessIteratorConst const& rhs) const {
				return _ptr > rhs._ptr;
			}
			
			bool operator<=(RandomAccessIteratorConst const& rhs) const {
				return _ptr <= rhs._ptr;
			}

			bool operator>=(RandomAccessIteratorConst const& rhs) const {
				return _ptr >= rhs._ptr;
			}

/*                        Increment / decrement                               */

			// Pre-increment
			RandomAccessIteratorConst& operator++() {
				_ptr++;

				return *this;
			}

			// Post-increment
			RandomAccessIteratorConst operator++(int) {
				RandomAccessIteratorConst<T> tmp(*this);

				_ptr++;

				return tmp;
			}

			// Pre-decrement
			RandomAccessIteratorConst& operator--() {
				_ptr--;

				return *this;
			}

			// Post-decrement
			RandomAccessIteratorConst operator--(int) {
				RandomAccessIteratorConst<T> tmp(*this);

				_ptr--;

				return tmp;
			}

/*                                Arithmetic                                  */

			RandomAccessIteratorConst operator+(difference_type val) const {
				return RandomAccessIteratorConst<T>(_ptr + val);
			}

			RandomAccessIteratorConst operator-(difference_type val) const {
				return RandomAccessIteratorConst<T>(_ptr - val);
			}

			RandomAccessIteratorConst& operator+=(difference_type val) {
				_ptr += val;

				return *this;
			}

			RandomAccessIteratorConst& operator-=(difference_type val) {
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

			const pointer _ptr;
	};
}

#endif
