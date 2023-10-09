/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:27:25 by fgeslin           #+#    #+#             */
/*   Updated: 2023/10/09 11:17:41 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char const *argv[])
{
	if (argc != 2)
		return (std::cerr << C_GRY << "./btc [input file]\n" << C_WHT, 1);
	BitcoinExchange newbtce((string(argv[1])));
	return 0;
}
