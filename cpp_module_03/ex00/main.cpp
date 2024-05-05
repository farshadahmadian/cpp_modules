/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 10:38:26 by fahmadia          #+#    #+#             */
/*   Updated: 2024/01/28 10:50:46 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap clapTrap1("clapTrap1");
	ClapTrap clapTrap2(clapTrap1);
	ClapTrap clapTrap3("clapTrap3");
	clapTrap3 = clapTrap2;
	clapTrap3.setAttackDamage(40);
	clapTrap3.attack("enemy");
	clapTrap3.attack("enemy");
	clapTrap3.beRepaired(20);
	clapTrap3.takeDamage(20);
	clapTrap3.beRepaired(15);
	clapTrap3.takeDamage(20);
	clapTrap3.takeDamage(10);
	clapTrap3.takeDamage(30);
	clapTrap3.attack("enemy");
	clapTrap3.beRepaired(10);

	return 0;
}
