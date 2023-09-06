/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 12:33:32 by fgeslin           #+#    #+#             */
/*   Updated: 2023/09/06 11:35:01 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP_
# define BUREAUCRAT_HPP_

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

# include "Form.hpp"
class Form;

class Bureaucrat
{
private:
	string	_name;
	int			_grade;

public:
	Bureaucrat( void );
	Bureaucrat( string n, int g );
	Bureaucrat( Bureaucrat const & src );
	~Bureaucrat( void );

	Bureaucrat &	operator=( Bureaucrat const & rhs );

	string	getName( void ) const;
	int		getGrade( void ) const;
	void	increaseGrade( void );
	void	decreaseGrade( void );
	void	signForm( Form &f );

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

std::ostream &	operator<<( std::ostream & o, Bureaucrat const & rhs );

#endif
