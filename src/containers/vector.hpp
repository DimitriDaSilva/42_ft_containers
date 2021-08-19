/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 17:07:06 by dda-silv          #+#    #+#             */
/*   Updated: 2021/08/19 09:26:50 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream> // TODO: DELETE
# include <limits>		// std::numeric_limits
# include <stdexcept>	// std::lenght_error
# include <iterator>	// std::distance

# include "../utils/distance.hpp"					// ft::distance
# include "../iterators/random_access_iterator.hpp"	// ft::random_access_iterator
# include "../utils/enable_if.hpp"					// ft::enable_if
# include "../utils/is_integral.hpp"					// ft::is_integral
//# include "../utils/is_const.hpp"					// ft::is_const

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

			typedef ft::random_access_iterator<value_type> iterator;
			typedef ft::random_access_iterator<value_type const> const_iterator;
			typedef std::reverse_iterator<iterator> reverse_iterator;
			typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

/******************************************************************************/
/*                   	        MEMBER FUNCTIONS                              */
/******************************************************************************/
/******************************************************************************/
/*                   	 CONSTRUCTORS & DESTRUCTORS                           */
/******************************************************************************/

/*                                Constructors                                */

			// Empty container constructor (default constructor)
			explicit vector(allocator_type const& alloc = allocator_type()) :
				_start(NULL),
				_allocator(alloc),
				_size(0),
				_capacity(0),
				_max_size(std::numeric_limits<long>::max() / sizeof(T))
			{} 

			// Fill
			explicit vector(size_type n,
							value_type const& val = value_type(),
                 			allocator_type const& alloc = allocator_type()) :
				_start(NULL),
				_allocator(alloc),
				_size(0),
				_capacity(0),
				_max_size(std::numeric_limits<long>::max() / sizeof(T))
			{
				assign(n, val);
			}

			// Range
			template <class InputIterator>
			vector (InputIterator first,
					InputIterator last,
					allocator_type const& alloc = allocator_type(),
					typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL) :
				_start(NULL),
				_allocator(alloc),
				_size(0),
				_capacity(0),
				_max_size(std::numeric_limits<long>::max() / sizeof(T))
			{
				assign(first, last);
			}

			// Copy
			vector(vector const& other) {*this = other;}

/*                                Destructors                                 */

			// Default
			virtual ~vector(void) {
				_allocator.deallocate(_start, _capacity);
				_start = NULL;
				_size = 0;
				_capacity = 0;
			}

/******************************************************************************/
/*                   	   OVERLOADING OPERATORS                              */
/******************************************************************************/

/*                                Assignement                                 */
			vector& operator=(vector const& other) {
				// Free memory
				this->~vector();

				// Deep copy of the sequence
				insert(begin(), other.begin(), other.end());

				_allocator = other._allocator;
				_size = other._size;	// Check if insert doesn't already change _size
				_capacity = other._capacity; // Check if insert doesn't already change _size
				_max_size = other._max_size;
				
				return *this;
			}

/******************************************************************************/
/*                   	    OTHER MEMBER FUNCTIONS                            */
/******************************************************************************/

/*                                 Iterators                                  */

			// Forward
			iterator begin(void) {return iterator(_start);}

			const_iterator begin(void) const {return const_iterator(_start);}

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

			// Reverse
			//reverse_iterator rbegin(void) {
				//if (empty()) {
					//return rend();
				//}
				//return _start + _size - 1;
			//}

			//const_reverse_iterator rbegin(void) const {
				//if (empty()) {
					//return rend();
				//}
				//return _start + _size - 1;
			//}

			//reverse_iterator rend(void) {
				//return _start - 1;
			//}

			//const_reverse_iterator rend(void) const {
				//return _start - 1;
			//}

/*                                  Capacity                                  */

			size_type size(void) const {return _size;}

			size_type max_size(void) const {return _max_size;}

			void resize(size_type n, value_type val = value_type()) {

				// Reduced content to its first n elements
				if (n < _size) {
					// We also need to destroy items beyond size
					// Destroy doesn't deallocate item so we don't need to
					// change _capacity (or destroy beyond _size)
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

			// Change _capacity
			void reserve(size_type n) {

				// We need to throw we try to allocate more than max_size
				if (n > _max_size) {
					throw std::length_error("vector::reserve");
				} else if (n > _capacity) {
					// Allocate for n size
					value_type* tmp = _allocator.allocate(n);

					// Copy existing sequence
					for (size_type i = 0; i < _size; i++) {
						tmp[i] = _start[i];
					}

					// We only want to deallocate if there has been previous
					// allocation
					if (_capacity != 0) {
						_allocator.deallocate(_start, _capacity);
					}

					// Update data
					_capacity = n;
					_start = tmp;
				}
			}

/*                                  Modifiers                                 */

			// Range
			template<typename InputIterator>
			void assign(InputIterator first,
						InputIterator last,
						typename ft::enable_if<!ft::is_integral<InputIterator>::value,
							InputIterator>::type* = NULL) {

				// Destroy existing vector
				this->~vector();

				// When assigning we are overwritting so we only need
				// last - first size
				reserve(ft::distance(first, last));

				// Setting new elements
				insert(begin(), first, last);
			}

			// Fill
			void assign(size_type n, const value_type& val) {
				// Destroy existing vector
				this->~vector();

				// We allocate only n items when constructing n size
				reserve(n);

				// Setting new elements
				insert(begin(), n, val);
			}

			void push_back(value_type const& val) {

				if (empty()) {
					reserve(2);
				} else if (_size == _capacity) {
					reserve(_capacity * 2);
				}
				_start[_size] = val;
				_size++;
			}

			// Single element
			iterator insert(iterator position, const value_type& val) {

				iterator	ret_position;
				value_type*	tmp;;
				iterator 	it_old;
				iterator 	it_new;

				// New element requires reallocation because vector is full
				if (_size == _capacity) {
					// Reallocate new
					tmp = _allocator.allocate(_capacity * 2);

					// Copy sequence to new array
					it_old = begin();
					it_new = tmp;
					while (it_old != end()) {

						// Copy old to new
						if (it_old != position) {
							*it_new = *it_old;
						// Position found 
						} else {
							*it_new = val;

							ret_position = it_new;

							// For the position found we only want to increment
							// the new iterator
							it_new++;
							continue;
						}
						it_old++;
						it_new++;
					}

					// Update private data of vector
					_allocator.deallocate(_start, _capacity);
					_start = tmp;
					_size += 1;
					_capacity *= 2;

				// No need to reallocate so iterator position will still be valid
				} else {
					// Val inserted right before position
					insert(position, 1, val);
					ret_position = position - 1;
				}

				return ret_position;
			}

			// Fill
			void insert(iterator position, size_type n, const value_type& val) {

				value_type*	tmp;;
				iterator 	it_old;
				iterator 	it_new;

				// New element requires reallocation because vector is full
				if (_size + n > _capacity) {
					// Reallocate new
					tmp = _allocator.allocate(_capacity + n);

					// Copy sequence to new array
					it_old = begin();
					it_new = tmp;
					while (it_old != end()) {

						// Copy old to new
						if (it_old != position) {
							*it_new = *it_old;
						// Position found 
						} else {
							for (int i = n; i > 0; i--) {
								*it_new = val;
								it_new++;
							}
						}
						it_old++;
						it_new++;
					}

					// Update private data of vector
					_allocator.deallocate(_start, _capacity);
					_start = tmp;
					_size += n;
					_capacity += n;
				} else 

				}

			}

			// Range
			template<class InputIterator>
			void insert(iterator position, InputIterator first, InputIterator last,
						typename ft::enable_if<!ft::is_integral<InputIterator>::value,
							InputIterator>::type* = NULL) {

				(void)position;
				(void)first;
				(void)last;
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
