/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:09:33 by fgeslin           #+#    #+#             */
/*   Updated: 2023/09/08 16:18:29 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ) : AForm("PresidentialPardonForm", 25, 5), _target("default") {
	cout << C_GRY << "+PrezForm\n" << C_WHT;
}

PresidentialPardonForm::PresidentialPardonForm( string target ) : AForm("PresidentialPardonForm", 25, 5), _target(target) {
	cout << C_GRY << "+PrezForm(typed)\n" << C_WHT;
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const & src ) : AForm( src ) {
	cout << C_GRY << "+PrezForm(copy)\n" << C_WHT;
}

PresidentialPardonForm::~PresidentialPardonForm( void ) {
	cout << C_GRY << "~PrezForm " << C_WHT;
}

PresidentialPardonForm &	PresidentialPardonForm::operator=( PresidentialPardonForm const & rhs ) {
	(void)rhs;
	return *this;
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	cout << "| " << getTarget() << " has be forgiven by Zaphod Beeblebrox...\n";
	cout << "↳ " << executor.getFormattedName() << " executed " << this->getFormattedName() << ".\n";
}

string	PresidentialPardonForm::getTarget( void ) const {
	return _target;
}
