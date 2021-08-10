/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RandomAccessIterator.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 17:07:05 by dda-silv          #+#    #+#             */
/*   Updated: 2021/08/10 11:07:52 by dda-silv         ###   ########.fr       */
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

/******************************************************************************/
/*                   	     GETTERS & SETTERS                                */
/******************************************************************************/


/******************************************************************************/
/*                   	    OTHER CLASS FUNCTIONS                             */
/******************************************************************************/

