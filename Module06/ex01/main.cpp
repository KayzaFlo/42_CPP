/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 11:44:42 by fgeslin           #+#    #+#             */
/*   Updated: 2023/09/19 12:32:47 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define C_WHT "\e[0m"
# define C_BOL "\e[1m"
# define C_ITA "\e[3m"
# define C_UND "\e[4m"
# define C_RED "\e[31m"
# define C_GRN "\e[32m"
# define C_YEL "\e[33m"
# define C_BLU "\e[34m"
# define C_MAG "\e[35m"
# define C_CYA "\e[36m"
# define C_GRY "\e[90m"

# include <iostream>
# include <iomanip>
# include <cmath>
using std::exception;
using std::string;
using std::cout;
using std::cerr;
using std::endl;

struct Data
{
	string	name;
	int		x;
	int		y;
	void	*content;
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

void		printData(string name, Data* data) {
	cout << std::setw(16) << name << "[";
	cout << std::setw(10) << data << "] -> ";
	cout << std::setw(8) << data->name << " | ";
	cout << std::setw(2) << data->x << " | ";
	cout << std::setw(2) << data->y << " | ";
	cout << std::setw(10) << data->content << "\n";
}

int main(int argc, char const *argv[]) {
	if (argc != 2) {
		return (cout << C_GRY << "./serialize [name]\n" << C_WHT, 1);
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
