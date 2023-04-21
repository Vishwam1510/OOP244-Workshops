#ifndef SDDS_SAVINGSACCOUNT_H
#define SDDS_SAVINGSACCOUNT_H
#include "Account.h"

namespace sdds
{
	class SavingsAccount :public Account
	{
		double interestRate;
	public:
		SavingsAccount(double, double);
		void monthEnd();
		void display(std::ostream&)const;
	};
}

#endif