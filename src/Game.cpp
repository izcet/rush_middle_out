#include "Game.hpp"
#include <ncurses.h>

int Game::score = 0;
int Game::maxX = 0;
int Game::maxY = 0;
bool Game::debug = false;

Game::Game()
{
};

Game::Game(const Game &other)
{
		*this = other;
};

Game::~Game()
{
};

Game& Game::operator=(const Game &rhs)
{
		// Check for self-assignment!
		if (this == &rhs)
				return *this;

		return *this;
}

void Game::launch()
{
		initscr();
		cbreak();
		noecho();
		keypad(stdscr, TRUE);
		getmaxyx(stdscr, maxY, maxX);
		printw("window size id %d tall and %d wide", maxY, maxX);
		play();
		endwin();
};
void Game::play()
{
		int ch = 0;
		timeout(50);
		while ((ch = getch()) != 'q')
		{
			Environment	map;
				// every X cycles, spawn a new enemy at a random position on the spawn wall.
				//this.spawnEnemies();

				// // This Game will have an array of bullets.
				// // This function just needs to loop through the array and move each bullet once,
				// // check for collisions and change is_alive as needed
				// this.bulletsAct();

				// // Do what for and mean to be. Fire lasers, do some damage! Move the player!
				// this.playerAct(ch);

				// // Loop through the array of Enemies and have them move, shoot, etc.
				// this.enemiesAct();

				//this.doStarStuff();

				//this.drawEverything();
				
				// // every X cycles, spawn a new enemy at a random position on the spawn wall.
				// this.spawnEnemies();

				// // loop through all enemies, bullets, and players, and remove all entities with
				// // is_alive == false;
				// this.cleanup();





				if (ch == 'D')
						debug = true;
				if (ch != ERR)
						addch(ch);
				refresh();
				ch = 0;
		}
};

