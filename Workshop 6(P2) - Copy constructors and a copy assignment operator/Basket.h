#ifndef SDDS_BASKET_H_
#define SDDS_BASKET_H_
#include <iostream>
namespace sdds
{
	struct Fruit
	{
		char m_name[30 + 1]; 
		double m_qty;        
	};
	class Basket
	{
		Fruit *m_fruits;
		int m_cnt;
		double m_price;
		void setEmpty();
	public:
		Basket();
		Basket(Fruit f1[], int count, double price);
		Basket(const Basket& b1);
		~Basket();
		Basket& operator=(const Basket& b1);
		void setPrice(double price);
		operator bool() const;
		Basket& operator+=(Fruit& fruit);
		friend std::ostream& operator<<(std::ostream& os, const Basket& B);
	};	
}
#endif

