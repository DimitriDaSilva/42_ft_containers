/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 17:07:05 by dda-silv          #+#    #+#             */
/*   Updated: 2021/08/08 14:52:39 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"

/******************************************************************************/
/*                   	 CONSTRUCTORS & DESTRUCTORS                           */
/******************************************************************************/

/*                                Constructors                                */

template<class T, class U>
ft::vector<T, U>::vector(void) {
}

template<class T, class U>
ft::vector<T, U>::vector(vector const& other) {
	*this = other;
}

/*                                Destructors                                 */

template<class T, class U>
ft::vector<T, U>::~vector(void) {}

/******************************************************************************/
/*                OVERLOADING OPERATORS (CLASS & NON-CLASS)                   */
/******************************************************************************/

/*                                Assignement                                 */

template<class T, class U>
ft::vector<T, U>& ft::vector<T, U>::operator=(vector const& other) {
	(void)other;

	return *this;
}

/******************************************************************************/
/*                   	     GETTERS & SETTERS                                */
/******************************************************************************/


/******************************************************************************/
/*                   	    OTHER CLASS FUNCTIONS                             */
/******************************************************************************/

/******************************************************************************/
/*                               EXCEPTIONS 								  */
/******************************************************************************/

template<class T, class U>
const char* ft::vector<T, U>::NameException::what(void) const throw () {
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
