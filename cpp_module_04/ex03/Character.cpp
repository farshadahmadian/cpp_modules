/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:55:38 by fahmadia          #+#    #+#             */
/*   Updated: 2024/05/05 16:58:39 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <cstring>
# include "Character.hpp"
# include "ICharacter.hpp"
# include "Ice.hpp"
# include "Cure.hpp"
# include "typeinfo"

int Character::_unequippedItemsNum = 0;
Character::Character(void) : _materias(), _name("Default Character"), _unequippedItems(NULL)
{
	return;
}

Character::Character(std::string const &name) : _materias(), _name(name), _unequippedItems(NULL)
{
	return;
}
 
Character::Character(Character const &character) : _materias(), _unequippedItems(NULL)
{
	*this = character;
	return;
}

Character &Character::operator=(Character const &character)
{
	if (this != &character)
	{
		this->_name = character._name;
		this->deleteInventory();
		this->copyInventory(character);
	}
	return (*this);
}

Character::~Character(void)
{
	this->deleteInventory();
	Character::deleteUnequippedItems();
}

AMateria *const *Character::getInventory(void) const 
{
	return (&_materias[0]);
}

AMateria *const (*Character::getInventory2(void) const)[4]
{
	return &(this->_materias);
}

void Character::deleteInventory(void)
{
	size_t length = sizeof(this->_materias) / sizeof(this->_materias[0]);
	for (size_t i = 0; i < length; i++)
	{
		if (this->_materias[i])
		{
			delete this->_materias[i];
			this->_materias[i] = NULL;
		}
	}
	return;
}

void Character::copyInventory(Character const &character)
{
	for (int i = 0; i < 4; i++)
	{
		if (!character.getInventory()[i])
			continue;
		this->_materias[i] = (character.getInventory()[i])->clone();
		if (this->_materias[i])
			*(this->_materias[i]) = *(character._materias[i]);
	}
	return;
}


std::string const &Character::getName() const
{
	return this->_name;
}

AMateria **Character::findFirstEmptyInventorySlot(Character *character)
{
	int length = sizeof(character->_materias) / sizeof(character->_materias[0]);

	for (int i = 0; i < length; i++)
	{
		if (!character->_materias[i])
			return &(character->_materias[i]);
	}
	return (NULL);
}

void Character::equip(AMateria *m, bool isOnHeap)
{
	AMateria **empty_slot = findFirstEmptyInventorySlot(this);
	if (!empty_slot)
	{
		if (isOnHeap)
			delete m;
		return ;
	}
	*empty_slot = m->clone();
	**empty_slot = *m;
	if (isOnHeap)
		delete m;
	return ;
}

void Character::deleteUnequippedItems(void)
{
	
	if (!Character::_unequippedItems)
		return;
	for (int i = 0; _unequippedItems[i]; i++)
	{
		delete this->_unequippedItems[i];
		_unequippedItems[i] = NULL;
	}

	delete [] this->Character::_unequippedItems;
	this->_unequippedItems = NULL;
}

void Character::pushUnequippedItems(AMateria **temp)
{
	if (!temp)
		return;

	int i = 0;
	while (temp[i])
	{
		this->_unequippedItems[i] = temp[i];
		i++;
	}
}

void Character::unequip(int idx)
{
	size_t length = sizeof(this->_materias) / sizeof(this->_materias[0]);
	if (!this->_materias[idx] || idx >= (int)length)
		return ;
	Character::_unequippedItemsNum++;
	AMateria **temp = this->_unequippedItems;
	this->_unequippedItems = new AMateria *[_unequippedItemsNum + 1];
	memset(_unequippedItems, 0, (_unequippedItemsNum + 1) * sizeof(AMateria *));
	this->_unequippedItems[_unequippedItemsNum - 1] = this->_materias[idx];
	this->_unequippedItems[_unequippedItemsNum] = NULL;
	this->pushUnequippedItems(temp);
	if (temp)
	{
		delete [] temp; 
		temp = NULL;
	}
	this->_materias[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	AMateria *current_materia = this->_materias[idx]; 
	if (!current_materia)
		return;
	std::string type = this->_materias[idx]->getType();
	std::cout << (type == "ice" ? type + ": * shoots an ice bolt at " + target.getName() + " *\"" : type + ": * heals " + target.getName() + "'s wounds *\"") << std::endl;
	return;
}
