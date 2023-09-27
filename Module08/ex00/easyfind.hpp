/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 10:43:03 by fgeslin           #+#    #+#             */
/*   Updated: 2023/09/27 14:45:07 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP_
# define EASYFIND_HPP_
# pragma once

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
# include <algorithm>
using std::exception;
using std::string;
using std::cout;
using std::cerr;
using std::endl;

void	printint(int i);

template< typename T >
int	easyfind( T const & cont, int const & val ) {
	cout << C_GRY;
	std::for_each(cont.begin(), cont.end(), printint);
	cout << " ==> Looking for " << val << "\n" << C_WHT;

	if ( std::find( cont.begin(), cont.end(), val ) != cont.end() )
		return (0);
	return (1);
}

#endif // EASYFIND_HPP_
