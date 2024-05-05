/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:32:08 by fahmadia          #+#    #+#             */
/*   Updated: 2024/01/29 17:48:11 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class AAnimal
{
protected:
	std::string type;

public:
	AAnimal(void);
	AAnimal(AAnimal const &animal);
	AAnimal &operator=(AAnimal const &animal);
	virtual ~AAnimal(void);
	virtual void makeSound(void) const = 0;
	std::string getType(void) const;
};

#endif
