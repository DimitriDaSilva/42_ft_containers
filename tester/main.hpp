/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 11:04:34 by dda-silv          #+#    #+#             */
/*   Updated: 2021/09/07 10:44:40 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HPP
# define MAIN_HPP

# include <iostream>	// std::cout
# include <stdlib.h>	// atoi
# include <sstream>		// std::ostringstream

# include "test_containers.hpp"
# include "test_others.hpp"
# include "test_wrappers.hpp"

# define SSTR( x ) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

extern int g_seed;

#endif
