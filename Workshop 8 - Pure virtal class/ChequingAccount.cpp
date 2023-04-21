#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"
#include "iAccount.h"
#include "SavingsAccount.h"
#include "ChequingAccount.h"

using namespace std;
namespace sdds
{
	ChequingAccount::ChequingAccount(double starting, double fees , double ending) :Account(starting)
	{
		if (fees > 0)
		{
			transaction = fees;
		}
		else
		{
			transaction = 0;
		}
		if (ending > 0)
		{
			monthly = ending;
		}
		else
		{
			monthly = 0;
		}
	}
	bool ChequingAccount::credit(double balance)
	{
		bool check = false;
		if (Account::credit(balance))
		{
			if (Account::debit(transaction))
			{
				check = true;
			}
		}
		return check;
	}
	bool ChequingAccount::debit(double balance)
	{
		bool  check = false;
		if (Account::debit(balance))
		{
			if (Account::debit(transaction))
			{
				check = true;
			}
		}
		return check;
	}
	void ChequingAccount::monthEnd()
	{
		Account::debit(monthly);
	}
	void ChequingAccount::display(std::ostream& os)const
	{
		os << "Account type: Chequing" << endl;
		os << "Balance: $" << Account::balance() << endl;
		os << "Per Transaction Fee: " << transaction << endl;
		os << "Monthly Fee: " << monthly << endl;
	}
}