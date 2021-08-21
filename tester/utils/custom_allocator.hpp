/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_allocator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 11:00:54 by dda-silv          #+#    #+#             */
/*   Updated: 2021/08/21 23:00:23 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUSTOM_ALLOCATOR_HPP
# define CUSTOM_ALLOCATOR_HPP

# include <cstddef>     // std::ptrdiff_t, std::size_t
# include <limits>      // std::numeric_limits

template<class T> class custom_allocator;

template<>
class custom_allocator<void>
{
    public:
        typedef void              value_type;
        typedef value_type*       pointer;
        typedef value_type const* const_pointer;
        typedef std::size_t       size_type;
        typedef std::ptrdiff_t    difference_type;

        template<class U>
        struct rebind
        {
            typedef custom_allocator<U> other;
        };
    };

template<class T>
class custom_allocator
{
public:
    typedef T                 value_type;
    typedef value_type&       reference;
    typedef value_type const& const_reference;
    typedef value_type*       pointer;
    typedef value_type const* const_pointer;
    typedef std::size_t       size_type;
    typedef std::ptrdiff_t    difference_type;

    template<class U>
    struct rebind
    {
        typedef custom_allocator<U> other;
    };

    custom_allocator() throw() {}  // not required, unless used
    template<class U> custom_allocator(custom_allocator<U> const&) throw() {}

    pointer
    allocate(size_type n, custom_allocator<void>::const_pointer = 0)
    {
        return static_cast<pointer>(::operator new (n*sizeof(value_type)));
    }

    void
    deallocate(pointer p, size_type)
    {
        ::operator delete(p);
    }

    void
    construct(pointer p, value_type const& val)
    {
        ::new(p) value_type(val);
    }

    void
    destroy(pointer p)
    {
        p->~value_type();
    }

    size_type
    max_size() const throw()
    {
        return std::numeric_limits<size_type>::max() / sizeof(value_type);
    }

    pointer
    address(reference x) const
    {
        return &x;
    }

    const_pointer
    address(const_reference x) const
    {
        return &x;
    }
};

template<class T, class U>
bool
operator==(custom_allocator<T> const&, custom_allocator<U> const&)
{
    return true;
}

template<class T, class U>
bool
operator!=(custom_allocator<T> const& x, custom_allocator<U> const& y)
{
    return !(x == y);
}

#endif
