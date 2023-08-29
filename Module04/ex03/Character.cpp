/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:53:28 by fgeslin           #+#    #+#             */
/*   Updated: 2023/07/26 15:55:01 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("default") {
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	cout << C_GRN << "<Character> " << C_WHT;
	cout << "Created " << C_CYA << "[" << _name << "]" << C_WHT << "\n";
}

Character::Character(const string &name) : _name(name) {
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	cout << C_GRN << "<Character(Typed)> " << C_WHT;
	cout << "Created " << C_CYA << "[" << _name << "]" << C_WHT << "\n";
}

Character::Character(const Character &other) {
	cout << C_GRN << "<Character>(Copy) " << C_WHT;
	*this = other;
}

Character::~Character() {
	for (int i = 0; i < 4; i++)	{
		if (_inventory[i])
			delete _inventory[i];
	}
	cout << C_RED << "~Character " << C_WHT;
}

Character &Character::operator=(const Character &rhs) {
	_name = rhs._name + "_copy";
	for (int i = 0; i < 4; i++)	{
		if (_inventory[i])
			delete _inventory[i];
		if (rhs._inventory[i])
			_inventory[i] = rhs._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
	return *this;
}

string const &	Character::getName() const {
	return _name;
}

void	Character::equip(AMateria* m) {
	if (!m)
		return;
	for (int i = 0; i < 4; i++)	{
		if (!_inventory[i]) {
			_inventory[i] = m;
			cout << "Materia " << C_MAG << m->getColor() << m->getType()  << C_WHT;
			cout << " equiped to " << C_CYA << "[" << _name << "]" << C_WHT << " Slot " << i << ".\n";
			return;
		}
	}
	cout << C_CYA << "[" << _name << "]" << C_WHT << "\'s inventory full...\n";
}

void	Character::unequip(int idx) {
	cout << "Materia " << C_MAG << _inventory[idx]->getColor() << _inventory[idx]->getType()  << C_WHT << " dropped on ground. Slot " << idx << " emptied.\n";
	_inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target) {
	if (_inventory[idx]) {
		cout << C_CYA << "[" << _name << "]" << C_WHT << " ";
		_inventory[idx]->use(target);
	}
}

void	Character::display() {
	cout << C_CYA << "[" << _name << "]" << C_WHT << ": [";
	for (int i = 0; i < 4; i++)	{
		if (_inventory[i])
			cout << _inventory[i]->getColor();
		else
			cout << "⚫️";
	}
	cout << "].\n";
}
