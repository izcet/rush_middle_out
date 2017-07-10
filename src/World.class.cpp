/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   World.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dubious </var/mail/dubious>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 00:03:40 by dubious           #+#    #+#             */
/*   Updated: 2017/07/09 17:22:59 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "World.class.hpp"

World::World(int height, int width) :
	_height(height),
	_width(width)
{
	int		x;
	int		y;

	this->grid = new Entity*[height][width];
	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < height)
			this->grid[y][x++] = nullptr;
		y++;
	}
	this->_Player = new Player(width / 2, height / 2);
	this->grid[this->_Player.getY()][this->_Player.getX()] = this->_Player;
	this->_Bullets = new List();
	this->_Enemies = new List();
	return;
}

World::~World(void) {
	this->_deleteList(this->_Bullets);
	this->_deleteList(this->_Enemies);
	delete this->_Player;
	delete this->grid;
	std::cout << "World Destructor" << std::endl;
	return;
}

void			World::addEnemy(void)
{
	int		x;

	//x = some randome value;
	this->addEnemy(x);
}

void			World::addEnemy(int x)
{
	Enemy	*e;

	if (this->grid[0][x])
		return;
	e = new Enemy(x);
	this->grid[e->getY()][e->getX] = e;
	this->_Enemies = this->_addList(this->_Enemies, e);
}

void			World::addBullet(Bullet &b)
{
	this->grid[b->getY()][b->getX] = b;
	this->_Bullets = this->_addList(this->_Bullets, b);
}

int				World::getWidth(void) const
{
	return (this->_width);
}

int				World::getHeight(void) const
{
	return (this->_height);
}

bool			World::doCycle(void) // maybe this is going to take inputs
{
	bool	ret;

	this->_act(this->_Bullets);
	this->_takeInput(); ///////////////???
	this->_Player.act(this);
	this->_act(this->_Enemies);
	ret = this->_cleanup();
	return (ret);
}

void			World::_act(List *ent)
{
	if (!temp.isEmpty())
	{
		this->_act(ent->next);
		ent.getEnt().act();
	}
}

void			World::_takeInput(void) // probably going to take args
{
	// brett,
	// brett i...
	// i need you.
}

bool			World::_cleanup(void)
{
	this->_Bullets = this->_clean(this->_Bullets);
	this->_Enemies = this->_clean(this->_Enemies);
	return (this->_Player.isAlive());
}	

List			*World::_clean(List *ent)
{
	List	*next;

	if (ent->isEmpty())
		return (ent);
	if (ent->getEnt().isAlive())
	{
		ent->next = this._clean(ent->next);
		return (ent);
	}
	next = ent->next;
	this->grid[ent->getEnt()->getY()][ent->getEnt()->getX()] = nullptr;
	delete ent->getEnt();
	delete ent;
	return (next);
}

void			World::_deleteList(List *ent)
{
	if (!ent->isEmpty())
	{
		this->_deleteList(ent->next());
		delete (ent->getEnt());
	}
	delete (ent);
}

List			*World::_addList(List *li, Entity *ent)
{
	List	*node;

	node = new List(ent);
	node->next = li;
	return (node);
}

///////////////////////////////////////////////////////////////

std::ostream	&operator<<(std::ostream &o, World const &c)
{
	o << "To String Function of World: "; // MAYBE FLESH THIS OUT
	return (o);
}

World::World(World const &old) {
	std::cout << "SUCK A DICK GRANDPA" << std::endl;
	*this = old;
	return;
}

World			&World::operator=(World const &old)
{
	std::cout << "DON'T EVEN THINK ABOUT IT" << std::endl;
	if (this != &old)
		this->_privateFoo = old.getFoo();
	return *this;
}

World::World(void) : _width(0), _height(0) {
	std::cout << "DO NOT CALL ME" << std::endl;
	return;
}
