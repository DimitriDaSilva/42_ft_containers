/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 17:07:05 by dda-silv          #+#    #+#             */
/*   Updated: 2021/08/11 10:27:15 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"

/******************************************************************************/
/*                   	 CONSTRUCTORS & DESTRUCTORS                           */
/******************************************************************************/

/*                                Constructors                                */

template<class T, class A>
ft::vector<T, A>::vector(void) {
	_size = 0;
	_capacity = 2;
	_max_size = std::numeric_limits<long>::max() / sizeof(T);
	_ptr = _allocator.allocate(_capacity);
}

template<class T, class A>
ft::vector<T, A>::vector(vector const& other) {
	*this = other;
}

/*                                Destructors                                 */

template<class T, class A>
ft::vector<T, A>::~vector(void) {
	_allocator.deallocate(_ptr, _capacity);
}

/******************************************************************************/
/*                   	    OTHER MEMBER FUNCTIONS                            */
/******************************************************************************/

/*                                 Iterators                                  */
template<class T, class A>
typename ft::vector<T, A>::iterator ft::vector<T, A>::begin(void) const {
	return RandomAccessIterator<T>(_ptr);
}
/*                                 Capacity                                   */

template<class T, class A>
typename ft::vector<T, A>::size_type ft::vector<T, A>::size(void) const {
	return _size;
}

template<class T, class A>
typename ft::vector<T, A>::size_type ft::vector<T, A>::max_size(void) const {
	return _max_size;
}

template<class T, class A>
void ft::vector<T, A>::resize(size_type n, value_type val) {
	if (n < _size) {
		for (size_type i = n; i < _size; i++) {
			_allocator.destroy(&_ptr[i]);
		}
		_size = n;
	} else if (n > _size) {
		if (n > _capacity) {
			reserve(n);
		}
		for (size_type i = _size; i < n; i++) {
			_ptr[i] = val;
		}
		_size = n;
	}
}

template<class T, class A>
typename ft::vector<T, A>::size_type ft::vector<T, A>::capacity(void) const {
	return _capacity;
}

template<class T, class A>
bool ft::vector<T, A>::empty(void) const {
	return (_size == 0);
}

template<class T, class A>
void ft::vector<T, A>::reserve(size_type n) {
	if (n > _max_size) {
		throw std::length_error("vector::reserve");
	} else if (n > _capacity) {
		value_type* tmp = _allocator.allocate(n);
		for (size_type i = 0; i < _size; i++) {
			tmp[i] = _ptr[i];
		}
		_allocator.deallocate(_ptr, _capacity);
		_capacity = n;
		_ptr = tmp;
	}
}

/*                                  Modifiers                                 */

template<class T, class A>
void ft::vector<T, A>::push_back(value_type const& val) {
	if (_size == _capacity) {
		reserve(_capacity * 2);
	}
	_ptr[_size] = val;
	_size++;
}

/******************************************************************************/
/*                OVERLOADING OPERATORS (CLASS & NON-CLASS)                   */
/******************************************************************************/

/*                                Assignement                                 */

template<class T, class A>
ft::vector<T, A>& ft::vector<T, A>::operator=(vector const& other) {
	(void)other;

	return *this;
}


/******************************************************************************/
/*                               EXCEPTIONS 								  */
/******************************************************************************/

template<class T, class A>
const char* ft::vector<T, A>::NameException::what(void) const throw () {
	return "Exception message";
}

/******************************************************************************/
/*                       TEMPLATE INSTANTIALISATION                           */
/******************************************************************************/

// We need to tell the compiler which particular template class he will need
// that way we are forcing him to compile them
// Otherwise in the main, we'll be calling an undefined reference
template class ft::vector<std::string>;
template class ft::vector<int>;
template class ft::vector<Buffer>;
