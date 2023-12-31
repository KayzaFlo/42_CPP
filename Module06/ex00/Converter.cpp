/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:24:29 by fgeslin           #+#    #+#             */
/*   Updated: 2023/09/25 15:43:03 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

Converter::Converter( void ) : _val("default") {}
Converter::Converter( string src ) : _val(src) {}
Converter::Converter( Converter const & src ) : _val(src._val) { *this = src; }
Converter::~Converter( void ) {}

Converter &	Converter::operator=( Converter const & rhs ) {
	(void)rhs;
	return *this;
}

// CASTS OPERATOR

Converter::operator char() {
	if (_val.size() == 1 && !std::isdigit(_val.c_str()[0]))
		return static_cast<char>(_val.c_str()[0]);

	int	castedInt = static_cast<int>(*this);
	if (castedInt < 0 || castedInt > 255)
		throw Converter::OverflowException();
	u_char c = static_cast<u_char>(castedInt);
	if (!std::isprint(c))
		throw Converter::NonDisplayableException();
	return c;
}

Converter::operator int() {
	if (_val.size() == 1 && !std::isdigit(_val.c_str()[0]))
		return static_cast<int>(_val.c_str()[0]);

	double vald = static_cast<double>(*this);
	if (isnan(vald) || isinf(vald))
		throw Converter::ImpossibleConversionException();
	if (vald > INT32_MAX || vald < INT32_MIN)
		throw Converter::OverflowException();
	return static_cast<int>(vald);
}

Converter::operator float() {
	if (_val.size() == 1 && !std::isdigit(_val.c_str()[0]))
		return static_cast<float>(_val.c_str()[0]);

	double vald = static_cast<double>(*this);
	return static_cast<float>(vald);
}

Converter::operator double() {
	if (_val.size() == 1 && !std::isdigit(_val.c_str()[0]))
		return static_cast<double>(_val.c_str()[0]);

	try {
		return std::stod(_val);
	}
	catch (const std::exception& e) {
		return std::numeric_limits<double>::quiet_NaN();
	};
}

// EXCEPTIONS

const char* Converter::NonDisplayableException::what() const throw() {
	return ("\e[90mNon displayable\e[0m");
}
const char* Converter::ImpossibleConversionException::what() const throw() {
	return ("\e[90mimpossible\e[0m");
}
const char* Converter::NanException::what() const throw() {
	return ("\e[90mnan\e[0m");
}
const char* Converter::NanfException::what() const throw() {
	return ("\e[90mnanf\e[0m");
}
const char* Converter::OverflowException::what() const throw() {
	return ("\e[90mOverflow\e[0m");
}

// OPERATOR OVERLOAD

std::ostream &	operator<<( std::ostream & input, Converter & rhs ) {
	// CHAR
	try {
		input << std::setw(12) << "char: ";
		char	convertedChar = static_cast<char>(rhs);
		input << "\'" << convertedChar << "\'";
	}
	catch(const std::exception& e) { input << e.what(); }
	cout << endl;

	// INT
	try {
		input << std::setw(12) << "int: ";
		int	convertedInt = static_cast<int>(rhs);
		input << convertedInt;
	}
	catch(const std::exception& e) { input << e.what(); }
	cout << endl;
	
	// FLOAT
	try {
		input << std::setw(12) << "float: ";
		float	convertedFloat = static_cast<float>(rhs);

		double integral;
		if (std::modf(convertedFloat, &integral) == 0)
			input << std::fixed << std::setprecision(1) << integral  << "f";
		else
			input << std::setprecision(8) << convertedFloat << "f";
	}
	catch(const std::exception& e) { input << e.what(); }
	cout << endl;

	// DOUBLE
	try {
		input << std::setw(12) << "double: ";
		double	convertedDouble = static_cast<double>(rhs);

		double integral;
		if (std::modf(convertedDouble, &integral) == 0)
			input << std::fixed << std::setprecision(1) << integral;
		else
			input << std::setprecision(8) << convertedDouble;
	}
	catch(const std::exception& e) { input << e.what(); }
	cout << endl;

	return (input);
}
