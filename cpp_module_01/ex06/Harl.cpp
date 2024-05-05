/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 11:50:56 by fahmadia          #+#    #+#             */
/*   Updated: 2024/01/21 18:45:35 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

typedef void (Harl::*f[])(void);

void callCurrentAndHigherLevels(int i, f memberFuntionsArray, Harl harl)
{
	while (i < 4)
	{
		(harl.*memberFuntionsArray[i])();
		i++;
	}
}

int findLevel(std::string level)
{
	int i;
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (i = 0; i < 4; i++)
	{
		if (levels[i].compare(level) == 0)
			break;
	}
	return i;
}

void Harl::complain(std::string level)
{
	int i = 0;
	void (Harl::*f1)(void) = &Harl::debug;
	void (Harl::*f2)(void) = &Harl::info;
	void (Harl::*f3)(void) = &Harl::warning;
	void (Harl::*f4)(void) = &Harl::error;
	f memberFunctions = {f1, f2, f3, f4};
	i = findLevel(level);

	switch (i)
	{
	case (0):
		callCurrentAndHigherLevels(i, memberFunctions, *this);
		break;
	case (1):
		callCurrentAndHigherLevels(i, memberFunctions, *this);
		break;
	case (2):
		callCurrentAndHigherLevels(i, memberFunctions, *this);
		break;
	case (3):
		callCurrentAndHigherLevels(i, memberFunctions, *this);
		break;
	default:
		std::cout << "Wrong Level!" << std::endl;
		break;
	}
}
