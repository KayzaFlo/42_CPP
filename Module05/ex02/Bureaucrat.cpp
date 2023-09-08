/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 12:33:29 by fgeslin           #+#    #+#             */
/*   Updated: 2023/09/06 15:36:55 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) : _name("default"), _grade(150) {
	cout << C_GRY << "+Bureaucrat\n" << C_WHT;
}

Bureaucrat::Bureaucrat( string n, int g ) : _name(n), _grade(g) {
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	cout << C_GRY << "+Bureaucrat(typed)\n" << C_WHT;
}

Bureaucrat::Bureaucrat( Bureaucrat const & src ) {
	cout << C_GRY << "+Bureaucrat(copy)\n" << C_WHT;
	*this = src;
}

Bureaucrat::~Bureaucrat( void ) {
	cout << C_GRY << "~Bureaucrat\n" << C_WHT;
}

// GETTERS

string		Bureaucrat::getName() const { return _name; }
string		Bureaucrat::getFormattedName() const { return (string)C_YEL + "\'" + _name + "\'" + C_WHT; }
int			Bureaucrat::getGrade() const { return _grade; }

// FUNCS

void		Bureaucrat::increaseGrade() {
	_grade--;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

void		Bureaucrat::decreaseGrade() {
	_grade++;
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

void		Bureaucrat::signForm( AForm &f ) {
	f.beSigned(*this);
}

void		Bureaucrat::executeForm( AForm &f ) {
	f.tryToExecute( *this );
}

// EXCEPTIONS

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("\e[31mBureaucrat: Grade Too High!\e[0m");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("\e[31mBureaucrat: Grade Too Low!\e[0m");
}

// OPERATOR OVERLOAD

Bureaucrat &	Bureaucrat::operator=( Bureaucrat const & rhs ) {
	cout << "Bureaucrat copy operator called\n";
	this->_name = rhs.getName();
	this->_grade = rhs.getGrade();
	return *this;
}

std::ostream &	operator<<( std::ostream & input, Bureaucrat const & rhs ) {
	input << C_GRY << "| " << rhs.getName();
	input << ", bureaucrat grade "<< rhs.getGrade() << ".\n" << C_WHT;
	return (input);
}
