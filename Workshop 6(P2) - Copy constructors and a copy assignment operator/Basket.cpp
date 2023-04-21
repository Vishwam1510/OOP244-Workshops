#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <fstream>
#include "Basket.h"
#include <iomanip>

using namespace std;
namespace sdds
{
	void Basket::setEmpty() {
		m_fruits = nullptr;
		m_cnt = 0;
		m_price = 0.0;
	}
	Basket::Basket() {
		setEmpty();
	}
	Basket::Basket(Fruit f1[], int count, double price) {
		setEmpty();
		if (count > 0 && f1 != NULL)
		{
			int i;
			m_cnt = count;
			m_price = price;
			m_fruits = new Fruit[count + 1];
			for (i = 0; i < count; i++)
			{
				m_fruits[i] = f1[i];
			}
		}
	}
	Basket::Basket(const Basket& b1)
	{
		int i;
		m_cnt = b1.m_cnt;
		m_price = b1.m_price;
		if (b1.m_fruits != nullptr)
		{
			m_fruits = new Fruit[m_cnt];
			for (i = 0; i < m_cnt; i++)
			{
				strcpy(m_fruits[i].m_name, b1.m_fruits[i].m_name);
				m_fruits[i].m_qty = b1.m_fruits[i].m_qty;
			}
		}
	
		else
		{
			m_fruits = nullptr;
		}
	}
	Basket& Basket::operator=(const Basket& b1) {
		int i;
		if (*this != b1)
		{
			m_cnt = b1.m_cnt;
			m_price = b1.m_price;
			delete[] m_fruits;
			if (b1.m_fruits != nullptr)
			{
				m_fruits = new Fruit[m_cnt];
				for (i = 0; i < m_cnt; i++)
				{
					strcpy(m_fruits[i].m_name, b1.m_fruits[i].m_name);
					m_fruits[i].m_qty = b1.m_fruits[i].m_qty;
				}
			}
			else
			{
				m_fruits = nullptr;
			}
		}
		return *this;
	}
	Basket::~Basket() {
		delete[] m_fruits;
		m_fruits = nullptr;
	}
		
	void Basket::setPrice(double price)
	{
		if (price > 0)
		{
			this->m_price = price;
		}
	}
	Basket::operator bool() const
	{
		bool check = false;
		if (m_cnt > 0)
		{
			if (m_fruits != nullptr)
			{
				check = true;
			}
		}
		return check;
	}
	Basket& Basket::operator+=(Fruit& fruit)
	{
		Fruit* temp = new Fruit[m_cnt + 1];
		int i;
		for (i = 0; i < m_cnt; i++)
		{
			strcpy(temp[i].m_name, m_fruits[i].m_name);
			temp[i].m_qty = m_fruits[i].m_qty;
		}
		m_cnt++;
		strcpy(temp[m_cnt-1].m_name, fruit.m_name);
		temp[m_cnt - 1].m_qty = fruit.m_qty;
		delete[] m_fruits;
		m_fruits = temp;
		return *this;
	}
	std::ostream& operator<<(std::ostream& os, const Basket& B)
	{
		if (!B.operator bool())
		{
			os << "The basket is empty!" << endl;
		}
		else
		{
			os << "Basket Content:" << endl;
			for (int i = 0; i < B.m_cnt; i++)
			{
				os.setf(std::ios::right);
				os.width(10);
				os << B.m_fruits[i].m_name << ": ";
				os << fixed << setprecision(2) << B.m_fruits[i].m_qty << "kg" << endl;
			}
			os << "Price: " << fixed << setprecision(2) << B.m_price << endl;
		}
		return os;
	}	
}