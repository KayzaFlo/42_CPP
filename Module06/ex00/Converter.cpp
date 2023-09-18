/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:24:29 by fgeslin           #+#    #+#             */
/*   Updated: 2023/09/18 17:31:10 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

Converter::Converter( void ) : _src("default") {}
Converter::Converter( string src ) : _src(src) {}
Converter::Converter( Converter const & src ) : _src(src._src) { *this = src; }
Converter::~Converter( void ) {}

Converter &	Converter::operator=( Converter const & rhs ) {
	(void)rhs;
	return *this;
}

// CASTS OPERATOR

Converter::operator char() {
	char c = char(std::stoi(_src));
	if (!std::isprint(c))
		throw Converter::NonDisplayableException();
	return c;
}

Converter::operator int() {
	return std::stoi(_src);
}

Converter::operator float() {
	return std::stof(_src);
}

Converter::operator double() {
	return std::stod(_src);
}

// EXCEPTIONS

const char* Converter::NonDisplayableException::what() const throw() {
	return ("\e[31mNon displayable\e[0m");
}
const char* Converter::ImpossibleConversionException::what() const throw() {
	return ("\e[31mimpossible\e[0m");
}
const char* Converter::NanException::what() const throw() {
	return ("\e[31mnan\e[0m");
}
const char* Converter::NanfException::what() const throw() {
	return ("\e[31mnanf\e[0m");
}
const char* Converter::OverflowException::what() const throw() {
	return ("\e[31mOverflow\e[0m");
}

// OPERATOR OVERLOAD

std::ostream &	operator<<( std::ostream & input, Converter const & rhs ) {
	Converter	c = const_cast<Converter &>(rhs);

	try { input << "char: " << static_cast<char>(c); }
	// catch(std::out_of_range &e) { cout << "OVERFLOW"; }
	catch(const std::exception& e) { input << e.what(); }
	cout << endl;
	try { input << "int: " << static_cast<int>(c); }
	// catch(std::out_of_range &e) { cout << "OVERFLOW"; }
	catch(const std::exception& e) { input << e.what(); }
	cout << endl;
	try {
		double integral;
		input << "float: ";
		if (std::modf(static_cast<float>(c), &integral) == 0)
			input << std::fixed << std::setprecision(1) << integral  << "f";
		else
			input << static_cast<float>(c) << "f";
	}
	catch(const std::exception& e) { input << e.what(); }
	cout << endl;
	try { input << "double: " << static_cast<double>(c); }
	catch(const std::exception& e) { input << e.what(); }
	return (input);
}
