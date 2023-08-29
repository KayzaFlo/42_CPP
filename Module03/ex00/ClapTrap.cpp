/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:15:48 by fgeslin           #+#    #+#             */
/*   Updated: 2023/07/25 17:31:14 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void ) : _name("defaultCT"), _health(10), _energy(10), _attack(0) {
	cout << C_GRN << "> ClapTrap \'" << _name << "\' Default constructor called! <" << C_WHT << endl;
}

ClapTrap::ClapTrap( string name ) : _name(name), _health(10), _energy(10), _attack(0) {
	cout << C_GRN << "> ClapTrap \'" << _name << "\' Named constructor called! <" << C_WHT << endl;
}

ClapTrap::ClapTrap( ClapTrap const & src) {
	*this = src;
	_name.append("_copy");
	cout << C_GRN << "> ClapTrap \'" << _name << "\' Copy constructor called! <" << C_WHT << endl;
}

ClapTrap::~ClapTrap() {
	cout << C_RED << "~ ClapTrap \'" << _name << "\' Destructor called! ~" << C_WHT << endl;
}

void	ClapTrap::attack(const string& target) {
	if (!isActive())
		return;
	updateStatus(0, -1);
	cout << "\'" << _name << "\' attacks " << target << ", dealing " << _attack << " points of damage." << endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	updateStatus(-amount, 0);
	cout << "\'" << _name << "\' takes " << amount << " points of damage." << endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (!isActive())
		return;
	updateStatus(amount, -1);
	cout << "\'" << _name << "\' gains " << amount << " health points." << endl;
}

bool	ClapTrap::isActive() {
	if (_health <= 0) {
		updateStatus(0, 0);
		cout << "\t/!\\ \'" << _name << "\' is broken /!\\" << endl;
		return (false);
	}
	if (_energy <= 0) {
		updateStatus(0, 0);
		cout << "\t/!\\ \'" << _name << "\' is out of energy /!\\" << endl;
		return (false);
	}
	return (true);
}

void	ClapTrap::updateStatus(int hp, int ep) {
	_health = std::max(_health + hp, 0);
	_energy = std::max(_energy + ep, 0);
	cout << C_GRY << "[HP:" << _health;
	if (hp > 0)
		cout << C_GRN << "(+" << hp << ")";
	else if (hp < 0)
		cout << C_RED << "(" << hp << ")";
	cout << C_GRY << "|EP:" << _energy;
	if (ep > 0)
		cout << C_GRN << "(+" << ep << ")";
	else if (ep < 0)
		cout << C_RED << "(" << ep << ")";
	cout << C_GRY << "] \t" << C_WHT;
}

ClapTrap &  ClapTrap::operator=( ClapTrap const & rhs ) {
	_name = rhs._name;
	_health = rhs._health;
	_energy = rhs._energy;
	_attack = rhs._attack;
	return *this;
}
