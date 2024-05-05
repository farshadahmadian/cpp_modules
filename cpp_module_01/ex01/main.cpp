/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:56:19 by fahmadia          #+#    #+#             */
/*   Updated: 2024/01/21 13:27:09 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	const int N = 10;
	Zombie *zombies = zombieHorde(N, "foo");
	for (int i = 0; i < N; i++)
		zombies[i].announce();
	delete[] zombies;
	return 0;
}
