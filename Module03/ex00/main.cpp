/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:15:47 by fgeslin           #+#    #+#             */
/*   Updated: 2023/07/24 14:50:18 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

int main()
{
	ClapTrap    ct("CT");
	ClapTrap	*ctClone;

	ct.attack("Monster");
	ct.takeDamage(3);
	ct.beRepaired(5);
	cout << endl;

	ctClone = new ClapTrap(ct);
	ctClone->beRepaired(10);
	ctClone->takeDamage(30);
	ctClone->attack("Monster");
	delete (ctClone);
	cout << endl;

	ct.attack("Monster");
	ct.attack("Monster");
	ct.attack("Monster");
	ct.attack("Monster");
	ct.attack("Monster");
	ct.attack("Monster");
	ct.attack("Monster");
	ct.attack("Monster");
	ct.attack("Monster");
	ct.takeDamage(30);
	ct.attack("Monster");

	return 0;
}
