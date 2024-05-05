/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 12:18:30 by fahmadia          #+#    #+#             */
/*   Updated: 2024/03/21 15:47:43 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

class RobotomyRequestForm::RobotoException : public std::exception
{
public:

	char const *what()const throw();
};

char const *RobotomyRequestForm::RobotoException::what() const throw()
{
	return "Unfortunately, robotomy failed!";
}


RobotomyRequestForm::RobotomyRequestForm(void) : AForm("Default Target", "Roboto Form", 72, 45)
{
	return;
}

void RobotomyRequestForm::runExecution(Bureaucrat const &bureaucrat, std::string const &target) const
{
	std::srand(std::time(NULL));
	int zeroOrOne = std::rand() % 2;
	std::cout << "Rrr..." << std::endl;
	
	try
	{
		if (zeroOrOne == 0)
			throw RobotoException();
		std::cout << bureaucrat.getName() << " executed " << this->getName() << std::endl;
		std::cout << target << " has been robotomized successfully!\n";
	}
	catch(RobotoException &robotoException)
	{
		std::cerr << robotoException.what() << std::endl;
	}
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, "Roboto Form", 72, 45)
{
	return;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &other) : AForm(other)
{
	*this = other;
	return;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	return;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	(void) rhs;
	return *this;
}
