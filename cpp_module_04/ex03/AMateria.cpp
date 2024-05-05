/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:03:40 by fahmadia          #+#    #+#             */
/*   Updated: 2024/05/05 16:57:34 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "typeinfo"

AMateria::AMateria(void) :_type("")
{
	return;
}

AMateria::AMateria(std::string const &type) : _type(type)
{
	return;
}

AMateria::AMateria(AMateria const &materia)
{
	*this = materia;
	return;
}


AMateria &AMateria::operator=(AMateria const &materia)
{
	if (this != &materia && this->getType() == materia.getType())
		this->_type = materia._type;
	else
		std::cerr << "Cannot assign " + materia.getType() + " to " + this->getType()  << std::endl;
	return (*this);
}

AMateria::~AMateria(void)
{
	return;
}

std::string const &AMateria::getType() const
{
	return this->_type;
}

void AMateria::use(ICharacter &target)
{
	std::cout << (this->_type == "ice" ? "Ice: \"* shoots an ice bolt at " + target.getName() + " *\"" : "Cure: \"* heals " + target.getName() + "'s wounds *\"") << std::endl;
	return;
}

void AMateria::setType(std::string const &type)
{
	if (type.compare("ice") == 0 || type == "cure")
		this->_type = type;
	return;
}
