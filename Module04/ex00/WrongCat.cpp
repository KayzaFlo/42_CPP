/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:53:37 by fgeslin           #+#    #+#             */
/*   Updated: 2023/07/26 13:05:21 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat( void ) : WrongAnimal( "t_WrongCat" ) {}

WrongCat::WrongCat( const WrongCat &src ) { *this = src; }

WrongCat::~WrongCat( void ) {}

WrongCat &	WrongCat::operator=( WrongCat const & rhs ) {
	_type = rhs.getType();
	return *this;
}

void WrongCat::makeSound( void ) const {
	cout << "*meow...*" << endl;
}
