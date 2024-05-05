/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 10:38:26 by fahmadia          #+#    #+#             */
/*   Updated: 2024/04/27 20:03:17 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void)
{
	FragTrap fragTrap;
	FragTrap fragTrap1("fragTrap1");
	FragTrap fragTrap2(fragTrap1);
	fragTrap2.setName("robot");
	fragTrap2.setAttackDamage(100);
	fragTrap2.setHitPoints(110);
	fragTrap2.setEnergypoints(200);

	FragTrap fragTrap3("fragTrap3");
	fragTrap3 = fragTrap2; 
	
	fragTrap3.attack("enemy");
	fragTrap3.attack("enemy");
	fragTrap3.beRepaired(20);
	fragTrap3.takeDamage(20);
	fragTrap3.beRepaired(15);
	fragTrap3.takeDamage(20);
	fragTrap3.takeDamage(10);
	fragTrap3.attack("enemy");
	fragTrap3.highFivesGuys();
	fragTrap3.takeDamage(100);
	fragTrap3.takeDamage(100);
	fragTrap3.highFivesGuys();
	fragTrap3.attack("enemy");
	fragTrap3.beRepaired(30);

	return 0;
}
