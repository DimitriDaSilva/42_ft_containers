/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 11:13:07 by dda-silv          #+#    #+#             */
/*   Updated: 2021/08/30 10:36:43 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <functional>	// std::less
# include <memory>		// std::allocator
# include <utility>		// std::pair

# include "red_black_tree.hpp"

namespace ft
{
	template<class Key,
	   class T,
	   class Compare = std::less<Key>,
	   class Alloc = std::allocator<std::pair<Key const, T> >
	   >
	class map
	{

	};
}

#endif
