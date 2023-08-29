/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 14:22:03 by fgeslin           #+#    #+#             */
/*   Updated: 2023/04/22 15:41:50 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Fixed
{
private:
	int					_n;
	static const int	_frac = 8;

public:
	Fixed( void );									// Canonical		Constructor Default
	Fixed( Fixed const & src );						// Canonical		Contructor Copy
	~Fixed( void );									// Canonical		Destructor

	Fixed &		operator=( Fixed const & rhs );		// Canonical		Surcharche operator =

	int			getRawBits( void ) const;
	void		setRawBits( int const raw );

};
