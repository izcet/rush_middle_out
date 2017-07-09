/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 14:51:30 by irhett            #+#    #+#             */
/*   Updated: 2017/07/09 15:29:40 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Player.class.hpp"
#include "World.class.hpp"
#include "Entity.class.hpp"

Player::Player(int x, int y) : 
	type('p'),
	_alive(true),
	_x(x),
	_y(y),
	_direction(NORTH),
	_symbol('^'),
	_moveStep(0),
	_moveMax(5)
{
	int		random;

	random = 69;
	this->_x = random;
	//std::cout << "Player Parametric Constructor" << std::endl;
	return;
}

virtual void	Player::act(World &w)
{
	Entity	*e;

	if (this->_alive)
	{
		switch (w.key)
		{
			case KEY_UP:
				this->_direction = NORTH;
				this->_move(w);
				break;
			case KEY_DOWN:
				this->_direction = SOUTH;
				this->_move(w);
				break;
			case KEY_LEFT:
				this->_direction = WEST;
				this->_move(w);
				break;
			case KEY_RIGHT:
				this->_direciton = EAST;
				this->_move(w);
				break;
			case KEY_SHOOT:
				this->_shoot(w);
				break;
			default:
				break;
		}
		if (this->_moveStep < this->_moveMax)
			this->_moveStep++;
	}
}

void			Player::_move(World &w)
{
	if (this->_moveStep >= this->_moveMax)
	{
		switch (this->_direction) {
			case NORTH:
				e = this->getUp(w);
				if (e)
					collision(this, e);
				else
					this->moveUp(w);
				break;
			case SOUTH:
				e = this->getDown(w);
				if (e)
					collision(this, e);
				else
					this->moveDown(w);
				break;
			case EAST:
				e = this->getRight(w);
				if (e)
					collision(this, e);
				else
					this->moveRight(w);
				break;
			case WEST:
				e = this->getLeft(w);
				if (e)
					collision(this, e);
				else
					this->moveLeft(w);
				break;
			default:
				break;
		}
		this->_moveStep = 0;
	}
}

void			Player::_shoot(World &w)
{
	Bullet	*b;
	switch(this->_direction)
	{
		case NORTH:
			b = new Bullet(this->_direction, this->_x, this->_y - 1);
			w.addBullet(*b);
			break;
		case SOUTH:
			b = new Bullet(this->_direction, this->_x, this->_y + 1);
			w.addBullet(*b);
			break;
		case EAST:
			b = new Bullet(this->_direction, this->_x + 1, this->_y);
			w.addBullet(*b);
			break;
		case WEST:
			b = new Bullet(this->_direction, this->_x - 1, this->_y);
			w.addBullet(*b);
			break;
	}
}


virtual char	getSymbol(void) const
{
	if (this->_alive)
		return (this->_symbol);
	return ('$');
}

// NOT MESSED WITH YET

Player::~Player(void) {
	std::cout << "Player Destructor" << std::endl;
	return;
}

Player				&Player::operator=(Player const &old)
{
	std::cout << "Player Assignment Operator" << std::endl;
	if (this != &old)
		this->_privateFoo = old.getFoo();
	return *this;
}

std::ostream	&operator<<(std::ostream &o, Player const &c)
{
	o << "To String Function of Player: " << c.getFoo();
	return (o);
}
