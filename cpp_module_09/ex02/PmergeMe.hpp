/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 08:39:20 by fahmadia          #+#    #+#             */
/*   Updated: 2024/04/26 10:01:55 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_HPP
# define PMERGE_ME_HPP

# include <vector>
# include <deque>
# include <string>
# include <iostream>
# include <algorithm>
# include <typeinfo>
# include <stdexcept>
# include <sstream>
# include <limits>
# include <cmath>
# include <ctime>

typedef enum e_error
{
	NO_ERROR = 0,
	INVALID_INPUT = 1,
	NOT_IN_INT_RANGE
} t_error;

class PmergeMe
{
	public:
		PmergeMe(std::string input);
		~PmergeMe(void);

		std::string const &getInput(void) const;
		std::vector<unsigned int> const &getVector(void) const;
		std::deque<unsigned int> const &getDeque(void) const;
		t_error getError(void) const;
		
		void parseInput(void);

		void pushInputToVector(void);
		void printVector(void);
		void pushToPairsVector(void);
		void printPairsVector(void);
		void sortEachPairInVector(void);
		void sortPairsVector();
		void sortPairsVectorRecursive(std::vector<std::pair<unsigned int, unsigned int> >::iterator i);
		void pushSortedFirstValuesOfPairsToVector(void);
		void changePairsVectorFirstValueToIndex(void);
		std::vector<std::vector<std::pair<unsigned int, unsigned int> > > createGroupsOfVectors(void);
		void printVectorOfVectors(void);
		void printVectorOfVectorsReverse(void);
		void binarySearchInVector(void);
		void printVectorTimeSpan(void);
		int isVectorSorted(void);

		void pushInputToDeque(void);
		void printDeque(void);
		void pushToPairsDeque(void);
		void printPairsDeque(void);
		void sortEachPairInDeque(void);
		void sortPairsDeque(void);
		void sortPairsDequeRecursive(std::deque<std::pair<unsigned int, unsigned int> >::iterator i);
		void pushSortedFirstValuesOfPairsToDeque(void);
		void changePairsDequeFirstValueToIndex(void);
		std::deque<std::deque<std::pair<unsigned int, unsigned int> > > createGroupsOfDeques(void);
		void printDequeOfDeques(void);
		void printDequeOfDequesReverse(void);
		void binarySearchInDeque(void);
		void printDequeTimeSpan(void);
		int isDequeSorted(void);
		
	private:
		PmergeMe(void);
		PmergeMe(PmergeMe const &other);
		PmergeMe &operator=(PmergeMe const &rhs);

		std::string &deleteRedundantWsp(void);
		std::string &trim(void);
		std::string &trimLeft(void);
		std::string &trimRight(void);
		
		void insertToVector(std::pair<unsigned int, unsigned int> const *indexValuePair);
		unsigned int findIndexToInsertToVector(unsigned int initialIndex, unsigned int startIndex, unsigned int number);

		void insertToDeque(std::pair<unsigned int, unsigned int> const *indexValuePair);
		unsigned int findIndexToInsertToDeque(unsigned int initialIndex, unsigned int startIndex, unsigned int number);

		std::vector<unsigned int> _vector;
		std::vector<std::pair<unsigned int, unsigned int> > _pairsVector;
		std::vector<std::vector<std::pair<unsigned int, unsigned int> > > _vectors;

		std::deque<unsigned int> _deque;
		std::deque<std::pair<unsigned int, unsigned int> > _pairsDeque;
		std::deque<std::deque<std::pair<unsigned int, unsigned int> > > _deques;

		std::clock_t _timeBegin;
		std::clock_t _timeEnd;
		std::string _input;
		unsigned int _lastNumber;
		bool _isNumOfElementsOdd;
		t_error _error;
		class MergeException;
};

class PmergeMe::MergeException : public std::exception
{
	public:
		MergeException(t_error error);
		~MergeException(void) throw();
		char const *what() const throw();

	private:
		t_error _error;
};

#endif
