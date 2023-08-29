/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bahamut.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:49:57 by fgeslin           #+#    #+#             */
/*   Updated: 2023/07/27 11:31:17 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Bahamut : public AMateria
{
public:
	Bahamut();
	Bahamut(const Bahamut &other);
	Bahamut &operator=(const Bahamut &rhs);
	~Bahamut();

	virtual AMateria*	clone() const;
	virtual void		use(ICharacter& target);

private:

};
