/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 15:30:55 by irhett            #+#    #+#             */
/*   Updated: 2017/07/09 21:44:31 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "World.class.hpp"
#include "List.class.hpp"
#include "Player.class.hpp"
#include "Entity.class.hpp"
#include "Enemy.class.hpp"
#include "Bullet.class.hpp"
#include <ncurses.h>
#include <unistd.h>
int main(void)
{
	int		x;
	int		y;
	int		sym;

	initscr();
	timeout(20);
	getmaxyx(stdscr, y, x);
	keypad(stdscr, TRUE);
	World	w(y, x); // update to take window size parameters

	bool	going;
	int		count;

	going = true;
	srand(time(NULL));
	count = 0;
	while (going)
	{
		// window.drawStars;
		w.key = getch();
		w.doCycle();
		clear();
		count++;
		if (count >= 10)
		{
			w.addEnemy();
			count = 0;
		}
		y = 0;
		while (y < w.getHeight())
		{
			x = 0;
			while (x < w.getWidth())
			{
				if (w.grid[y][x])
				{
					sym = w.grid[y][x]->getSymbol();
					mvaddch(y, x, sym);
					;
				}
				else
				{

				}
				x++;
			}
			y++;
		}
		// call sleep
		refresh();
		going = w._cleanup();
		// window.clear;
	}
	// game over;
	endwin();
	return (0);
}
