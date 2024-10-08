
#include "account.hpp"

#include <iostream>
#include <iomanip>
#include <ctime>


// 	typedef Account		t;

// 	static int	getNbAccounts( void );
// 	static int	getTotalAmount( void );
// 	static int	getNbDeposits( void );
// 	static int	getNbWithdrawals( void );
// 	static void	displayAccountsInfos( void );

// 	Account( int initial_deposit );
// 	~Account( void );

// 	void	makeDeposit( int deposit );
// 	bool	makeWithdrawal( int withdrawal );
// 	int		checkAmount( void ) const;
// 	void	displayStatus( void ) const;


// private:

// 	static int	_nbAccounts;
// 	static int	_totalAmount;
// 	static int	_totalNbDeposits;
// 	static int	_totalNbWithdrawals;

// 	static void	_displayTimestamp( void );

// 	int				_accountIndex;
// 	int				_amount;
// 	int				_nbDeposits;
// 	int				_nbWithdrawals;

// 	Account( void );



//gotta init static var, line by line
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;


//constructor
Account::Account(int initial_deposit) : _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
	_accountIndex = _nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << "created" << std::endl;	
} 

Account::~Account() {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

int Account::getNbAccounts() { return _nbAccounts; }
int Account::getTotalAmount() { return _totalAmount; }
int Account::getNbDeposits() { return _totalNbDeposits; }
int Account::getNbWithdrawals() { return _totalNbWithdrawals; }


void Account::displayAccountsInfos() {
	_displayTimestamp();
	
}

void Account::makeDeposit(int deposit) {

	_displayTimestamp();
	(void)deposit;
}

bool Account::makeWithdrawal(int withdrawal) {

	_displayTimestamp();
	(void)withdrawal;
	return false; //placeholder return statement

}

int Account::checkAmount() const { return _amount; }

void Account::displayStatus() const {

	_displayTimestamp();
}

void Account::_displayTimestamp() {
	// std::time_t t; 
	//PLACEHOLDER_TIMESTAMP
	 std::cout << "[Placeholder_Timestamp] ";

}


//----------------------------------------------------------------

// [19920104_091532] index:0;amount:42;created

// [19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0

// [19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
// [19920104_091532] accounts:8;total:21524;deposits:8;withdrawals:0


// [19920104_091532] index:0;amount:47;deposits:1;withdrawals:0
// [19920104_091532] index:0;p_amount:47;withdrawal:refused`


//bruh do i really wanna spend 1 day on something that isnt mandatory 