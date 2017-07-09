/*=============================================================================
 * Project: Rush00 - Middle Out
 *
 * Program: Create a game with n-cursus
 *
 * Author: Sesl, Irhett, Tiny, Bemillie, Searsie
 * ==========================================================================*/

#include <iostream>
#include <string>
#include <ncurses.h>
#include "Player.class.hpp"
#include "Game.hpp"

// METHODS //

void Player::shoot(std::string gun)
{
	std::cout << "Shooting with " << gun << std::endl;
	//Missile::_instantiate(this->_posX + 1, this->_posY + 1);
}

bool Player::move(int x, int y)
{
	std::cout << "Moving to " << x << ", " << y << std::endl;
	if (KEY_UP)
		this->_posX = this->_posX + 1;
	if (KEY_DOWN)
		this->_posX = this->_posX -1;
	if (KEY_LEFT)
		this->_posY = this->_posY + 1;
	if (KEY_RIGHT)
		this->_posY = this->_posY - 1;
	return (true);
}

// OPERATOR OVERLOADS //

Player & Player::operator=(Player const & rhs)
{
	this->_posX = rhs._posX;
	this->_posY = rhs._posY;
	this->_dirX = rhs._dirX;
	this->_dirY = rhs._dirY;
	this->_speed = rhs._speed;
	this->_symbol = rhs._symbol;
	this->_isAlive = rhs._isAlive;
	this->_name = rhs._name;
	return *this;
}

// CONSTRUCTORS //

Player::Player(std::string name)
{
	std::srand(std::time(NULL));
	this->_initValue();
	this->_name = name;
	if (Game::debug)
	{
		std::cout << "Player " << this->_name
			<< " has been created!" << std::endl;
	}
}

Player::Player(Player const & src)
{
	std::srand(std::time(NULL));
	*this = src;
	if (Game::debug)
	{
		std::cout << "Player " << this->_name
			<< " has been created!" << std::endl;
	}
	return;
}

Player::Player(void)
{
	std::srand(std::time(NULL));
	this->_initValue();
	//std::cout << "Player has been created!" << std::endl;
	mvwprintw(stdscr, Game::maxX / 2, Game::maxY / 2, "Player has been created!");
}

// DECONSTRUCTORS //

Player::~Player(void)
{
	mvwprintw(stdscr, Game::maxX / 2, Game::maxY / 2, "Player has been destroyed!");
	return;
}

// INIT //

void Player::_initValue(void)
{
	this->_name = "PlayerOne";
	this->_posX = 0;
	this->_posY = 0;
	this->_dirX = 1;
	this->_dirY = 1;
	this->_speed = 1;
	this->_symbol = '@';
	this->_lives = 3;

}