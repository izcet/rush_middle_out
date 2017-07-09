/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   World.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dubious </var/mail/dubious>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 00:03:40 by dubious           #+#    #+#             */
/*   Updated: 2017/07/09 15:33:59 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_CLASS_HPP
# define WORLD_CLASS_HPP

# include <iostream>
# include <string>
# include "List.class.hpp"
# include "Entity.class.hpp"
# include "Player.class.hpp"

class World {

	public:

		World(int height, int width);
		~World(void); // to be updated

		void			addEnemy(void);
		void			addEnemy(int x);
		void			addBullet(Bullet &b);

		bool			doCycle(void); //input args?

		int				getWidth(void) const;
		int				getHeight(void) const;

		Entity			***grid;
		int				key;

	private:
		World(void);
		World(World const & old);
		World			&operator=(World const &old);

		void			_act(List *Entities);
		void			_playerInput(void/*args*/); // input args?
		bool			_cleanup(void);


		int				_width;
		int				_height;

		List			*_Bullets;
		List			*_Enemies;
		Entity			*_Player;

};

std::ostream	&operator<<(std::ostream &o, World const &c);

#endif
