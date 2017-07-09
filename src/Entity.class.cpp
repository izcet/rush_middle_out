/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dubious </var/mail/dubious>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 20:04:52 by dubious           #+#    #+#             */
/*   Updated: 2017/07/09 13:56:47 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Entity.class.hpp"
#include "World.class.hpp"

Entity			&Entity::operator=(Entity const &old)
{
	//std::cout << "Entity Assignment FUCK" << std::endl;
	this = old;
	return *this;
}

virtual void	Entity::act(World &w)
{
	Entity	*e;

	if (this->_alive)
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
				std::cout << "ENTITY " << this->_sybmol << " is confused!";
				break;
		}
	}
}

virtual char	Entity::getSymbol(void) const
{
	return (this->_symbol);
}

bool			Entity::isAlive(void) const
{
	return (this->_alive);
}

void			Entity::die(void)
{
	this->_alive = false;
}

void			collision(Entity &a, Entity &b)
{
	// PROBABLY NOT THE RIGHT SYNTAX, DEBUG LATER
	if (a && b)
	{
		a->die();
		b->die();
	}
}

// MOVEMENT HELPERS /////////////////////////////

void			Entity::moveUp(World &w)
{
	this->_y = this->_y - 1;
	w->grid[this->_y][this->_x] = &this;
	w->grid[this->_y + 1][this->_x] = nullptr;
}

void			Entity::moveDown(World &w)
{
	this->_y = this->_y + 1;
	w->grid[this->_y][this->_x] = &this;
	w->grid[this->_y - 1][this->_x] = nullptr;
}

void			Entity::moveLeft(World &w)
{
	this->_x = this->_x - 1;
	w->grid[this->_y][this->_x] = &this;
	w->grid[this->_y][this->_x + 1] = nullptr;
}

void			Entity::moveUp(World &w)
{
	this->_x = this->_x + 1;
	w->grid[this->_y][this->_x] = &this;
	w->grid[this->_y][this->_x - 1] = nullptr;
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
