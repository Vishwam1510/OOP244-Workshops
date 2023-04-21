/*
*****************************************************************************
< Workshop - #5 (Part-1)>
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
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Book.h"
#include "Chapter.h"

using namespace std;
namespace sdds {
	void Book::init_book() {
		m_title[0] = '\0';
		m_author[0] = '\0';
		m_num_chapters=0;
		m_num_pages=0;
	}

	Book::Book() {
		init_book();
	}

	Book::Book(const char* title_) {
		init_book();
		strcpy(m_title, title_);
	}

	Book::Book(const char* title_, const char* author_, double price_) {
		init_book();
		strcpy(m_title, title_);
		strcpy(m_author, author_);
		m_price = price_;
	}

	Book Book::operator++(int)
	{
		Book temp = *this;
		m_num_chapters++;
		return temp;
	}

	int Book::add_chapter(Chapter* chapter)
	{
		m_chapters[m_num_chapters] = *chapter;
		m_num_chapters++;
		m_num_pages += chapter->operator int();
		return m_num_chapters;
	}

	std::ostream& Book::display(std::ostream& os) const
	{
		int i;
		os << "Title:'" << m_title << "'" << endl;
		os << "Author: '" << m_author << "'" << endl;
		for (i = 0;i < m_num_chapters;i++)
		{
			os << m_chapters[i];
		}
		return os;
	}

	Book::operator int() const
	{
		return m_num_chapters;
	}

	Book::operator bool()const
	{
		bool check = false;
		Chapter ch;
		if (m_title != '\0' && m_author != '\0' && m_num_chapters > 0)
		{
			if (m_num_pages > 0)
			{
				check = true;
			}
		}
		return check;
	}

	Book::operator double() const
	{
		return m_price;
	}

	Book::operator const char* ()const
	{
		return m_title;
	}

	bool Book::operator!()const
	{
		return(!operator bool());
	}

	Book& Book::operator+=(Chapter chapter)
	{		
		add_chapter(&chapter);
		return *this;
	}

	Book& Book::operator-=(double discount)
	{
		m_price -= discount;
		return *this;
	}

	ostream& operator << (std::ostream& os,const Book& book)
	{
		return book.display(os);
	}

	// Print a book summary
	void Book::summary() {
		cout.setf(ios::left);
		cout << "| ";
		cout.width(MAX_BOOK_TITEL);
		cout << m_title << " | ";
		cout.width(MAX_AUTHOR_NAME);
		cout << m_author << " | ";
		cout.width(3);
		cout << m_num_chapters << "  ";
		cout.width(4);
		cout << m_num_pages << " | ";
		cout.width(6);
		cout << m_price << " |" << endl;
	}

}
