/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbazagli <bbazagli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:02:11 by bbazagli          #+#    #+#             */
/*   Updated: 2024/08/19 15:42:06 by bbazagli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

#include <iostream>
#include <string>


class Weapon
{
  private:
	std::string type;

  public:
	Weapon(std::string type);
	~Weapon();
	void setType(const std::string &type);
	const std::string &getType() const; // constant member function returning a constant reference

};

#endif


/* const std::string &getType() const;
 *
 * 1. The first "const" is the return type
 * The function returns a reference to a constant string (read-only).
 * The caller of the function cannot modify the data returned by the function.
 *
 * 2. The last "const" referes to the member function
 * The function does not modify any member variables of the class.
 * Calling this function will not change the state of the object.
*/