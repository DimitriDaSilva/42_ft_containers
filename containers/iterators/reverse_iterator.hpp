/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 14:34:06 by dda-silv          #+#    #+#             */
/*   Updated: 2021/08/31 18:45:36 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include <stdlib.h>				// NULL

# include "random_access_iterator.hpp"
# include "iterator_traits.hpp"

namespace ft
{
	template<class Iter>
	class reverse_iterator
	{
	public:
/******************************************************************************/
/*                   	        MEMBER TYPES					              */
/******************************************************************************/
		typedef Iter iterator_type;
		typedef
			typename iterator_traits<Iter>::iterator_category
			iterator_category;
		typedef
			typename iterator_traits<Iter>::value_type
			value_type;
		typedef
			typename iterator_traits<Iter>::difference_type
			difference_type;
		typedef
			typename iterator_traits<Iter>::pointer
			pointer;
		typedef
			typename iterator_traits<Iter>::reference
			reference;

/******************************************************************************/
/*                   	 CONSTRUCTORS & DESTRUCTORS                           */
/******************************************************************************/

/*                                Constructors                                */

		// Default
		reverse_iterator() : _it(iterator_type()) {}

		// Initialization
		explicit
		reverse_iterator(iterator_type it) : _it(it) {}

		// Copy
		reverse_iterator(reverse_iterator const& rhs)
			: _it(rhs._it) {}

/*                                Destructors                                 */

		// Default
		virtual
		~reverse_iterator() {}

/******************************************************************************/
/*                   	   OVERLOADING OPERATORS                              */
/******************************************************************************/

/*                                Assignement                                 */

		reverse_iterator&
		operator=(reverse_iterator const& rhs)
		{
			// Self-assignement check
			if (this == &rhs)
				return *this;

			_it = rhs._it;

			return *this;
		}

		// Overload called when trying to copy construct a const_iterator
		// based on an iterator
		operator reverse_iterator<typename ft::random_access_iterator<value_type const> >() const
		{
			return reverse_iterator<typename ft::random_access_iterator<value_type const> >(_it);
		}

/*                        Increment / decrement                               */

		// Pre-increment
		reverse_iterator&
		operator++()
		{
			_it--;

			return *this;
		}

		// Post-increment
		reverse_iterator
		operator++(int)
		{
			reverse_iterator<Iter> tmp(*this);

			_it--;

			return tmp;
		}

		// Pre-decrement
		reverse_iterator&
		operator--()
		{
			_it++;

			return *this;
		}

		// Post-decrement
		reverse_iterator
		operator--(int)
		{
			reverse_iterator<Iter> tmp(*this);

			_it++;

			return tmp;
		}

/*                                Arithmetic                                  */

		reverse_iterator
		operator+(difference_type n) const
		{
			return reverse_iterator(_it - n);
		}

		reverse_iterator
		operator-(difference_type n) const
		{
			return reverse_iterator(_it + n);
		}

		reverse_iterator&
		operator+=(difference_type val)
		{
			_it -= val;

			return *this;
		}

		reverse_iterator&
		operator-=(difference_type val)
		{
			_it += val;

			return *this;
		}

/*                                 Access                                     */

		reference
		operator*() const
		{
			return *(_it - 1);
		}

		pointer
		operator->() const
		{
			return &(operator*());
		}

		reference
		operator[](difference_type val) const
		{
			return _it[-val - 1];
		}

/******************************************************************************/
/*                   	    GETTERS & SETTERS                                 */
/******************************************************************************/

		iterator_type
		base() const
		{
			return _it;
		}

	private:
/******************************************************************************/
/*                   	        PRIVATE DATA                                  */
/******************************************************************************/

		iterator_type	_it;
	};

/******************************************************************************/
/*                        NON-MEMBER FUNCTION OVERLOADS                       */
/******************************************************************************/

/*                                Arithmetic                                  */

	template<class Iterator>
	ft::reverse_iterator<Iterator>
	operator+(typename ft::reverse_iterator<Iterator>::difference_type n,
			ft::reverse_iterator<Iterator> const& rev_it)
	{
		return rev_it + n;
	}

	template<class Iterator>
	typename ft::reverse_iterator<Iterator>::difference_type
	operator-(ft::reverse_iterator<Iterator> const& lhs,
			ft::reverse_iterator<Iterator> const& rhs)
	{
		return rhs.base() - lhs.base();
	}

	template<class Iterator_lhs, class Iterator_rhs>
	typename ft::reverse_iterator<Iterator_lhs>::difference_type
	operator-(ft::reverse_iterator<Iterator_lhs> const & lhs,
				ft::reverse_iterator<Iterator_rhs> const& rhs)
	{
		return rhs.base() - lhs.base();
	}

/*                            Relational operators                            */

	template<class Iterator>
	bool
	operator==(ft::reverse_iterator<Iterator> const & lhs,
				ft::reverse_iterator<Iterator> const& rhs)
	{
		return lhs.base() == rhs.base();
	}

	// For const and non-const comparisons
	template<class Iterator_lhs, class Iterator_rhs>
	bool
	operator==(ft::reverse_iterator<Iterator_lhs> const & lhs,
				ft::reverse_iterator<Iterator_rhs> const& rhs)
	{
		return lhs.base() == rhs.base();
	}

	template<class Iterator>
	bool
	operator!=(ft::reverse_iterator<Iterator> const & lhs,
				ft::reverse_iterator<Iterator> const& rhs)
	{
		return lhs.base() != rhs.base();
	}

	// For const and non-const comparisons
	template<class Iterator_lhs, class Iterator_rhs>
	bool
	operator!=(ft::reverse_iterator<Iterator_lhs> const & lhs,
				ft::reverse_iterator<Iterator_rhs> const& rhs)
	{
		return lhs.base() != rhs.base();
	}

	template<class Iterator>
	bool
	operator<(ft::reverse_iterator<Iterator> const & lhs,
				ft::reverse_iterator<Iterator> const& rhs)
	{
		return lhs.base() < rhs.base();
	}

	// For const and non-const comparisons
	template<class Iterator_lhs, class Iterator_rhs>
	bool
	operator<(ft::reverse_iterator<Iterator_lhs> const & lhs,
				ft::reverse_iterator<Iterator_rhs> const& rhs)
	{
		return lhs.base() < rhs.base();
	}

	template<class Iterator>
	bool
	operator<=(ft::reverse_iterator<Iterator> const & lhs,
				ft::reverse_iterator<Iterator> const& rhs)
	{
		return lhs.base() <= rhs.base();
	}

	// For const and non-const comparisons
	template<class Iterator_lhs, class Iterator_rhs>
	bool
	operator<=(ft::reverse_iterator<Iterator_lhs> const & lhs,
				ft::reverse_iterator<Iterator_rhs> const& rhs)
	{
		return lhs.base() <= rhs.base();
	}

	template<class Iterator>
	bool
	operator>(ft::reverse_iterator<Iterator> const & lhs,
				ft::reverse_iterator<Iterator> const& rhs)
	{
		return lhs.base() > rhs.base();
	}

	// For const and non-const comparisons
	template<class Iterator_lhs, class Iterator_rhs>
	bool
	operator>(ft::reverse_iterator<Iterator_lhs> const & lhs,
				ft::reverse_iterator<Iterator_rhs> const& rhs)
	{
		return lhs.base() > rhs.base();
	}

	template<class Iterator>
	bool
	operator>=(ft::reverse_iterator<Iterator> const & lhs,
				ft::reverse_iterator<Iterator> const& rhs)
	{
		return lhs.base() >= rhs.base();
	}

	// For const and non-const comparisons
	template<class Iterator_lhs, class Iterator_rhs>
	bool
	operator>=(ft::reverse_iterator<Iterator_lhs> const & lhs,
				ft::reverse_iterator<Iterator_rhs> const& rhs)
	{
		return lhs.base() >= rhs.base();
	}
}

#endif
