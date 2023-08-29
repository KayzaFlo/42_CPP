/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 12:33:32 by fgeslin           #+#    #+#             */
/*   Updated: 2023/08/29 14:35:35 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Bureaucrat
{
private:
	std::string	_name;
	int			_grade;

public:
	Bureaucrat( void );
	Bureaucrat( std::string n, int g );
	Bureaucrat( Bureaucrat const & src );
	~Bureaucrat( void );

	Bureaucrat &	operator=( Bureaucrat const & rhs );

	std::string		getName( void ) const;
	int				getGrade( void ) const;
	void			increaseGrade( void );
	void			decreaseGrade( void );

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

};

std::ostream &	operator<<( std::ostream & o, Bureaucrat const & rhs );
