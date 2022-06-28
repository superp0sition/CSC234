/**
 * \brief Definitions for functions contained in the account class
 * \author David Badcoe
 * \date 2022-3-2
 */
#include "account.h"

using std::cout;
using std::endl;

/**
 * \brief Constructor for account class
 * \param identifier The account identifier (int)
 * \param name The name of the account holder
 * \param bal The balance in the account
 */
account::account(int identifier, const char* name, double bal) : identifier(identifier), name(name), // initialize all data members to related parameters
                                                                 balance(bal)
{
}

/**
 * \brief Modifies the account balance by removing currency.
 * \throws accountException Throws exception if amount is greater than balance or negative.
 * \param amount Amount to withdraw from the account.
 */
void account::withdraw(double amount)
{
    if (amount > balance || amount < 0) // check if the amount to take away is greater than balance or if amount is negative
        throw accountException("withdraw");
    balance -= amount;
}

/**
 * \brief Modifies the account balance by adding currency
 * \throws accountException Throws exception if the amount deposited is negative
 * \param amount Amount to deposit to the account
 */
void account::deposit(double amount)
{
    if (amount < 0)
        throw accountException("deposit");
    balance += amount;
}

/**
 * \brief Displays information about the account in a user-friendly way.
 */
void account::display_account()
{
    // setting the width of the values to justify them looks a bit nicer to me
    cout << std::setw(20) << "Account number: " << std::setw(4) << std::setfill('0') << identifier << std::setfill(' ') << endl;
    cout << std::setw(20) << "Account name: " << name << endl;
    cout << std::setw(20) << "Account balance: " << std::fixed << std::setprecision(2) << '$' << balance << endl << endl;
}
