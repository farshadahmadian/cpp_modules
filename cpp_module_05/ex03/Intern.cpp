/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 08:41:50 by fahmadia          #+#    #+#             */
/*   Updated: 2024/03/21 16:51:55 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

char const *Intern::UnknownForm::what() const throw() 
{
	return "Intern could not create the form, as it was an unknown form!\n";
}

Intern::Intern(void)
{
	return;
}

Intern::Intern(Intern const &other)
{
	*this = other;
}

Intern::~Intern(void)
{
	return;
}

Intern &Intern::operator=(Intern const &rhs)
{
	(void) rhs;
	return *this;
}

AForm *Intern::createShrubberyForm(std::string target)
{
	AForm *createdForm = new ShrubberyCreationForm(target);
	return createdForm;
}
AForm *Intern::createRobotomyForm(std::string target)
{
	AForm *createdForm = new RobotomyRequestForm(target);
	return createdForm;
}
AForm *Intern::createPresidentialForm(std::string target)
{
	AForm *createdForm = new PresidentialPardonForm(target);
	return createdForm;
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	AForm *(Intern::*formCreations [])(std::string target) = {&Intern::createShrubberyForm, &Intern::createRobotomyForm, &Intern::createPresidentialForm};

	std::string forms[] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	size_t length = sizeof(forms) / (sizeof(std::string));

	try
	{
		for (size_t i = 0; i < length; i++)
		{
			if (forms[i].compare(name) == 0)
			{
				AForm *createdForm = (this->*formCreations[i])(target);
				std::cout << "Intern creates " << name << std::endl;
				return createdForm;
			}
		}
		throw Intern::UnknownForm();
	}
	catch(UnknownForm &unknownForm)
	{
		std:: cerr << unknownForm.what();
	}
	return NULL;
}
