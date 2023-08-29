/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 14:22:09 by fgeslin           #+#    #+#             */
/*   Updated: 2023/04/22 15:44:28 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void ) {
	std::cout << "Default constructor called\n";
	_n = 0;
}

Fixed::Fixed( Fixed const & src ) {
	std::cout << "Copy constructor called\n";
	*this = src;
}

Fixed::~Fixed( void ) {
	std::cout << "Destructor called\n";
}

int		Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called\n";
	return _n;
}

void	Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member function called\n";
	_n = raw;
}

Fixed &	Fixed::operator=( Fixed const & rhs ) {
	std::cout << "Copy assignement operator called\n";
	this->_n = rhs.getRawBits();
	return *this;
}
