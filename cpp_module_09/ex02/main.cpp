/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 08:38:51 by fahmadia          #+#    #+#             */
/*   Updated: 2024/04/26 10:05:53 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::string convertInputToString(char **input)
{
	std::string str = "";
	bool firstInput = true;
	while (*input)
	{
		std::string temp = static_cast<std::string>(*input);
		if (!firstInput)
			str += " " + temp;
		else
		{
			str += temp;
			firstInput = false;
		}
		input++;
	}
	return str;
}

void useVector(char **argv, t_error &exitCode)
{
	std::string input = convertInputToString(argv);
	PmergeMe merge(input);
	std::vector<std::vector<std::pair<unsigned int, unsigned int> > > vectors;
	try
	{
		merge.parseInput();
		merge.pushInputToVector();
		std::cout << "Before: ";
		merge.printVector();
		std::cout << "\n";
		// std::cout << "\n--------------------------- Pairs Vector Before Sorting\n";
		merge.pushToPairsVector();
		// merge.printPairsVector();

		// std::cout << "--------------------------- Pairs Vector After Internal Sorting\n";
		merge.sortEachPairInVector();
		// merge.printPairsVector();

		// std::cout << "--------------------------- Pairs Vector After External Sorting\n";
		merge.sortPairsVector();
		// merge.printPairsVector();

		// std::cout << "--------------------------- Vector After Sorting the First Values of the Pairs\n";
		merge.pushSortedFirstValuesOfPairsToVector();
		// merge.printVector();

		// std::cout << "\n--------------------------- Pairs Vector After Index\n";
		merge.changePairsVectorFirstValueToIndex();
		// merge.printPairsVector();

		// std::cout << "--------------------------- Vector of Vectors\n";
		vectors = merge.createGroupsOfVectors();
		// merge.printVectorOfVectors();
		// std::cout << "--------------------------- Vector of Vectors in Reversed Order\n";
		// merge.printVectorOfVectorsReverse();
		merge.binarySearchInVector();
		std::cout << "After: ";
		merge.printVector();
		std::cout << "\n";
		merge.printVectorTimeSpan();

		// std::cout << "\n--------------------------- Result\n";
		// merge.isVectorSorted();
	}
	catch(std::exception &exception)
	{
		std::cerr << exception.what();
	}
	exitCode = merge.getError();
}

void useDeque(char **argv, t_error &exitCode)
{
	std::string input = convertInputToString(argv);
	PmergeMe merge(input);
	std::deque<std::deque<std::pair<unsigned int, unsigned int> > > deques;
	try
	{
		merge.parseInput();
		merge.pushInputToDeque();
		std::cout << "Before: ";
		merge.printDeque();
		std::cout << "\n";

		// std::cout << "\n--------------------------- Pairs Deque Before Sorting\n";
		merge.pushToPairsDeque();
		// merge.printPairsDeque();

		// std::cout << "--------------------------- Pairs Deque After Internal Sorting\n";
		merge.sortEachPairInDeque();
		// merge.printPairsDeque();
	
		// std::cout << "--------------------------- Pairs Deque After External Sorting\n";
		merge.sortPairsDeque();
		// merge.printPairsDeque();

		// std::cout << "--------------------------- Deque After Sorting the First Values of the Pairs\n";
		merge.pushSortedFirstValuesOfPairsToDeque();
		// merge.printDeque();

		// std::cout << "\n--------------------------- Pairs Deque After Index\n";
		merge.changePairsDequeFirstValueToIndex();
		// merge.printPairsDeque();

		// std::cout << "--------------------------- Deque of Deques\n";
		deques = merge.createGroupsOfDeques();
		// merge.printDequeOfDeques();
		// std::cout << "--------------------------- Deque of Deques in Reversed Order\n";
		// merge.printDequeOfDequesReverse();
		merge.binarySearchInDeque();
		std::cout << "After: ";
		merge.printDeque();
		std::cout << "\n";
		merge.printDequeTimeSpan();
		// std::cout << "\n--------------------------- Result\n";
		// merge.isDequeSorted();
	}
	catch(std::exception &exception)
	{
		std::cerr << exception.what();
	}
	exitCode = merge.getError();
}

int main(int argc, char **argv)
{
	t_error exitCode = NO_ERROR;
	
	if (argc <= 1)
	{
		std::cerr << "No arguments!" << std::endl;
		return INVALID_INPUT;
	}
	argv++;
	useVector(argv, exitCode);
	useDeque(argv, exitCode);

	return static_cast<int>(exitCode);
}
