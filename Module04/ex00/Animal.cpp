/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:53:34 by fgeslin           #+#    #+#             */
/*   Updated: 2023/07/26 13:15:38 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal( void ) : _type( "t_Default" ) {}

Animal::Animal( string type ) : _type( type ) {}

Animal::Animal( const Animal &src ) { *this = src; }

Animal::~Animal( void ) {}

Animal &	Animal::operator=( Animal const & rhs ) {
	_type = rhs.getType();
	return *this;
}

void	Animal::makeSound( void ) const {
	cout << "(sound not defined)" << endl;
}

string	Animal::getType( void ) const {
	return _type;
}
