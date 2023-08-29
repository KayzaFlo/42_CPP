/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:15:47 by fgeslin           #+#    #+#             */
/*   Updated: 2023/07/25 16:31:28 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	// ScavTrap	st("ST");
	DiamondTrap	dt("DT");
	dt.attack("Monster");
	dt.takeDamage(3);
	dt.beRepaired(5);
	dt.guardGate();
	dt.highFivesGuys();
	dt.whoAmI();
	dt.takeDamage(300);
	dt.attack("Monster");
	dt.whoAmI();
	std::cout << std::endl;

	return 0;
}
