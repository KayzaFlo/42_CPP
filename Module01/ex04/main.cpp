/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 11:54:25 by fgeslin           #+#    #+#             */
/*   Updated: 2023/04/22 13:16:11 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int	sed(std::string filename, std::string find, std::string replace) {

	std::ifstream	ifs(filename);
	std::ofstream	ofs(filename + ".replace");
	std::string		content;
	size_t			cursor;

	if (!ifs.is_open() || !ofs.is_open())
		return (std::cout << "Error: File could not be opened\n", 1);

	std::getline(ifs, content, '\0');
	while ((cursor = content.find(find)) != std::string::npos)
	{
		content.erase(cursor, find.length());
		content.insert(cursor, replace);
	}
	ofs << content;

	ifs.close();
	ofs.close();

	return (0);
}

int	main(int argc, char const *argv[]) {
	
	if (argc != 4)
		return (std::cout << "Syntaxe error!\n", 1);

	return (sed(argv[1], argv[2], argv[3]));
}
