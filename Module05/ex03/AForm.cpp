/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:36:37 by fgeslin           #+#    #+#             */
/*   Updated: 2023/09/06 15:37:39 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm( void ) : _name("default"), _isSigned(false), _gradeToSign(1), _gradeToExec(1) {
	cout << C_GRY << "+AForm " << C_WHT;
}

AForm::AForm( string name, int gradeToSign, int gradeToExec ) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {
	if (this->_gradeToSign < 1 || this->_gradeToExec < 1)
		throw AForm::GradeTooHighException();
	if (this->_gradeToSign > 150 || this->_gradeToExec > 150)
		throw AForm::GradeTooLowException();
	cout << C_GRY << "+AForm(typed) " << C_WHT;
}

AForm::AForm( AForm const & src ) : _gradeToSign(src._gradeToSign), _gradeToExec(src._gradeToExec) {
	*this = src;
	cout << C_GRY << "+AForm(copy) " << C_WHT;
}

AForm::~AForm( void ) {
	cout << C_GRY << "~AForm\n" << C_WHT;
}

//GETTERS

string	AForm::getName( void ) const { return _name; }
string	AForm::getFormattedName( void ) const { return (string)C_CYA + "\'" + _name + "\'" + C_WHT; }
bool	AForm::getIsSigned( void ) const { return _isSigned; }
int		AForm::getGradeToSign( void ) const { return _gradeToSign; }
int		AForm::getGradeToExec( void ) const { return _gradeToExec; }

//FUNCS

void	AForm::beSigned( Bureaucrat &b ) {
	cout << "• " << b.getFormattedName() << " tries to SIGN " << this->getFormattedName() << ".\n";
	if (_isSigned)
		throw AlreadySignedException();
	if (b.getGrade() > this->_gradeToSign)
		throw(AForm::GradeTooLowException());
	this->_isSigned = true;
	cout << "↳ AForm " << this->getFormattedName() << " successfully signed by " << b.getFormattedName() << "!\n";
}

void	AForm::tryToExecute( Bureaucrat &b ) {
	cout << "• " << b.getFormattedName() << " tries to EXECUTE " << this->getFormattedName() << ".\n";
	if (b.getGrade() > this->_gradeToExec)
		throw GradeTooLowException();
	if (!this->_isSigned)
		throw NotSignedException();
	execute(b);
	cout << "↳ " << b.getFormattedName() << " executed " << this->getFormattedName() << ".\n";
}

// EXCEPTIONS

const char* AForm::GradeTooHighException::what() const throw() { return ("\e[31mAForm: Grade Too High!\e[0m"); }
const char* AForm::GradeTooLowException::what() const throw() { return ("\e[31mAForm: Grade Too Low!\e[0m"); }
const char* AForm::AlreadySignedException::what() const throw() { return ("\e[31mAForm: Form is already Signed!\e[0m"); }
const char* AForm::NotSignedException::what() const throw() { return ("\e[31mAForm: Form must be Signed!\e[0m"); }

// OPERATOR OVERLOAD

AForm &	AForm::operator=( AForm const & rhs ) {
	this->_name = rhs._name;
	this->_isSigned = rhs._isSigned;
	return *this;
}

std::ostream &	operator<<( std::ostream & input, AForm const & rhs ) {
	input << C_GRY;
	input << "| AForm \'" << rhs.getName() << "\' is ";
	input << (rhs.getIsSigned() ? "signed" : "unsigned") << ",\n";
	input << "| it requires Grade " << rhs.getGradeToSign() << " to be signed,\n";
	input << "| and Grade " << rhs.getGradeToExec() << " to be executed.";
	input << "\n" << C_WHT;
	return (input);
}
