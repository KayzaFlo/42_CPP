/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:20:51 by fgeslin           #+#    #+#             */
/*   Updated: 2023/09/13 11:59:02 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern( void ) {}

Intern::Intern( Intern const & src ) {
	*this = src;
}

Intern::~Intern( void ) {}

Intern &	Intern::operator=( Intern const & rhs ) {
	(void)rhs;
	return *this;
}

AForm *		Intern::makeForm(string name, string target) {
	const string	formNames[] = {
        "robotomy request",
        "presidential pardon",
        "shrubbery creation"
	};
	// ERROR if target == NULL
	// create 3 new each time, inefficient and leaks
	const AForm*	forms[] = {
        new RobotomyRequestForm( target ),
        new PresidentialPardonForm( target ),
        new ShrubberyCreationForm( target )
	};

	for (size_t i = 0; i < 3; i++) {
		if (name == formNames[i]) {
			cout << "Intern created " << name << "!\n";
			return (AForm*)forms[i];
		}
	}
	cout << "Intern couldn't create " << name << " form...\n";
	return new PresidentialPardonForm();
}