/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:52:03 by fgeslin           #+#    #+#             */
/*   Updated: 2023/07/26 15:31:22 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_H
# define AANIMAL_H

# define C_WHT "\033[0m"
# define C_RED "\033[31m"
# define C_GRN "\033[32m"
# define C_YEL "\033[33m"
# define C_BLU "\033[34m"
# define C_MAG "\033[35m"
# define C_CYA "\033[36m"
# define C_GRY "\033[90m"

# include <iostream>

using std::string;
using std::cout;
using std::endl;

class AAnimal
{
protected:
	string	_type;
	
public:
	AAnimal( void );
	AAnimal( string type );
	AAnimal( const AAnimal &src );
	virtual ~AAnimal( void );

	AAnimal &	operator=( AAnimal const & rhs );

	virtual void	makeSound( void ) const = 0;
	string	getType( void ) const;

	
};

#endif
