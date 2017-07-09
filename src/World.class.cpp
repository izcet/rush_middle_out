/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   World.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dubious </var/mail/dubious>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 00:03:40 by dubious           #+#    #+#             */
/*   Updated: 2017/07/09 15:36:01 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "World.class.hpp"

World::World(void) : _width(0), _height(0) {
	std::cout << "DO NOT CALL ME" << std::endl;
	return;
}

World::World(int height, int width) : _height(height), _width(width) {
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
	this->payer = new Player();

	

	// generate 2d array from width and height;
	// generate empty list of bullets;
	// generate emptyu list of enemies;
	// spawn the player and put them at the bottom center of the map

	std::cout << "World Parametric Constructor" << std::endl;
	return;
}

World::World(World const &old) {
	std::cout << "SUCK A DICK GRANDPA" << std::endl;
	*this = old;
	return;
}

World::~World(void) {
	// flesh out later. clean up all the classes
	std::cout << "World Destructor" << std::endl;
	return;
}

World			&World::operator=(World const &old)
{
	std::cout << "DON'T EVEN THINK ABOUT IT" << std::endl;
	if (this != &old)
		this->_privateFoo = old.getFoo();
	return *this;
}

void			World::addEnemy(void)
{
	int		x;

	//x = some randome value;
	this->addEnemy(x);
}

void			World::addEnemy(int x)
{
	Enemy	*e = new Enemy(); // fix this
	// add it to the list
	// add it to the grid
}

void			World::addBullet(Bullet &b)
{


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
	// take inputs and set this->key here
	this->_Player.act(this);
	this->_act(this->_Enemies);
	ret = this->_cleanup();
	return (ret);
}

void			World::_act(List *ent)
{
	List	*temp;

	temp = ent;
	while (!temp.isEmpty())
	{
		ent.getEnt().act();
		temp = temp.next;
	}
}

void			World::_playerInput(void) // probably going to take args
{
	if (keys fuck shit shuffle move)
	{
		player. move the fuck around()
	}
	if (keys fire lasers shit)
		player.shootgunsdodamage;

	if (player.crashed into shit)
	{
		player.loseLife();
		if (player.lives == 0)
			return (false);
	}
	return (true);
}

bool			World::_cleanup(void)
{
	//loop through bullets and delete any that ! this->_isAlive;
	// loop through enemies and do the same shit
	// it's a linked list so it shouldn't be too hard, just listdel
	// then delete the entity that is contained. or delete the entity first.
	// but also, from that entity, delete the pointer in world->grid[ent_y][ent_x]
	return (true); // actually return if the player is still alive or not
}	

std::ostream	&operator<<(std::ostream &o, World const &c)
{
	o << "To String Function of World: "; // MAYBE FLESH THIS OUT
	return (o);
}
