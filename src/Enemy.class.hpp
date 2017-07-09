#ifndef ENEMY_CLASS_HPP
# define ENEMY_CLASS_HPP

# include <iostream>
# include <string>

# include "Entity.class.hpp"
# include "World.cass.hpp"

class Enemy : public Entity{

public:

	Enemy(void);
	Enemy(char symbol);
	Enemy(int x);
	Enemy(int x, char symbol);
	~Enemy(void);
	Enemy			&operator=(Enemy const &old);

	virtual void	act(World &w);
	virtual char	getSymbol(void) const;

private:
	Enemy(Enemy const & old);

	int		_moveStep; // 0
	int		_moveMax; // 10
	// move every 10 frames or cycles

};

std::ostream	&operator<<(std::ostream &o, Enemy const &c);

#endif
