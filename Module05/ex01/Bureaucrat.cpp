/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 12:33:29 by fgeslin           #+#    #+#             */
/*   Updated: 2023/09/06 12:00:13 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) : _name("default"), _grade(150) {
	cout << "+ Bureaucrat default constructor called\n";
}

Bureaucrat::Bureaucrat( string n, int g ) : _name(n), _grade(g) {
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	cout << "+ Bureaucrat typed constructor called\n";
}

Bureaucrat::Bureaucrat( Bureaucrat const & src ) {
	cout << "+ Bureaucrat copy constructor called\n";
	*this = src;
}

Bureaucrat::~Bureaucrat( void ) {
	cout << "~ Bureaucrat default destructor called\n";
}

// GETTERS

string		Bureaucrat::getName() const { return _name; }
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

void		Bureaucrat::signForm( Form &f ) {
	if (f.getIsSigned()) {
		cout << "\'" << _name << "\' couldn't sign \'" << f.getName() << "\' because the Form is already signed.\n";
		return;
	}
	if (_grade > f.getGradeToSign()) {
		cout << "\'" << _name << "\' couldn't sign \'" << f.getName() << "\' because the Bureaucrat doesn't have the required grade.\n";
		return;
	}
	cout << _name << " successfully signed " << f.getName() << "!\n";
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
