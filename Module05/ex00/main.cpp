/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 12:33:33 by fgeslin           #+#    #+#             */
/*   Updated: 2023/08/29 14:59:46 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try {
		// Grade too low
		Bureaucrat Gille("Gille", 150);
		Gille.decreaseGrade();
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	try {
		// Grade too high
		std::string name = "Gille2";
		Bureaucrat Gille2(name, 500);
		Gille2.increaseGrade();
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	// Constructor
	// Default
	std::cout << std::endl;
	Bureaucrat Default;
	std::cout << Default << std::endl;
	Bureaucrat Guy("Guy", 38);
	std::cout << Guy << std::endl << std::endl;
	// Copy
	Bureaucrat Gille(Guy);
	std::cout << Gille << std::endl << std::endl;
	// Assigment
	Bureaucrat Pas_Guy("Pas_Guy", 46);
	std::cout << Pas_Guy << std::endl;
	Pas_Guy = Guy;
	std::cout << Pas_Guy << std::endl;
}
