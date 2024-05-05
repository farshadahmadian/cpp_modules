/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:25:11 by fahmadia          #+#    #+#             */
/*   Updated: 2024/01/28 17:19:03 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	this->setHitPoints(100);
	this->setEnergypoints(50);
	this->setAttackDamage(20);
	std::cout << "ScavTrap class : Default constructor called" << std::endl;
	return;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->setHitPoints(100);
	this->setEnergypoints(50);
	this->setAttackDamage(20);
	std::cout << "ScavTrap class: " << this->getName() << " is created by parameterized constructor." << std::endl;

	std::cout << "this->getName() = " << this->getName() << std::endl;
	std::cout << "this->getHitPoints() = " << this->getHitPoints() << std::endl;
	std::cout << "this->getEnergypoints() = " << this->getEnergypoints() << std::endl;
	std::cout << "this->getAttackDamage() = " << this->getAttackDamage() << std::endl;
	return;
}

ScavTrap::ScavTrap(ScavTrap const &scavTrap) : ClapTrap(scavTrap)
{
	// operator=(scavTrap);
	std::cout << "ScavTrap class : " << this->getName() << " is created by copy constructor." << std::endl;
	return;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &scavTrap)
{
	if (this != &scavTrap)
		this->ClapTrap::operator=(scavTrap);
	return *this;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap class : " << this->getName() << " is destroyed by destructor." << std::endl;
}

void ScavTrap::guardGate(void)
{
	if (this->getEnergypoints() <= 0 || this->getHitPoints() <= 0)
	{
		std::cout << this->getName() << " is dead, or does not have enough energy points to gaurd the gate!" << std::endl;
		return;
	}
	std::cout << this->getName() << " is now in Gate keeper mode." << std::endl;
}

void ScavTrap::attack(const std::string &target)
{

	std::cout << "Method attack() from the class ScavTrap is called:" << std::endl;
	this->ClapTrap::attack(target);
}
