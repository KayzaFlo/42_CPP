/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:53:36 by fgeslin           #+#    #+#             */
/*   Updated: 2023/07/26 11:45:38 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void ) : Animal( "t_Dog" ) {}

Dog::Dog( const Dog &src ) { *this = src; }

Dog::~Dog( void ) {}

Dog &	Dog::operator=( Dog const & rhs ) {
	_type = rhs.getType();
	return *this;
}

void Dog::makeSound( void ) const {
	cout << "*barf!*" << endl;
}
