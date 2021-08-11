/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 17:07:06 by dda-silv          #+#    #+#             */
/*   Updated: 2021/08/11 10:30:00 by dda-silv         ###   ########.fr       */
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

			typedef typename ft::RandomAccessIterator<value_type> iterator;
			typedef typename ft::RandomAccessIterator<value_type const> const_iterator;
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
			vector(void);
			// Copy
			vector(vector const& other);

/*                                Destructors                                 */
			// Default
			virtual ~vector(void);

/******************************************************************************/
/*                   	    OTHER MEMBER FUNCTIONS                            */
/******************************************************************************/

/*                                 Iterators                                  */

			iterator begin(void);
			const_iterator begin(void) const;

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
