/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:52:03 by fgeslin           #+#    #+#             */
/*   Updated: 2023/07/26 13:06:10 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_H
# define WRONGANIMAL_H

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

class WrongAnimal
{
protected:
	string	_type;
public:
	WrongAnimal( void );
	WrongAnimal( string type );
	WrongAnimal( const WrongAnimal &src );
	virtual ~WrongAnimal( void );

	WrongAnimal &	operator=( WrongAnimal const & rhs );

	void	makeSound( void ) const;
	string	getType( void ) const;
	
};

#endif
