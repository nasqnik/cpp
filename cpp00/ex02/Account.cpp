#include "Account.hpp"

#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts(void){
    return Account::_nbAccounts;
}

int	Account::getTotalAmount(void){
    return Account::_totalAmount;
}

int	Account::getNbDeposits(void){
    return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals(void){
    return Account::_totalNbWithdrawals;
}

void	Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << "accounts:" << Account::getNbAccounts() <<
                ";total:" << Account::getTotalAmount() <<
                ";deposits:" << Account::getNbDeposits() <<
                ";withdrawals:" << Account::getNbWithdrawals() <<
                std::endl;

}

Account::Account(int initial_deposit) : 
    _amount(initial_deposit), 
    _nbDeposits(0),
    _nbWithdrawals(0)
{
    _accountIndex = Account::_nbAccounts;
    Account::_nbAccounts++;

    Account::_totalAmount += _amount;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex <<
                ";amount:" << checkAmount() <<
                ";created" << std::endl;
}

Account::~Account()
{
    Account::_nbAccounts--;
    Account::_totalAmount -= _amount;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex <<
                ";amount:" << checkAmount() <<
                ";closed" << std::endl;

}

void Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex <<
                ";p_amount:" << checkAmount();

    _amount += deposit;
    _nbDeposits++;
    Account::_totalNbDeposits++;
    Account::_totalAmount += deposit;

    std::cout << ";deposit:" << deposit <<
                ";amount:" << checkAmount() <<
                ";nb_deposits:" << _nbDeposits <<
                std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex <<
                ";p_amount:" << checkAmount() <<
                ";withdrawal:";

    if (_amount >= withdrawal)
    {
        std::cout << withdrawal;

        _amount -= withdrawal;
        _nbWithdrawals++;
        Account::_totalNbWithdrawals++;
        Account::_totalAmount -= withdrawal;

        std::cout << ";amount:" << checkAmount() <<
                ";nb_withdrawals:" << _nbWithdrawals << 
                std::endl;
        return true;
    }
    std::cout << "refused" << std::endl;
    return false;
}

int Account::checkAmount(void) const
{
    return _amount;
}

void Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex <<
                ";amount:" << checkAmount() <<
                ";deposits:" << _nbDeposits <<
                ";withdrawals:" << _nbWithdrawals <<
                std::endl;
}

void Account::_displayTimestamp(void)
{
    std::time_t now = std::time(NULL);
    std::tm *lt = std::localtime(&now);

    std::cout << "["
              << (lt->tm_year + 1900)
              << (lt->tm_mon + 1 < 10 ? "0" : "") << lt->tm_mon + 1
              << (lt->tm_mday < 10 ? "0" : "") << lt->tm_mday
              << "_"
              << (lt->tm_hour < 10 ? "0" : "") << lt->tm_hour
              << (lt->tm_min < 10 ? "0" : "") << lt->tm_min
              << (lt->tm_sec < 10 ? "0" : "") << lt->tm_sec
              << "] ";
}
