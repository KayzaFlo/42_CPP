/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:15:47 by fgeslin           #+#    #+#             */
/*   Updated: 2023/07/24 15:46:35 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ClapTrap    ct("CT");
	ct.attack("Monster");
	ct.takeDamage(3);
	ct.beRepaired(5);
	std::cout << std::endl;

	ClapTrap	*ctClone;
	ctClone = new ClapTrap(ct);
	ctClone->beRepaired(10);
	delete (ctClone);
	std::cout << std::endl;

	ScavTrap    st("ST");
	ScavTrap    sts("ST_sec");
	sts.attack("Fish");
	sts.takeDamage(3);
	sts.beRepaired(50);
	sts = st;
	sts.attack("Squid");
	sts.takeDamage(300);
	sts.beRepaired(5);
	sts.guardGate();
	std::cout << std::endl;

	ScavTrap	*stClone;
	stClone = new ScavTrap(st);
	stClone->beRepaired(10);
	stClone->guardGate();
	delete (stClone);
	std::cout << std::endl;

	return 0;
}
