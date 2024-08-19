/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbazagli <bbazagli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:31:03 by bbazagli          #+#    #+#             */
/*   Updated: 2024/08/19 15:39:58 by bbazagli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
# define HUMANA_H

# include "Weapon.hpp"

class HumanA
{
  private:
	std::string name;
	Weapon& weapon;

  public:
	HumanA(std::string name, Weapon& weapon);
	~HumanA();
	void attack();
};

#endif

/* HumanA is always armed. 

	* A reference must be initialized when the object is created and cannot be null. */