/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:15:34 by fahmadia          #+#    #+#             */
/*   Updated: 2024/05/05 16:53:12 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter
{
private:
	AMateria *_materias[4];
	std::string _name;
	AMateria **_unequippedItems;
	static int _unequippedItemsNum;

	void pushUnequippedItems(AMateria **temp);
	void deleteUnequippedItems(void);
	void deleteInventory();
	void copyInventory(Character const &character);
	AMateria **findFirstEmptyInventorySlot(Character *character);

public:
	Character(void);
	Character(std::string const &name);
	Character(Character const &character);
	Character &operator=(Character const &character);
	~Character(void);
	std::string const &getName() const;
	
	void equip(AMateria *m, bool isOnHeap);
	void unequip(int idx);
	void use(int idx, ICharacter &target);

	AMateria *const *getInventory(void) const; 
	AMateria *const (*getInventory2(void) const)[4];
};

#endif
