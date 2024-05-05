/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:46:46 by fahmadia          #+#    #+#             */
/*   Updated: 2024/03/21 14:12:21 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

unsigned int Form::_maxGrade = 1;
unsigned int Form::_minGrade = 150;

class Form::GradeTooHighException : public std::exception
{
public:

	char const *what() const throw();
};

char const *Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

class Form::GradeTooLowException : public std::exception
{
public:

	char const *what() const throw();
};

char const *Form::GradeTooLowException::what() const throw()
{
	return "The form Grade is too low, or it is higher that the bureaucrat's grade!";
}

Form::Form(void) : _name("Default Form"), _isSigned(false), _requiredGradeToSign(_minGrade), _requiredGradeToExe(Form::_minGrade)
{
	return;
}

void Form::checkGrades(unsigned int requiredGradeToSign, unsigned int requiredGradeToExe)
{
	if ((int)requiredGradeToSign < (int)Form::_maxGrade || (int)requiredGradeToExe < (int)_maxGrade)
	{
		throw Form::GradeTooHighException();
	}
	else if (requiredGradeToSign > Form::_minGrade || requiredGradeToExe > _minGrade)
	{
		throw GradeTooLowException();
	}
}

Form::Form(std::string name, unsigned int requiredGradeToSign, unsigned int requiredGradeToExe) : 
	_name(name), _isSigned(false), _requiredGradeToSign(requiredGradeToSign), _requiredGradeToExe(requiredGradeToExe)
{
	try
	{
		Form::checkGrades(requiredGradeToSign, requiredGradeToExe);
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

Form::Form(Form const &other) :
	_name(other._name), _requiredGradeToSign(other._requiredGradeToSign), _requiredGradeToExe(other._requiredGradeToExe)
{
	try
	{
		checkGrades(other._requiredGradeToSign, other._requiredGradeToExe);
	}
	catch(GradeTooHighException &tooHighException)
	{
		std::cerr << tooHighException.what() << std::endl;
	}
	catch(GradeTooLowException &tooLowException)
	{
		std::cerr << tooLowException.what() << std::endl;
	}
	*this = other;
	return;
}

Form &Form::operator=(Form const &rhs)
{
	if (this != &rhs)
		this->_isSigned = rhs._isSigned;
	return *this;
}

Form::~Form(void)
{
	return;
}

std::string const &Form::getName(void) const
{
	return this->_name;
}

bool Form::getIsSigned(void) const
{
	return this->_isSigned;
}

unsigned int Form::getRequiredGradeToSign(void) const
{
	return this->_requiredGradeToSign;
}

unsigned int Form::getRequiredGradeToExe(void) const
{
	return this->_requiredGradeToExe;
}

std::ostream &operator<<(std::ostream &cout, Form const &form)
{
	std::cout << "Form Name: " << form.getName() << std::endl;
	std::cout << "Form Required Grade to Sign: " << form.getRequiredGradeToSign() << std::endl;
	std::cout << "Form Required Grade to Execute: " << form.getRequiredGradeToExe() << std::endl;
	std::cout << "Is Form Signed: " << (form.getIsSigned() ? "true" : "false") << std::endl;
	return cout;
}

void Form::beSigned(Bureaucrat const &bureaucrat)
{
	try
	{
		checkGrades(this->_requiredGradeToSign, this->_requiredGradeToExe);
		try
		{
			if (bureaucrat.getGrade() > this->_requiredGradeToSign)
				throw Form::GradeTooLowException();
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
