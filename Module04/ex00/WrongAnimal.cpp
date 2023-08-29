/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:53:34 by fgeslin           #+#    #+#             */
/*   Updated: 2023/07/26 13:15:10 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) : _type( "t_WrongDefault" ) {}

WrongAnimal::WrongAnimal( string type ) : _type( type ) {}

WrongAnimal::WrongAnimal( const WrongAnimal &src ) { *this = src; }

WrongAnimal::~WrongAnimal( void ) {}

WrongAnimal &	WrongAnimal::operator=( WrongAnimal const & rhs ) {
	_type = rhs.getType();
	return *this;
}

void	WrongAnimal::makeSound( void ) const {
	cout << "(sound not defined)" << endl;
}

string	WrongAnimal::getType( void ) const {
	return _type;
}
