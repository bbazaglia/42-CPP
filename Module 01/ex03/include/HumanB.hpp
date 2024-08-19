/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbazagli <bbazagli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:31:06 by bbazagli          #+#    #+#             */
/*   Updated: 2024/08/19 15:41:21 by bbazagli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
# define HUMANB_H

# include "Weapon.hpp"

class HumanB
{
  private:
	std::string name;
	Weapon* weapon;

  public:
	HumanB(std::string name);
	~HumanB();
	void setWeapon(Weapon& weapon);
	void attack();
};

#endif

/* A pointer can be set to NULL, allowing HumanB to exist without a Weapon. 
 * The pointer can later be assigned a valid Weapon if needed. */