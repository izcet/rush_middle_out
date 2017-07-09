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
#include "Environment.hpp"
#include "GameEntity.class.hpp"
#include "Player.class.hpp"
#include "Enemy.class.hpp"

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
  initscr();
  cbreak();
  noecho();
  curs_set(0);
  keypad(stdscr, TRUE);
  getmaxyx(stdscr, maxY, maxX);
  printw("window size id %d tall and %d wide", maxY, maxX);
  play();
  endwin();
}

void Game::play() {
  Environment map;
  int ch = 0;
  timeout(300);
  border(0,0,0,0,0,0,0,0);
  Player playerOne(maxX / 2, maxY - 10);
  playerWin = newwin(0, 0, 0, 0);
  Enemy enemy1(maxX / 2, maxY / 2);
  Enemy enemy2(0, 0);
  enemyWin = newwin(0, 0, 0, 0);
  while ((ch = getch()) != 'q') {
    map.starsRnd();
    playerOne.move(ch);
    // every X cycles, spawn a new enemy at a random position on the spawn wall.
    // this.spawnEnemies();

    // // This Game will have an array of bullets.
    // // This function just needs to loop through the array and move each
    // bullet once,
    // // check for collisions and change is_alive as needed
    // this.bulletsAct();

    // // Do what for and mean to be. Fire lasers, do some damage! Move the
    // player!
    // this.playerAct(ch);

    // // Loop through the array of Enemies and have them move, shoot, etc.
    // this.enemiesAct();

    // this.doStarStuff();

    // this.drawEverything();

    // // every X cycles, spawn a new enemy at a random position on the spawn
    // wall.
    // this.spawnEnemies();

    // // loop through all enemies, bullets, and players, and remove all
    // entities with
    // // is_alive == false;
    // this.cleanup();

    
    
      if (playerOne.getPosX() == enemy1.getPosY() &&
            playerOne.getPosX() == enemy1.getPosY())
      {
        //delete enemyHorde[i];
        playerOne.takeDamage();
      }
      wclear(enemyWin);
      enemy1.doAction(enemyWin);
      overlay(enemyWin, stdscr);
      wclear(playerWin);
      playerOne.drawPlayer(playerWin);
      overlay(playerWin, stdscr);      
    refresh();
    ch = 0;
  }
  //delete  enemy1;
}
/*
GameEntity		*Game::getEntityAt(int x, int y)
{
                return (this->grid[x][y]);
}
*/
