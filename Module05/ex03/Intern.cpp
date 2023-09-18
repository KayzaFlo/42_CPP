/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:20:51 by fgeslin           #+#    #+#             */
/*   Updated: 2023/09/18 11:31:30 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern( void ) {}
Intern::Intern( Intern const & src ) { *this = src; }
Intern::~Intern( void ) {}

Intern &	Intern::operator=( Intern const & rhs ) {
	(void)rhs;
	return *this;
}

AForm *	Intern::makePrezForm(string target) const { return new PresidentialPardonForm( target ); }
AForm *	Intern::makeRobotForm(string target) const { return new RobotomyRequestForm( target ); }
AForm *	Intern::makeShrubForm(string target) const { return new ShrubberyCreationForm( target ); }

AForm *	Intern::makeForm(string name, string target) const {
	const string	formNames[] = {
        "robotomy request",
        "presidential pardon",
        "shrubbery creation"
	};
	AForm *	(Intern::*forms[])(string target) const = {
        &Intern::makePrezForm,
        &Intern::makeRobotForm,
        &Intern::makeShrubForm
	};

	for (size_t i = 0; i < 3; i++) {
		if (name == formNames[i]) {
			cout << "• Intern created " << C_YEL << "\'" << name << "\'" << C_WHT << "!\n";
			return (this->*forms[i])(target);
		}
	}
	cout << "• Intern couldn't create " << C_YEL << "\'" << name << "\'" << C_WHT << " form...\n";
	return NULL;
}