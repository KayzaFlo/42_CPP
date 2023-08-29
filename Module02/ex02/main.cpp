/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 14:20:39 by fgeslin           #+#    #+#             */
/*   Updated: 2023/07/21 15:13:58 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << "a = " << a << std::endl;
	std::cout << "++a = " <<  ++a << std::endl;
	std::cout << "a = " <<  a << std::endl;
	std::cout << "a++ = " <<  a++ << std::endl;
	std::cout << "a = " <<  a << std::endl;
	std::cout << "b = " <<  b << std::endl;
	std::cout << "b / 2 = " <<  b / 2 << std::endl;
	a = a * 2;
	std::cout << "a = a * 2 = " <<  a << std::endl;
	std::cout << "a + b = " <<  a + b << std::endl;
	std::cout << "b - a = " <<  b - a << std::endl;
	std::cout << "max(a,b) = " <<  Fixed::max( a, b ) << std::endl;
	std::cout << "min(a,b) = " <<  Fixed::min( a, b ) << std::endl;

	std::cout << "a == a ? " <<  (a == a ? "true" : "false") << std::endl;
	std::cout << "a == b ? " <<  (a == b ? "true" : "false") << std::endl;
	std::cout << "a < b ? " <<  (a < b ? "true" : "false") << std::endl;
	std::cout << "a > b ? " <<  (a > b ? "true" : "false") << std::endl;

	return 0;
}
