/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:23:03 by fahmadia          #+#    #+#             */
/*   Updated: 2024/05/05 16:59:21 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria()
{
	this->_type = "ice";
	return;
}

Ice::Ice(std::string const &type) : AMateria(type)
{
	this->_type = "ice";
	return;
}

Ice::Ice(Ice const &ice) : AMateria(ice)
{
	return;
}

Ice &Ice::operator=(Ice const &ice)
{
	if (this != &ice)
		this->AMateria::operator=(ice);
	return (*this);
}

Ice::~Ice(void)
{
	return;
}

AMateria *Ice::clone(void) const
{
	Ice *ice = new Ice;
	return ice;
}
