/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 13:59:48 by irhett            #+#    #+#             */
/*   Updated: 2017/07/09 18:59:34 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULLET_HPP
# define BULLET_HPP

# include <iostream>
# include <string>

class Entity;
class World;

// bullet type is 'b'
// bullet _symbol is '-' or '|' or ' '

class Bullet : public Entity{

public:

	Bullet(int direction, int x, int y);
	~Bullet(void);

	virtual void	act(World &w);
	virtual char	getSymbol(void) const;

	int				getX(void) const;
	int				getY(void) const;

	char			type;

private:
	Bullet(void);

	bool			_alive;
	int				_x;
	int				_y;
	int				_direction;
	char			_symbol;

};

std::ostream	&operator<<(std::ostream &o, Bullet const &c);

#endif
