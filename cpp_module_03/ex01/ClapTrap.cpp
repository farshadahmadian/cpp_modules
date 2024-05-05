/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 10:28:33 by fahmadia          #+#    #+#             */
/*   Updated: 2024/01/28 17:22:54 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name(""), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap class: Default constructor called" << std::endl;
	return;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap class : " << this->_name << " is created by parameterized constructor." << std::endl;
	std::cout << "this->getName() = " << this->getName() << std::endl;
	std::cout << "this->getHitPoints() = " << this->getHitPoints() << std::endl;
	std::cout << "this->getEnergypoints() = " << this->getEnergypoints() << std::endl;
	std::cout << "this->getAttackDamage() = " << this->getAttackDamage() << std::endl;
	return;
}

ClapTrap::ClapTrap(ClapTrap const &clapTrap)
{
	*this = clapTrap;
	std::cout << "ClapTrap class : " << this->_name << " is created by copy constructor." << std::endl;
	return;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &clapTrap)
{
	if (this != &clapTrap)
	{
		this->_name = clapTrap._name;
		this->_hitPoints = clapTrap._hitPoints;
		this->_energyPoints = clapTrap._energyPoints;
		this->_attackDamage = clapTrap._attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap class : " << this->_name << " is destroyed by destructor." << std::endl;
	return;
}

void ClapTrap::attack(const std::string &target)
{
	if ((int)this->_energyPoints <= 0 || (int)this->_hitPoints <= 0)
	{
		std::cout << this->_name << " is dead, or does not have enough energy points to attack!" << std::endl;
		return;
	}
	this->_energyPoints--;
	std::cout << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	std::cout << "Total hit points => " << this->_hitPoints << std::endl;
	std::cout << "Total energy points => " << this->_energyPoints << std::endl;
	return;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	int temp = 0;
	if (static_cast<int>(amount) < 0)
	{
		std::cout << "Negative amount for takeDamage()!" << std::endl;
		return ;
	}
	if (static_cast<int>(this->_hitPoints) <= 0)
	{
		std::cout << this->_name << " is dead, and cannot be attacked!" << std::endl;
		return;
	}
	if (static_cast<int>(this->_hitPoints) - static_cast<int>(amount) < 0)
	{
		temp = this->_hitPoints;
		this->_hitPoints = 0;
	}
	else
		this->_hitPoints -= amount;
	std::cout << this->_name << " was attacked, and lost " << (this->_hitPoints > 0 ? amount : temp) << " hit points." << std::endl;
	if ((int)this->_hitPoints <= 0)
	{
		std::cout << this->_name << " is dead." << std::endl;
		return;
	}
	std::cout << "Total hit points => " << this->_hitPoints << std::endl;
	std::cout << "Total energy points => " << this->_energyPoints << std::endl;
	return;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if ((int)amount <= 0)
	{
		std::cout << "Amount must be more than zero for beRepaired()!" << std::endl;
		return ;
	}
	if ((int)this->_energyPoints <= 0 || (int)this->_hitPoints <= 0)
	{
		std::cout << this->_name << " is dead, or does not have enough energy points to be repaired!" << std::endl;
		return;
	}
	this->_hitPoints += amount;
	this->_energyPoints--;
	std::cout << this->_name << " was repaired and gained " << amount << " hit points." << std::endl;
	std::cout << "Total hit points => " << this->_hitPoints << std::endl;
	std::cout << "Total energy points => " << this->_energyPoints << std::endl;
	return;
}

void ClapTrap::setName(std::string name)
{
	this->_name = name;
	return;
}
void ClapTrap::setHitPoints(unsigned int amount)
{
	if ((int)amount > 0)
		this->_hitPoints = amount;
	return;
}
void ClapTrap::setEnergypoints(unsigned int amount)
{
	if ((int)amount > 0)
		this->_energyPoints = amount;
	return;
}

void ClapTrap::setAttackDamage(unsigned int amount)
{
	if ((int)amount >= 0)
		this->_attackDamage = amount;
	return;
}

std::string ClapTrap::getName(void) const
{
	return this->_name;
}

unsigned int ClapTrap::getHitPoints(void) const
{
	return this->_hitPoints;
}

unsigned int ClapTrap::getEnergypoints(void) const
{
	return this->_energyPoints;
}

unsigned int ClapTrap::getAttackDamage(void) const
{
	return this->_attackDamage;
}
