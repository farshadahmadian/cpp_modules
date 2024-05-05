/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 10:18:20 by fahmadia          #+#    #+#             */
/*   Updated: 2024/04/27 20:03:00 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_HPP 
#define CLAP_TRAP_HPP

#include <iostream>

class ClapTrap
{
private:
	std::string _name;
	unsigned int _hitPoints;
	unsigned int _energyPoints;
	unsigned int _attackDamage;

public:
	ClapTrap(void);
	ClapTrap(std::string name);
	ClapTrap(ClapTrap const &clapTrap);
	ClapTrap &operator=(ClapTrap const &clapTrap);
	~ClapTrap(void);
	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	void setName(std::string name);
	void setHitPoints(unsigned int amount);
	void setEnergypoints(unsigned int amount);
	void setAttackDamage(unsigned int amount);

	std::string getName(void) const;
	unsigned int getHitPoints(void) const;
	unsigned int getEnergypoints(void) const;
	unsigned int getAttackDamage(void) const;
};

#endif
