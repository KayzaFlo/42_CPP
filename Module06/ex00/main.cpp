/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 11:41:27 by fgeslin           #+#    #+#             */
/*   Updated: 2023/09/19 11:19:45 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Converter.hpp"

int main(int argc, char const *argv[])
{
	if (argc != 2)
		return (cout << "Wrong args!\n", 1);
	Converter	converter(argv[1]);
	cout << converter;
	return 0;
}
