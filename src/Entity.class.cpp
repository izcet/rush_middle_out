/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dubious </var/mail/dubious>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 20:04:52 by dubious           #+#    #+#             */
/*   Updated: 2017/07/09 15:29:18 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Entity.class.hpp"
#include "World.class.hpp"

Entity			&Entity::operator=(Entity const &old)
{
	// I hope this works the way I think it does
	this = old;
	return *this;
}

// by default an entity will do nothing every turn
virtual void	Entity::act(World &w)
{
	(void)w;
}

virtual char	Entity::getSymbol(void) const
{
	return (this->_symbol);
}

bool			Entity::isAlive(void) const
{
	return (this->_alive);
}

int				Entity::getX(void) const
{
	return (this->_x);
}

int				Entity::getY(void) const
{
	return (this->_y);
}

void			Entity::die(void)
{
	this->_alive = false;
}

void			collision(Entity &a, Entity &b)
{
	a.die();
	b.die();
}

// MOVEMENT HELPERS /////////////////////////////

void			Entity::moveUp(World &w)
{
	if (this->_y > 0)
	{
		this->_y = this->_y - 1;
		w->grid[this->_y][this->_x] = &this;
		w->grid[this->_y + 1][this->_x] = nullptr;
	}
	else
		this->die();
}

void			Entity::moveDown(World &w)
{
	if (this->_y < w.getHeight())
	{
		this->_y = this->_y + 1;
		w->grid[this->_y][this->_x] = &this;
		w->grid[this->_y - 1][this->_x] = nullptr;
	}
	else
		this->die();
}

void			Entity::moveLeft(World &w)
{
	if (this->_x > 0)
	{
		this->_x = this->_x - 1;
		w->grid[this->_y][this->_x] = &this;
		w->grid[this->_y][this->_x + 1] = nullptr;
	}
	else
		this->die();

}

void			Entity::moveUp(World &w)
{
	if (this->_x < w.getWidth())
	{
		this->_x = this->_x + 1;
		w->grid[this->_y][this->_x] = &this;
		w->grid[this->_y][this->_x - 1] = nullptr;
	}
	else
		this->die();

}

// LOCATION COLLISION HELPERS //////////////////////

Entity			*Entity::getLeft(World &w)
{
	return (w->grid[this->_y][this->_x - 1]);
}

Entity			*Entity::getRight(World &w)
{
	return (w->grid[this->_y][this->_x + 1]);
}

Entity			*Entity::getUp(World &w)
{
	return (w->grid[this->_y - 1][this->_x]);
}

Entity			*Entity::getDown(World &w)
{
	return (w->grid[this->_y + 1][this->_x]);
}

// BELOW HERE BE SOME CRAYZ SHIT I DON'T WANT TO DEAL WITH

std::ostream	&operator<<(std::ostream &o, Entity const &c)
{
	o << "ENTITY TOSTREAM";
	return (o);
}

Entity::Entity(void) : _empty(true), _ent(nullptr) {
	std::cout << "Entity Default FUCK" << std::endl;
	return;
}

Entity::Entity(const Entity *ent) : _empty(false) _ent(ent) {
	std::cout << "Entity Parametric FUCK" << std::endl;
	return;
}

Entity::Entity(Entity const &old) {
	std::cout << "Entity Copy FUCK" << std::endl;
	*this = old;
	return;
}

Entity::~Entity(void) {
	std::cout << "Entity Destructor" << std::endl;
	return;
}
