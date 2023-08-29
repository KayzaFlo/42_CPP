/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:53:37 by fgeslin           #+#    #+#             */
/*   Updated: 2023/08/01 13:00:22 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void ) : AAnimal( "t_Cat" ) {
	_brain = new Brain();
	cout << C_CYA << "<Cat> " << C_WHT;
}

Cat::Cat( const Cat &src ) {
	*this = src;
	cout << C_CYA << "<Cat(Copy)> " << C_WHT;
}

Cat::~Cat( void ) {
	delete _brain;
	cout << C_RED << "~Cat " << C_WHT;
}

Cat &	Cat::operator=( Cat const & rhs ) {
	_type = rhs.getType();
	*(this->_brain) = *(rhs._brain);
	return *this;
}

void	Cat::makeSound( void ) const {
	cout << "*meow...*" << endl;
}

void	Cat::printIdeas( int n ) const {
	for (int i = 0; i < n; i++)
		_brain->printIdea(i);
}
