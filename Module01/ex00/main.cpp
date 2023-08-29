/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 11:54:25 by fgeslin           #+#    #+#             */
/*   Updated: 2023/04/07 12:16:04 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <unistd.h>

Zombie* newZombie( std::string name );
void randomChump( std::string name );

int main()
{
	randomChump("Sylvia");
	std::cout << std::endl;

	Zombie	*zombie = newZombie("Hector");
	zombie->announce();
	delete (zombie);

	return 0;
}
