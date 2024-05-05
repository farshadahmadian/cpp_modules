/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:20:47 by fahmadia          #+#    #+#             */
/*   Updated: 2024/04/17 10:57:29 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <string>
#include <iostream>
#include <algorithm>
#include <stack>
#include <iterator>
#include <iomanip>

typedef enum e_operator
{
	INVALID = -1,
	ADDITION = '+',
	SUBTRACTION = '-',
	MULTIPLICATION = '*',
	DIVISION = '/',
} t_operator;

class RPN
{
	private:
		RPN(void);
		RPN(RPN const &other);
		~RPN(void);
		RPN &operator=(RPN const &rhs);

		static void pushToContainer(char currentChar);
		static bool popFromContainer(float (&operands)[2]);
		static void print(void);
		static t_operator getOperator(char currentChar);
		static bool doOperation(t_operator currentOperator);
		static float runOperation(float leftOperand, float rightOperand, t_operator currentOperator);

		static std::stack<float> _container;

	public:
		static bool calc(std::string input);
};

typedef enum e_error
{
	INVALID_ARGUMENTS_NUM,
	INVALID_INPUT,
} t_error;

#endif
