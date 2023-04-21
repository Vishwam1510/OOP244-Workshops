#ifndef SDDS_ACCOUNT_H
#define SDDS_ACCOUNT_H
#include "iAccount.h"

namespace sdds
{
	class Account :public iAccount
	{
		double accBalance;
	public:
		Account(double balance = 0);
		bool credit(double);
		bool debit(double);
	protected:
		double balance() const;
	};
}

#endif
