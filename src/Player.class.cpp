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

bool Player::move(int key)
{
  int prevX = this->_posX;
  int prevy = this->_posY;

	if (key == KEY_UP && this->_posY - 1 > 0)
		this->_posY = this->_posY - 1;
	if (key == KEY_DOWN && this->_posY + 1 < Game::maxY)
		this->_posY = this->_posY +1;
	if (key == KEY_LEFT && this->_posX - 1 > 0)
		this->_posX = this->_posX - 1;
	if (key == KEY_RIGHT && this->_posX + 1 < Game::maxX)
		this->_posY = this->_posX + 1;
	if (checkCollision(this->_posX, this->_posY))
	  return(false);
	if (prevX == this->_posX && prevy == this->_posY)
	  {
	    if (checkCollision(this->_posX, this->_posY - 1))
	      return (false);
	  }
	return (true);
}

bool Player::checkCollisionObject(char c)
{
	if (c == 'X')
	{
		this->_lives--;
		std::cout << "Player hit!" << std::endl;
		return true;
	}
	return false;
}

//Params same x and y as movement

bool Player::checkCollision(int x, int y)
{
	bool hit = false;
	char d;

	d = 'S';
	mvwscanw(Game::playerWin, y, x, "%c", d);
	hit = checkCollisionObject(d);
	return (hit);
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

Player::Player(int startX, int startY)
{
	this->_initValue();
	this->_posX = startX;
	this->_posY = startY;
	if (Game::debug)
	{
		std::cout << "Player " << this->_name
			<< " has been created!" << std::endl;
	}
}

Player::Player(Player const & src)
{
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
	this->_initValue();
	//std::cout << "Player has been created!" << std::endl;
	mvwprintw(Game::playerWin, Game::maxX / 2, Game::maxY / 2, "Player has been created!");
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

int Player::getPosX(void) const
{
  return (this->_posX);
}


int Player::getPosY(void) const
{
  return (this->_posY);
}

void Player::takeDamage(void)
{
  this->_lives--;
}


