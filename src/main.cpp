/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 15:30:55 by irhett            #+#    #+#             */
/*   Updated: 2017/07/09 21:08:32 by irhett           ###   ########.fr       */
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
	timeout(30);
	getmaxyx(stdscr, y, x);
	keypad(stdscr, TRUE);
	World	w(y, x); // update to take window size parameters

	bool	going;
	int		count;

	count = 0;
	while ((going = w.doCycle()))
	{
		w.key = getch();
		clear();
		count++;
		if (count >= 175)
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
		refresh();
	//	std::cout << "one cycle done" << std::endl;
		// window.clear;
		// window.drawStars;
		// window.drawEntities;
	}
	// game over;
	endwin();
	return (0);
}
