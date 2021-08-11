/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 17:07:06 by dda-silv          #+#    #+#             */
/*   Updated: 2021/08/11 19:07:07 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include "../main.hpp"
# include "../utils/RandomAccessIterator.hpp"
# include <iostream>
# include <string>
# include <limits>
# include <iterator>
# include <stdexcept> // std::lenght_error

//namespace ft {
	//template<class T> class RandomAccessIterator;
//}

//namespace ft {
	//template<class T, class A> class vector;
//}

namespace ft {

	template<class T, class A = std::allocator<T> >
	class vector {
		public:
/******************************************************************************/
/*                   	        MEMBER TYPES					              */
/******************************************************************************/

			typedef T value_type; 
			typedef A allocator_type;
			typedef typename A::reference reference;
			typedef typename A::const_reference const_reference;
			typedef typename A::pointer pointer;
			typedef typename A::const_pointer const_pointer;
			typedef typename A::difference_type difference_type;
			typedef typename A::size_type size_type;

			typedef ft::RandomAccessIterator<value_type> iterator;
			typedef ft::RandomAccessIterator<const value_type> const_iterator;
			typedef std::reverse_iterator<iterator> reverse_iterator;
			typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

/******************************************************************************/
/*                   	        MEMBER FUNCTIONS                              */
/******************************************************************************/
/******************************************************************************/
/*                   	 CONSTRUCTORS & DESTRUCTORS                           */
/******************************************************************************/

/*                                Constructors                                */

			// Default
			vector(void) {
				_size = 0;
				_capacity = 2;
				_max_size = std::numeric_limits<long>::max() / sizeof(T);
				_start = _allocator.allocate(_capacity);
			} 

			// Copy
			vector(vector const& other) {*this = other;}

/*                                Destructors                                 */

			// Default
			virtual ~vector(void) {
				_allocator.deallocate(_start, _capacity);
			}

/******************************************************************************/
/*                   	    OTHER MEMBER FUNCTIONS                            */
/******************************************************************************/

/*                                 Iterators                                  */

			iterator begin(void) {return _start;}

			const_iterator begin(void) const {
				return _start;
			}

			iterator end(void) {
				if (empty()) {
					return begin();
				}
				return _start + _size;
			}

			const_iterator end(void) const {
				if (empty()) {
					return begin();
				}
				return _start + _size;
			}

/*                                  Capacity                                  */

			size_type size(void) const {return _size;}

			size_type max_size(void) const {return _max_size;}

			void resize (size_type n, value_type val = value_type()) {
				if (n < _size) {
					for (size_type i = n; i < _size; i++) {
						_allocator.destroy(&_start[i]);
					}
					_size = n;
				} else if (n > _size) {
					if (n > _capacity) {
						reserve(n);
					}
					for (size_type i = _size; i < n; i++) {
						_start[i] = val;
					}
					_size = n;
				}
			}

			size_type capacity(void) const {return _capacity;}

			bool empty() const {return _size == 0;}

			void reserve (size_type n) {
				if (n > _max_size) {
					throw std::length_error("vector::reserve");
				} else if (n > _capacity) {
					value_type* tmp = _allocator.allocate(n);
					for (size_type i = 0; i < _size; i++) {
						tmp[i] = _start[i];
					}
					_allocator.deallocate(_start, _capacity);
					_capacity = n;
					_start = tmp;
				}
			}

/*                                  Modifiers                                 */

			void push_back (value_type const& val) {
				if (_size == _capacity) {
					reserve(_capacity * 2);
				}
				_start[_size] = val;
				_size++;
			}

/******************************************************************************/
/*                   	   OVERLOADING OPERATORS                              */
/******************************************************************************/

/*                                Assignement                                 */
			vector& operator=(vector const& other) {
				(void)other;

				return *this;
			}

/******************************************************************************/
/*                               EXCEPTIONS 								  */
/******************************************************************************/

			class NameException : public std::exception {
				public:
					const char* what(void) const throw ();
			};

		protected:
/******************************************************************************/
/*                   	       PROTECTED DATA                                 */
/******************************************************************************/


		private:
/******************************************************************************/
/*                   	        PRIVATE DATA                                  */
/******************************************************************************/

			pointer			_start;
			allocator_type	_allocator;
			size_type		_size;
			size_type		_capacity;
			size_type		_max_size;
	};

/******************************************************************************/
/*                          NON-CLASS FUNCTIONS		                          */
/******************************************************************************/

}

#endif
