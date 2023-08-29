/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:51:57 by fgeslin           #+#    #+#             */
/*   Updated: 2023/07/26 14:55:40 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
# define DOG_H

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain	*_brain;

public:
	Dog( void );
	Dog( const Dog &src );
	virtual ~Dog( void );

	Dog &	operator=( Dog const & rhs );
	
	virtual void	makeSound( void ) const;
	void	printIdeas( int i ) const;

};

#endif
