/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 11:44:42 by fgeslin           #+#    #+#             */
/*   Updated: 2023/09/19 13:13:33 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define C_WHT "\e[0m"
# define C_GRY "\e[90m"

# include <iostream>
# include <iomanip>

struct Data
{
	std::string	name;
	int			x;
	int			y;
	void		*content;
};

uintptr_t	serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

// uint64_t	serializeError(Data* ptr) {
// 	return reinterpret_cast<uint64_t>(ptr);
// }

Data*		deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}

void		printData(std::string name, Data* data) {
	std::cout << std::setw(16) << name << "[";
	std::cout << std::setw(10) << data << "] -> ";
	std::cout << std::setw(8) << data->name << " | ";
	std::cout << std::setw(2) << data->x << " | ";
	std::cout << std::setw(2) << data->y << " | ";
	std::cout << std::setw(10) << data->content << "\n";
}

int main(int argc, char const *argv[]) {
	if (argc != 2) {
		return (std::cout << C_GRY << "./serialize [name]\n" << C_WHT, 1);
	}
	
	Data		dat = { argv[1], 42, 21, argv };
	printData("dat", &dat);

	uintptr_t	serializedDat = serialize(&dat);
	Data		*deserializedDat = deserialize(serializedDat);
	printData("deserializedDat", deserializedDat);
	
	// uint64_t		serializedDat = serializeError(&dat);
	// Data		*deserializedDat = deserialize(serializedDat);
	// printData("deserializedDat", deserializedDat);

	return 0;
}
