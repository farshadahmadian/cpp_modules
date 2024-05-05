/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 08:44:24 by fahmadia          #+#    #+#             */
/*   Updated: 2024/03/21 16:48:45 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <typeinfo>
#include "AForm.hpp"

unsigned int AForm::_maxGrade = 1;
unsigned int AForm::_minGrade = 150;

char const *AForm::GradeTooHighException::what() const throw()
{
	return "The form Grade is too high!";
}

char const *AForm::GradeTooLowException::what() const throw()
{
	return "The form Grade is too low, or it is higher that the bureaucrat's grade!";
}

AForm::AForm(void) : _target("Default Target"), _name("Default Form"), _isSigned(false), _requiredGradeToSign(_minGrade), _requiredGradeToExe(AForm::_minGrade)
{
	return;
}

void AForm::checkGrades(unsigned int requiredGradeToSign, unsigned int requiredGradeToExe) const
{
	if ((int)requiredGradeToSign < (int)AForm::_maxGrade || (int)requiredGradeToExe < (int)_maxGrade)
	{
		throw AForm::GradeTooHighException();
	}
	else if (requiredGradeToSign > AForm::_minGrade || requiredGradeToExe > _minGrade)
	{
		throw GradeTooLowException();
	}
}

AForm::AForm(std::string target, std::string name, unsigned int requiredGradeToSign, unsigned int requiredGradeToExe) :
	_target(target), _name(name), _isSigned(false), _requiredGradeToSign(requiredGradeToSign), _requiredGradeToExe(requiredGradeToExe)
{
	try
	{
		AForm::checkGrades(requiredGradeToSign, requiredGradeToExe);
	}
	catch(GradeTooHighException &tooHighException)
	{
		std::cerr << tooHighException.what() << std::endl;
	}
	catch(GradeTooLowException &tooLowException)
	{
		std::cerr << tooLowException.what() << std::endl;
	}
	return;
}

AForm::AForm(AForm const &other) :
	_target(other._target), _name(other._name), _requiredGradeToSign(other._requiredGradeToSign), _requiredGradeToExe(other._requiredGradeToExe)
{
	try
	{
		this->checkGrades(other._requiredGradeToSign, other._requiredGradeToExe);
		*this = other;
	}
	catch(GradeTooHighException &tooHighException)
	{
		std::cerr << tooHighException.what() << std::endl;
	}
	catch(GradeTooLowException &tooLowException)
	{
		std::cerr << tooLowException.what() << std::endl;
	}
	
	return;
}

AForm &AForm::operator=(AForm const &rhs)
{
	if (this != &rhs)
		this->_isSigned = rhs._isSigned;
	return *this;
}

AForm::~AForm(void)
{
	return;
}

std::string const &AForm::getName(void) const
{
	return this->_name;
}

bool AForm::getIsSigned(void) const
{
	return this->_isSigned;
}

unsigned int AForm::getRequiredGradeToSign(void) const
{
	return this->_requiredGradeToSign;
}

unsigned int AForm::getRequiredGradeToExe(void) const
{
	return this->_requiredGradeToExe;
}


std::string const &AForm::getTarget(void) const
{
	return this->_target;
}

std::ostream &operator<<(std::ostream &cout, AForm const &form)
{
	std::cout << "Form Name: " << form.getName() << std::endl;
	std::cout << "Form Target: " << form.getTarget() << std::endl;
	std::cout << "Form Required Grade to Sign: " << form.getRequiredGradeToSign() << std::endl;
	std::cout << "Form Required Grade to Execute: " << form.getRequiredGradeToExe() << std::endl;
	std::cout << "Is Form Signed: " << (form.getIsSigned() ? "true" : "false") << std::endl;
	return cout;
}

void AForm::setIsSigned(bool isSigned)
{
	this->_isSigned = isSigned;
	return;
}

void AForm::beSigned(Bureaucrat const &bureaucrat)
{
	try
	{
		checkGrades(this->_requiredGradeToSign, this->_requiredGradeToExe);
		try
		{
			if (bureaucrat.getGrade() > this->_requiredGradeToSign)
				throw AForm::GradeTooLowException();
			this->_isSigned = true;
		}
		catch(GradeTooLowException &tooLowException)
		{
			std::cerr << tooLowException.what() << std::endl;
		}
	}
	catch(GradeTooHighException &tooHighException)
	{
		std::cerr << tooHighException.what() << std::endl;
	}
	catch(GradeTooLowException &tooLowException)
	{
		std::cerr << tooLowException.what() << std::endl;
	}
	return;
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (!this->_isSigned)
	{
		std::cout << this->_name << " is not signed yet! " << std::endl;
		return;
	}

	try
	{
		this->checkGrades(this->_requiredGradeToSign, this->_requiredGradeToExe);
		try
		{
			if (executor.getGrade() > this->_requiredGradeToExe)
				throw GradeTooLowException();
			this->runExecution(executor, this->_target);
		}
		catch(GradeTooLowException &tooLowException)
		{
			std::cerr << tooLowException.what() << std::endl;
		}
	}
	catch(GradeTooHighException &tooHighException)
	{
		std::cerr << tooHighException.what() << std::endl;
	}
	catch(GradeTooLowException &tooLowException)
	{
		std::cerr << tooLowException.what() << std::endl;
	}
	return;
}
