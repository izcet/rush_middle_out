/*=============================================================================
 * Project: Rush00 - Middle Out
 *
 * Program: Create a game with n-cursus
 *
 * Author: Sesl, Irhett, Tiny, Bemillie, Searsie
 * ==========================================================================*/
#include <iostream>
#include <string>
#include "Enemy.class.hpp"
#include "Player.class.hpp"
#include "Game.hpp"

Enemy::Enemy(void) {
	this->_initValue();
	std::cout << "Enemy Default Constructor" << std::endl;
	return;
}

Enemy::Enemy(int x, int y) {
	this->_initValue();
	this->_posX = x;
	this->_posY = y;
	std::cout << "Enemy Parametric Constructor" << std::endl;
	return;
}

Enemy::Enemy(Enemy const &old) {
	std::srand(std::time(NULL));
	*this = old;
	std::cout << "Enemy " << this->_name
		<< " has been created!" << std::endl;
	return;
}

Enemy::~Enemy(void) {
	std::cout << "Enemy Destructor" << std::endl;
	return;
}

// void			Enemy::sampleFunction(void) const
// {
// 	std::cout << "Enemy Sample Function" << std::endl
// }

Enemy				&Enemy::operator=(Enemy const &old)
{
	std::cout << "Enemy Assignment Operator" << std::endl;
	if (this == &old)
	  return(*this);
	return(*this);
	// 	this->_privateF = old.getFoo();
	// return *this;
}

// std::ostream	&operator<<(std::ostream &o, Enemy const &c)
// {
// 	o << "To String Function of Enemy: " << c.getFoo();
// 	return (o);
// }

// METHODS //

// void Enemy::shoot(std::string gun)
// {
// 	std::cout << "Shooting with " << gun << std::endl;
// 	//Missile::_instantiate(this->_posX + 1, this->_posY + 1);
// }


bool Enemy::move(void)
{
	if (this->_posX + this->_dirX == Game::maxX || this->_posX + this->_dirX == 0)
	{
		this->_dirX *= -1;
		this->_dirY = 1;
	}
	else
	  this->_dirY = 0;
	this->_posX +=  this->_dirX;
	this->_posY +=  this->_dirY;
	return (true);
}

bool Enemy::checkCollisionObject(char c)
{
  if (c == '&' || c == '|') //change second to Bullet::_symbol
	{
		this->_lives--;
		std::cout << "Enemy hit!" << std::endl;
		return true;
	}
	return false;
}

void Enemy::doAction(void)
{
  bool hit = false;
  this->move();
  hit = this->checkCollision();
  if (hit)
    wprintw(enemyWin, "%c", this->_symbol);
  
}

bool Enemy::checkCollision(void)
{
	char c;
	bool hit = false;

	mvwscanw(stdscr, this->_posY, this->_posX, "%c", c);
	hit = this->checkCollisionObject(c);
	return (hit);
}

//INIT

void Enemy::_initValue(void)
{
	this->_name = "Enemy";
	this->_posX = 0;
	this->_posY = 0;
	this->_dirX = 1;
	this->_dirY = 0;
	this->_speed = 1;
	this->_symbol = 'X';
	this->_lives = 1;

}
