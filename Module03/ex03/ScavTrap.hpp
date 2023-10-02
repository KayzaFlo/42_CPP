/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:15:49 by fgeslin           #+#    #+#             */
/*   Updated: 2023/10/02 11:42:02 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
# define SCAVTRAP_H

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
protected:
	static int	_baseHealth;
	static int	_baseEnergy;
	static int	_baseAttack;
	
public:
    ScavTrap( void );
    ScavTrap( const string &name );
    ScavTrap( const ScavTrap &src);
    virtual ~ScavTrap( void );

    virtual void	attack( const string &target );
    void			guardGate( void );

};

#endif
