/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:53:12 by fgeslin           #+#    #+#             */
/*   Updated: 2023/08/01 14:19:28 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Bahamut.hpp"

int main()
{
	AMateria *tmpMat;
	AMateria *tmpMat2;

	IMateriaSource* src = new MateriaSource();
	cout << "\n";
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Bahamut());
	src->learnMateria(new Bahamut());
	tmpMat = new Bahamut();
	src->learnMateria(tmpMat);
	delete(tmpMat);
	cout << "\n";
	src->display();
	cout << "\n";
	
	ICharacter* me = new Character("me");
	me->display();
	me->equip(src->createMateria("bahamut"));
	me->equip(src->createMateria("null"));
	tmpMat = src->createMateria("cure");
	me->equip(tmpMat);
	me->equip(src->createMateria("cure"));
	me->equip(src->createMateria("ice"));
	tmpMat2 = src->createMateria("ice");
	me->equip(tmpMat2);
	delete(tmpMat2);
	cout << "\n";
	me->display();
	me->unequip(1);
	delete(tmpMat);
	cout << "\n";
	me->display();
	tmpMat = src->createMateria("bahamut");
	me->equip(tmpMat);
	me->display();
	me->unequip(1);
	delete(tmpMat);
	cout << "\n";
	me->use(1, *me);
	me->use(2, *me);
	cout << "\n";
	
	Character bob("bob");
	bob = *dynamic_cast<Character*>(me);
	bob.equip(src->createMateria("ice"));
	bob.display();
	bob.use(0, *me);
	bob.use(2, bob);
	bob.use(1, *me);
	cout << "\n";

	delete me;
	cout << "\n";
	delete src;
	cout << "\n";
	return 0;

}
