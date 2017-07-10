/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 17:18:56 by irhett            #+#    #+#             */
/*   Updated: 2017/07/09 20:42:03 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "World.class.hpp"
#include "Entity.class.hpp"
#include "Enemy.class.hpp"

Enemy::Enemy(void) :
	Entity('e', 0, 0, SOUTH, '8', true), // ?
	_moveStep(0),
	_moveMax(10)
{
	int		randomNumber;

	randomNumber = 4; // fix this to be truly random
	this->_x = randomNumber;

	//std::cout << "Enemy Default Constructor" << std::endl;
	return;
}

Enemy::Enemy(char symbol) : 
	Entity('e', 0, 0, SOUTH, symbol, true),
	_moveStep(0),
	_moveMax(10)
{
	int		random;

	random = 69;
	this->_x = random;
	//std::cout << "Enemy Parametric Constructor" << std::endl;
	return;
}

Enemy::Enemy(int x) : 
	Entity('e', x, 0, SOUTH, '8', true),
	_moveStep(0),
	_moveMax(10)
{
	//std::cout << "Enemy Parametric Constructor 2" << std::endl;
	return;
}

Enemy::Enemy(int x, char symbol) : 
	Entity('e', x, 0, SOUTH, symbol, true),
	_moveStep(0),
	_moveMax(10)
{
	//std::cout << "Enemy Parametric Constructor 3" << std::endl;
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
