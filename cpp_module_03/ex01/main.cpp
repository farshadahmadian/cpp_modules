/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 10:38:26 by fahmadia          #+#    #+#             */
/*   Updated: 2024/05/05 17:40:25 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap scavTrap;
	ScavTrap scavTrap1("scavTrap1"); 
	ScavTrap scavTrap2 = ScavTrap(scavTrap1);
	ScavTrap scavTrap3;
	scavTrap3 = scavTrap2;

	scavTrap3.attack("enemy");
	scavTrap3.attack("enemy");
	scavTrap3.beRepaired(20);
	scavTrap3.takeDamage(20);
	scavTrap3.beRepaired(15);
	scavTrap3.takeDamage(20);
	scavTrap3.takeDamage(10);
	scavTrap3.attack("enemy");
	scavTrap3.takeDamage(100);
	scavTrap3.guardGate();
	scavTrap3.takeDamage(40);
	scavTrap3.attack("enemy");
	scavTrap3.beRepaired(10);

	const ClapTrap *p = new ScavTrap();
	delete p ;
	return 0;
}
