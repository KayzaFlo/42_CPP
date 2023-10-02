/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:15:49 by fgeslin           #+#    #+#             */
/*   Updated: 2023/10/02 11:45:25 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
# define FRAGTRAP_H

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
protected:
	static int	_baseHealth;
	static int	_baseEnergy;
	static int	_baseAttack;

public:
	FragTrap( void );
	FragTrap( const string &name );
	FragTrap( const FragTrap &src);
	virtual ~FragTrap( void );

	virtual void	attack( const string &target );
	void			highFivesGuys( void );

};

#endif
