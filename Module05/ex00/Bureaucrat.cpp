/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 12:33:29 by fgeslin           #+#    #+#             */
/*   Updated: 2023/08/29 14:53:13 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) : _name("default"), _grade(150) {
	std::cout << "Bureaucrat default constructor called\n";
}

Bureaucrat::Bureaucrat( std::string n, int g ) : _name(n), _grade(g) {
	std::cout << "Bureaucrat constructor called\n";
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat( Bureaucrat const & src ) {
	std::cout << "Bureaucrat copy constructor called\n";
	*this = src;
}

Bureaucrat::~Bureaucrat( void ) {
	std::cout << "Bureaucrat default destructor called\n";
}

Bureaucrat &	Bureaucrat::operator=( Bureaucrat const & rhs ) {
	std::cout << "Bureaucrat copy operator called\n";
	this->_name = rhs.getName();
	this->_grade = rhs.getGrade();
	return *this;
}

// GETTERS
std::string	Bureaucrat::getName() const { return _name; }
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

// EXCEPTIONS
const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade Too High!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade Too Low!");
}

// OPERATOR OVERLOAD
std::ostream &	operator<<( std::ostream & input, Bureaucrat const & rhs ) {
	input << rhs.getName();
	input << ", bureaucrat grade ";
	input << rhs.getGrade();
	input << ".\n";
	return (input);
}
