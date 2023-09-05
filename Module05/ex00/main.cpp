/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 12:33:33 by fgeslin           #+#    #+#             */
/*   Updated: 2023/09/05 12:27:33 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
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
}
