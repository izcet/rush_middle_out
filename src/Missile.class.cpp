/*=============================================================================
 * Project: Rush00 - Middle Out
 *
 * Program: Create a game with n-cursus
 *
 * Author: Sesl, Irhett, Tiny, Bemillie, Searsie
 * ==========================================================================*/

#include "Missile.class.hpp"
#include "Game.hpp"
#include "Player.class.hpp"

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
  if (this == &old)
    return(*this);
  else
    {
      this->_posX = old._posX;
      this->_posY = old._posY;
      this->_symbol = old._symbol;
    }
  return(*this);
}

// METHODS //

// void Missile::shoot(std::string gun)
// {
// 	std::cout << "Shooting with " << gun << std::endl;
// 	if (gun == "single_shot")
// 		this->_symbol = '|';
// 	//Missile::_instantiate(this->_posX + 1, this->_posY + 1);
// }

bool Missile::move(void)
{
	if (this->_posY - 1 == 0)
	{
		
		this->_lives--;
		return (false);
	}
	else
	  this->_posY -= 1;
	return (true);
}

bool Missile::takeAction(void)
{
  bool hit = false;
  hit = this->move();
  return(hit);
}

void Missile::drawMissile(WINDOW *wind) const
{
  mvwaddch(wind, this->_posY, this->_posX, this->_symbol);
}


// INIT //

void Missile::_initValue(void)
{
	this->_name = "Missile";
	this->_posX = Game::maxX / 2;
	this->_posY = Game::maxY;
	this->_speed = 1;
	this->_symbol = '|';
	this->_lives = 1;
}
