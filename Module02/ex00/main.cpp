/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 14:20:39 by fgeslin           #+#    #+#             */
/*   Updated: 2023/07/21 14:56:00 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void ) {

	std::cout << "\t\033[1;33mDefault Constructor a:\033[0m" << std::endl;
	Fixed a;
	std::cout << a.getRawBits() << std::endl;
	std::cout << std::endl;

	std::cout << "\t\033[1;33mCopy Constructor b:\033[0m" << std::endl;
	Fixed b( a );
	std::cout << b.getRawBits() << std::endl;
	std::cout << std::endl;

	std::cout << "\t\033[1;33mDefault Constructor c then Copy b:\033[0m" << std::endl;
	Fixed c;
	c = b;
	std::cout << c.getRawBits() << std::endl;
	std::cout << std::endl;
	
	return 0;
}
