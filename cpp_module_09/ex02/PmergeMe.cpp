/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 08:39:07 by fahmadia          #+#    #+#             */
/*   Updated: 2024/04/26 10:01:12 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

//////////////////////////////////////////////////////// Exception Class
PmergeMe::MergeException::MergeException(t_error error) : std::exception(), _error(error)
{
	return;
}

PmergeMe::MergeException::~MergeException(void) throw()
{
	return;
}

char const *PmergeMe::MergeException::what() const throw()
{
	if (this->_error == INVALID_INPUT)
		return "Invalid input!\n";
	else if (this->_error == NOT_IN_INT_RANGE)
		return "Input is not in integer range!\n";
	else
		return "Exception\n";
}

//////////////////////////////////////////////////////// Constructors
PmergeMe::PmergeMe(void) : _vector(0), _pairsVector(0), _vectors(0), _deque(0), _pairsDeque(0), _deques(0), _timeBegin(0), _timeEnd(0), _input(""), _lastNumber(0), _isNumOfElementsOdd(false), _error(NO_ERROR)
{
	return;
}

PmergeMe::PmergeMe(std::string input) : _vector(0),_pairsVector(0), _vectors(0), _deque(0), _pairsDeque(0), _deques(0), _timeBegin(0), _timeEnd(0), _input(input), _lastNumber(0), _isNumOfElementsOdd(false), _error(NO_ERROR)
{
	return;
}

PmergeMe::PmergeMe(PmergeMe const &other)
{
	(void)other;
}
PmergeMe::~PmergeMe(void)
{
	return;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &rhs)
{
	(void)rhs;
	return *this;
}

//////////////////////////////////////////////////////// Getters
std::string const &PmergeMe::getInput(void) const
{
	return this->_input;
}

std::vector<unsigned int> const &PmergeMe::getVector(void) const
{
	return this->_vector;
}

std::deque<unsigned int> const &PmergeMe::getDeque(void) const
{
	return this->_deque;
}

t_error PmergeMe::getError(void) const
{
	return this->_error;
}

//////////////////////////////////////////////////////// Parsing
void PmergeMe::parseInput(void)
{
	this->_timeBegin = std::clock();

	if (this->_input.empty() || this->_input.find_first_not_of("0123456789 ") != this->_input.npos)
	{
		this->_error = INVALID_INPUT;
		throw PmergeMe::MergeException(this->_error);
	}
	this->deleteRedundantWsp();
}

std::string &PmergeMe::deleteRedundantWsp(void)
{
	this->trim();

	std::string::iterator iterator;
	std::string::iterator iteratorEnd = this->_input.end();

	for (iterator = this->_input.begin(); iterator != iteratorEnd; iterator++)
	{
		std::string::iterator found = std::find(iterator, iteratorEnd, ' ');
		if (found != iteratorEnd && *(found + 1) == ' ')
		{
			this->_input.erase(found);
			iterator--;
		}
	}
	return this->_input;
}

std::string &PmergeMe::trim(void)
{
	this->trimLeft();
	this->trimRight();
	return this->_input;
}

std::string &PmergeMe::trimLeft(void)
{
	size_t firstNoneWspIndex = this->_input.find_first_not_of(" \t");
	if (firstNoneWspIndex != this->_input.npos)
		this->_input = this->_input.substr(firstNoneWspIndex, std::string::npos);
	return this->_input;
}

std::string &PmergeMe::trimRight(void)
{
	size_t lastNoneWspIndex = this->_input.find_last_not_of(" \t");
	if (lastNoneWspIndex != this->_input.npos)
		this->_input = this->_input.substr(0, lastNoneWspIndex + 1);
	return this->_input;
}

//////////////////////////////////////////////////////// Sorting In Vector
void PmergeMe::pushInputToVector(void)
{
	long int number;

	std::istringstream inputStream(this->_input);
	inputStream.exceptions(std::ios::failbit | std::ios::badbit);
	while (!inputStream.eof())
	{
		inputStream >> number;
		if (number > std::numeric_limits<int>::max())
		{
			this->_error = NOT_IN_INT_RANGE;
			throw PmergeMe::MergeException(NOT_IN_INT_RANGE);
		}
		else
			this->_vector.push_back(number);
	}
	return;
}

void print(unsigned int number)
{
	std:: cout << number << " ";
}

void PmergeMe::printVector(void)
{
	std::for_each(this->_vector.begin(), this->_vector.end(), ::print);
	return;
}


void PmergeMe::pushToPairsVector(void)
{
	if (this->_vector.size() <= 1)
	{
		this->_error = INVALID_INPUT;
		throw PmergeMe::MergeException(INVALID_INPUT);
	}
	std::vector<unsigned int>::iterator it;
	std::vector<unsigned int>::iterator itEnd = this->_vector.end();

	this->_isNumOfElementsOdd= this->_vector.size() % 2 == 1;

	for (it = this->_vector.begin(); it != itEnd; it++)
	{
		std::pair<unsigned int, unsigned int> pairs;
		pairs.first = *it;
		if (it + 1 != itEnd)
			pairs.second = *(++it);
		else
			continue;
		this->_pairsVector.push_back(pairs);

	}
	if (this->_isNumOfElementsOdd)
		this->_lastNumber = _vector[_vector.size() - 1];

	return;
}

void printPair(std::pair<unsigned int, unsigned int> pairs)
{
	std::cout << "<" << pairs.first << ", " << pairs.second << ">\n";
	return;
}

void PmergeMe::printPairsVector(void)
{
	std::for_each(this->_pairsVector.begin(), this->_pairsVector.end(), ::printPair);
	return;
}

void PmergeMe::sortEachPairInVector(void)
{
	std::vector<std::pair<unsigned int, unsigned int> >::iterator it;
	std::vector<std::pair<unsigned int, unsigned int> >::iterator itEnd = this->_pairsVector.end();
	
	for (it = this->_pairsVector.begin(); it != itEnd; it++)
	{
		if (it->first < it->second)
		{
			unsigned int temp = it->first;
			it->first = it->second;
			it->second = temp;
		}
	}
	return;
}

void PmergeMe::sortPairsVectorRecursive(std::vector<std::pair<unsigned int, unsigned int> >::iterator i) {
    if (i == this->_pairsVector.end() - 1)
        return;
    if (i->first > (i + 1)->first) {
			std::swap(*i, *(i + 1));       
    }
    sortPairsVectorRecursive(i + 1);
		if (i != this->_pairsVector.begin() && (i - 1)->first > i->first) {
			std::swap(*(i - 1), *i);
			sortPairsVectorRecursive(i);
		}
		return;
}

void PmergeMe::sortPairsVector() {
	sortPairsVectorRecursive(this->_pairsVector.begin());
}

void PmergeMe::pushSortedFirstValuesOfPairsToVector(void)
{
	this->_vector.clear();
	this->_vector.push_back(this->_pairsVector[0].second);

	std::vector<std::pair<unsigned int, unsigned int> >::iterator it;
	std::vector<std::pair<unsigned int, unsigned int> >::iterator itEnd = this->_pairsVector.end();

	for (it = this->_pairsVector.begin(); it != itEnd; it++)
		this->_vector.push_back(it->first);
}

void PmergeMe::changePairsVectorFirstValueToIndex(void)
{
	this->_pairsVector.erase(this->_pairsVector.begin());

	std::vector<std::pair<unsigned int, unsigned int> >::iterator it;
	std::vector<std::pair<unsigned int, unsigned int> >::iterator itEnd = this->_pairsVector.end();

	int i = 3;
	for (it = this->_pairsVector.begin(); it != itEnd; it++)
	{
		it->first = i;
		i++;
	}

	if (this->_isNumOfElementsOdd)
		this->_pairsVector.push_back(std::pair<unsigned int, unsigned int>(i, this->_lastNumber));
	return;
}

void copyToGroupVectors(std::vector<std::pair<unsigned int, unsigned int> > const &indexPairsVector, int groupSize, std::vector<std::pair<unsigned int, unsigned int> > &group)
{
	for (int i = 0; i < groupSize && static_cast<size_t>(i) < indexPairsVector.size(); i++)
	{
		group.push_back(indexPairsVector[i]);
	}
	
}

std::vector<std::vector<std::pair<unsigned int, unsigned int> > > PmergeMe::createGroupsOfVectors(void)
{
	std::vector<std::vector<std::pair<unsigned int, unsigned int> > > vectors;
	int i = 1;
	int initialGroupSize = 0;
	int groupSize = 0;

	std::vector<std::pair<unsigned int, unsigned int> >::iterator itBegin = this->_pairsVector.begin();
	std::vector<std::pair<unsigned int, unsigned int> >::iterator itEnd = this->_pairsVector.end();

	while (itBegin < itEnd)
	{
		std::vector<std::pair<unsigned int, unsigned int> > group;
		groupSize = std::pow(2, i) - initialGroupSize;
		initialGroupSize = groupSize;
		copyToGroupVectors(this->_pairsVector, groupSize, group);
		vectors.push_back(group);
	
		if (itBegin + groupSize > itEnd || static_cast<size_t>(groupSize) > this->_pairsVector.size())
		{
			this->_pairsVector.clear();
			break;
		}
		this->_pairsVector.erase(itBegin, itBegin + groupSize);
		i++;
	}
	this->_vectors = vectors;
	return vectors;
}

void PmergeMe::printVectorOfVectors(void)
{
	std::vector<std::vector<std::pair<unsigned int, unsigned int> > >::iterator iterator;
	std::vector<std::vector<std::pair<unsigned int, unsigned int> > >::iterator iteratorEnd = this->_vectors.end();

	std::cout << "*********" << std::endl;
	for (iterator = this->_vectors.begin(); iterator != iteratorEnd; iterator++)
	{
		std::vector<std::pair<unsigned int, unsigned int> >::iterator nestedIt;
		std::vector<std::pair<unsigned int, unsigned int> >::iterator nestedItEnd = iterator->end();

		for (nestedIt = iterator->begin(); nestedIt != nestedItEnd; nestedIt++)
		{
			std::cout << "<" << nestedIt->first << ", " << nestedIt->second << ">" << std::endl;
		}
		std::cout << "*********" << std::endl;
	}
}

void PmergeMe::printVectorOfVectorsReverse(void)
{
	std::vector<std::vector<std::pair<unsigned int, unsigned int> > >::iterator iterator;
	std::vector<std::vector<std::pair<unsigned int, unsigned int> > >::iterator iteratorEnd = this->_vectors.end();

	for (iterator = this->_vectors.begin(); iterator != iteratorEnd; iterator++)
	{
		std::vector<std::pair<unsigned int, unsigned int> >::reverse_iterator nestedReveresIt;
		std::vector<std::pair<unsigned int, unsigned int> >::reverse_iterator nestedReveresItEnd = iterator->rend();
		for (nestedReveresIt = iterator->rbegin(); nestedReveresIt != nestedReveresItEnd; nestedReveresIt++)
		{
			std::cout << "<" << nestedReveresIt->first << ", " << nestedReveresIt->second << ">" << std::endl;
		}
		std::cout << "*********" << std::endl;
	}
	return;
}

void PmergeMe::binarySearchInVector(void)
{
	std::vector<std::vector<std::pair<unsigned int, unsigned int> > >::iterator iterator;
	std::vector<std::vector<std::pair<unsigned int, unsigned int> > >::iterator iteratorEnd = this->_vectors.end();

	for (iterator = this->_vectors.begin(); iterator != iteratorEnd; iterator++)
	{
		std::vector<std::pair<unsigned int, unsigned int> >::reverse_iterator nestedRevereseIt;
		std::vector<std::pair<unsigned int, unsigned int> >::reverse_iterator nestedRevereseItEnd = iterator->rend();
		for (nestedRevereseIt = iterator->rbegin(); nestedRevereseIt != nestedRevereseItEnd; nestedRevereseIt++)
		{
			this->insertToVector(&(*nestedRevereseIt));
		}
	}
	this->_timeEnd = std::clock();
	return;
}

void increaseIndexInGroupVectors(std::pair<unsigned int, unsigned int> &currentPair)
{
	currentPair.first++;
}

void getCurrentGroupVector(std::vector<std::pair<unsigned int, unsigned int> > &currentGroup)
{
	std::for_each(currentGroup.begin(), currentGroup.end(), increaseIndexInGroupVectors);
}

void PmergeMe::insertToVector(std::pair<unsigned int, unsigned int> const *indexValuePair)
{
	unsigned int index = indexValuePair->first - 1;
	unsigned int number = indexValuePair->second;
	unsigned int indexOfInsertion = findIndexToInsertToVector(index, index / 2, number);
	this->_vector.insert(this->_vector.begin() + indexOfInsertion, number);
	std::for_each(this->_vectors.begin(), this->_vectors.end(), getCurrentGroupVector);
}

unsigned int PmergeMe::findIndexToInsertToVector(unsigned int initialIndex, unsigned int startIndex, unsigned int number)
{
	if (startIndex == 0 || startIndex >= initialIndex || number == this->_vector[startIndex])
		return startIndex;

	if (number < this->_vector[startIndex] && (number > this->_vector[startIndex - 1]))
		return startIndex;
	else if (number < this->_vector[startIndex])
		return (findIndexToInsertToVector(startIndex, startIndex / 2, number));
	else 
		return (findIndexToInsertToVector(initialIndex, (initialIndex + startIndex + 1) / 2, number));
}

void PmergeMe::printVectorTimeSpan(void)
{
	std::cout << "Time to process a range of " << this->_vector.size() << " elements with std::vector<unsigned int> : " << (this->_timeEnd - this->_timeBegin) / 1000.0 << " ms" << std::endl;
	return;
}

int PmergeMe::isVectorSorted(void)
{
	std::vector<unsigned int>::iterator iterator;
	std::vector<unsigned int>::iterator iteratorEnd = this->_vector.end();

	for (iterator = this->_vector.begin(); iterator != iteratorEnd - 1; iterator++)
	{
		if (*iterator > *(iterator + 1))
		{
			std::cerr << "NOT SORTED\n";
			std::cout << *iterator << std::endl;
			return 1;
		}
	}
	std::cout << "SORTED\n";
	return 0;
}

//////////////////////////////////////////////////////// Sorting In Deque
void PmergeMe::pushInputToDeque(void)
{
	long int number;

	std::istringstream inputStream(this->_input);
	inputStream.exceptions(std::ios::failbit | std::ios::badbit);
	while (!inputStream.eof())
	{
		inputStream >> number;
		if (number > std::numeric_limits<int>::max())
		{
			this->_error = NOT_IN_INT_RANGE;
			throw PmergeMe::MergeException(NOT_IN_INT_RANGE);
		}
		else
			this->_deque.push_back(number);
	}
	return;
}

void PmergeMe::printDeque(void)
{
	std::for_each(this->_deque.begin(), this->_deque.end(), ::print);
	return;
}

void PmergeMe::pushToPairsDeque(void)
{
	if (this->_deque.size() <= 1)
	{
		this->_error = INVALID_INPUT;
		throw PmergeMe::MergeException(INVALID_INPUT);
	}
	std::deque<unsigned int>::iterator it;
	std::deque<unsigned int>::iterator itEnd = this->_deque.end();

	this->_isNumOfElementsOdd= this->_deque.size() % 2 == 1;

	for (it = this->_deque.begin(); it != itEnd; it++)
	{
		std::pair<unsigned int, unsigned int> pairs;
		pairs.first = *it;
		if (it + 1 != itEnd)
			pairs.second = *(++it);
		else
			continue;
		this->_pairsDeque.push_back(pairs);

	}
	if (this->_isNumOfElementsOdd)
		this->_lastNumber = _deque[_deque.size() - 1];
	return;
}

void PmergeMe::printPairsDeque(void)
{
	std::for_each(this->_pairsDeque.begin(), this->_pairsDeque.end(), ::printPair);
	return;
}

void PmergeMe::sortEachPairInDeque(void)
{
	std::deque<std::pair<unsigned int, unsigned int> >::iterator it;
	std::deque<std::pair<unsigned int, unsigned int> >::iterator itEnd = this->_pairsDeque.end();
	
	for (it = this->_pairsDeque.begin(); it != itEnd; it++)
	{
		if (it->first < it->second)
		{
			unsigned int temp = it->first;
			it->first = it->second;
			it->second = temp;
		}
	}
	return;
}

void PmergeMe::sortPairsDeque(void)
{
	this->sortPairsDequeRecursive(this->_pairsDeque.begin());
	return;
}
void PmergeMe::sortPairsDequeRecursive(std::deque<std::pair<unsigned int, unsigned int> >::iterator i)
{
	if (i == this->_pairsDeque.end() - 1)
		return;
	
	if (i + 1 != this->_pairsDeque.end() && i->first > (i + 1)->first)
			std::swap(*i, *(i + 1));

	sortPairsDequeRecursive(i + 1);

	if (i != this->_pairsDeque.begin() && i->first < (i - 1)->first)
	{
		std::swap(*i, *(i - 1));
		sortPairsDequeRecursive(i);
	}
	return;
}

void PmergeMe::pushSortedFirstValuesOfPairsToDeque(void)
{
	this->_deque.clear();
	this->_deque.push_back(this->_pairsDeque[0].second);

	std::deque<std::pair<unsigned int, unsigned int> >::iterator it;
	std::deque<std::pair<unsigned int, unsigned int> >::iterator itEnd = this->_pairsDeque.end();

	for (it = this->_pairsDeque.begin(); it != itEnd; it++)
		this->_deque.push_back(it->first);
}

void PmergeMe::changePairsDequeFirstValueToIndex(void)
{
	this->_pairsDeque.erase(this->_pairsDeque.begin());

	std::deque<std::pair<unsigned int, unsigned int> >::iterator it;
	std::deque<std::pair<unsigned int, unsigned int> >::iterator itEnd = this->_pairsDeque.end();

	int i = 3;
	for (it = this->_pairsDeque.begin(); it != itEnd; it++)
	{
		it->first = i;
		i++;
	}

	if (this->_isNumOfElementsOdd)
		this->_pairsDeque.push_back(std::pair<unsigned int, unsigned int>(i, this->_lastNumber));
	return;
}

void copyToGroupDeques(std::deque<std::pair<unsigned int, unsigned int> > const &indexPairsDeque, int groupSize, std::deque<std::pair<unsigned int, unsigned int> > &group)
{
	for (int i = 0; i < groupSize && static_cast<size_t>(i) < indexPairsDeque.size(); i++)
	{
		group.push_back(indexPairsDeque[i]);
	}
	
}

std::deque<std::deque<std::pair<unsigned int, unsigned int> > > PmergeMe::createGroupsOfDeques(void)
{
	std::deque<std::deque<std::pair<unsigned int, unsigned int> > > deques;
	int i = 1;
	int initialGroupSize = 0;
	int groupSize = 0;

	std::deque<std::pair<unsigned int, unsigned int> >::iterator itBegin = this->_pairsDeque.begin();
	std::deque<std::pair<unsigned int, unsigned int> >::iterator itEnd = this->_pairsDeque.end();

	while (itBegin < itEnd)
	{
		std::deque<std::pair<unsigned int, unsigned int> > group;
		groupSize = std::pow(2, i) - initialGroupSize;
		initialGroupSize = groupSize;
		copyToGroupDeques(this->_pairsDeque, groupSize, group);
		deques.push_back(group);
		if (itBegin + groupSize > itEnd || static_cast<size_t>(groupSize) > this->_pairsDeque.size())
		{
			this->_pairsDeque.clear();
			break;
		}
		this->_pairsDeque.erase(itBegin, itBegin + groupSize);
		
		i++;
	}
	this->_deques = deques;
	return deques;
}

void PmergeMe::printDequeOfDeques(void)
{
	std::deque<std::deque<std::pair<unsigned int, unsigned int> > >::iterator iterator;
	std::deque<std::deque<std::pair<unsigned int, unsigned int> > >::iterator iteratorEnd = this->_deques.end();

	std::cout << "*********" << std::endl;
	for (iterator = this->_deques.begin(); iterator != iteratorEnd; iterator++)
	{
		std::deque<std::pair<unsigned int, unsigned int> >::iterator nestedIt;
		std::deque<std::pair<unsigned int, unsigned int> >::iterator nestedItEnd = iterator->end();

		for (nestedIt = iterator->begin(); nestedIt != nestedItEnd; nestedIt++)
		{
			std::cout << "<" << nestedIt->first << ", " << nestedIt->second << ">" << std::endl;
		}
		std::cout << "*********" << std::endl;
	}
}

void PmergeMe::printDequeOfDequesReverse(void)
{
	std::deque<std::deque<std::pair<unsigned int, unsigned int> > >::iterator iterator;
	std::deque<std::deque<std::pair<unsigned int, unsigned int> > >::iterator iteratorEnd = this->_deques.end();

	for (iterator = this->_deques.begin(); iterator != iteratorEnd; iterator++)
	{
		std::deque<std::pair<unsigned int, unsigned int> >::reverse_iterator nestedReveresIt;
		std::deque<std::pair<unsigned int, unsigned int> >::reverse_iterator nestedReveresItEnd = iterator->rend();
		for (nestedReveresIt = iterator->rbegin(); nestedReveresIt != nestedReveresItEnd; nestedReveresIt++)
		{
			std::cout << "<" << nestedReveresIt->first << ", " << nestedReveresIt->second << ">" << std::endl;
		}
		std::cout << "*********" << std::endl;
	}
	
	return;
}

void PmergeMe::binarySearchInDeque(void)
{
	std::deque<std::deque<std::pair<unsigned int, unsigned int> > >::iterator iterator;
	std::deque<std::deque<std::pair<unsigned int, unsigned int> > >::iterator iteratorEnd = this->_deques.end();

	for (iterator = this->_deques.begin(); iterator != iteratorEnd; iterator++)
	{
		std::deque<std::pair<unsigned int, unsigned int> >::reverse_iterator nestedRevereseIt;
		std::deque<std::pair<unsigned int, unsigned int> >::reverse_iterator nestedRevereseItEnd = iterator->rend();
		for (nestedRevereseIt = iterator->rbegin(); nestedRevereseIt != nestedRevereseItEnd; nestedRevereseIt++)
		{
			this->insertToDeque(&(*nestedRevereseIt));
		}
	}
	this->_timeEnd = std::clock();
	return;
}


void increaseIndexInGroupDeques(std::pair<unsigned int, unsigned int> &currentPair)
{
	currentPair.first++;
}

void getCurrentGroupDeque(std::deque<std::pair<unsigned int, unsigned int> > &currentGroup)
{
	std::for_each(currentGroup.begin(), currentGroup.end(), increaseIndexInGroupDeques);
}

void PmergeMe::insertToDeque(std::pair<unsigned int, unsigned int> const *indexValuePair)
{
	unsigned int index = indexValuePair->first - 1;
	unsigned int number = indexValuePair->second;
	unsigned int indexOfInsertion = findIndexToInsertToDeque(index, index / 2, number);
	this->_deque.insert(this->_deque.begin() + indexOfInsertion, number);
	std::for_each(this->_deques.begin(), this->_deques.end(), getCurrentGroupDeque);
}

unsigned int PmergeMe::findIndexToInsertToDeque(unsigned int initialIndex, unsigned int startIndex, unsigned int number)
{		
	if (startIndex == 0 || startIndex >= initialIndex || number == this->_deque[startIndex])
		return startIndex;

	if (number < this->_deque[startIndex] && (number > this->_deque[startIndex - 1]))
		return startIndex;
	else if (number < this->_deque[startIndex])
		return (this->findIndexToInsertToDeque(startIndex, startIndex / 2, number));
	else 
		return (this->findIndexToInsertToDeque(initialIndex, (initialIndex + startIndex + 1) / 2, number));
}

void PmergeMe::printDequeTimeSpan(void)
{
	std::cout << "Time to process a range of " << this->_deque.size() << " elements with std::_deque<unsigned int> : " << static_cast<float>(this->_timeEnd - this->_timeBegin) / 1000 << " ms" << std::endl;
	return;
}

int PmergeMe::isDequeSorted(void)
{
	std::deque<unsigned int>::iterator iterator;
	std::deque<unsigned int>::iterator iteratorEnd = this->_deque.end();

	for (iterator = this->_deque.begin(); iterator != iteratorEnd - 1; iterator++)
	{
		if (*iterator > *(iterator + 1))
		{
			std::cerr << "NOT SORTED\n";
			return 1;
		}
	}
	std::cout << "SORTED\n";
	return 0;
}
