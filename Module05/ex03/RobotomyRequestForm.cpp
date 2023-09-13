/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:16:52 by fgeslin           #+#    #+#             */
/*   Updated: 2023/09/08 16:18:35 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( void ) : AForm("RobotomyRequestForm", 72, 45), _target("default") {
	cout << C_GRY << "+RobotForm\n" << C_WHT;
}

RobotomyRequestForm::RobotomyRequestForm( string target ) : AForm("RobotomyRequestForm", 72, 45), _target(target) {
	cout << C_GRY << "+RobotForm(typed)\n" << C_WHT;
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const & src ) : AForm( src ) {
	cout << C_GRY << "+RobotForm(copy)\n" << C_WHT;
}

RobotomyRequestForm::~RobotomyRequestForm( void ) {
	cout << C_GRY << "~RobotForm " << C_WHT;
}

RobotomyRequestForm &	RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs ) {
	(void)rhs;
	return *this;
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	srand(time(NULL));
	cout << "| " << "Bzzzzzzzzzzzz, Bzzzz, Bzzzzzzzz...\n";
	if (rand() % 2)
		cout << "| " << getTarget() << " has be robotomized.\n";
	else
		cout << "| " << "Operation Failed! " << executor.getFormattedName() << " is still human.\n";
	cout << "↳ " << executor.getFormattedName() << " executed " << this->getFormattedName() << ".\n";
}

string	RobotomyRequestForm::getTarget( void ) const {
	return _target;
}
