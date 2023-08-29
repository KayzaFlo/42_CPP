/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 14:20:39 by fgeslin           #+#    #+#             */
/*   Updated: 2023/04/25 14:51:23 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

bool    bsp( Point const a, Point const b, Point const c, Point const point);

int main( int ac, char *av[] ) {
	if (ac != 9)
		return (std::cout << "Bad argumets\n", 1);
	for (int i = 1; i < ac; i++)
		for (size_t j = 0; av[i][j]; j++)
			if (!std::isdigit(av[i][j]) && av[i][j] != '.' && av[i][j] != '-')
				return (std::cout << "NaN\n", 1);

	Point const	a( atof(av[1]), atof(av[2]) );
	Point const	b( atof(av[3]), atof(av[4]) );
	Point const	c( atof(av[5]), atof(av[6]) );
	Point const	point( atof(av[7]), atof(av[8]) );

	if (bsp(a, b, c, point))
		std::cout << "YAY! Point is inside Triangle" << std::endl;
	else
		std::cout << "NAY! Point is outside Triangle" << std::endl;
	
	return 0;
}
