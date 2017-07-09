/*=============================================================================
 * Project: Rush00 - Middle Out
 *
 * Program: Create a game with n-cursus
 *
 * Author: Sesl, Irhett, Tiny, Bemillie, Searsie
 * ==========================================================================*/

#ifndef MISSILE_HPP
# define MISSILE_HPP

class Missile {
public:
	void instantiate(void);
	bool move(void);

	//operator overloads
	Missile & operator=(Missile const & rhs); //Canonical

	Missile(int startX, int startY); //Canonical
	Missile(Missile const & src); //canonical
	Missile(void); //Canonical
	~Missile(void); //Canonical
private:
	void _initValue(void);
};

#endif