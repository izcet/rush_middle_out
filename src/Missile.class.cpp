/*=============================================================================
 * Project: Rush00 - Middle Out
 *
 * Program: Create a game with n-cursus
 *
 * Author: Sesl, Irhett, Tiny, Bemillie, Searsie
 * ==========================================================================*/

#include "Missile.class.hpp"
#include "Game.hpp"

// CONSTRUCTORS //

Missile::Missile(void) {
	this->_initValue();
	return;
}

Missile::Missile(int x, int y) {
	this->_initValue();
	this->_posX = x;
	this->_posY = y;
	return;
}

Missile::Missile(Missile const &old) {
	std::srand(std::time(NULL));
	*this = old;
	return;
}

Missile::~Missile(void) {
	return;
}

// OPERATOR OVERLOAD //

Missile	&Missile::operator=(Missile const &old)
{
	return(*this);
}

// METHODS //

void Missile::shoot(std::string gun)
{
	std::cout << "Shooting with " << gun << std::endl;
	if (gun == "single_shot")
		this->symbol = '|';
	//Missile::_instantiate(this->_posX + 1, this->_posY + 1);
}

bool Missile::move(int key)
{
	if (this->_posX == Game::maxX)
	{
		return (false);
		this->_live--;
	}
	else
	  this->_posX += _speed;
	return (true);
}

// INIT //

void Enemy::_initValue(void)
{
	this->_name = "Missile";
	this->_posX = Player::_posX;
	this->_posY = Player::_posY;
	this->_speed = 1;
	this->_symbol = '|';
	this->_lives = 1;
}

