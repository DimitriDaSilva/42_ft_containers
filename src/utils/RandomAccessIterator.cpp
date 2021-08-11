/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RandomAccessIterator.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 17:07:05 by dda-silv          #+#    #+#             */
/*   Updated: 2021/08/11 10:22:30 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RandomAccessIterator.hpp"

/******************************************************************************/
/*                   	 CONSTRUCTORS & DESTRUCTORS                           */
/******************************************************************************/

/*                                Constructors                                */

template<class T>
ft::RandomAccessIterator<T>::RandomAccessIterator(void) {
	_ptr = NULL;
}

template<class T>
ft::RandomAccessIterator<T>::RandomAccessIterator(pointer ptr) {
	_ptr = ptr;
}

template<class T>
ft::RandomAccessIterator<T>::RandomAccessIterator(RandomAccessIterator const& rhs) {
	*this = rhs;
}

/*                                Destructors                                 */

template<class T>
ft::RandomAccessIterator<T>::~RandomAccessIterator(void) {}

/******************************************************************************/
/*                OVERLOADING OPERATORS (CLASS & NON-CLASS)                   */
/******************************************************************************/

/*                                Assignement                                 */

template<class T>
ft::RandomAccessIterator<T>& ft::RandomAccessIterator<T>::operator=(RandomAccessIterator const& rhs) {
	_ptr = rhs._ptr;

	return *this;
}

/*                                Comparison                                  */

template<class T>
bool ft::RandomAccessIterator<T>::operator==(RandomAccessIterator const& rhs) const {
	return _ptr == rhs._ptr;
}

template<class T>
bool ft::RandomAccessIterator<T>::operator!=(RandomAccessIterator const& rhs) const {
	return _ptr != rhs._ptr;
}

template<class T>
bool ft::RandomAccessIterator<T>::operator<(RandomAccessIterator const& rhs) const {
	return _ptr < rhs._ptr;
}

template<class T>
bool ft::RandomAccessIterator<T>::operator>(RandomAccessIterator const& rhs) const {
	return _ptr > rhs._ptr;
}

template<class T>
bool ft::RandomAccessIterator<T>::operator<=(RandomAccessIterator const& rhs) const {
	return _ptr <= rhs._ptr;
}

template<class T>
bool ft::RandomAccessIterator<T>::operator>=(RandomAccessIterator const& rhs) const {
	return _ptr >= rhs._ptr;
}

/*                        Increment / decrement                               */

// Pre-increment
template<class T>
ft::RandomAccessIterator<T>& ft::RandomAccessIterator<T>::operator++(void) {
	_ptr++;

	return *this;
}

// Post-increment
template<class T>
ft::RandomAccessIterator<T> ft::RandomAccessIterator<T>::operator++(int) {
	RandomAccessIterator<T> tmp(*this);

	_ptr++;

	return tmp;
}

// Pre-decrement
template<class T>
ft::RandomAccessIterator<T>& ft::RandomAccessIterator<T>::operator--(void) {
	_ptr--;

	return *this;
}

// Post-decrement
template<class T>
ft::RandomAccessIterator<T> ft::RandomAccessIterator<T>::operator--(int) {
	RandomAccessIterator<T> tmp(*this);

	_ptr--;

	return tmp;
}

/*                                Arithmetic                                  */

template<class T>
ft::RandomAccessIterator<T> ft::RandomAccessIterator<T>::operator+(difference_type val) const {
	RandomAccessIterator<T> tmp(_ptr + val);

	return tmp;
}

template<class T>
ft::RandomAccessIterator<T> ft::RandomAccessIterator<T>::operator-(difference_type val) const {
	RandomAccessIterator<T> tmp(_ptr - val);

	return tmp;
}

template<class T>
ft::RandomAccessIterator<T>& ft::RandomAccessIterator<T>::operator+=(difference_type val) {
	_ptr += val;

	return *this;
}

template<class T>
ft::RandomAccessIterator<T>& ft::RandomAccessIterator<T>::operator-=(difference_type val) {
	_ptr -= val;

	return *this;
}

/*                                 Access                                     */

// Returns the value pointed by address
template<class T>
typename ft::RandomAccessIterator<T>::reference ft::RandomAccessIterator<T>::operator*(void) const {
	return *_ptr;
}

// Returns the address of the pointer
template<class T>
typename ft::RandomAccessIterator<T>::pointer ft::RandomAccessIterator<T>::operator->(void) const {
	return _ptr;
}

// Offsetting the pointer
template<class T>
typename ft::RandomAccessIterator<T>::reference ft::RandomAccessIterator<T>::operator[](difference_type val) const {
	return *(_ptr + sizeof(value_type) * val);
}
