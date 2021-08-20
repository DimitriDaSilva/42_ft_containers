/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 15:29:24 by dda-silv          #+#    #+#             */
/*   Updated: 2021/08/12 18:19:12 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

// is_integral is a struct that checks if the type is a fundamental integral
// type, i.e. it's among these types:
// - bool
// - char
// - char16_t - since C++11 so not implemented
// - char32_t - since C++11 so not implemented
// - wchar_t
// - signed char
// - short int
// - int
// - long int
// - long long int
// - unsigned char
// - unsigned short int
// - unsigned int
// - unsigned long int
// - unsigned long long int

namespace ft {

	// The member types, functions and constants are defined in integral_constant.
	template <class T, T v>
	struct integral_constant {
		// Member types
		typedef T value_type;
		typedef integral_constant<T,v> type;

		// Member constants
		static const value_type value = v;

		// Member functions
		operator value_type() const {return value;}
	};

	// true_type and false_type are initializations of integral_constant.
	// For instance, is_integral<char> will have access to true_type's members
	// while is_integral<char *> will have false_type's members
	typedef integral_constant<bool, true> true_type;
	typedef integral_constant<bool, false> false_type;

	// is_integral_type uses partial template specialization to create a list
	// of the valid integral types.
	// If it's a valid integral type it inherits with true_type, else false_type

	// Primary template of the partial template specialization. It's the default
	// struct used by is_integral. The default case inherits from false_type
	template<typename> struct is_integral_type : false_type {};

	// All other partial template specialization inherit from true_type
	template<> struct is_integral_type<bool> : true_type {};

	template<> struct is_integral_type<char> : true_type {};

	template<> struct is_integral_type<wchar_t> : true_type {};

	template<> struct is_integral_type<signed char> : true_type {};

	template<> struct is_integral_type<short int> : true_type {};

	template<> struct is_integral_type<int> : true_type {};

	template<> struct is_integral_type<long int> : true_type {};

	template<> struct is_integral_type<long long int> : true_type {};

	template<> struct is_integral_type<unsigned char> : true_type {};

	template<> struct is_integral_type<unsigned short int> : true_type {};

	template<> struct is_integral_type<unsigned int> : true_type {};

	template<> struct is_integral_type<unsigned long int> : true_type {};

	template<> struct is_integral_type<unsigned long long int> : true_type {};

	// is_integral inherits from is_integral_type to get its correct members
	template<typename T> struct is_integral : is_integral_type<T> {};
}

#endif
