/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 12:16:12 by fgeslin           #+#    #+#             */
/*   Updated: 2023/04/25 14:55:37 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

Fixed sign (Point a, Point b, Point c) {
	return (a.getX() - c.getX()) * (b.getY() - c.getY()) - (b.getX() - c.getX()) * (a.getY() - c.getY());
}

/// @brief Check if point inside triangle
/// @param a,b,c Triangle points
/// @param point Point to check for
/// @return True if point inside triangle, false if outside or on border
bool    bsp( Point const a, Point const b, Point const c, Point const point) {
	Fixed   dab = sign(point, a, b);
	Fixed   dbc = sign(point, b, c);
	Fixed   dca = sign(point, c, a);
	bool    has_neg = (dab < 0) || (dbc < 0) || (dca < 0);
	bool    has_pos = (dab > 0) || (dbc > 0) || (dca > 0);
	bool    has_zer = (dab == 0) || (dbc == 0) || (dca == 0);
	return !((has_neg && has_pos) || has_zer);
}
