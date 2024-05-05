/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 09:51:24 by fahmadia          #+#    #+#             */
/*   Updated: 2024/01/16 18:03:55 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void )
{
	return  Account::_nbAccounts;
}

int	Account::getTotalAmount( void )
{
	return Account::_totalAmount;
}

int	Account::getNbDeposits( void )
{
	return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals( void )
{
	return Account::_totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout << "accounts:"<< getNbAccounts();
	std::cout << ";total:"<< getTotalAmount();
	std::cout << ";deposits:"<< getNbDeposits();
	std::cout << ";withdrawals:"<< getNbWithdrawals() << std::endl;
}

Account::Account( int initial_deposit ) : _amount(initial_deposit)
{
	_displayTimestamp();
	std::cout << "index:" << Account::_nbAccounts;
	std::cout << ";amount:" << _amount << ";created" << std::endl;
	this->_accountIndex = _nbAccounts;
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
}
Account::~Account( void )
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount << ";closed" << std::endl;
	Account::_nbAccounts--;
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount;
	std::cout << ";deposit:" << deposit;
	std::cout << ";amount:" << this->_amount + deposit;
	std::cout << ";nb_deposits:" << ++(this->_nbDeposits) << std::endl;
	this->_amount += deposit;
	Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
		std::cout << "index:" << this->_accountIndex;	
		std::cout << ";p_amount:" << this->_amount;
	if (this->_amount - withdrawal >= 0)
	{
		std::cout << ";withdrawal:" << withdrawal;
		std::cout << ";amount:" << this->_amount - withdrawal;
		std::cout << ";nb_withdrawals:" << ++(this->_nbWithdrawals) << std::endl;
		this->_amount -= withdrawal;
		_totalNbWithdrawals++;
		_totalAmount -= withdrawal;
		return true;
	}
	else
	{
		std::cout << ";withdrawal:" << "refused" << std::endl;
		return false;
	}
}

int		Account::checkAmount( void ) const
{
	return this->_amount;
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";deposits:" << this->_nbDeposits;
	std::cout << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void )
{
	std::time_t now = time(nullptr);
	struct tm *localTime = localtime(&now);
	if (!localTime)
		std::cout << "Error in getting time!";
	char buffer[80];
	strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", localTime);
	std::cout << "[" << buffer << "] ";
}
