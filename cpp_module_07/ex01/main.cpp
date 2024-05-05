/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 09:39:36 by fahmadia          #+#    #+#             */
/*   Updated: 2024/04/04 14:45:45 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(void)
{
	std::string arr[] = {"Hello", "World", "!"};
	iter<std::string>(arr, 3, callback);
	
	float arr2[] = {4, 5, 6, 7};
	iter<float>(arr2, 4, callback);
	iter<float, void(*)(float)>(arr2, 4, callback<float>);

	iter(&arr2[0], 4, callback<float>);
	iter<float, void(*)(float)>(&arr2[0], -1 ,callback<float>);

	return 0;

}
