/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:11:05 by fahmadia          #+#    #+#             */
/*   Updated: 2024/03/27 12:54:43 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	Data data;
	std::cout << "************ Before Serialization ************" << std::endl;

	std::cout << "&data: " << reinterpret_cast<void *>(&data) << std::endl;
	std::cout << "&data: " << &data << std::endl;
	std::cout << "data members:\n" << data;

	std::cout << "************ After Serialization ************" << std::endl;

	uintptr_t reinterpretedPointere1 = Serializer::serialize(&data);
	std::cout << "reinterpretedPointere1: " << reinterpret_cast<void *>(reinterpretedPointere1) << std::endl;
	std::cout << "reinterpretedPointere1: " << reinterpretedPointere1 << std::endl;
	
	Data *reinterpretedPointere2 = Serializer::deserialize(reinterpretedPointere1);
	std::cout << "reinterpretedPointere2: " << reinterpret_cast<void *>(reinterpretedPointere2) << std::endl;
	std::cout << "data members: " << data;
	std::cout << "reinterpretedPointere2 == &data: " << (reinterpretedPointere2 == &data ? "true" : "false")  << std::endl;
	
	std::cout << "************ After Serialization ************" << std::endl;

	int *reinterpretedPointere3 = reinterpret_cast<int *>(reinterpretedPointere1);
	std::cout << "reinterpretedPointere3: " << reinterpret_cast<void *>(reinterpretedPointere3) << std::endl;
	std::cout << "*reinterpretedPointere3: " << *reinterpretedPointere3 << std::endl;

	Data *reinterpretedPointere4 = reinterpret_cast<Data *>(reinterpretedPointere3);
	std::cout << "reinterpretedPointere4: " << reinterpret_cast<void *>(reinterpretedPointere4) << std::endl;
	std::cout << "data members:\n" << data;

	return 0;
}
