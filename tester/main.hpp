/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 11:04:34 by dda-silv          #+#    #+#             */
/*   Updated: 2021/09/10 09:53:15 by dda-silv         ###   ########.fr       */
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

template<typename T>
std::string
ft_itoa(T n)
{
        std::ostringstream ss;

        ss << n;

        return ss.str();
}

extern int g_seed;

#endif
