/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 12:16:21 by fgeslin           #+#    #+#             */
/*   Updated: 2023/04/25 14:47:54 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
private:
	Fixed const _x;
	Fixed const _y;

public:
	Point();
	Point( float x, float y );
	Point( Point const & src );
	~Point();

	Point &		operator=( Point const & rhs );
	
	Fixed const	getX(void) const;
	Fixed const	getY(void) const;
	//

};

#endif
