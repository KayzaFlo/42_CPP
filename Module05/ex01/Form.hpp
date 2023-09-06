/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:36:49 by fgeslin           #+#    #+#             */
/*   Updated: 2023/09/06 11:54:04 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP_
# define FORM_HPP_
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
using std::exception;
using std::string;
using std::cout;
using std::cerr;
using std::endl;

# include "Bureaucrat.hpp"
class Bureaucrat;

class Form
{
private:
	string		_name;
	bool		_isSigned;
	const int	_gradeToSign;
	const int	_gradeToExec;

public:
	Form( void );
	Form( string name, int gradeToSign, int gradeToExec );
	Form( Form const & src );
	~Form( void );

	Form &	operator=( Form const & rhs );

	string	getName( void ) const;
	bool	getIsSigned( void ) const;
	int		getGradeToSign( void ) const;
	int		getGradeToExec( void ) const;
	void	beSigned( Bureaucrat &b );

	class GradeTooHighException : public exception
	{
		public:
			virtual const char* what() const throw();
	};

	class GradeTooLowException : public exception
	{
		public:
			virtual const char* what() const throw();
	};
	
};

std::ostream &	operator<<( std::ostream & o, Form const & rhs );

#endif // FORM_HPP_