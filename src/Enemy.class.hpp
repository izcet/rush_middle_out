/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 17:29:36 by irhett            #+#    #+#             */
/*   Updated: 2017/07/09 18:51:22 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_CLASS_HPP
# define ENEMY_CLASS_HPP

# include <iostream>
# include <string>

class Entity;
class World;

// enemy type is 'e'
// enemy _symbol is '8' or user-defined
// enemy _symbol is '$' on death

class Enemy : public Entity{

public:

	Enemy(void);
	Enemy(char symbol);
	Enemy(int x);
	Enemy(int x, char symbol);
	~Enemy(void);
	Enemy			&operator=(Enemy const &old);


	virtual void	act(World &w);
	virtual char	getSymbol(void) const;

	char			type;

private:
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

	int		_moveStep; // 0
	int		_moveMax; // 10
	// move every 10 frames or cycles

};

std::ostream	&operator<<(std::ostream &o, Enemy const &c);

#endif
