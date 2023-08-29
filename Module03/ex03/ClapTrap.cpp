/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:15:48 by fgeslin           #+#    #+#             */
/*   Updated: 2023/07/25 17:31:20 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("defaultCT"), _health(getBaseHealth()), _energy(getBaseEnergy()), _attack(getBaseAttack()) {
	cout << C_GRN << "> ClapTrap \'" << _name << "\' Default constructor called! <" << C_WHT << endl;
}

ClapTrap::ClapTrap( string name ) : _name(name), _health(getBaseHealth()), _energy(getBaseEnergy()), _attack(getBaseAttack()) {
	cout << C_GRN << "> ClapTrap \'" << _name << "\' Named constructor called! <" << C_WHT << endl;
}

ClapTrap::ClapTrap( std::string name, int h, int e, int a ) : _name(name), _health(h), _energy(e), _attack(a) {
	cout << C_GRN << "> ClapTrap \'" << _name << "\' Defined constructor called! <" << C_WHT << endl;
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
	cout << "\'" << _name << "\' attacks " << target << ", dealing " << _attack << " points of damage." << endl;
	updateStatus(0, -1);
}

void	ClapTrap::takeDamage(unsigned int amount) {
	cout << "\'" << _name << "\' takes " << amount << " points of damage." << endl;
	updateStatus(-amount, 0);
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (!isActive())
		return;
	cout << "\'" << _name << "\' gains " << amount << " health points." << endl;
	updateStatus(amount, -1);
}

bool	ClapTrap::isActive() {
	if (_health <= 0) {
		cout << "/!\\ \'" << _name << "\' is broken /!\\" << endl;
		updateStatus(0, 0);
		return (false);
	}
	if (_energy <= 0) {
		cout << "/!\\ \'" << _name << "\' is out of energy /!\\" << endl;
		updateStatus(0, 0);
		return (false);
	}
	return (true);
}

void	ClapTrap::updateStatus(int hp, int ep) {
	_health = std::max(_health + hp, 0);
	_energy = std::max(_energy + ep, 0);
	cout << C_GRY << "\t[HP:" << _health;
	if (hp > 0)
		cout << C_GRN << "(+" << hp << ")";
	else if (hp < 0)
		cout << C_RED << "(" << hp << ")";
	cout << C_GRY << "|EP:" << _energy;
	if (ep > 0)
		cout << C_GRN << "(+" << ep << ")";
	else if (ep < 0)
		cout << C_RED << "(" << ep << ")";
	cout << C_GRY << "]\n" << C_WHT;
}

ClapTrap &  ClapTrap::operator=( ClapTrap const & rhs ) {
	_name = rhs._name;
	_health = rhs._health;
	_energy = rhs._energy;
	_attack = rhs._attack;
	return *this;
}
