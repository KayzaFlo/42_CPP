/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:15:40 by fgeslin           #+#    #+#             */
/*   Updated: 2023/09/08 16:16:38 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP_
# define ROBOTOMYREQUESTFORM_HPP_
# pragma once

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	string	_target;
	
public:
	RobotomyRequestForm( void );
	RobotomyRequestForm( string target );
	RobotomyRequestForm( RobotomyRequestForm const & src );
	~RobotomyRequestForm( void );

	RobotomyRequestForm &	operator=( RobotomyRequestForm const & rhs );

	virtual void	execute(Bureaucrat const & executor) const;
	string			getTarget( void ) const;

};

#endif // ROBOTOMYREQUESTFORM_HPP_
