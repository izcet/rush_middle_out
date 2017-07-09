/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 14:51:30 by irhett            #+#    #+#             */
/*   Updated: 2017/07/09 15:14:37 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
# define PLAYER_HPP

# include <iostream>
# include <string>

# include "Entity.class.hpp"
# include "World.class.hpp"
# include "Bullet.class.hpp"

// player type is 'p'
// player _symbol is '^' or '>' or '<' or 'v'
// player _symbol is 'X' on death

class Player : public Entity{

	public:

		Player(int x, int y);
		~Player(void);
		Player			&operator=(Player const &old);

		virtual void	act(World &w);
		virtual char	getSymbol(void) const;

	private:

		int				_moveStep; // 0
		int				_moveMax; // 5
		// move every 5 frames or cycles
		
		void			_move(World &w);
		void			_shoot(World &w);

};

std::ostream	&operator<<(std::ostream &o, Player const &c);

#endif
