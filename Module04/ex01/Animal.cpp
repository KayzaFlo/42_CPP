/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:53:34 by fgeslin           #+#    #+#             */
/*   Updated: 2023/07/26 13:44:53 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal( void ) : _type( "t_Default" ) {
	cout << C_CYA << "<Animal> " << C_WHT;
}

Animal::Animal( string type ) : _type( type ) {
	cout << C_CYA << "<Animal(Typed)> " << C_WHT;
}

Animal::Animal( const Animal &src ) {
	*this = src;
	cout << C_CYA << "<Animal(Copy)> " << C_WHT;
}

Animal::~Animal( void ) {
	cout << C_RED << "~Animal " << C_WHT;
}

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
