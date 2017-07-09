#ifndef GAMEENTITY_CLASS_HPP
# define GAMEENTITY_CLASS_HPP
# include <ncurses.h>
# include <string>
# include <iostream>

class AGameEntity
{
public:

  virtual bool move(int x, int y);
  virtual bool getAlive(void) const;
  virtual void drawToWindow(void) const;
    
protected:
  std::string _name;
  int _posX;
  int _posY;
  int _dirX;
  int _dirY;
  int _speed;
  char _symbol;
  int _lives;
  bool _isAlive;
  char pos;

  
};

#endif



