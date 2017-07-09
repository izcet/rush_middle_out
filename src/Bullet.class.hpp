/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 13:59:48 by irhett            #+#    #+#             */
/*   Updated: 2017/07/09 14:01:52 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULLET_HPP
# define BULLET_HPP

# include <iostream>
# include <string>

# include "Entity.class.hpp"
# include "World.cass.hpp"

class Bullet : public Entity{

public:

	Bullet(int direction, int x, int y);
	~Bullet(void);
	Bullet			&operator=(Bullet const &old);

	virtual void	act(World &w);
	virtual char	getSymbol(void) const;

private:
	Bullet(Bullet const & old);
	Bullet(void);

};

std::ostream	&operator<<(std::ostream &o, Bullet const &c);

#endif
