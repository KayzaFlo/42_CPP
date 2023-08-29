/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 11:54:25 by fgeslin           #+#    #+#             */
/*   Updated: 2023/04/07 12:50:37 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <unistd.h>

Zombie* zombieHorde( int N, std::string name );

int main()
{
	Zombie	*zombie_horde;
	int		n;

	std::cout << "Horde size [1, +Inf]: ";
	std::cin >> n;
	if (n < 1)
		return -1;
	zombie_horde = zombieHorde(n, "Morisse");
	for (int i = 0; i < n; i++)
		zombie_horde[i].announce();
	delete [] (zombie_horde);
	return 0;
}
