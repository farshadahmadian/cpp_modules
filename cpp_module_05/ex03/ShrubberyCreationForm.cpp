/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 09:00:52 by fahmadia          #+#    #+#             */
/*   Updated: 2024/03/21 16:12:38 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <stdexcept>
#include <typeinfo>

class ShrubberyCreationForm::FileException : public std::exception
{
public:
	char const *what() const throw();
};

char const *ShrubberyCreationForm::FileException::what() const throw()
{
	return "The file could not be open!";
}

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("Default Target" ,"shrubbery creation", 145, 137)
{
	return;
}

void draw(std::ofstream &file)
{
	file << "    *    \n";
	file << "   ***\n";
	file << "  *****\n";
	file << " *******\n";
	file << "   | |\n";
	file << "   |_|\n"; 
}

void ShrubberyCreationForm::createAndOpenFile(std::string target)
{
	std::ofstream file;
	file.open((target + "_shrubbery").c_str(), std::ios::out);
	if (!file.is_open())
		throw FileException();
	draw(file);
	file.close();
	return;
}

void ShrubberyCreationForm::runExecution(Bureaucrat const &bureaucrat, std::string const &target) const
{
	try
	{
		ShrubberyCreationForm::createAndOpenFile(target);
		std::cout << bureaucrat.getName() << " executed " << this->getName() << std::endl;
	}
	catch(FileException &fileException)
	{
		std::cout << fileException.what() << std::endl;
	}
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target, "shrubbery creation", 145, 137)
{
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other) : AForm(other)
{
	return;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	return;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	(void) rhs;
	return *this;
}
