#ifndef SDDS_CHEQUINGACCOUNT_H
#define SDDS_CHEQUINGACCOUNT_H
#include "Account.h"
#include <iostream>

namespace sdds
{
	class ChequingAccount :public Account
	{
		double transaction;
		double monthly;

	public:
		ChequingAccount(double, double, double);
		bool credit(double);
		bool debit(double);
		void monthEnd();
		void display(std::ostream&)const;
	};
}

#endif