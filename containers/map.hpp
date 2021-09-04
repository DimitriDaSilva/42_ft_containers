/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 11:13:07 by dda-silv          #+#    #+#             */
/*   Updated: 2021/08/30 12:00:23 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <functional>	// std::less
# include <memory>		// std::allocator

# include "red_black_tree.hpp"
# include "pair.hpp"
# include "less.hpp"

namespace ft
{
	template<class Key,
	   class T,
	   class Compare = ft::less<Key>,
	   class Alloc = std::allocator<ft::pair<Key const, T> >
	   >
	class map
	{

	};
}

#endif
