/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 12:33:33 by fgeslin           #+#    #+#             */
/*   Updated: 2023/09/08 16:15:01 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void	BureaucratTests();

int main()
{
	AForm *PrezForm = new PresidentialPardonForm();
	AForm *RobotForm = new RobotomyRequestForm("Intern");
	AForm *ShrubForm = new ShrubberyCreationForm("Garden");

	Bureaucrat	AllMighty("AllMighty", 1);
	Bureaucrat	Secretary("Secretary", 42);
	Bureaucrat	Worker("Worker", 87);
	Bureaucrat	Guest("Guest", 150);

	cout << endl;
	
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

	delete(PrezForm);
	delete(RobotForm);
	delete(ShrubForm);
}
