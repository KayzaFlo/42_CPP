/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 13:07:30 by fgeslin           #+#    #+#             */
/*   Updated: 2023/09/19 13:38:37 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define C_WHT "\e[0m"
# define C_YEL "\e[33m"

#include <iostream>
#include <stdlib.h>
#include <time.h>

class Base			  { public: virtual ~Base( void ) {} };
class A : public Base {};
class B : public Base {};
class C : public Base {};

Base * generate(void) {
	srand (time(NULL));
	int	pick = rand() % 3;
	
	std::cout << "Randomly picked class ";
	switch (pick)
	{
	case 0:
		return (std::cout << "A\n", new A());
	case 1:
		return (std::cout << "B\n", new B());
	case 2:
		return (std::cout << "C\n", new C());
	default:
		std::cout << "picked OOR\n";
		return new Base();
	}
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "➜ Class A\n";
	else
		std::cout << "  Class A (NULL)\n";

	if (dynamic_cast<B*>(p))
		std::cout << "➜ Class B\n";
	else
		std::cout << "  Class B (NULL)\n";

	if (dynamic_cast<C*>(p))
		std::cout << "➜ Class C\n";
	else
		std::cout << "  Class C (NULL)\n";
}

void identify(Base& p) {
	try {
		A	&iA = dynamic_cast<A&>(p);
		(void)iA;
		std::cout << "➜ Class A\n";
	}
	catch(const std::bad_cast& e) { std::cout << "  Class A (" << e.what() << ")\n"; }

	try {
		B	&iB = dynamic_cast<B&>(p);
		(void)iB;
		std::cout << "➜ Class B\n";
	}
	catch(const std::bad_cast& e) { std::cout << "  Class B (" << e.what() << ")\n"; }

	try {
		C	&iC = dynamic_cast<C&>(p);
		(void)iC;
		std::cout << "➜ Class C\n";
	}
	catch(const std::bad_cast& e) { std::cout << "  Class C (" << e.what() << ")\n"; }
}

int main()
{
	std::cout << C_YEL << "-- Generate Random Class --\n" << C_WHT;
	Base* rndBase = generate();
	std::cout << "\n";

	std::cout << C_YEL << "-- Identify Class w/ pointer --\n" << C_WHT;
	identify(rndBase);
	std::cout << "\n";

	std::cout << C_YEL << "-- Identify Class w/ reference --\n" << C_WHT;
	identify(*rndBase);
	std::cout << "\n";

	delete(rndBase);
	return 0;
}
