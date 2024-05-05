/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:50:54 by fahmadia          #+#    #+#             */
/*   Updated: 2024/04/27 18:54:16 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap(), ScavTrap(), FragTrap()
{
	std::cout << "DiamondTrap class: Default constructor called" << std::endl;
	ScavTrap scavtrap;
	this->setEnergypoints(scavtrap.getEnergypoints());
	return;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{
	std::cout << "DiamondTrap class: " << this->_name << " (" << this->getName() << ") "	<< "is created by parameterized constructor." << std::endl;
	ScavTrap scavtrap("temp");
	this->setEnergypoints(scavtrap.getEnergypoints());
	std::cout << "this->getName() = " << this->getName() << std::endl;
	std::cout << "this->getHitPoints() = " << this->getHitPoints() << std::endl;
	std::cout << "this->getEnergypoints() = " << this->getEnergypoints() << std::endl;
	std::cout << "this->getAttackDamage() = " << this->getAttackDamage() << std::endl;
	return;
}

DiamondTrap::DiamondTrap(DiamondTrap const &diamondTrap) : ClapTrap(diamondTrap), ScavTrap(diamondTrap), FragTrap(diamondTrap)
{
	this->_name = diamondTrap._name;
	std::cout << "DiamondTrap class :" << this->_name << " (" << this->getName() << ")"
						<< " is created by copy constructor." << std::endl;
	return;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &diamondTrap)
{
	if (this != &diamondTrap)
	{
		this->ClapTrap::operator=(diamondTrap);
		this->_name = diamondTrap._name;
	}
	return *this;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap class : " << this->_name << " (" << this->getName() << ") "
						<< "is destroyed by destructor." << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
	this->ScavTrap::attack(target);
	return;
}

void DiamondTrap::whoAmI()
{
	std::cout << "My class calls me " << this->_name << " ,but other classes call me " << this->getName() + '.' << std::endl;
	return;
}

std::string DiamondTrap::getOwnName()
{
	return this->_name;
}

void DiamondTrap::setOwnName(std::string const name)
{
	this->DiamondTrap::_name = name;
}
