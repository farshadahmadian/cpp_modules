/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:13:41 by fahmadia          #+#    #+#             */
/*   Updated: 2024/04/27 18:46:33 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	this->setHitPoints(100);
	this->setEnergypoints(100);
	this->setAttackDamage(30);
	std::cout << "FragTrap class: Default constructor called" << std::endl;
	return;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->setHitPoints(100);
	this->setEnergypoints(100);
	this->setAttackDamage(30);

	std::cout << "FragTrap class: " << this->getName() << " is created by parameterized constructor." << std::endl;
	std::cout << "this->getName() = " << this->getName() << std::endl;
	std::cout << "this->getHitPoints() = " << this->getHitPoints() << std::endl;
	std::cout << "this->getEnergypoints() = " << this->getEnergypoints() << std::endl;
	std::cout << "this->getAttackDamage() = " << this->getAttackDamage() << std::endl;
	return;
}

FragTrap::FragTrap(FragTrap const &fragTrap) : ClapTrap(fragTrap)
{
	std::cout << "FragTrap class : " << this->getName() << " is created by copy constructor." << std::endl;
	return;
}

FragTrap &FragTrap::operator=(FragTrap const &fragTrap)
{
	if (this != &fragTrap)
		this->ClapTrap::operator=(fragTrap);
	return *this;
}


FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap class : " << this->getName() << " is destroyed by destructor." << std::endl;
	return;
}

void FragTrap::highFivesGuys(void)
{
	if (this->getHitPoints() <= 0 || this->getEnergypoints() <= 0)
	{
		std::cout << this->getName() << " is dead, or does not have enough energy points to request a high five!" << std::endl;
		return;
	}
	std::cout << this->getName() + ": Good job guys! Give me a high five!" << std::endl;
}
