/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 17:18:56 by irhett            #+#    #+#             */
/*   Updated: 2017/07/09 21:38:24 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "World.class.hpp"
#include "Entity.class.hpp"
#include "Enemy.class.hpp"

Enemy::Enemy(int wid) :
	Entity('e', 0, 0, SOUTH, '8', true), // ?
	_moveStep(0),
	_moveMax(10)
{
	this->Entity::_x = rand() % wid;
	return;
}

Enemy::Enemy(int wid, char symbol) : 
	Entity('e', -1, 0, SOUTH, symbol, true),
	_moveStep(0),
	_moveMax(10)
{
	this->_x = rand() % wid;
	return;
}

Enemy::Enemy(int wid, int pos) : 
	Entity('e', pos, 0, SOUTH, '8', true),
	_moveStep(0),
	_moveMax(10)
{
	(void)wid;
	return;
}

Enemy::Enemy(int wid, int pos, char symbol) : 
	Entity('e', pos, 0, SOUTH, symbol, true),
	_moveStep(0),
	_moveMax(10)
{
	(void)wid;
	return;
}

void			Enemy::act(World &w)
{
	Entity	*e;

	if (this->Entity::_alive)
	{
		if (this->_moveStep >= this->_moveMax)
		{
			switch (this->Entity::_direction) {
				case NORTH:
					e = this->Entity::getUp(w);
					if (e)
						collision(*this, *e);
					else
						this->Entity::moveUp(w);
					break;
				case SOUTH:
					e = this->Entity::getDown(w);
					if (e)
						collision(*this, *e);
					else
						this->Entity::moveDown(w);
					break;
				case EAST:
					e = this->Entity::getRight(w);
					if (e)
						collision(*this, *e);
					else
						this->Entity::moveRight(w);
					break;
				case WEST:
					e = this->Entity::getLeft(w);
					if (e)
						collision(*this, *e);
					else
						this->Entity::moveLeft(w);
					break;
				default:
					std::cout << "Enemy is confused!";
					break;

			}
			this->_moveStep = 0;
		}
		this->_moveStep++;

		// we could put some other behaviors here
		// like changing direction or sucking dick
		// the world is truly our oyster
	}
}

int					Enemy::getSymbol(void) const
{
	if (this->_alive)
		return (this->_symbol);
	return ('$');
}

// NOT MESSED WITH YET

Enemy::~Enemy(void) {
//	std::cout << "Enemy Destructor" << std::endl;
	return;
}

Enemy				&Enemy::operator=(Enemy const &old)
{
//	std::cout << "Enemy Assignment Operator" << std::endl;
	(void)old;
	return *this;
}

std::ostream	&operator<<(std::ostream &o, Enemy const &c)
{
	(void)c;
	o << "To String Function of Enemy: ";
	return (o);
}
