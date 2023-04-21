#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"
#include "iAccount.h"
#include "SavingsAccount.h"
#include <iomanip>

using namespace std;
namespace sdds
{
	SavingsAccount::SavingsAccount(double starting, double interest) :Account(starting)
	{
		if (interest > 0)
		{
			interestRate = interest;
		}
		else
		{
			interestRate = 0;
		}
	}
	void SavingsAccount::monthEnd()
	{
		double interest = Account::balance() * interestRate;
		Account::credit(interest);
	}
	void SavingsAccount::display(std::ostream& os)const
	{
		os << "Account type: Savings" << endl;
		os << "Balance: $" << fixed << setprecision(2) << Account::balance() << endl;
		os << "Interest Rate (%): " << fixed << setprecision(2) << interestRate * 100 << endl;
	}
}