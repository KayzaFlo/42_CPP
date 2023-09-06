/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:36:37 by fgeslin           #+#    #+#             */
/*   Updated: 2023/09/06 11:56:46 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form( void ) : _name("default"), _isSigned(false), _gradeToSign(1), _gradeToExec(1) {
	cout << "+ Form default constructor called\n";
}

Form::Form( string name, int gradeToSign, int gradeToExec ) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {
	if (this->_gradeToSign < 1 || this->_gradeToExec < 1)
		throw Form::GradeTooHighException();
	if (this->_gradeToSign > 150 || this->_gradeToExec > 150)
		throw Form::GradeTooLowException();
	cout << "+ Form typed constructor called\n";
}

Form::Form( Form const & src ) : _gradeToSign(src._gradeToSign), _gradeToExec(src._gradeToExec) {
	*this = src;
	cout << "+ Form copy constructor called\n";
}

Form::~Form( void ) {
	cout << "~ Form default destructor called\n";
}

//GETTERS

string	Form::getName( void ) const { return _name; }
bool	Form::getIsSigned( void ) const { return _isSigned; }
int		Form::getGradeToSign( void ) const { return _gradeToSign; }
int		Form::getGradeToExec( void ) const { return _gradeToExec; }

//FUNCS

void	Form::beSigned( Bureaucrat &b ) {
	if (_isSigned) {
		cout << "\'" << _name << "\' is already signed.\n";
		return;
	}
	if (b.getGrade() > _gradeToSign)
		throw(Form::GradeTooLowException());
	_isSigned = true;
	cout << "Form \'" << _name << "\' successfully signed by \'" << b.getName() << "\'!\n";
}

// EXCEPTIONS

const char* Form::GradeTooHighException::what() const throw() {
	return ("\e[31mForm: Grade Too High!\e[0m");
}

const char* Form::GradeTooLowException::what() const throw() {
	return ("\e[31mForm: Grade Too Low!\e[0m");
}

// OPERATOR OVERLOAD

Form &	Form::operator=( Form const & rhs ) {
	this->_name = rhs._name;
	this->_isSigned = rhs._isSigned;
	return *this;
}

std::ostream &	operator<<( std::ostream & input, Form const & rhs ) {
	input << C_GRY;
	input << "| Form \'" << rhs.getName() << "\' is ";
	input << (rhs.getIsSigned() ? "signed" : "unsigned") << ",\n";
	input << "| it requires Grade " << rhs.getGradeToSign() << " to be signed,\n";
	input << "| and Grade " << rhs.getGradeToExec() << " to be executed.";
	input << "\n" << C_WHT;
	return (input);
}
