/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 12:33:33 by fgeslin           #+#    #+#             */
/*   Updated: 2023/09/25 14:38:19 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void	FormTests(AForm *PrezForm, AForm *RobotForm, AForm *ShrubForm);

int main()
{
	Intern	Ducky;
	
	AForm	*ErrorForm;	
	try { ErrorForm = Ducky.makeForm("error", "target"); }
	catch(const exception& e) { cerr << e.what() << '\n'; }
	
	AForm	*PrezForm;
	AForm	*RobotForm;
	AForm	*ShrubForm;

	try {
		PrezForm = Ducky.makeForm("presidential pardon", "President");
		RobotForm = Ducky.makeForm("robotomy request", "Intern");
		ShrubForm = Ducky.makeForm("shrubbery creation", "Garden");
		FormTests(PrezForm, RobotForm, ShrubForm);
	}
	catch(const exception& e) { cerr << e.what() << '\n'; }

	delete(PrezForm);
	delete(RobotForm);
	delete(ShrubForm);
}

void	FormTests(AForm *PrezForm, AForm *RobotForm, AForm *ShrubForm) {
		cout << endl;
	
	Bureaucrat	AllMighty("AllMighty", 1);
	Bureaucrat	Secretary("Secretary", 42);
	Bureaucrat	Worker("Worker", 87);
	Bureaucrat	Guest("Guest", 150);

	cout << C_CYA << "----------" << C_WHT << endl << endl;
	
	cout << C_CYA << "Try to sign Prez Form with Worker" << C_WHT << endl;
	try {
		Worker.signForm(*PrezForm);
	}
	catch(const exception& e) {
		cerr << e.what() << '\n';
	}
	cout << C_CYA << "----------" << C_WHT << endl << endl;
	
	// ## ------------------------------ ##
	
	cout << C_CYA << "Execute before Signed" << C_WHT << endl;
	try {
		AllMighty.executeForm(*RobotForm);
	}
	catch(const exception& e) {
		cerr << e.what() << '\n';
	}
	cout << C_CYA << "----------" << C_WHT << endl << endl;
	
	// ## ------------------------------ ##
	
	cout << C_CYA << "Sign all Forms" << C_WHT << endl;
	try {
		AllMighty.signForm(*PrezForm);
		Secretary.signForm(*RobotForm);
		Worker.signForm(*ShrubForm);
		cout << *RobotForm;
		AllMighty.signForm(*RobotForm);
	}
	catch(const exception& e) {
		cerr << e.what() << '\n';
	}
	cout << C_CYA << "----------" << C_WHT << endl << endl;
	
	// ## ------------------------------ ##
	
	cout << C_CYA << "Executes" << C_WHT << endl;
	try {
		AllMighty.executeForm(*PrezForm);
		Secretary.executeForm(*RobotForm);
		Worker.executeForm(*ShrubForm);
		Guest.executeForm(*PrezForm);
	}
	catch(const exception& e) {
		cerr << e.what() << '\n';
	}
	cout << C_CYA << "----------" << C_WHT << endl << endl;
	
	// ## ------------------------------ ##
}
