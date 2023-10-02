/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:15:48 by fgeslin           #+#    #+#             */
/*   Updated: 2023/10/02 11:42:27 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	FragTrap::_baseHealth = 100;
int	FragTrap::_baseEnergy = 100;
int	FragTrap::_baseAttack = 30;

FragTrap::FragTrap() : ClapTrap( "defaultFT", _baseHealth, _baseEnergy, _baseAttack ) {
	cout << C_YEL << "  > FragTrap \'" << _name << "\' Default constructor called! <" << C_WHT << endl;
}

FragTrap::FragTrap( const string &name ) : ClapTrap( name, _baseHealth, _baseEnergy, _baseAttack ) {
	cout << C_YEL << "  > FragTrap \'" << _name << "\' Named constructor called! <" << C_WHT << endl;
}

FragTrap::FragTrap( const FragTrap &src) : ClapTrap( src ) {
	cout << C_YEL << "  > FragTrap \'" << _name << "\' Copy constructor called! <" << C_WHT << endl;
}

FragTrap::~FragTrap( void ) {
	cout << C_RED << "  ~ FragTrap \'" << _name << "\' Destructor called! ~" << C_WHT << endl;
}

void	FragTrap::attack( const string &target ) {
	if (!isActive())
		return;
	cout << "\'" << _name << "\' explodes " << target << ", dealing " << _attack << " points of damage." << endl;
	updateStatus(0, -1);
}

void	FragTrap::highFivesGuys( void ) {
	if (!isActive())
		return;
	std::cout << "\'" << _name << "\' wants a High Five!" << std::endl;
	updateStatus(0, -1);
}
