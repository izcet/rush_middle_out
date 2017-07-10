/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 15:30:55 by irhett            #+#    #+#             */
/*   Updated: 2017/07/09 17:43:05 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "World.class.hpp"
#include "List.class.hpp"
#include "Player.class.hpp"
#include "Entity.class.hpp"
#include "Enemy.class.hpp"
#include "Bullet.class.hpp"

int main(void)
{
	World	w(20, 40); // update to take window size parameters

	bool	going;
	int		count;

	count = 0;
	while ((going = w.doCycle()))
	{
		count++;
		if (count >= 10)
		{
			w.addEnemy(5);
			count = 0;
		}
		// window.clear;
		// window.drawStars;
		// window.drawEntities;
	}
	// game over;
	return (0);
}
