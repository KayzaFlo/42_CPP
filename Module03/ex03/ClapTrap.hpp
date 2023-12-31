/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:15:49 by fgeslin           #+#    #+#             */
/*   Updated: 2023/10/02 11:39:32 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
# define CLAPTRAP_H

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

class ClapTrap
{
protected:
	string	_name;
	int		_health;
	int		_energy;
	int		_attack;

	static int	_baseHealth;
	static int	_baseEnergy;
	static int	_baseAttack;

public:
	ClapTrap( void );
	ClapTrap( string name );
	ClapTrap( string name, int h, int e, int a );
	ClapTrap( ClapTrap const & src);
	virtual ~ClapTrap();

	ClapTrap &	operator=( ClapTrap const & rhs );

	virtual void	attack(const string& target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);
	bool			isActive();
	void			updateStatus(int hp, int ep);
	int				getBaseHealth( void ) { return (10); };
	int				getBaseEnergy( void ) { return (10); };
	int				getBaseAttack( void ) { return (0); };

};

#endif
