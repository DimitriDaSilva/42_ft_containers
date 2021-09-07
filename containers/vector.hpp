/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 17:07:06 by dda-silv          #+#    #+#             */
/*   Updated: 2021/09/07 13:31:25 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <limits>		// std::numeric_limits
# include <stdexcept>	// std::lenght_error, std::out_of_range
# include <memory>		// std::allocator

# include "random_access_iterator.hpp"
# include "reverse_iterator.hpp"
# include "distance.hpp"
# include "enable_if.hpp"
# include "is_integral.hpp"
# include "lexicographical_compare.hpp"

namespace ft
{
	template<class T, class A = std::allocator<T> >
	class vector
	{
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

		typedef ft::random_access_iterator<value_type> iterator;
		typedef ft::random_access_iterator<value_type const> const_iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

/******************************************************************************/
/*                   	        MEMBER FUNCTIONS                              */
/******************************************************************************/
/******************************************************************************/
/*                   	 CONSTRUCTORS & DESTRUCTORS                           */
/******************************************************************************/

/*                                Constructors                                */

		// Empty (default)
		explicit
		vector(allocator_type const& alloc = allocator_type()) :
			_start(NULL),
			_allocator(alloc),
			_size(0),
			_capacity(0),
			_max_size(std::numeric_limits<long>::max() / sizeof(value_type))
		{}

		// Fill
		explicit
		vector(size_type n,
				value_type const& val = value_type(),
				allocator_type const& alloc = allocator_type()) :
			_start(NULL),
			_allocator(alloc),
			_size(0),
			_capacity(0),
			_max_size(std::numeric_limits<long>::max() / sizeof(value_type))
		{
			reserve(n);

			for (size_type i = 0; i < n; i++)
				_allocator.construct(_start + i, val);

			_size = n;
		}

		// Range
		template<class InputIterator>
		vector(InputIterator first,
				InputIterator last,
				allocator_type const& alloc = allocator_type(),
				typename ft::enable_if<!ft::is_integral<InputIterator>::value,
										InputIterator>::type* = NULL) :
			_start(NULL),
			_allocator(alloc),
			_size(0),
			_capacity(0),
			_max_size(std::numeric_limits<long>::max() / sizeof(value_type))
		{
			reserve(ft::distance(first, last));

			for (iterator it_arg = first; it_arg != last; it_arg++)
			{
				_allocator.construct(_start + _size, *it_arg);
				_size++;
			}
		}

		// Copy
		vector(vector const& rhs) :
			_start(NULL),
			_allocator(rhs._allocator),
			_size(0),
			_capacity(0),
			_max_size(std::numeric_limits<long>::max() / sizeof(value_type))
		{
			*this = rhs;
		}

/*                                Destructors                                 */

		// Default
		virtual
		~vector()
		{
			clear();
			_allocator.deallocate(_start, _capacity);
		}

/******************************************************************************/
/*                   	   OVERLOADING OPERATORS                              */
/******************************************************************************/

/*                                Assignement                                 */

		vector&
		operator=(vector const& rhs)
		{
			// Self-assignement check
			if (this == &rhs)
				return *this;

			// Deep copy of the rhs sequence
			assign(rhs.begin(), rhs.end());

			return *this;
		}

/******************************************************************************/
/*                   	    OTHER MEMBER FUNCTIONS                            */
/******************************************************************************/

/*                                 Iterators                                  */

		// Forward
		iterator
		begin()
		{
			return _start;
		}

		const_iterator
		begin() const
		{
			return _start;
		}

		iterator
		end()
		{
			if (empty())
				return begin();
			return _start + _size;
		}

		const_iterator
		end() const
		{
			if (empty())
				return begin();
			return _start + _size;
		}

		// Reverse
		reverse_iterator
		rbegin()
		{
			if (empty())
				return rend();
			return reverse_iterator(_start + _size);
		}

		const_reverse_iterator
		rbegin() const
		{
			if (empty())
				return rend();
			return const_reverse_iterator(_start + _size);
		}

		reverse_iterator
		rend()
		{
			return reverse_iterator(_start);
		}

		const_reverse_iterator
		rend() const
		{
			return const_reverse_iterator(_start);
		}

/*                                  Capacity                                  */

		size_type
		size() const
		{
			return _size;
		}

		size_type
		max_size() const
		{
			return _max_size;
		}

		void
		resize(size_type n, value_type val = value_type())
		{
			// Reduced content to its first n elements
			if (n < _size)
			{
				// We also need to destroy items beyond size
				// Destroy doesn't deallocate item so we don't need to
				// change _capacity (or destroy beyond _size)
				for (size_type i = n; i < _size; i++)
					_allocator.destroy(&_start[i]);
				_size = n;
			}
			else if (n > _size)
			{
				if (n > _capacity)
					reserve(n);
				for (size_type i = _size; i < n; i++)
					_allocator.construct(&_start[i], val);
				_size = n;
			}
		}

		size_type
		capacity() const
		{
			return _capacity;
		}

		bool
		empty() const
		{
			return _size == 0;
		}

		// Change _capacity
		void
		reserve(size_type n)
		{
			// We need to throw we try to allocate more than max_size
			if (n > _max_size)
				throw std::length_error("reserve:: cannot increase capacity beyond max_size");
			else if (n > _capacity)
			{
				// Allocate for n size
				value_type* new_vec = _allocator.allocate(n);
				size_type	tmp = _size;

				// Copy existing sequence
				for (size_type i = 0; i < _size; i++)
					_allocator.construct(&new_vec[i], _start[i]);

				// Update data
				this->~vector();
				_start = new_vec;
				_size = tmp;
				_capacity = n;
			}
		}

/*                               Element access                               */

		reference
		operator[](size_type n)
		{
			return *(_start + n);
		}

		const_reference
		operator[](size_type n) const
		{
			return *(_start + n);
		}

		reference
		at(size_type n)
		{
			if (_size <= n)
				throw std::out_of_range("at:: out of range index");
			return *(_start + n);
		}

		const_reference
		at(size_type n) const
		{
			if (_size <= n)
				throw std::out_of_range("at:: out of range index");
			return *(_start + n);
		}

		reference
		front()
		{
			return *_start;
		}

		const_reference
		front() const
		{
			return *_start;
		}

		reference
		back()
		{
			return *(_start + _size - 1);
		}

		const_reference
		back() const
		{
			return *(_start + _size - 1);
		}

/*                                  Modifiers                                 */

		// Range
		template<typename InputIterator>
		void
		assign(InputIterator first,
				InputIterator last,
				typename ft::enable_if<!ft::is_integral<InputIterator>::value,
					InputIterator>::type* = NULL)
		{
			// Destroy existing elements
			clear();

			// Setting new elements
			insert(begin(), first, last);
		}

		// Fill
		void
		assign(size_type n, const value_type& val)
		{
			// Destroy existing elements
			clear();

			// Setting new elements
			insert(begin(), n, val);
		}

		void
		push_back(value_type const& val)
		{
			if (empty())
				reserve(2);
			else if (_size == _capacity)
				reserve(_capacity * 2);

			_allocator.construct(&_start[_size], val);
			_size++;
		}

		void
		pop_back()
		{
			_allocator.destroy(&_start[_size - 1]);
			_size--;
		}

		// Single element
		iterator
		insert(iterator position, const value_type& val)
		{
			iterator	ret_position = NULL;
			value_type*	new_vec;
			size_type	new_size = _size + 1;
			size_type	new_capacity = _capacity == 0 ? 2 : _capacity * 2;
			iterator 	it_old;
			iterator 	it_new;

			// New element requires reallocation because vector is full
			if (new_size > _capacity)
			{
				// Reallocate new. If empty, size 2, otherwise * 2
				new_vec = _allocator.allocate(new_capacity);

				// Copy sequence to new array
				it_old = begin();
				it_new = new_vec;
				// We need to parse until we didn't reach the end AND we haven't
				// found the position
				while (it_old != end() || ret_position == NULL)
				{
					// Position found
					if (it_old == position)
					{
						ret_position = it_new;
						_allocator.construct(&*it_new++, val);
					}
					// In the case the position is the last element, we need to
					// make sure we won't be constructing beyond the sequence
					if (it_old != end())
						_allocator.construct(&*it_new++, *it_old++);
				}
				// Update private data of vector
				this->~vector();
				_start = new_vec;
				_size = new_size;
				_capacity = new_capacity;
			}
			// No need to reallocate so iterator position will still be valid
			else
			{
				insert(position, 1, val);
				ret_position = position;
			}

			return ret_position;
		}

		// Fill
		void
		insert(iterator position, size_type n, const value_type& val)
		{
			value_type*	new_vec;
			size_type	new_size = _size + n;
			size_type	new_capacity = _capacity == 0 ? 2 : _capacity;
			iterator 	it_old;
			iterator 	it_new;
			int 		i;

			// New element requires reallocation because vector is full
			if (new_size > _capacity)
			{
				// Get new capacity
				while (new_size > new_capacity)
					new_capacity *= 2;

				// Reallocate new
				new_vec = _allocator.allocate(new_capacity);

				// Copy sequence to new array
				it_old = begin();
				it_new = new_vec;
				i = n;
				while (it_old != end() || i > 0)
				{
					// Position found
					if (it_old == position)
					{
						while (i--)
							_allocator.construct(&*it_new++, val);
					}

					// Copy old to new
					if (it_old != end())
						_allocator.construct(&*it_new++, *it_old++);
				}
				// Update private data of vector
				this->~vector();
				_start = new_vec;
				_size = new_size;
				_capacity = new_capacity;
			}
			else
			{
				// We offset the whole vector by n one item at a time
				// We need to start by the end to avoid overwritting values
				for (reverse_iterator it = rbegin() - n;
						it != reverse_iterator(position) - n;
						it++)
				{
					_allocator.construct(&*it, *(it + n));
					_allocator.destroy(&*(it + n));
				}

				// Setting the new values before position
				for (iterator it = position; it != position + n; it++)
					_allocator.construct(&*it, val);

				//Update private data of vector
				_size += n;
			}
		}

		// Range
		template<class InputIterator>
		void
		insert(iterator position, InputIterator first, InputIterator last,
				typename ft::enable_if<!ft::is_integral<InputIterator>::value,
					InputIterator>::type* = NULL)
		{
			value_type*		new_vec;
			difference_type	distance = ft::distance(first, last);
			size_type		new_size = _size + distance;
			size_type		new_capacity = _capacity == 0 ? 2 : _capacity;
			iterator 		it_old;
			iterator 		it_new;

			// New element requires reallocation because vector is full
			if (new_size > _capacity)
			{
				// Get new capacity
				while (new_size > new_capacity)
					new_capacity *= 2;

				// Reallocate new
				new_vec = _allocator.allocate(new_capacity);

				// Copy sequence to new array
				it_old = begin();
				it_new = new_vec;
				while (it_old != end() || distance > 0)
				{
					// Position found
					if (it_old == position)
					{
						while (distance--)
							_allocator.construct(&*it_new++, *first++);
					}

					// Copy old to new
					if (it_old != end())
						_allocator.construct(&*it_new++, *it_old++);
				}

				// Update private data of vector
				this->~vector();
				_start = new_vec;
				_size = new_size;
				_capacity = new_capacity;
			}
			// No reallocation
			else
			{
				// We offset the whole vector by distance one item at a time
				// We need to start by the end to avoid overwritting values
				for (reverse_iterator it = rbegin() - distance;
						it != reverse_iterator(position) - distance;
						it++)
				{
					_allocator.construct(&*it, *(it + distance));
					_allocator.destroy(&*(it + distance));
				}

				// Setting the new values before position
				for (iterator it = position; it != position + distance; it++, first++)
					_allocator.construct(&*it, *first);

				// Update private data of vector
				_size += distance;
			}
		}

		// Erase a single element
		iterator
		erase(iterator position)
		{
			// Destroy the element at position
			_allocator.destroy(&*position);

			// Offset all the elements by one to fill the gap
			for (iterator it = position; it + 1 != end(); it++)
			{
				_allocator.construct(&*it, *(it + 1));
				_allocator.destroy(&*(it + 1));
			}

			_size--;

			return position;
		}

		// Erase a range of elements
		iterator
		erase(iterator first, iterator last)
		{
			difference_type	distance = ft::distance(first, last);
			iterator save_first = first;

			// Destroy the range of elements
			while (first != last)
				_allocator.destroy(&*first++);

			// Offset all the elements by distance to fill the gap
			for (iterator it = save_first; it + distance != end(); it++)
			{
				_allocator.construct(&*it, *(it + distance));
				_allocator.destroy(&*(it + distance));
			}

			_size -= distance;

			return save_first;
		}

		void
		swap(vector& rhs)
		{
			vector tmp(rhs);
			rhs = *this;
			*this = tmp;
		}

		void
		clear()
		{
			while (!empty())
				pop_back();
		}

/*                                  Allocator                                 */

		allocator_type
		get_allocator() const
		{
			return _allocator;
		}

/******************************************************************************/
/*                               EXCEPTIONS 								  */
/******************************************************************************/

		class NameException : public std::exception
		{
			public:
				const char* what() const throw () {}
		};

	private:
/******************************************************************************/
/*                   	        PRIVATE DATA                                  */
/******************************************************************************/

		pointer			_start;
		allocator_type	_allocator;
		size_type		_size;
		size_type		_capacity;
		size_type		_max_size;
	};

/******************************************************************************/
/*                        NON-MEMBER FUNCTION OVERLOADS                       */
/******************************************************************************/

/*                              Relational operators                          */

	template<class T, class A>
	bool
	operator==(vector<T, A> const& lhs, vector<T, A> const& rhs)
	{
		if (lhs.size() != rhs.size())
			return false;

		return equal(lhs.begin(), lhs.begin(), rhs.begin());
	}

	template<class T, class A>
	bool
	operator!=(vector<T, A> const& lhs, vector<T, A> const& rhs)
	{
		return !(lhs == rhs);
	}

	template<class T, class A>
	bool
	operator<(vector<T, A> const& lhs, vector<T, A> const& rhs)
	{
		return lexicographical_compare(lhs.begin(),
										lhs.end(),
										rhs.begin(),
										rhs.end());

	}

	template<class T, class A>
	bool
	operator<=(vector<T, A> const& lhs, vector<T, A> const& rhs)
	{
		return !(rhs < lhs);
	}

	template<class T, class A>
	bool
	operator>(vector<T, A> const& lhs, vector<T, A> const& rhs)
	{
		return (rhs < lhs);
	}

	template<class T, class A>
	bool
	operator>=(vector<T, A> const& lhs, vector<T, A> const& rhs)
	{
		return !(lhs < rhs);
	}

/*                                  Swap                                      */

	template<class T, class A>
	void
	swap(vector<T, A>& lhs, vector<T, A>& rhs)
	{
		lhs.swap(rhs);
	}
}

#endif
