/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:15:48 by fgeslin           #+#    #+#             */
/*   Updated: 2023/10/02 11:44:07 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	ScavTrap::_baseHealth = 100;
int	ScavTrap::_baseEnergy = 50;
int	ScavTrap::_baseAttack = 20;

ScavTrap::ScavTrap() : ClapTrap( "defaultST", _baseHealth, _baseEnergy, _baseAttack ) {
	cout << C_YEL << "  > ScavTrap \'" << _name << "\' Default constructor called! <" << C_WHT << endl;
}

ScavTrap::ScavTrap( const string &name ) : ClapTrap( name, _baseHealth, _baseEnergy, _baseAttack ) {
	cout << C_YEL << "  > ScavTrap \'" << _name << "\' Named constructor called! <" << C_WHT << endl;
}

ScavTrap::ScavTrap( const ScavTrap &src) : ClapTrap( src ) {
	cout << C_YEL << "  > ScavTrap \'" << _name << "\' Copy constructor called! <" << C_WHT << endl;
}

ScavTrap::~ScavTrap( void ) {
	cout << C_RED << "  ~ ScavTrap \'" << _name << "\' Destructor called! ~" << C_WHT << endl;
}

void	ScavTrap::attack( const string& target ) {
	if (!isActive())
		return;
	cout << "\'" << _name << "\' shots " << target << ", dealing " << _attack << " points of damage." << endl;
	updateStatus(0, -1);
}

void	ScavTrap::guardGate( void ) {
	if (!isActive())
		return;
	std::cout << "\'" << _name << "\' started Gate keeper mode" << std::endl;
	updateStatus(0, -1);
}
