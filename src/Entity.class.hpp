/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dubious </var/mail/dubious>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 20:04:52 by dubious           #+#    #+#             */
/*   Updated: 2017/07/09 14:20:31 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_HPP
# define ENTITY_HPP

# include <iostream>
# include <string>

# include "World.class.hpp"

# define NORTH 0
# define SOUTH 1
# define EAST 2
# define WEST 3

class Entity {

	public:

		// we have to be able to reference a generic entity
		// as a return value from another function
		// but an entity will never be declared on its own
		// it should technically be abstract butt fuck it
		Entity			&operator=(Entity const &old);
		~Entity(void);

		// overridden by child classes
		virtual void	act(World &w);

		// these are the same for all entities
		virtual	char	getSymbol(void) const;
		bool			isAlive(void) const;
	
		void			die(void);
		void			collision(Entity &a, Entity &b);

		char			type;

	private:

		Entity(void);
		Entity(const Entity *ent);
		Entity(Entity const & old);
		Entity(void);

	protected:

		void			moveUp(World &w);
		void			moveDown(World &w);
		void			moveLeft(World &w);
		void			moveRight(World &w);

		Entity			*getLeft(World &w) const;
		Entity			*getRight(World &w) const;
		Entity			*getUp(World &w) const;
		Entity			*getDown(World &w) const;

		bool			_alive;
		int				_x;
		int				_y;
		int				_direction;
		char			_symbol;
};

std::ostream		&operator<<(std::ostream &o, Entity const &c);

#endif
