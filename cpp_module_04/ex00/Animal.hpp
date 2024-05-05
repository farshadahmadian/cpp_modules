/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:32:08 by fahmadia          #+#    #+#             */
/*   Updated: 2024/04/27 20:07:12 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
protected:
	std::string type;

public:
	Animal(void);
	Animal(Animal const &animal);
	Animal &operator=(Animal const &animal);
	virtual ~Animal(void);
	virtual void makeSound(void) const;
	std::string getType(void) const;
};

#endif
