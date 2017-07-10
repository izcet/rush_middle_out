/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dubious </var/mail/dubious>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 20:04:52 by dubious           #+#    #+#             */
/*   Updated: 2017/07/09 17:54:29 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Entity.class.hpp"
#include "World.class.hpp"

// by default an entity will do nothing every turn
void			Entity::act(World &w)
{
	(void)w;
}

char			Entity::getSymbol(void) const
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
		w.grid[this->_y][this->_x] = this;
		w.grid[this->_y + 1][this->_x] = nullptr;
	}
	else
		this->die();
}

void			Entity::moveDown(World &w)
{
	if (this->_y < w.getHeight())
	{
		this->_y = this->_y + 1;
		w.grid[this->_y][this->_x] = this;
		w.grid[this->_y - 1][this->_x] = nullptr;
	}
	else
		this->die();
}

void			Entity::moveLeft(World &w)
{
	if (this->_x > 0)
	{
		this->_x = this->_x - 1;
		w.grid[this->_y][this->_x] = this;
		w.grid[this->_y][this->_x + 1] = nullptr;
	}
	else
		this->die();

}

void			Entity::moveRight(World &w)
{
	if (this->_x < w.getWidth())
	{
		this->_x = this->_x + 1;
		w.grid[this->_y][this->_x] = this;
		w.grid[this->_y][this->_x - 1] = nullptr;
	}
	else
		this->die();

}

// LOCATION COLLISION HELPERS //////////////////////

Entity			*Entity::getLeft(World &w) const
{
	return (w.grid[this->_y][this->_x - 1]);
}

Entity			*Entity::getRight(World &w) const
{
	return (w.grid[this->_y][this->_x + 1]);
}

Entity			*Entity::getUp(World &w) const
{
	return (w.grid[this->_y - 1][this->_x]);
}

Entity			*Entity::getDown(World &w) const
{
	return (w.grid[this->_y + 1][this->_x]);
}

// BELOW HERE BE SOME CRAYZ SHIT I DON'T WANT TO DEAL WITH

std::ostream	&operator<<(std::ostream &o, Entity const &c)
{
	o << "ENTITY TOSTREAM";
	(void)c;
	return (o);
}

Entity::Entity(void) {
	std::cout << "Entity Default FUCK" << std::endl;
	return;
}

Entity::Entity(const Entity *ent) {
	(void)ent;
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

Entity			&Entity::operator=(Entity const &old)
{
	Entity	&e = *(new Entity());
	// I hope this works the way I think it does
	(void)old;
	return e;
}
