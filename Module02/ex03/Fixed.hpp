/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 14:22:03 by fgeslin           #+#    #+#             */
/*   Updated: 2023/04/25 12:32:35 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int					_n;
	static int const	_frac = 8;

public:
	Fixed( void );									// Canonical		Constructor Default
	Fixed( int const n );
	Fixed( float const f );
	Fixed( Fixed const & src );						// Canonical		Contructor Copy
	~Fixed( void );									// Canonical		Destructor

	Fixed &		operator=( Fixed const & rhs );		// Canonical		Surcharge operator =
	Fixed		operator+( Fixed const & rhs ) const;
	Fixed		operator-( Fixed const & rhs ) const;
	Fixed		operator*( Fixed const & rhs ) const;
	Fixed		operator/( Fixed const & rhs ) const;

	Fixed		operator++( int n );	// post
	Fixed		operator--( int n );	// post
	Fixed		operator++();			// pre
	Fixed		operator--();			// pre

	bool		operator>( Fixed const & rhs ) const;
	bool		operator<( Fixed const & rhs ) const;
	bool		operator>=( Fixed const & rhs ) const;
	bool		operator<=( Fixed const & rhs ) const;
	bool		operator==( Fixed const & rhs ) const;
	bool		operator!=( Fixed const & rhs ) const;

	int			getRawBits( void ) const;
	void		setRawBits( int const raw );

	int			toInt( void ) const;
	float		toFloat( void ) const;

	static Fixed &	min( Fixed & a, Fixed & b );
	static Fixed const &	min( Fixed const & a, Fixed const & b );
	static Fixed &	max( Fixed & a, Fixed & b );
	static Fixed const &	max( Fixed const & a, Fixed const & b );

};

#endif

std::ostream &	operator<<( std::ostream & o, Fixed const & rhs );
