/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 08:39:56 by fahmadia          #+#    #+#             */
/*   Updated: 2024/03/21 16:48:51 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	std::string const _target;
	std::string const _name;
	bool _isSigned;
	unsigned int const _requiredGradeToSign;
	unsigned int const _requiredGradeToExe;
	class GradeTooHighException;
	class GradeTooLowException;
	
	static unsigned int _minGrade;
	static unsigned int _maxGrade;

	AForm &operator=(AForm const &rhs);

public:

	AForm(void);
	AForm(std::string target, std::string name, unsigned int requiredGradeToSign, unsigned int requiredGradeToExe);
	AForm(AForm const &other);
	virtual ~AForm(void);

	std::string const &getName(void) const;
	bool getIsSigned(void) const;
	unsigned int getRequiredGradeToSign(void) const;
	unsigned int getRequiredGradeToExe(void) const;
	std::string const &getTarget(void) const;

	void setIsSigned(bool isSigned);
	void beSigned(Bureaucrat const &bureaucrat);
	void checkGrades(unsigned int requiredGradeToSign, unsigned int requiredGradeToExe) const;
	void execute(Bureaucrat const &executor) const;
	virtual void runExecution(Bureaucrat const &bureaucrat, std::string const &target) const = 0;
};

class AForm::GradeTooHighException : public std::exception
{
public:

	char const *what() const throw();
};

class AForm::GradeTooLowException : public std::exception
{
public:

	char const *what() const throw();
};

std::ostream &operator<<(std::ostream &cout, AForm const &form);

#endif
