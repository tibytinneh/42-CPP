#include "Account.hpp"

#include <iostream>
#include <iomanip>
#include <ctime> // time_t, struct tm, time, localtime, strftime

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) : _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
	_accountIndex = _nbAccounts++;
	_totalAmount += initial_deposit;
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "created" << std::endl;	
} 

Account::~Account() {
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed" << std::endl;
}

int Account::getNbAccounts() { return _nbAccounts; }
int Account::getTotalAmount() { return _totalAmount; }
int Account::getNbDeposits() { return _totalNbDeposits; }
int Account::getNbWithdrawals() { return _totalNbWithdrawals; }


void Account::displayAccountsInfos() {
	Account::_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";";
    std::cout << "total:" << _totalAmount << ";";
    std::cout << "deposits:" << _totalNbDeposits << ";";
    std::cout << "withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit) {
	Account::_displayTimestamp();
	int old_amount= _amount;
	_nbDeposits = 0;
	if (deposit > 0){
		_amount += deposit;
		_nbDeposits++;
		_totalNbDeposits++;
		_totalAmount += deposit;
	}
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << old_amount << ";";
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
Account::_displayTimestamp();
int old_amount = _amount;
std::cout << "index:" << _accountIndex << ";";
std::cout << "p_amount:" << old_amount << ";";
if (withdrawal > _amount) {
		std::cout << ";withdrawal:refused" << std::endl;
        return false;
}
_amount -= withdrawal;
_nbWithdrawals++;
_totalNbWithdrawals++;
_totalAmount -= withdrawal;
std::cout << "withdrawal:" << withdrawal << ";";
std::cout << "amount:" << _amount << ";";
std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
	return true;
}

//this is not used
int Account::checkAmount() const { std::cout << "CHECKAMOUNT" << std::endl; return _amount; }

void Account::displayStatus() const {
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
    std::cout << "deposits:" << _nbDeposits << ";";
    std::cout << "withdrawals:" << _nbWithdrawals;
    std::cout << std::endl;
}

/**
 * @brief Display timestamp
 * time(0)	| get epoch time 
 * 
 * localtime(&now)	| converts to local time, gives tm structure
 *
 *  std::strftime	| formats date and time to specified format
 * 
 * [%Y] YYYY | [%m] MM | [%d] dd | [%H] HH | [%M] MM | [%S] SS
*/
void Account::_displayTimestamp() {
	std::time_t now = std::time(0);
	struct std::tm *timeinfo = std::localtime(&now);
	char buffer[20];
	std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", timeinfo); //formats time to specified format
	std::cout << buffer << " ";

}