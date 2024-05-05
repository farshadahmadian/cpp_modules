/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:57:43 by fahmadia          #+#    #+#             */
/*   Updated: 2024/01/29 15:46:37 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

typedef void (*fillIdeas)(std::string *ideas);

class Brain
{
private:
	std::string ideas[100];
	
public:
	Brain(void);
	Brain(fillIdeas f);
	Brain(Brain const &brain);
	Brain &operator=(Brain const &brain);
	~Brain(void);

	std::string const *getIdeas(void) const;
	void setIdeas(std::string const *ideas, int size);
	void setIdeasDefault(std::string idea, int const size);
};

#endif
