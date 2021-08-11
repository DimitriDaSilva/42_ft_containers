/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RandomAccessIterator.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 17:07:06 by dda-silv          #+#    #+#             */
/*   Updated: 2021/08/11 10:23:30 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOMACCESSITERATOR_HPP
# define RANDOMACCESSITERATOR_HPP

# include <iostream>
# include <string>
# include <iterator>

namespace ft {

	template<class T>
	class RandomAccessIterator {

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
/*                   	        PUBLIC DATA                                   */
/******************************************************************************/


/******************************************************************************/
/*                   	 CONSTRUCTORS & DESTRUCTORS                           */
/******************************************************************************/

/*                                Constructors                                */
			// Default
			RandomAccessIterator(void);
			// Type specific
			RandomAccessIterator(pointer ptr);
			// Copy
			RandomAccessIterator(RandomAccessIterator const& rhs);

/*                                Destructors                                 */
			// Default
			virtual ~RandomAccessIterator(void);


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
			RandomAccessIterator& operator=(RandomAccessIterator const& rhs);

/*                                Comparison                                  */
			bool operator==(RandomAccessIterator const& rhs) const;
			bool operator!=(RandomAccessIterator const& rhs) const;
			bool operator<(RandomAccessIterator const& rhs) const;
			bool operator>(RandomAccessIterator const& rhs) const;
			bool operator<=(RandomAccessIterator const& rhs) const;
			bool operator>=(RandomAccessIterator const& rhs) const;

/*                        Increment / decrement                               */
			RandomAccessIterator& operator++();
			RandomAccessIterator operator++(int);
			RandomAccessIterator& operator--();
			RandomAccessIterator operator--(int);

/*                                Arithmetic                                  */
			RandomAccessIterator operator+(difference_type val) const;
			RandomAccessIterator operator-(difference_type val) const;
			RandomAccessIterator& operator+=(difference_type val);
			RandomAccessIterator& operator-=(difference_type val);

/*                                 Access                                     */
			reference operator*(void) const;
			pointer operator->(void) const;
			reference operator[](difference_type val) const;

		private:
/******************************************************************************/
/*                   	        PRIVATE DATA                                  */
/******************************************************************************/

			pointer _ptr;
	};
}

#endif
