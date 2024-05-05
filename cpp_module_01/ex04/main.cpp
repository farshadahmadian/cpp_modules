/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 15:55:16 by fahmadia          #+#    #+#             */
/*   Updated: 2024/02/26 16:54:25 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>
#include "copy.hpp"

void findAndReplace(std::ifstream &readFile, std::ofstream &writeFile, std::string s1, std::string s2)
{
	std::string line;
	if (s1.empty())
		return;
	while (getline(readFile, line))
	{
		size_t result = line.find(s1, 0);
		while (result != std::string::npos)
		{
			line.erase(result, s1.size());
			line.insert(result, s2);
			result += s2.size();
			result = line.find(s1, result);
		}
		writeFile << line << std::endl;
	}
}

void printFileNotOpened(std::string fileName)
{
	std::cerr << "File " << fileName << " not opened!" << std::endl;
}

bool createAndOpenAnotherFile(std::ifstream &readFile, std::string otherFileName, std::string s1, std::string s2)
{
	std::ofstream writeFile(otherFileName.c_str(), std::ios::in | std::ios::out | std::ios::trunc);
	if (writeFile.is_open())
		findAndReplace(readFile, writeFile, s1, s2);
	else
	{
		printFileNotOpened(otherFileName);
		return false;
	}
	return true;
}

bool openFileAndCopy(std::string fileName, std::string s1, std::string s2)
{
	std::string otherFileName = fileName + ".replace";
	std::ifstream readFile;
	readFile.open(fileName.c_str(), std::ios::in);
	std::string line;
	if (readFile.is_open())
	{
		createAndOpenAnotherFile(readFile, otherFileName, s1, s2);
		readFile.close();
	}
	else
	{
		printFileNotOpened(fileName);
		return false;
	}
	return true;
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Wrong Arguments!" << std::endl;
		return WrongArguments;
	}

	std::string readFileName = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if (!openFileAndCopy(readFileName, s1, s2))
	{
		return FileNotOpened;
	}
	return 0;
}
