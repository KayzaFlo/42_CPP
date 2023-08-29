/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 11:54:25 by fgeslin           #+#    #+#             */
/*   Updated: 2023/04/22 11:08:02 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

int main(int ac, char *av[])
{
    Harl        harl;
    std::string level;

    if (ac != 2)
        return (std::cout << "Bad arguments\n", 1);
        
    harl.complain(av[1]);

    return 0;
}
