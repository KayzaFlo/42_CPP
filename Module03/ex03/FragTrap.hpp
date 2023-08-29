/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:15:49 by fgeslin           #+#    #+#             */
/*   Updated: 2023/07/26 11:52:19 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
# define FRAGTRAP_H

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap( void );
	FragTrap( const string &name );
	FragTrap( const FragTrap &src);
	virtual ~FragTrap( void );

	virtual void	attack( const string &target );
	void			highFivesGuys( void );
	int				getBaseHealth( void ) { return (100); };
	int				getBaseEnergy( void ) { return (100); };
	int				getBaseAttack( void ) { return (30); };

};

#endif
