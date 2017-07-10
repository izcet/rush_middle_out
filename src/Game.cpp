/*=============================================================================
 * Project: Rush00 - Middle Out
 *
 * Program: Create a game with n-cursus
 *
 * Author: Sesl, Irhett, Tiny, Bemillie, Searsie
 * ==========================================================================*/

#include "Game.hpp"
#include <ncurses.h>
//#include "Enemy.class.hpp"
#include "Enemy.class.hpp"
#include "Environment.hpp"
#include "GameEntity.class.hpp"
#include "Missile.class.hpp"
#include "Player.class.hpp"

int Game::score = 0;
int Game::maxX = 0;
int Game::maxY = 0;
bool Game::debug = false;
WINDOW *Game::enemyWin = NULL;
WINDOW *Game::playerWin = NULL;

Game::Game() {}

Game::Game(const Game &other) { *this = other; }

Game::~Game() {}

Game &Game::operator=(const Game &rhs) {
  // Check for self-assignment!
  if (this == &rhs) return *this;

  return *this;
}

void Game::launch() {
  cbreak();
  noecho();
  curs_set(0);
  keypad(stdscr, TRUE);
  getmaxyx(stdscr, maxY, maxX);
  printw("window size id %d tall and %d wide", maxY, maxX);
  play();
}

void Game::play() {
  Environment map;
  int ch = 0;
  keypad(map.getWin(), TRUE);
  nodelay(map.getWin(), TRUE);
  timeout(300);
  border(0, 0, 0, 0, 0, 0, 0, 0);
  Player playerOne(maxX / 2, maxY - 10);
  playerWin = newwin(0, 0, 0, 0);
  Enemy enemy1(maxX / 2, maxY / 2);
  Enemy massEnemy[10];
  enemyWin = newwin(0, 0, 0, 0);
  while ((ch = getch()) != 'q') {
    map.starsRnd();
    playerOne.move(ch);
    if (ch == 32) {
      printw("Shoot missile!");
      // Missile bullet(playerOne.getPosY(), playerOne.getPosX());
    }
    wclear(map.getWin());
    for (int i = 0; i < 10; i++) {
      if (playerOne.getPosX() == massEnemy[i].getPosX() &&
          playerOne.getPosY() == massEnemy[i].getPosY()) {
        printw("Missile hit target!");
        ;
      }
    }
    if (playerOne.getPosX() == enemy1.getPosX() &&
        playerOne.getPosY() == enemy1.getPosY()) {
      playerOne.takeDamage();
    }

    enemy1.doAction(enemyWin);

    for (int i = 0; i < 10; i++) {
      massEnemy[i].doAction(enemyWin);
    }

    overlay(enemyWin, stdscr);
    wclear(playerWin);

    playerOne.drawPlayer(playerWin);
    overlay(playerWin, stdscr);
    refresh();
    ch = 0;
  }
  // delete  enemy1;
}
/*
GameEntity		*Game::getEntityAt(int x, int y)
{
                return (this->grid[x][y]);
}
*/
