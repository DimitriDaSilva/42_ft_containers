/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 15:36:45 by dda-silv          #+#    #+#             */
/*   Updated: 2021/08/27 19:31:30 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include <cstddef>		// std::size_t
# include <deque>

# include "vector.hpp"
# include <vector>

namespace ft
{
	template<class T, class Container = ft::vector<T> >
	class stack
	{
	public:
/******************************************************************************/
/*                   	        MEMBER TYPES					              */
/******************************************************************************/

		typedef T value_type;
		typedef Container container_type;
		typedef std::size_t size_type;

/******************************************************************************/
/*                   	        MEMBER FUNCTIONS                              */
/******************************************************************************/

/*                                Constructor                                 */

		explicit
		stack(container_type const& ctnr = container_type()) :
			_ctnr(ctnr) {}

		bool
		empty() const
		{
			return _ctnr.empty();
		}

		size_type
		size() const
		{
			return _ctnr.size();
		}

		value_type&
		top()
		{
			return _ctnr.back();
		}

		value_type const&
		top() const
		{
			return _ctnr.back();
		}

		void
		push(value_type const& val)
		{
			_ctnr.push_back(val);
		}

		void
		pop()
		{
			_ctnr.pop_back();
		}

		template<class U, class Ctnr>
		friend bool operator==(stack<U, Ctnr> const& lhs, stack<U, Ctnr> const& rhs);

		template<class U, class Ctnr>
		friend bool operator!=(stack<U, Ctnr> const& lhs, stack<U, Ctnr> const& rhs);

		template<class U, class Ctnr>
		friend bool operator<(stack<U, Ctnr> const& lhs, stack<U, Ctnr> const& rhs);

		template<class U, class Ctnr>
		friend bool operator<=(stack<U, Ctnr> const& lhs, stack<U, Ctnr> const& rhs);

		template<class U, class Ctnr>
		friend bool operator>(stack<U, Ctnr> const& lhs, stack<U, Ctnr> const& rhs);

		template<class U, class Ctnr>
		friend bool operator>=(stack<U, Ctnr> const& lhs, stack<U, Ctnr> const& rhs);

	private:
/******************************************************************************/
/*                   	        PRIVATE DATA                                  */
/******************************************************************************/

		container_type	_ctnr;
	};

/******************************************************************************/
/*                        NON-MEMBER FUNCTION OVERLOADS                       */
/******************************************************************************/

	template<class T, class Container>
	bool
	operator==(ft::stack<T, Container> const& lhs, ft::stack<T, Container> const& rhs)
	{
		return (lhs._ctnr == rhs._ctnr);
	}

	template<class T, class Container>
	bool
	operator!=(ft::stack<T, Container> const& lhs, ft::stack<T, Container> const& rhs)
	{
		return (lhs._ctnr != rhs._ctnr);
	}

	template<class T, class Container>
	bool
	operator<(ft::stack<T, Container> const& lhs, ft::stack<T, Container> const& rhs)
	{
		return (lhs._ctnr < rhs._ctnr);
	}

	template<class T, class Container>
	bool
	operator<=(ft::stack<T, Container> const& lhs, ft::stack<T, Container> const& rhs)
	{
		return (lhs._ctnr <= rhs._ctnr);
	}

	template<class T, class Container>
	bool
	operator>(ft::stack<T, Container> const& lhs, ft::stack<T, Container> const& rhs)
	{
		return (lhs._ctnr > rhs._ctnr);
	}

	template<class T, class Container>
	bool
	operator>=(ft::stack<T, Container> const& lhs, ft::stack<T, Container> const& rhs)
	{
		return (lhs._ctnr >= rhs._ctnr);
	}
}

#endif
