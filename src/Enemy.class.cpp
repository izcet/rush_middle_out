#include <iostream>
#include <string>
#include "Enemy.class.hpp"
#include "World.class.hpp"
#include "Entity.class.hpp"

Enemy::Enemy(void) :
	_type('e'),
	_alive(true),
	_y(0),
	_direction(SOUTH),
	_symbol('8'),
	_moveStep(0),
	_moveMax(10)
{
	int		randomNumber;

	randomNumber = 4; // fix this to be truly random
	this->_x = randomNumber;

	//std::cout << "Enemy Default Constructor" << std::endl;
	return;
}

Enemy::Enemy(char symbol) : 
	type('e'),
	_alive(true),
	_y(0),
	_direction(SOUTH),
	_symbol(symbol);
_moveStep(0),
	_moveMax(10)
{
	int		random;

	random = 69;
	this->_x = random;
	//std::cout << "Enemy Parametric Constructor" << std::endl;
	return;
}

Enemy::Enemy(int x) : 
	type('e'),
	_alive(true),
	_x(x)
	_y(0),
	_direction(SOUTH),
	_symbol('8')
	_moveStep(0),
	_moveMax(10)
{
	//std::cout << "Enemy Parametric Constructor 2" << std::endl;
	return;
}

Enemy::Enemy(int x, char symbol) : 
	type(e),	
	_alive(true),
	_x(x)
	_y(0),
	_direction(SOUTH),
	_symbol(symbol);
{
	//std::cout << "Enemy Parametric Constructor 3" << std::endl;
	return;
}

virtual void	Enemy::act(World &w)
{
	Entity	*e;

	if (this->_alive)
	{
		if (this->_moveStep >= this->_moveMax)
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
					std::cout << "Enemy " << this->_sybmol << " is confused!";
					break;

			}
			this->_moveStep = 0;
		}
		this->_moveStep++;

		// we could put some other behaviors here
		// like changing direction or sucking dick
		// the world is truly our oyster
	}
}

virtual char	getSymbol(void) const
{
	if (this->_alive)
		return (this->_symbol);
	return ('$');
}

// NOT MESSED WITH YET

Enemy::~Enemy(void) {
	std::cout << "Enemy Destructor" << std::endl;
	return;
}

Enemy				&Enemy::operator=(Enemy const &old)
{
	std::cout << "Enemy Assignment Operator" << std::endl;
	if (this != &old)
		this->_privateFoo = old.getFoo();
	return *this;
}

std::ostream	&operator<<(std::ostream &o, Enemy const &c)
{
	o << "To String Function of Enemy: " << c.getFoo();
	return (o);
}
