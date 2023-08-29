/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:15:49 by fgeslin           #+#    #+#             */
/*   Updated: 2023/07/26 11:52:03 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
# define SCAVTRAP_H

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
public:
    ScavTrap( void );
    ScavTrap( const string &name );
    ScavTrap( const ScavTrap &src);
    virtual ~ScavTrap( void );

    virtual void	attack( const string &target );
    void			guardGate( void );
	int				getBaseHealth( void ) { return (100); };
	int				getBaseEnergy( void ) { return (50); };
	int				getBaseAttack( void ) { return (20); };

};

#endif
