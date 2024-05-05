/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:40:30 by fahmadia          #+#    #+#             */
/*   Updated: 2024/05/05 16:59:02 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria()
{
	this->_type = "cure";
	return;
}

Cure::Cure(std::string const &type) : AMateria(type)
{
	this->_type = "cure";
	return;
}

Cure::Cure(Cure const &cure) : AMateria(cure)
{
	return;
}

Cure &Cure::operator=(Cure const &cure)
{
	if (this != &cure)
		this->AMateria::operator=(cure);
	return (*this);
}

Cure::~Cure(void)
{
	return;
}

AMateria *Cure::clone(void) const
{
	return (new Cure);
}
