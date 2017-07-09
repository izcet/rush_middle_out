/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 15:30:55 by irhett            #+#    #+#             */
/*   Updated: 2017/07/09 15:31:47 by irhett           ###   ########.fr       */
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
		World	w(20, 40);
		bool	going;
		// update to take window parameters rather than hardcoded

		while ((going = World.doCycle(void)))
		{
				//add enemies
				// window.clear;
				// window.drawStars;
				// window.drawEntities;
		}
		// game over;
  return (0);
}
