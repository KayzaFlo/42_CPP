/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 14:22:03 by fgeslin           #+#    #+#             */
/*   Updated: 2023/08/31 11:25:34 by fgeslin          ###   ########.fr       */
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

	Fixed &		operator=( Fixed const & rhs );		// Canonical		Surcharge operator =

	int			getRawBits( void ) const;
	void		setRawBits( int const raw );

};
