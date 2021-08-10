/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RandomAccessIterator.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 17:07:06 by dda-silv          #+#    #+#             */
/*   Updated: 2021/08/10 11:07:52 by dda-silv         ###   ########.fr       */
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
					bool operator==(RandomAccessIterator const& rhs) const;
					bool operator!=(RandomAccessIterator const& rhs) const;
					bool operator<(RandomAccessIterator const& rhs) const;
					bool operator>(RandomAccessIterator const& rhs) const;
					bool operator<=(RandomAccessIterator const& rhs) const;
					bool operator>=(RandomAccessIterator const& rhs) const;

					RandomAccessIterator& operator++();
					RandomAccessIterator operator++(int val);
					RandomAccessIterator& operator--();
					RandomAccessIterator operator--(int val);
					RandomAccessIterator& operator+=(difference_type val);
					RandomAccessIterator operator+(difference_type val) const;
					//friend RandomAccessIterator operator+(difference_type, RandomAccessIterator const&);
					RandomAccessIterator& operator-=(difference_type val);
					RandomAccessIterator operator-(difference_type val) const;
					difference_type operator-(RandomAccessIterator val) const;

					reference operator*() const;
					pointer operator->() const;
					reference operator[](difference_type val) const;

		protected:
	/******************************************************************************/
	/*                   	       PROTECTED DATA                                 */
	/******************************************************************************/


		private:
	/******************************************************************************/
	/*                   	        PRIVATE DATA                                  */
	/******************************************************************************/

			pointer _ptr;

	};
}


#endif
