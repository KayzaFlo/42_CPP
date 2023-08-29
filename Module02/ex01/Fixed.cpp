/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 14:22:09 by fgeslin           #+#    #+#             */
/*   Updated: 2023/04/22 16:25:25 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed( void ) : _n(0) {
	std::cout << "Default constructor called\n";
}

Fixed::Fixed( int const n ) : _n(n << _frac) {
	std::cout << "Int constructor called\n";
}

Fixed::Fixed( float const f ) : _n(roundf(f * (1 << _frac))) {
	std::cout << "Float constructor called\n";
}

Fixed::Fixed( Fixed const & src ) {
	std::cout << "Copy constructor called\n";
	*this = src;
}

Fixed::~Fixed( void ) {
	std::cout << "Destructor called\n";
}


int		Fixed::getRawBits( void ) const { return _n; }
void	Fixed::setRawBits( int const raw ) { _n = raw; }

int		Fixed::toInt( void ) const { return _n >> _frac; }
float	Fixed::toFloat( void ) const { return (float)_n / (1 << _frac); }


Fixed &			Fixed::operator=( Fixed const & rhs ) {
	std::cout << "Copy assignement operator called\n";
	this->_n = rhs.getRawBits();
	return *this;
}

std::ostream &	operator<<( std::ostream & o, Fixed const & rhs ) {
	o << rhs.toFloat();
	return o;
}
