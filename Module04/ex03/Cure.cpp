/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:50:42 by fgeslin           #+#    #+#             */
/*   Updated: 2023/07/26 15:51:33 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria( "cure", "🟢" ) {
	cout << C_GRN << "<Cure> " << C_WHT;
}

Cure::Cure(const Cure &other) : AMateria( other ) {
	cout << C_GRN << "<Cure>(Copy) " << C_WHT;
	*this = other;
}

Cure::~Cure() {
	cout << C_RED << "~Cure " << C_WHT;
}

Cure &Cure::operator=(const Cure &rhs) {
	(void)rhs;
	return *this;
}

AMateria*	Cure::clone() const {
	return new Cure;
}

void		Cure::use(ICharacter& target) {
	cout << "* heals " << C_CYA << "[" << target.getName() << "]" << C_WHT << "'s wounds *\n";
}
