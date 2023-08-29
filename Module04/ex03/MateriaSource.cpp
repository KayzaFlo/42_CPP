/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:53:28 by fgeslin           #+#    #+#             */
/*   Updated: 2023/07/26 16:24:41 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	cout << C_GRN << "<MateriaSource> " << C_WHT;
}

MateriaSource::MateriaSource(const MateriaSource &other) {
	*this = other;
	cout << C_GRN << "<MateriaSource>(Copy) " << C_WHT;
}

MateriaSource::~MateriaSource() { 
	for (int i = 0; i < 4; i++)	{
		if (_inventory[i])
			delete _inventory[i];
	}
	cout << C_RED << "~MateriaSource " << C_WHT;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &rhs) {
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

void		MateriaSource::learnMateria(AMateria* m) {
	for (int i = 0; i < 4; i++)	{
		if (!_inventory[i]) {
			_inventory[i] = m;
			cout << "Materia " << C_MAG << m->getColor() << m->getType() << C_WHT << " added to " << C_BLU << "[SOURCE]" << C_WHT << " Slot " << i << ".\n";
			return;
		}
	}
	cout << "Source full...\n";
}

AMateria*	MateriaSource::createMateria(string const & type) {
	for (int i = 0; i < 4; i++)	{
		if (_inventory[i]) {
			if (_inventory[i]->getType() == type) {
				AMateria *temp = _inventory[i]->clone();
				cout << "Materia " << C_MAG << temp->getColor() << type << C_WHT << " created from " << C_BLU << "[SOURCE]" << C_WHT << ".\n";
				return temp;
			}
		}
	}
	return NULL;
}

void		MateriaSource::display() {
	cout << C_BLU << "[SOURCE]" << C_WHT << " [";
	for (int i = 0; i < 4; i++)	{
		if (_inventory[i])
			cout << _inventory[i]->getColor();
		else
			cout << "⚫️";
	}
	cout << "].\n";
}
