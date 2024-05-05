/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:26:35 by fahmadia          #+#    #+#             */
/*   Updated: 2024/01/29 18:11:04 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal
{
	protected:
		std::string type;

	public:
		WrongAnimal(void);
		WrongAnimal(std::string const type);
		WrongAnimal(WrongAnimal const &wrongAnimal);
		WrongAnimal &operator=(WrongAnimal const &wrongAnimal);
		virtual ~WrongAnimal(void);
		void makeSound(void) const;
		std::string getType(void)const;
};

#endif
