#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"
#include "iAccount.h"

using namespace std;
namespace sdds
{
	Account::Account(double balance)
	{
		if (balance < 0)
		{
			accBalance = 0;
		}
		else
		{
			accBalance = balance;
		}
	}
	bool Account::credit(double balance)
	{
		bool check = false;
		if (balance > 0)
		{
			accBalance += balance;
			check = true;
		}
		return check;
	}
	bool Account::debit(double balance)
	{
		bool check = false;
		if (balance > 0)
		{
			accBalance -= balance;
			check = true;
		}
		return check;
	}
	double Account::balance() const
	{
		return accBalance;
	}
}