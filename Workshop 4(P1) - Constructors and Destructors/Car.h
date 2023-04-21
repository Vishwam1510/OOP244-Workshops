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

#ifndef SDDS_CAR_H
#define SDDS_CAR_H

namespace sdds
{
	class Car
	{

	public:
		Car();
		Car(const  char* type, const char* brand, const char* model, int year = 2022, int code = 100, double price = 1);
		void resetInfo();
		Car& setInfo(const char* type, const char* brand, const char* model, int year, int code, double price);
		void printInfo() const;
		bool isValid() const;
		bool isSimilarTo(const Car& car)const;
		~Car();

	private:
		char* m_type;
		char* m_brand;
		char* m_model;
		int m_year;
		int m_code;
		double m_price;

	
	};
	bool has_similar(const Car car[], const int num_cars);
	bool has_invalid(const Car car[], const int num_cars);
	void print(const Car car[], const int num_cars);
}
#endif
