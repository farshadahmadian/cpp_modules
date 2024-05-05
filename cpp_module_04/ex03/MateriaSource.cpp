/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 14:18:33 by fahmadia          #+#    #+#             */
/*   Updated: 2024/05/05 17:00:45 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

MateriaSource::MateriaSource() : _materias()
{
	return;
}


MateriaSource::MateriaSource(MateriaSource const &materiaSource) : _materias()
{
	*this = materiaSource;
	return;
}

MateriaSource &MateriaSource::operator=(MateriaSource const &materiaSource)
{
	if (this != &materiaSource)
	{
		deleteCurrentMaterias();
		copyMaterias(materiaSource);
	}
	return *this;
}

void MateriaSource::copyMaterias(MateriaSource const &materiaSource)
{
	int length = sizeof(this->_materias) / sizeof(this->_materias[0]);
	for (int i = 0; i < length; i++)
	{
		if (!materiaSource._materias[i])
			continue;
		if (materiaSource._materias[i]->getType() == "ice")
		{
			this->_materias[i] = new Ice();
			*(this->_materias[i]) = *(materiaSource._materias[i]);
		}
		else if (materiaSource._materias[i]->getType() == "cure")
		{
			this->_materias[i] = new Cure;
			*(this->_materias[i]) = *(materiaSource._materias[i]);
		}
	}
	
	return;
}

void MateriaSource::deleteCurrentMaterias(void)
{
	int length = sizeof(this->_materias) / sizeof(this->_materias[0]);
	for (int i = 0; i < length; i++)
	{
		if (this->_materias[i])
		{
			delete this->_materias[i];
			this->_materias[i] = NULL;
		}
	}
	return;
}

MateriaSource::~MateriaSource(void)
{
	this->deleteCurrentMaterias(); 
}

AMateria **MateriaSource::findFirstEmptySlot(void)
{
	int length = sizeof(this->_materias) / sizeof(this->_materias[0]);
	for (int i = 0; i < length; i++)
	{
		if (!this->_materias[i])
			return &(this->_materias[i]);
	}
	return (NULL);
}

void MateriaSource::learnMateria(AMateria *materia, bool isOnHeap)
{
	AMateria **dPtr;

	dPtr = findFirstEmptySlot();
	if (!dPtr)
	{
		if (isOnHeap)
			delete materia;
		return;
	}

	*dPtr = materia->clone();
	**dPtr = *materia;
	if (isOnHeap)
		delete materia;
	return;
}

AMateria *MateriaSource::findMateriaWithType(std::string const &type)
{
	int length = sizeof(this->_materias) / sizeof(this->_materias[0]);
	for (int i = 0; i < length; i++)
	{
		if (this->_materias[i]->getType() == type)
			return this->_materias[i];
	}
	std::cerr << "Wrong type: cannot create a materia of type " + type + "\n";
	return NULL;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	AMateria *materia = this->findMateriaWithType(type);
	if (!materia)
		return NULL;
	else
		return (materia->clone());
}
