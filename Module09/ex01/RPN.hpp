/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:42:48 by fgeslin           #+#    #+#             */
/*   Updated: 2023/10/09 15:37:15 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP_
# define RPN_HPP_
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
#include <fstream>
#include <sstream>
#include <stack>
using std::string;
using std::cout;
using std::endl;

class RPN
{
public:
	RPN( string formulae );
	~RPN();

private:
	RPN( void );
	RPN( const RPN &src );

	RPN &	operator=( RPN const & rhs );
	
	void	calculate( string );

	std::stack<float>	_calculation_stack;
};

#endif // RPN_HPP_
