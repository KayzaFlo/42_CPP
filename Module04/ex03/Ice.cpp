/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:50:42 by fgeslin           #+#    #+#             */
/*   Updated: 2023/08/01 11:20:17 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria( "ice", "🔵" ) {
	cout << C_GRN << "<Ice> " << C_WHT;
}

Ice::Ice(const Ice &other) : AMateria( other ) {
	cout << C_GRN << "<Ice> " << C_WHT;
	*this = other;
}

Ice::~Ice() {
	cout << C_RED << "~Ice " << C_WHT;
}

Ice &Ice::operator=(const Ice &rhs) {
	(void)rhs;
	return *this;
}

AMateria*	Ice::clone() const {
	return new Ice;
}

void		Ice::use(ICharacter& target) {
	cout << "* shoots an ice bolt at " << C_CYA << "[" << target.getName() << "]" << C_WHT << " *\n";
}
