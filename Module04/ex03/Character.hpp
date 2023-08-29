/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character copy.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:53:46 by fgeslin           #+#    #+#             */
/*   Updated: 2023/07/26 16:30:56 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
public:
	Character();
	Character(const string &name);
	Character(const Character &other);
	virtual Character &operator=(const Character &rhs);
	virtual ~Character();
	
	virtual string const & getName() const;
	virtual void equip(AMateria* m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter& target);
	virtual void display();

private:
	string		_name;
	AMateria*	_inventory[4];

};
