/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:10:31 by fahmadia          #+#    #+#             */
/*   Updated: 2024/03/26 14:44:10 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void) 
{
	return;
}

Serializer::Serializer(Serializer const &other)
{
	(void)other;
	return;
}
Serializer::~Serializer(void)
{
	return;
}

Serializer &Serializer::operator=(Serializer const &rhs)
{
	(void)rhs;
	return *this;
}

uintptr_t Serializer::serialize(Data* ptr)
{
	uintptr_t reinterpretedPointer = reinterpret_cast<uintptr_t>(ptr);
	return reinterpretedPointer;
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}
