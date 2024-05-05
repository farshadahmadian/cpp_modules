/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 10:38:26 by fahmadia          #+#    #+#             */
/*   Updated: 2024/04/27 20:40:45 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap diamondTrap1("diamondTrap1");
	DiamondTrap diamondTrap2 = DiamondTrap(diamondTrap1);
	DiamondTrap diamondTrap3 = diamondTrap2;
	DiamondTrap diamondTrap4;
	diamondTrap4 = diamondTrap3;

	std::cout << "diamondTrap4.getOwnName() = " << diamondTrap4.getOwnName() << std::endl;
	std::cout << "diamondTrap4.getName() = " << diamondTrap4.getName() << std::endl;
	diamondTrap4.whoAmI();
	diamondTrap4.beRepaired(50);
	diamondTrap4.attack("enemy");
	diamondTrap4.takeDamage(50);
	diamondTrap4.guardGate();
	diamondTrap4.highFivesGuys();
	diamondTrap4.takeDamage(250);
	diamondTrap4.beRepaired(20);
	diamondTrap4.attack("enemy");
	diamondTrap4.guardGate();
	diamondTrap4.highFivesGuys();

	return 0;
}
