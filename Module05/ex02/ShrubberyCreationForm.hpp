/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:15:35 by fgeslin           #+#    #+#             */
/*   Updated: 2023/09/08 16:16:33 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP_
# define SHRUBBERYCREATIONFORM_HPP_
# pragma once

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
	string	_target;
	
public:
	ShrubberyCreationForm( void );
	ShrubberyCreationForm( string target );
	ShrubberyCreationForm( ShrubberyCreationForm const & src );
	~ShrubberyCreationForm( void );

	ShrubberyCreationForm &	operator=( ShrubberyCreationForm const & rhs );

	virtual void	execute(Bureaucrat const & executor) const;
	string			getTarget( void ) const;

};

#endif // SHRUBBERYCREATIONFORM_HPP_
