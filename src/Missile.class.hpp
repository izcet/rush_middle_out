/*=============================================================================
 * Project: Rush00 - Middle Out
 *
 * Program: Create a game with n-cursus
 *
 * Author: Sesl, Irhett, Tiny, Bemillie, Searsie
 * ==========================================================================*/

#ifndef MISSILE_HPP
# define MISSILE_HPP
# include "GameEntity.class.hpp"
# include "Game.hpp"

class Missile : public AGameEntity{
public:
	void instantiate(void);
	bool move(void);

	//operator overloads
	Missile & operator=(Missile const & rhs); //Canonical

	Missile(int startX, int startY); //Canonical
	Missile(Missile const & src); //canonical
	Missile(void); //Canonical
	~Missile(void); //Canonical
    bool takeAction(void);
  void drawMissile(WINDOW *wind) const;
  void getHit(void);
    void setIsAlive(bool shot);
  void setPos(int x, int y);
private:
	void _initValue(void);
};

#endif
