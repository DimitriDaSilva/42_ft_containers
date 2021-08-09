/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 17:07:06 by dda-silv          #+#    #+#             */
/*   Updated: 2021/08/09 12:19:09 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include "main.hpp"
# include <iostream>
# include <string>
# include <limits>
# include <stdexcept> // std::lenght_error

namespace ft {

	template<class T, class A = std::allocator<T> >
	class vector {

		public:
/******************************************************************************/
/*                   	        MEMBER TYPES					              */
/******************************************************************************/

			typedef A allocator_type;
			typedef typename A::value_type value_type; 
			typedef typename A::reference reference;
			typedef typename A::const_reference const_reference;
			typedef typename A::difference_type difference_type;
			typedef typename A::size_type size_type;

/******************************************************************************/
/*                   	        MEMBER FUNCTIONS                              */
/******************************************************************************/
/******************************************************************************/
/*                   	 CONSTRUCTORS & DESTRUCTORS                           */
/******************************************************************************/

/*                                Constructors                                */
			// Default
			vector(void);
			// Copy
			vector(vector const& other);

/*                                Destructors                                 */
			// Default
			virtual ~vector(void);

/******************************************************************************/
/*                   	    OTHER MEMBER FUNCTIONS                            */
/******************************************************************************/

/*                                  Capacity                                  */
			size_type size(void) const;
			size_type max_size(void) const;
			void resize (size_type n, value_type val = value_type());
			size_type capacity(void) const;
			bool empty() const;
			void reserve (size_type n);

/*                                  Modifiers                                 */
			void push_back (value_type const& val);

/******************************************************************************/
/*                   	   OVERLOADING OPERATORS                              */
/******************************************************************************/

/*                                Assignement                                 */
			vector& operator=(vector const& other);

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

			value_type*		_ptr;
			allocator_type	_allocator;
			size_t			_size;
			size_t			_capacity;
			size_t			_max_size;
	};

/******************************************************************************/
/*                          NON-CLASS FUNCTIONS		                          */
/******************************************************************************/

}

#endif
