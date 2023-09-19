/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 13:48:03 by fgeslin           #+#    #+#             */
/*   Updated: 2023/09/19 14:30:01 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP_
# define WHATEVER_HPP_
# pragma once

# define C_WHT "\e[0m"
# define C_BOL "\e[1m"
# define C_ITA "\e[3m"
# define C_UND "\e[4m"
# define C_RED "\e[31m"
# define C_GRN "\e[32m"
# define C_YEL "\e[33m"
# define C_BLU "\e[34m"
# define C_MAG "\e[35m"
# define C_CYA "\e[36m"
# define C_GRY "\e[90m"

# include <iostream>
# include <iomanip>
# include <cmath>
using std::exception;
using std::string;
using std::cout;
using std::cerr;
using std::endl;

template< typename T >
void	swap( T & x, T & y ) {
	T tmp;
	tmp = x;
	x = y;
	y = tmp;
}

template< typename T >
T const &	min( T const & x, T const & y ) {
	return ( x <= y ? x : y );
}

template< typename T >
T const &	max( T const & x, T const & y ) {
	return ( x >= y ? x : y );
}

#endif // WHATEVER_HPP_
