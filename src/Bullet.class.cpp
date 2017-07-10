/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 13:59:48 by irhett            #+#    #+#             */
/*   Updated: 2017/07/09 18:59:49 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Entity.class.hpp"
#include "Bullet.class.hpp"
#include "World.class.hpp"

Bullet::Bullet(int direction, int x, int y) : 
		type('b'),
		_alive(true),
		_x(x),
		_y(y),
		_direction(direction),
		_symbol('b')
{
	//std::cout << "Bullet Parametric Constructor" << std::endl;
	return;
}

void				Bullet::act(World &w)
{
	Entity	*e;

	if (this->_alive)
	{
		switch (this->_direction) {
			case NORTH:
				e = this->getUp(w);
				if (e)
					collision(*this, *e);
				else
					this->moveUp(w);
				break;
			case SOUTH:
				e = this->getDown(w);
				if (e)
					collision(*this, *e);
				else
					this->moveDown(w);
				break;
			case EAST:
				e = this->getRight(w);
				if (e)
					collision(*this, *e);
				else
					this->moveRight(w);
				break;
			case WEST:
				e = this->getLeft(w);
				if (e)
					collision(*this, *e);
				else
					this->moveLeft(w);
				break;
			default:
				std::cout << "Bullet " << this->_symbol << " is confused!";
				break;
		}
	}
}

char			Bullet::getSymbol(void) const
{
	if (!this->_alive)
		return (' ');
	if (this->_direction == NORTH || this->_direction == SOUTH)
		return ('|');
	return ('-');
}

// NOT MESSED WITH YET

Bullet::~Bullet(void) {
	std::cout << "Bullet Destructor" << std::endl;
	return;
}

Bullet::Bullet(void) :
	type('b'),
	_alive(false),
	_x(-1),
	_y(0),
	_direction(NORTH),
	_symbol('b')
{
	std::cout << "ERROR BULLET" << std::endl;
	return;
}

std::ostream	&operator<<(std::ostream &o, Bullet const &c)
{
	o << "To String Function of Bullet";
	(void)c;
	return (o);
}
