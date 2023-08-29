/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:15:47 by fgeslin           #+#    #+#             */
/*   Updated: 2023/07/24 15:46:30 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ClapTrap    ct("CT");
	ct.attack("Monster");
	ct.takeDamage(3);
	ct.beRepaired(5);
	std::cout << std::endl;

	ScavTrap	*st;
	st = new ScavTrap("scavTrap");
	st->beRepaired(10);
	st->guardGate();
	delete (st);
	std::cout << std::endl;

	FragTrap    ft("FT");
	FragTrap    fts("FT_sec");
	fts.attack("Fish");
	fts.takeDamage(3);
	fts.beRepaired(50);
	fts = ft;
	fts.attack("Squid");
	fts.takeDamage(300);
	fts.beRepaired(5);
	fts.highFivesGuys();
	std::cout << std::endl;

	FragTrap	*ftClone;
	ftClone = new FragTrap(ft);
	ftClone->beRepaired(10);
	ftClone->highFivesGuys();
	delete (ftClone);
	std::cout << std::endl;

	return 0;
}
