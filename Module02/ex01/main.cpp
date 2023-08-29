/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 14:20:39 by fgeslin           #+#    #+#             */
/*   Updated: 2023/07/21 15:00:25 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void ) {

	std::cout << "\t\033[1;33mDefault Constructor \'a\' then Operator=:\033[0m" << std::endl;
	Fixed a;
	a = Fixed( 1234.4321f );
	std::cout << "a is " << a << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << std::endl;

	std::cout << "\t\033[1;33mInt Constructor \'b\':\033[0m" << std::endl;
	Fixed const b( 10 );
	std::cout << "b is " << b << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << std::endl;

	std::cout << "\t\033[1;33mFloat Constructor \'c\':\033[0m" << std::endl;
	Fixed const c( 42.42f );
	std::cout << "c is " << c << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << std::endl;

	std::cout << "\t\033[1;33mCopy Constructor \'d\':\033[0m" << std::endl;
	Fixed const d( b );
	std::cout << "d is " << d << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	std::cout << std::endl;
	
	return 0;
}
