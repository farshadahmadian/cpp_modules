/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 09:58:22 by fahmadia          #+#    #+#             */
/*   Updated: 2024/03/21 13:26:47 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

unsigned int Bureaucrat::_minGrade = 150;
unsigned int Bureaucrat::_maxGrade = 1;

char const *Bureaucrat::AssignmentException::what() const throw()
{
	return "Bureaucrats cannot be assigned to each other!";
}

Bureaucrat::AssignmentException::~AssignmentException(void) throw()
{
	return;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(void) : std::exception()
{
	return;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(GradeTooHighException const &gradeTooHighException) : std::exception(gradeTooHighException)
{
	return;
}

char const *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high to be assigned to the bureaucrat! Instead, the maximum grade is assigned to them.";
}

Bureaucrat::GradeTooHighException::~GradeTooHighException(void) throw() 
{
	return;
}

char const *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low to be assigned to the bureaucrat! Instead, the minimum grade is assigned to them.";
}

Bureaucrat::GradeTooLowException::~GradeTooLowException(void) throw()
{
	return;
}


Bureaucrat::Bureaucrat(void) : _name("Default"), _grade(_minGrade)
{
	return;
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : _name(name), _grade(grade)
{
	try
	{
		if ((int)grade < 1)
			throw Bureaucrat::GradeTooHighException();
		else if (grade > 150)
			throw GradeTooLowException();
	}
	catch(Bureaucrat::GradeTooHighException &highGradeException)
	{
		this->_grade = Bureaucrat::_maxGrade;
		std::cerr << highGradeException.what() << std::endl;
	}
	catch(GradeTooLowException &lowGradeException)
	{
		this->_grade = Bureaucrat::_minGrade;
		std::cerr << lowGradeException.what() << std::endl;
	}
	catch(std::exception &exception)
	{
		std::cerr << exception.what() << std::endl;
	}
}

Bureaucrat::Bureaucrat(Bureaucrat const& other) : _name(other._name)
{
	this->_grade = other._grade;
	return;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const& rhs)
{
	try
	{
		if (this != &rhs)
			throw AssignmentException();
	}
	catch(AssignmentException &assignmentException)
	{
		std::cerr << assignmentException.what() << std::endl;
	}
	return *this;
}

Bureaucrat::~Bureaucrat(void)
{
	return;
}

std::string const Bureaucrat::getName(void) const
{
	return this->_name;
}

unsigned int Bureaucrat::getGrade(void) const
{
	return this->_grade;
}

Bureaucrat &Bureaucrat::operator++(void)
{
	try
	{
		this->_grade--;
		if (this->_grade < _maxGrade)
			throw GradeTooHighException();
	}
	catch(GradeTooHighException &tooHighException)
	{
		this->_grade++;
		std::cerr << tooHighException.what() << std::endl;
	}
	return *this;
}

Bureaucrat Bureaucrat::operator++(int a)
{
	a = 1;
	Bureaucrat temp(*this);

	try
	{
		this->_grade -= a;
		if (this->_grade < Bureaucrat::_maxGrade)
			throw GradeTooHighException();
	}
	catch(Bureaucrat::GradeTooHighException &tooHighException)
	{
		this->_grade += a;
		std::cerr << tooHighException.what() << std::endl;
	}
	return temp;
}

Bureaucrat &Bureaucrat::operator--(void)
{
	try
	{
		this->_grade++;
		if (_grade > Bureaucrat::_minGrade)
			throw Bureaucrat::GradeTooLowException();
	}
	catch(GradeTooLowException &tooLowException)
	{
		_grade = _minGrade;
		std::cerr << tooLowException.what() << std::endl;
	}
	return *this;
}

Bureaucrat Bureaucrat::operator--(int a)
{
	a = 1;
	Bureaucrat temp(*this);
	 
	try
	{
		_grade += a;
		if (this->_grade > _minGrade)
		{
			GradeTooLowException gradeTooLowException;
			throw gradeTooLowException;
		}
	}
	catch(GradeTooLowException &gradeTooLowException)
	{
		this->_grade -= a;
		std::cerr << gradeTooLowException.what() << std::endl;
	}
	return temp;
}

std::ostream &operator<<(std::ostream &cout, Bureaucrat const &bureaucrat)
{
	std::cout << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return cout;
}
