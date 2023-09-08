/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:36:49 by fgeslin           #+#    #+#             */
/*   Updated: 2023/09/06 13:27:42 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP_
# define AFORM_HPP_
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

class AForm
{
private:
	string		_name;
	bool		_isSigned;
	const int	_gradeToSign;
	const int	_gradeToExec;

public:
	AForm( void );
	AForm( string name, int gradeToSign, int gradeToExec );
	AForm( AForm const & src );
	virtual ~AForm( void );

	AForm &	operator=( AForm const & rhs );

	string	getName( void ) const;
	string	getFormattedName( void ) const;
	bool	getIsSigned( void ) const;
	int		getGradeToSign( void ) const;
	int		getGradeToExec( void ) const;
	void	beSigned( Bureaucrat &b );
	void	tryToExecute( Bureaucrat &b );
	
	virtual void	execute(Bureaucrat const & executor) const = 0;

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
	class AlreadySignedException : public exception
	{
		public:
			virtual const char* what() const throw();
	};
	class NotSignedException : public exception
	{
		public:
			virtual const char* what() const throw();
	};
	
};

std::ostream &	operator<<( std::ostream & o, AForm const & rhs );

#endif // AFORM_HPP_