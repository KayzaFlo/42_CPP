/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:09:27 by fgeslin           #+#    #+#             */
/*   Updated: 2023/09/08 16:16:48 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP_
# define PRESIDENTIALPARDONFORM_HPP_
# pragma once

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	string	_target;
	
public:
	PresidentialPardonForm( void );
	PresidentialPardonForm( string target );
	PresidentialPardonForm( PresidentialPardonForm const & src );
	~PresidentialPardonForm( void );

	PresidentialPardonForm &	operator=( PresidentialPardonForm const & rhs );

	virtual void	execute(Bureaucrat const & executor) const;
	string			getTarget( void ) const;

};

#endif // PRESIDENTIALPARDONFORM_HPP_
