#include <iostream>
#include <ctime>
#include "Account.hpp"

/* These lines initialize the static members of the Account class. 
Static members are shared across all instances of the class, 
meaning there's only one copy of each static member, 
regardless of how many Account objects are created. */
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;


// Initialize the members variable specific to each instance of Account 
Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts++;
	_amount = initial_deposit;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account(void) {
    _nbAccounts--;
    _displayTimestamp(); 
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

int Account::getNbAccounts(void) {
    return _nbAccounts;
}

int Account::getTotalAmount(void) {
    return _totalAmount;
}

int Account::getNbDeposits(void) {
    return _totalNbDeposits;
}

int Account::getNbWithdrawals(void) {
    return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(void) {
    _displayTimestamp(); 
   std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount() 
              << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() 
              << std::endl;
}

void Account::makeDeposit(int deposit) {

    _displayTimestamp();

    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount;
  
    _amount += deposit;
    _totalAmount += deposit;
    _nbDeposits++;
    _totalNbDeposits++;

    std::cout << ";deposit:" << deposit << ";amount:" << _amount << ";nb_deposits:" 
              << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {

    _displayTimestamp();

    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount;

    if (withdrawal > _amount) {
        // If the withdrawal amount exceeds the current balance, refuse the withdrawal
        std::cout << ";withdrawal:refused" << std::endl;
        return false;
    }

    _amount -= withdrawal; 
    _totalAmount -= withdrawal; 
    _nbWithdrawals++;
    _totalNbWithdrawals++; 

    std::cout << ";withdrawal:" << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" 
              << _nbWithdrawals << std::endl;

    return true;
}

int Account::checkAmount(void) const {
    return _amount;
}

void Account::displayStatus(void) const {

    _displayTimestamp(); 

    std::cout << "index:" << _accountIndex << ";amount:" << _amount 
              << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals 
              << std::endl;
}

void    Account::_displayTimestamp(void) {

    // Get the current time as a time_t object
    // Sending a NULL argument because storing the result is not needed
    std::time_t		timestamp = std::time(NULL);
	
    char		    formattedTimestamp[20];
    
    // The function parameters are the formatted string, the size of the buffer, the format, and the time
    strftime(formattedTimestamp, 20, "[%Y%m%d_%H%M%S]", localtime(&timestamp));
	
    std::cout << formattedTimestamp;
}