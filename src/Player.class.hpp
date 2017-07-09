/*=============================================================================
 * Project: Rush00 - Middle Out
 *
 * Program: Create a game with n-cursus
 *
 * Author: Sesl, Irhett, Tiny, Bemillie, Searsie
 * ==========================================================================*/

#ifndef PLAYER_HPP
# define PLAYER_HPP

#include "GameEntity.class.hpp"
#include "Game.hpp"

class Player : public AGameEntity
{
public:
	//methods
	void shoot(std::string gun);
	bool move(int key);
	bool checkCollisionObject(char c);
	bool checkCollision(int x, int y);
	void draw(void) const;

	//operator overloads
	Player & operator=(Player const & rhs); //Canonical

	Player(int startX, int startY); //Canonical
	Player(Player const & src); //canonical
	Player(void); //Canonical
	~Player(void); //Canonical

private:
	void _initValue(void);
};

#endif
