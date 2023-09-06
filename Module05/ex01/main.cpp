/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 12:33:33 by fgeslin           #+#    #+#             */
/*   Updated: 2023/09/06 11:57:46 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

void	BureaucratTests();

int main()
{
	cout << endl;
	
	// BureaucratTests();

	cout << C_CYA << "Create new Form (\"NewForm\", 200, 5)" << C_WHT << endl;
	try {
		Form NewForm("NewForm", 200, 5);
		cout << NewForm;
	}
	catch(const exception& e) {
		cerr << e.what() << '\n';
	}
	cout << C_CYA << "----------" << C_WHT << endl << endl;
	
	// ## ------------------------------ ##

	cout << C_CYA << "Create Form1(\"Form1\", 100, 5) signed by User42(\"User42\", 42)" << C_WHT << endl;
	try {
		Form Form1("Form1", 100, 5);
		cout << Form1;
		Bureaucrat User42("User42", 42);
		Form1.beSigned(User42);
		User42.signForm(Form1);
	}
	catch(const exception& e) {
		cerr << e.what() << '\n';
	}
	cout << C_CYA << "----------" << C_WHT << endl << endl;
	
	// ## ------------------------------ ##

	{
		Form *Default;
		cout << C_CYA << "Create Form1(\"Form1\", 100, 5) signed by User50(\"User50\", 50)" << C_WHT << endl;
		try {
			Default = new Form();
			cout << *Default;
			Bureaucrat User50("User50", 50);
			User50.signForm(*Default);
			Default->beSigned(User50);
		}
		catch(const exception& e) {
			cerr << e.what() << '\n';
		}
		delete (Default);
		cout << C_CYA << "----------" << C_WHT << endl << endl;
	}
}

void	BureaucratTests()
{
	cout << C_CYA << "Init w/ grade 150 then decrease grade" << C_WHT << endl;
	try {
		Bureaucrat Low("Low", 150);
		Low.decreaseGrade();
		cout << Low;
	}
	catch(const exception& e) {
		cerr << e.what() << '\n';
	}
	cout << C_CYA << "----------" << C_WHT << endl << endl;

	// ## ------------------------------ ##

	cout << C_CYA << "Init w/ grade 500 then increase grade" << C_WHT << endl;
	Bureaucrat *WayTooLow;
	try {
		WayTooLow = new Bureaucrat("WayTooLow", 500);
		WayTooLow->increaseGrade();
	}
	catch(const exception& e) {
		cerr << e.what() << '\n';
	}
	cout << C_CYA << "----------" << C_WHT << endl << endl;

	// ## ------------------------------ ##

	cout << C_CYA << "Init w/ grade 1 then increase grade" << C_WHT << endl;
	{
		try {
			Bureaucrat High("High", 1);
			High.increaseGrade();
		}
		catch(const exception& e) {
			cerr << e.what() << '\n';
		}
	}
	cout << C_CYA << "----------" << C_WHT << endl << endl;

	// ## ------------------------------ ##

	cout << C_CYA << "Init default then increase grade" << C_WHT << endl;
	{
		Bureaucrat *Default;
		try {
			Default = new Bureaucrat();
			Default->increaseGrade();
		}
		catch(const exception& e) {
			cerr << e.what() << '\n';
		}
		cout << *Default;
		delete(Default);
	}
	cout << C_CYA << "----------" << C_WHT << endl << endl;

	// ## ------------------------------ ##

	cout << C_CYA << "Init w/ grade 42 then decrease grade" << C_WHT << endl;
	try {
		Bureaucrat Student("Student", 42);
		Student.decreaseGrade();
		cout << Student;
	}
	catch(const exception& e) {
		cerr << e.what() << '\n';
	}
	cout << C_CYA << "----------" << C_WHT << endl << endl;

	// ## ------------------------------ ##
}
