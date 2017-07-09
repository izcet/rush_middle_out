/*=============================================================================
 * Project: Rush00 - Middle Out
 *
 * Program: Create a game with n-cursus
 *
 * Author: Sesl, Irhett, Tiny, Bemillie, Searsie
 * ==========================================================================*/
#ifndef ENEMY_CLASS_HPP
# define ENEMY_CLASS_HPP

# include "GameEntity.class.hpp"
# include <iostream>
# include <string>

class Enemy : public AGameEntity{

public:

	Enemy(void);
  	Enemy(int x, int y);
	Enemy(Enemy const & old);
	~Enemy(void); // to be updated

	Enemy &operator=(Enemy const &old);

  bool  move(void);
  bool checkCollisionObject(char c);
  bool checkCollision(void);
  void _initValue(void);
  void doAction(void);
  int getPosX(void) const;
  int getPosY(void) const;
  
  
  
  
private:
  std::string name;

};

// std::ostream	&operator<<(std::ostream &o, Enemy const &c);

#endif

