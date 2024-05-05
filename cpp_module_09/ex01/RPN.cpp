/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:23:13 by fahmadia          #+#    #+#             */
/*   Updated: 2024/04/27 10:53:15 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

std::stack<float> RPN::_container;

RPN::RPN(void)
{
	return;
}

RPN::RPN(RPN const &other)
{
	(void)other;
}

RPN::~RPN(void)
{
	return;
}

RPN &RPN::operator=(RPN const &rhs)
{
	(void)rhs;
	return *this;
}

void RPN::print(void)
{
	for (std::stack<float> copy = RPN::_container; !copy.empty(); copy.pop())
	{
		std::cout << "|  ";
		std::cout << copy.top();
		std::cout << "  |\n";
		std::cout << " -----\n";
	}
}

void RPN::pushToContainer(char currentChar)
{
	int currentNumber = currentChar - '0';
	RPN::_container.push(currentNumber);
	return;
}

float RPN::runOperation(float leftOperand, float rightOperand, t_operator currentOperator)
{
	switch (currentOperator)
	{
		case ADDITION:
			return static_cast<float>(leftOperand + rightOperand);
		case SUBTRACTION:
			return static_cast<float>(leftOperand - rightOperand);
		case MULTIPLICATION:
			return static_cast<float>(leftOperand * rightOperand);
		case DIVISION:
			return static_cast<float>(leftOperand / rightOperand);
		default:
			return 0;
	}
}

bool RPN::doOperation(t_operator currentOperator)
{
	float operands[2];
	(void)currentOperator;
	if (!RPN::popFromContainer(operands))
		return false;
	float leftOperand = operands[0];
	float rightOperand = operands[1];
	float result = runOperation(leftOperand, rightOperand, currentOperator);
	std::cout << leftOperand << (currentOperator == ADDITION ? " + " : (currentOperator == SUBTRACTION ? " - " : (currentOperator == MULTIPLICATION ? " * " : " / "))) << rightOperand << " = " << result << std::endl;
	RPN::_container.push(result);
	return true;
}

bool RPN::popFromContainer(float (&operands)[2])
{
	if (RPN::_container.size() >= 2)
	{
		float rightOperand = _container.top();
		_container.pop();
		float leftOperand = _container.top();
		_container.pop();
		operands[0] = leftOperand;
		operands[1] = rightOperand;
	}
	else
	{
		std::cerr << "Operator needs two operands!\n";
		return false;
	}
	return true;
}

t_operator RPN::getOperator(char currentChar)
{
	switch (currentChar)
	{
		case '+':
			return ADDITION;
		case '-':
			return SUBTRACTION;
		case '*':
			return MULTIPLICATION;
		case '/':
			return DIVISION;
		default:
			return INVALID;
	}
}

bool RPN::calc(std::string input)
{
	for (size_t i = 0; i < input.length(); i++)
	{
		if (isdigit(input[i]))
			pushToContainer(input[i]);
		else
		{
			t_operator currentOperator = RPN::getOperator(input[i]);
			if (!RPN::doOperation(currentOperator))
				return false;
		}
	}
	if (RPN::_container.size() == 1)
		std::cout << "result = " << _container.top() << std::endl;
	else
	{
		std::cout << "More than one operand is letf in stack, but no more operator is available!\n";
		return false;
	}

	std::cout << std::setprecision(2) << std::fixed << RPN::_container.top() << std::endl;
	return true;
}
