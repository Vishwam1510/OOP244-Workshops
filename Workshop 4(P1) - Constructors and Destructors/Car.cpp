/*
*****************************************************************************
< Workshop - #4 (Part-1)>
Full Name : Vishwam Shailesh Kapadia
Student ID#: 154933212
Email : vkapadia3@myseneca.ca
Section : NCC
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************

*/

#define CRT_SECURE_NO_WARNINGS
#include "Car.h"
#include <iostream>
#include <cstring>


using namespace std;
namespace sdds
{
	Car::Car()
	{
		m_type = nullptr;
		m_brand = nullptr;
		m_model = nullptr;
		resetInfo();
	}
	Car::Car(const char* type, const char* brand, const char* model, int year, int code, double price)
	{
		int n = 0, codecopy = code;
		while (codecopy > 0)
		{
			codecopy = codecopy / 10;
			++n;
		}
		if (type != nullptr && brand != nullptr && model != nullptr && year >= 1990 && price > 0 && n == 3)
		{
			m_type = new char[strlen(type) + 1];
			m_brand = new char[strlen(brand) + 1];
			m_model = new char[strlen(model) + 1];
			strcpy(m_type, type);
			strcpy(m_brand, brand);
			strcpy(m_model, model);
			m_year = year;
			m_code = code;
			m_price = price;
		}
		else
		{
			resetInfo();
		}
	}
	Car& Car::setInfo(const char* type, const char* brand, const char* model, int year, int code, double price)
	{
		this->resetInfo();
		int n = 0, codecopy = code;
		while (codecopy > 0)
		{
			codecopy = codecopy / 10;
			++n;
		}
		if (type != nullptr && brand != nullptr && model != nullptr && year >= 1990 && price > 0 && n == 3)
		{
			m_type = new char[strlen(type) + 1];
			m_brand = new char[strlen(brand) + 1];
			m_model = new char[strlen(model) + 1];
			strcpy(m_type, type);
			strcpy(m_brand, brand);
			strcpy(m_model, model);
			m_year = year;
			m_code = code;
			m_price = price;
			return *this;
		}
		else
		{
			return *this;
		}
	}
	void Car::resetInfo()
	{
		delete[] m_type;
		delete[] m_brand;
		delete[] m_model;
		m_type = nullptr;
		m_brand = nullptr;
		m_model = nullptr;
		m_year = 0;
		m_code = 0;
		m_price = 0;
	}
	
	void Car::printInfo() const
	{
		if (isValid())
		{
			printf("| %-10s | %-16s | %-16s | %-4d |  %3d |  %8.2lf |\n", m_type, m_brand, m_model, m_year, m_code, m_price);
		}
	}
	bool Car::isValid() const
	{
		bool flag = false;
		int n = 0, codecopy = m_code;
		while (codecopy > 0)
		{
			codecopy = codecopy / 10;
			++n;
		}
		if (m_type != nullptr && m_brand != nullptr && m_model != nullptr && m_year >= 1990 && m_price > 0 && n == 3)
		{
			flag = true;
		}
		else
		{
			flag = false;
		}
		return flag;
	}

	bool Car::isSimilarTo(const Car & car) const
	{
		bool flag = true;
		if (m_type != car.m_type || m_brand != car.m_brand || m_model != car.m_model || m_year != car.m_year)
		{
			flag = false;
		}
		return flag;
    }
	bool has_similar(const Car car[], const int num_cars)
	{
		int i, j;
		bool flag = false;
		for (i = 0;i < num_cars;i++)
		{
			for (j = i + 1;j < num_cars;j++)
			{
				if (car[i].isSimilarTo(car[j]))
				{
					flag = true;
				}
			}
		}
		return flag;
	}
	bool has_invalid(const Car car[], const int num_cars)
	{
		bool flag = false;
		for (int i = 0;i < num_cars; i++)
		{
			if (!car[i].isValid())
			{
				flag = true;
			}
		}
		return flag;
	}
	void print(const Car car[], const int num_cars)
	{
		for (int i = 0;i < num_cars;i++)
		{
			car[i].printInfo();
		}
	}
	Car::~Car()
	{
		delete[] m_type;
		delete[] m_brand;
		delete[] m_model;
		m_type = nullptr;
		m_brand = nullptr;
		m_model = nullptr;
	}
}