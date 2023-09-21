/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:32:17 by fgeslin           #+#    #+#             */
/*   Updated: 2023/09/21 11:52:32 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP_
# define ITER_HPP_
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
void	iter( T *tab, size_t len, void (*f)(T &) ) {
	cout << C_YEL << "  ---- Calling iter: ----  \n" << C_WHT;
	for ( size_t i = 0; i < len; i++ ) {
		f( tab[i] );
	}
}

template< typename T >
void	print( T &i ) {
	cout << std::setw(12) << i << endl;
}

#endif // ITER_HPP_
