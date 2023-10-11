/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:42:50 by fgeslin           #+#    #+#             */
/*   Updated: 2023/10/11 14:47:37 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char const *argv[])
{
	if (argc < 2)
		return (std::cerr << C_GRY << "./PmergeMe [n1, n2, n3, ...]\n" << C_WHT, 1);
	try {
		PmergeMe pmVec( argc, argv );
	}
	catch(const std::exception& e) { return (std::cerr << e.what() << '\n', 1); }
	return 0;
}
