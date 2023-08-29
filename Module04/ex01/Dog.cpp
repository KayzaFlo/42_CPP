/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:53:36 by fgeslin           #+#    #+#             */
/*   Updated: 2023/07/26 15:17:07 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void ) : Animal( "t_Dog" ) {
	_brain = new Brain();
	cout << C_CYA << "<Dog> " << C_WHT;
}

Dog::Dog( const Dog &src ) {
	*this = src;
	cout << C_CYA << "<Dog(Copy)> " << C_WHT;
}

Dog::~Dog( void ) {
	delete _brain;
	cout << C_RED << "~Dog " << C_WHT;
}

Dog &	Dog::operator=( Dog const & rhs ) {
	_type = rhs.getType();
	*(this->_brain) = *(rhs._brain);
	return *this;
}

void	Dog::makeSound( void ) const {
	cout << "*barf!*" << endl;
}

void	Dog::printIdeas( int n ) const {
	for (int i = 0; i < n; i++)
		_brain->printIdea(i);
}
