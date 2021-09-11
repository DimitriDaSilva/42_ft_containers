/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 17:07:06 by dda-silv          #+#    #+#             */
/*   Updated: 2021/09/11 18:10:15 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

# include <iterator>	// std::random_access_iterator_tag
# include <cstddef>		// std::ptrdiff_t, NULL

namespace ft
{
	template<class T>
	class random_access_iterator
	{
	public:
/******************************************************************************/
/*                   	        MEMBER TYPES					              */
/******************************************************************************/

		typedef T								value_type;
		typedef value_type&						reference;
		typedef value_type*						pointer;
		typedef value_type const&				const_reference;
		typedef value_type const*				const_pointer;

		typedef typename std::ptrdiff_t			difference_type;
		typedef std::random_access_iterator_tag	iterator_category;

/******************************************************************************/
/*                   	 CONSTRUCTORS & DESTRUCTORS                           */
/******************************************************************************/

/*                                Constructors                                */

		// Default
		random_access_iterator() : _ptr(NULL) {}

		// Type specific
		random_access_iterator(pointer ptr) : _ptr(ptr) {}

		// Copy
		random_access_iterator(random_access_iterator const& rhs)
			: _ptr(rhs._ptr) {}

/*                                Destructors                                 */

		// Default virtual
		~random_access_iterator() {}

/******************************************************************************/
/*                   	   OVERLOADING OPERATORS                              */
/******************************************************************************/

/*                                Assignement                                 */

		random_access_iterator&
		operator=(random_access_iterator const& rhs)
		{
			// Self-assignement check
			if (this == &rhs)
				return *this;

			_ptr = rhs._ptr;

			return *this;
		}

		// Overload called when trying to copy construct a const_iterator
		// based on an iterator
		operator random_access_iterator<value_type const>() const
		{
			return random_access_iterator<value_type const>(_ptr);
		}

/*                            Relational operators                            */

		bool
		operator==(random_access_iterator const& rhs) const
		{
			return _ptr == rhs._ptr;
		}

		template<typename T_lhs, typename T_rhs>
		friend bool
		operator==(ft::random_access_iterator<T_lhs> const& lhs,
				ft::random_access_iterator<T_rhs> const& rhs);

		bool
		operator!=(random_access_iterator const& rhs) const
		{
			return _ptr != rhs._ptr;
		}

		template<typename T_lhs, typename T_rhs>
		friend bool
		operator!=(ft::random_access_iterator<T_lhs> const& lhs,
				ft::random_access_iterator<T_rhs> const& rhs);

		bool
		operator<(random_access_iterator const& rhs) const
		{
			return _ptr < rhs._ptr;
		}

		template<typename T_lhs, typename T_rhs>
		friend bool
		operator<(ft::random_access_iterator<T_lhs> const& lhs,
				ft::random_access_iterator<T_rhs> const& rhs);

		bool
		operator>(random_access_iterator const& rhs) const
		{
			return _ptr > rhs._ptr;
		}

		template<typename T_lhs, typename T_rhs>
		friend bool
		operator>(ft::random_access_iterator<T_lhs> const& lhs,
				ft::random_access_iterator<T_rhs> const& rhs);

		bool
		operator<=(random_access_iterator const& rhs) const
		{
			return _ptr <= rhs._ptr;
		}

		template<typename T_lhs, typename T_rhs>
		friend bool
		operator<=(ft::random_access_iterator<T_lhs> const& lhs,
				ft::random_access_iterator<T_rhs> const& rhs);

		bool
		operator>=(random_access_iterator const& rhs) const
		{
			return _ptr >= rhs._ptr;
		}

		template<typename T_lhs, typename T_rhs>
		friend bool
		operator>=(ft::random_access_iterator<T_lhs> const& lhs,
				ft::random_access_iterator<T_rhs> const& rhs);

/*                        Increment / decrement                               */

		// Pre-increment
		random_access_iterator&
		operator++()
		{
			_ptr++;

			return *this;
		}

		// Post-increment
		random_access_iterator
		operator++(int)
		{
			random_access_iterator<T> tmp(*this);

			_ptr++;

			return tmp;
		}

		// Pre-decrement
		random_access_iterator&
		operator--()
		{
			_ptr--;

			return *this;
		}

		// Post-decrement
		random_access_iterator
		operator--(int)
		{
			random_access_iterator<T> tmp(*this);

			_ptr--;

			return tmp;
		}

/*                                Arithmetic                                  */

		random_access_iterator
		operator+(difference_type val) const
		{
			return random_access_iterator<T>(_ptr + val);
		}

		difference_type
		operator+(random_access_iterator const& rhs) const
		{
			return _ptr + rhs._ptr;
		}

		random_access_iterator
		operator-(difference_type val) const
		{
			return random_access_iterator<T>(_ptr - val);
		}

		difference_type
		operator-(random_access_iterator const& rhs) const
		{
			return _ptr - rhs._ptr;
		}

		random_access_iterator&
		operator+=(difference_type val)
		{
			_ptr += val;

			return *this;
		}

		random_access_iterator&
		operator-=(difference_type val)
		{
			_ptr -= val;

			return *this;
		}

/*                                 Access                                     */

		reference
		operator*() const
		{
			return *_ptr;
		}

		pointer
		operator->() const
		{
			return _ptr;
		}

		reference
		operator[](difference_type val) const
		{
			return *(_ptr + val);
		}

	private:
/******************************************************************************/
/*                   	        PRIVATE DATA                                  */
/******************************************************************************/

		pointer _ptr;
	};

/******************************************************************************/
/*                        NON-MEMBER FUNCTION OVERLOADS                       */
/******************************************************************************/

/*                            Relational operators                            */

		template<typename T_lhs, typename T_rhs>
		bool
		operator==(ft::random_access_iterator<T_lhs> const& lhs,
				ft::random_access_iterator<T_rhs> const& rhs)
		{
			return (lhs._ptr == rhs._ptr);
		}

		template<typename T_lhs, typename T_rhs>
		bool
		operator!=(ft::random_access_iterator<T_lhs> const& lhs,
				ft::random_access_iterator<T_rhs> const& rhs)
		{
			return (lhs._ptr != rhs._ptr);
		}

		template<typename T_lhs, typename T_rhs>
		bool
		operator<(ft::random_access_iterator<T_lhs> const& lhs,
				ft::random_access_iterator<T_rhs> const& rhs)
		{
			return (lhs._ptr < rhs._ptr);
		}

		template<typename T_lhs, typename T_rhs>
		bool
		operator>(ft::random_access_iterator<T_lhs> const& lhs,
				ft::random_access_iterator<T_rhs> const& rhs)
		{
			return (lhs._ptr > rhs._ptr);
		}

		template<typename T_lhs, typename T_rhs>
		bool
		operator<=(ft::random_access_iterator<T_lhs> const& lhs,
				ft::random_access_iterator<T_rhs> const& rhs)
		{
			return (lhs._ptr <= rhs._ptr);
		}

		template<typename T_lhs, typename T_rhs>
		bool
		operator>=(ft::random_access_iterator<T_lhs> const& lhs,
				ft::random_access_iterator<T_rhs> const& rhs)
		{
			return (lhs._ptr >= rhs._ptr);
		}

/*                                Arithmetic                                  */

	template<class T>
	ft::random_access_iterator<T>
	operator+(typename ft::random_access_iterator<T>::difference_type n,
				ft::random_access_iterator<T> const& rhs)
	{
		return rhs + n;
	}
}

#endif
