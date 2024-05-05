/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 19:13:34 by fahmadia          #+#    #+#             */
/*   Updated: 2024/01/29 17:36:30 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void) 
{
	this->setIdeasDefault("Default Idea", 100);
	std::cout << "Brain class: Default constructor is called." << std::endl;
	return;
}

Brain::Brain(fillIdeas f)
{
	std::cout << "Brain class: Parameterized constructor is called." << std::endl;
	(*f)(this->ideas);
	return;
}

Brain::Brain(Brain const &brain)
{
	std::cout << "Brain class: copy constructor is called." << std::endl;
	*this = brain;
	return;
}

Brain &Brain::operator=(Brain const &brain)
{
	if (this != &brain)
		this->setIdeas(brain.ideas, 100);
	return *this;	
}

Brain::~Brain(void)
{
	std::cout << "Brain class: destructor is called." << std::endl;
	return;
}

void Brain::setIdeasDefault(std::string idea, int const size)
{
	for (int i = 0; i < size; i++)
	{
		this->ideas[i] = idea;
	}
	return;
}

std::string const *Brain::getIdeas(void) const
{
	return this->ideas;
}

void Brain::setIdeas(std::string const *ideas, int size)
{
	for (int i = 0; i < size; i++)
	{
		this->ideas[i] = ideas[i];
	}
	return;
}

