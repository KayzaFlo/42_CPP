/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 14:22:09 by fgeslin           #+#    #+#             */
/*   Updated: 2023/04/24 13:27:44 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include "Fixed.hpp"

///////////////////////
//-----OPERATORS-----//
///////////////////////

Fixed::Fixed( void ) : _n(0) {}
Fixed::Fixed( int const n ) : _n(n << _frac) {}
Fixed::Fixed( float const f ) : _n(roundf(f * (1 << _frac))) {}
Fixed::Fixed( Fixed const & src ) { *this = src; }
Fixed::~Fixed( void ) {}

///////////////////////
//-------FUNCS-------//
///////////////////////

int			Fixed::getRawBits( void ) const { return _n; }
void		Fixed::setRawBits( int const raw ) { _n = raw; }

int			Fixed::toInt( void ) const { return _n >> _frac; }
float		Fixed::toFloat( void ) const { return (float)_n / (1 << _frac); }

Fixed &			Fixed::min( Fixed & a, Fixed & b ) { return a._n < b._n ? a : b; }
Fixed const &	Fixed::min( Fixed const & a, Fixed const & b ) { return a._n < b._n ? a : b; }
Fixed &			Fixed::max( Fixed & a, Fixed & b ) { return a._n > b._n ? a : b; }
Fixed const &	Fixed::max( Fixed const & a, Fixed const & b ) { return a._n > b._n ? a : b; }

///////////////////////
//-----OVERLOADS-----//
///////////////////////

bool		Fixed::operator>( Fixed const & rhs ) const { return this->getRawBits() > rhs.getRawBits() ? true : false; }
bool		Fixed::operator<( Fixed const & rhs ) const { return this->getRawBits() < rhs.getRawBits() ? true : false; }
bool		Fixed::operator>=( Fixed const & rhs ) const { return this->getRawBits() >= rhs.getRawBits() ? true : false; }
bool		Fixed::operator<=( Fixed const & rhs ) const { return this->getRawBits() <= rhs.getRawBits() ? true : false; }
bool		Fixed::operator==( Fixed const & rhs ) const { return this->getRawBits() == rhs.getRawBits() ? true : false; }
bool		Fixed::operator!=( Fixed const & rhs ) const { return this->getRawBits() != rhs.getRawBits() ? true : false; }

Fixed &		Fixed::operator=( Fixed const & rhs ) { return ( this->setRawBits(rhs.getRawBits()), *this ); }
Fixed		Fixed::operator+( Fixed const & rhs ) const { return Fixed( this->toFloat() + rhs.toFloat() ); }
Fixed		Fixed::operator-( Fixed const & rhs ) const { return Fixed( this->toFloat() - rhs.toFloat() ); }
Fixed		Fixed::operator*( Fixed const & rhs ) const { return Fixed( this->toFloat() * rhs.toFloat() ); }
Fixed		Fixed::operator/( Fixed const & rhs ) const { return Fixed( this->toFloat() / rhs.toFloat() ); }

Fixed		Fixed::operator++( int n ) { Fixed temp( *this ); return (this->_n += n + 1, temp ); }
Fixed		Fixed::operator--( int n ) { Fixed temp( *this ); return (this->_n -= n + 1, temp ); }
Fixed		Fixed::operator++() { return (this->_n++, *this); }
Fixed		Fixed::operator--() { return (this->_n--, *this); }

std::ostream &	operator<<( std::ostream & o, Fixed const & rhs ) { return (o << rhs.toFloat(), o); }
