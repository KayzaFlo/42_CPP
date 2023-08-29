/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:53:37 by fgeslin           #+#    #+#             */
/*   Updated: 2023/07/26 12:03:04 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void ) : Animal( "t_Cat" ) {}

Cat::Cat( const Cat &src ) { *this = src; }

Cat::~Cat( void ) {}

Cat &	Cat::operator=( Cat const & rhs ) {
	_type = rhs.getType();
	return *this;
}

void Cat::makeSound( void ) const {
	cout << "*meow...*" << endl;
}
