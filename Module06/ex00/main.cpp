/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 11:41:27 by fgeslin           #+#    #+#             */
/*   Updated: 2023/09/18 17:01:30 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Converter.hpp"

int main(int argc, char const *argv[])
{
	if (argc != 2)
		return (cout << "Wrong args!\n", 1);
	Converter	converter(argv[1]);
	// cout << converter.getSrc() << endl;
	cout << converter << endl;
	// cout << "Processing... " << argv[1] << "\n";
	// try {
	// 	cout << "char: " << (char)std::stoi(argv[1]) << "\n";
	// }
	// catch(const std::exception& e) {
	// 	cout << "char: overflow\n";
	// }
	// try {
	// 	cout << "int: " << std::stoi(argv[1]) << "\n";
	// }
	// catch(const std::exception& e) {
	// 	cout << "int: overflow\n";
	// }
	
	// cout << "float: " << std::stof(argv[1]) << "f\n";
	// cout << "double: " << std::stod(argv[1]) << "\n";
	return 0;
}
