/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 17:07:06 by dda-silv          #+#    #+#             */
/*   Updated: 2021/08/14 15:38:40 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

# include <iterator>	// std::random_access_iterator_tag

namespace ft {

	template<class T>
	class random_access_iterator {

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
/*                   	 CONSTRUCTORS & DESTRUCTORS                           */
/******************************************************************************/

/*                                Constructors                                */

			// Default
			random_access_iterator(void) : _ptr(NULL) {};

			// Type specific
			random_access_iterator(pointer ptr) : _ptr(ptr) {};

			// Copy
			random_access_iterator(random_access_iterator const& rhs)
				: _ptr(rhs._ptr) {};

/*                                Destructors                                 */

			// Default
			virtual ~random_access_iterator(void) {}

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

			random_access_iterator& operator=(random_access_iterator const& rhs) {
				_ptr = rhs._ptr;

				return *this;
			}

			// Overload called when trying to copy construct a const_iterator
			// based on an iterator
			operator random_access_iterator<T const>(void) const
			{
				return random_access_iterator<T const>(_ptr);
			}

/*                                Comparison                                  */

			bool operator==(random_access_iterator const& rhs) const {
				return _ptr == rhs._ptr;
			}

			bool operator!=(random_access_iterator const& rhs) const {
				return _ptr != rhs._ptr;
			}

			bool operator<(random_access_iterator const& rhs) const {
				return _ptr < rhs._ptr;
			}

			bool operator>(random_access_iterator const& rhs) const {
				return _ptr > rhs._ptr;
			}
			
			bool operator<=(random_access_iterator const& rhs) const {
				return _ptr <= rhs._ptr;
			}

			bool operator>=(random_access_iterator const& rhs) const {
				return _ptr >= rhs._ptr;
			}

/*                        Increment / decrement                               */

			// Pre-increment
			random_access_iterator& operator++() {
				_ptr++;

				return *this;
			}

			// Post-increment
			random_access_iterator operator++(int) {
				random_access_iterator<T> tmp(*this);

				_ptr++;

				return tmp;
			}

			// Pre-decrement
			random_access_iterator& operator--() {
				_ptr--;

				return *this;
			}

			// Post-decrement
			random_access_iterator operator--(int) {
				random_access_iterator<T> tmp(*this);

				_ptr--;

				return tmp;
			}

/*                                Arithmetic                                  */

			random_access_iterator operator+(difference_type val) const {
				return random_access_iterator<T>(_ptr + val);
			}

			random_access_iterator operator-(difference_type val) const {
				return random_access_iterator<T>(_ptr - val);
			}

			random_access_iterator& operator+=(difference_type val) {
				_ptr += val;

				return *this;
			}

			random_access_iterator& operator-=(difference_type val) {
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
