/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:24:20 by fgeslin           #+#    #+#             */
/*   Updated: 2023/09/19 11:11:37 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP_
# define CONVERTER_HPP_
# pragma once

# define C_WHT "\e[0m"
# define C_BOL "\e[1m"
# define C_ITA "\e[3m"
# define C_UND "\e[4m"
# define C_RED "\e[31m"
# define C_GRN "\e[32m"
# define C_YEL "\e[33m"
# define C_BLU "\e[34m"
# define C_MAG "\e[35m"
# define C_CYA "\e[36m"
# define C_GRY "\e[90m"

# include <iostream>
# include <iomanip>
# include <string>
# include <cmath>
using std::exception;
using std::string;
using std::cout;
using std::cerr;
using std::endl;

class Converter
{
private:
	const string	_val;

public:
	Converter( void );
	Converter( string val );
	Converter( Converter const & val );
	~Converter( void );

	Converter &	operator=( Converter const & rhs );

	operator char();
	operator int();
	operator float();
	operator double();

	class NonDisplayableException : public std::exception {
		public:
			virtual const char* what() const throw();
	};
	class ImpossibleConversionException : public std::exception {
		public:
			virtual const char* what() const throw();
	};
	class NanException : public std::exception {
		public:
			virtual const char* what() const throw();
	};
	class NanfException : public std::exception {
		public:
			virtual const char* what() const throw();
	};
	class OverflowException : public std::exception {
		public:
			virtual const char* what() const throw();
	};

};

std::ostream &	operator<<( std::ostream & o, Converter & rhs );

#endif // CONVERTER_HPP_