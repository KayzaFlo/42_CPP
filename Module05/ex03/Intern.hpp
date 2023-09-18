/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:20:49 by fgeslin           #+#    #+#             */
/*   Updated: 2023/09/18 11:18:33 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP_
# define INTERN_HPP_
# pragma once

# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"
// class AForm;

class Intern
{
public:
	Intern( void );
	Intern( Intern const & src );
	~Intern( void );

	Intern &	operator=( Intern const & rhs );
	
	AForm *		makePrezForm(string target) const;
	AForm *		makeRobotForm(string target) const;
	AForm *		makeShrubForm(string target) const;
	AForm *		makeForm(string name, string target) const;

};

#endif // INTERN_HPP_