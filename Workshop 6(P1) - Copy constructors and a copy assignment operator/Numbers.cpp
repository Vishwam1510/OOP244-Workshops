#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <fstream>
#include "Numbers.h"
#include "Numbers.h"  // intentional
using namespace std;
namespace sdds {


    Numbers::Numbers() {
        setEmpty();
        m_isOriginal = false;
    }

    Numbers::Numbers(const char* filename) {
        setEmpty();
        m_isOriginal = true;
        setFilename(filename);
        m_numCount = numberCount();
        if (m_numCount == 0 || !load()) {
            delete[] m_numbers;
            delete[] m_filename;
            setEmpty();
            m_isOriginal = false;
        }
        else {
            sort();
        }
    }
    Numbers::~Numbers() {
        save();
        delete[] m_numbers;
        delete[] m_filename;
    }

    bool Numbers::isEmpty() const {
        return m_numbers == nullptr;
    }

    void Numbers::setEmpty() {
        m_numbers = nullptr;
        m_filename = nullptr;
        m_numCount = 0;
    }
    void Numbers::setFilename(const char* filename) {
        delete[] m_filename;
        m_filename = new char[strlen(filename) + 1];
        strcpy(m_filename, filename);
    }
    void Numbers::sort() {
        int i, j;
        double temp;
        for (i = m_numCount - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (m_numbers[j] > m_numbers[j + 1]) {
                    temp = m_numbers[j];
                    m_numbers[j] = m_numbers[j + 1];
                    m_numbers[j + 1] = temp;
                }
            }
        }
    }

    double Numbers::average() const {
        double aver = 0.0;
        if (!isEmpty()) {
            for (int i = 0; i < m_numCount; i++)
                aver += m_numbers[i];
            aver = aver / m_numCount;
        }
        return aver;
    }
    double Numbers::min() const {
        double minVal = 0.0;
        if (!isEmpty()) {
            minVal = m_numbers[0];
            for (int i = 1; i < m_numCount; i++)
                if (minVal > m_numbers[i]) minVal = m_numbers[i];
        }
        return minVal;
    }
    double Numbers::max() const {
        double maxVal = 0.0;
        if (!isEmpty()) {
            maxVal = m_numbers[0];
            for (int i = 1; i < m_numCount; i++)
                if (maxVal < m_numbers[i]) maxVal = m_numbers[i];
        }
        return maxVal;
    }
    Numbers::Numbers(const Numbers& n1)
    {
        setEmpty();
        m_isOriginal = !true;
        *this = n1;
    }    
    int Numbers::numberCount()
    {
        ifstream file(this->m_filename);
        int count = 0;
        double i = 0;
        if (file.is_open())
        {
            while (file >> i)
            {
                count++;
            }
        }
        return count;
    }
    Numbers& Numbers::operator=(const Numbers& n1)
    {
        delete[] this->m_numbers;
        this->m_numbers = new double[n1.m_numCount];
        for (int i = 0; i < n1.m_numCount; i++)
        {
            this->m_numbers[i] = n1.m_numbers[i];
        }
        setFilename(n1.m_filename);
        this->m_numCount = n1.m_numCount;
        return *this;
    }
    bool Numbers::load()
    {
        bool check = false;
        if (m_numCount > 0)
        {
            m_numbers = new double[m_numCount + 1];
            ifstream file(this->m_filename);
            int j = 0;
            double i = 0;
            if (file.is_open())
            {
                while (file >> i)
                {
                    this->m_numbers[j] = i;
                    j++;
                }
            }
            if (j == m_numCount)
            {
                check = true;
            }
        }
        return check;
    }
    void Numbers::save()
    {
        if (!this->isEmpty() && this->m_isOriginal)
        {
            ofstream file(m_filename);
            for (int i = 0; i < m_numCount; i++)
            {
                file << m_numbers[i] << endl;
            }
        }
    }
    Numbers& Numbers::operator+=(double add)
    {
        int i;
        if (!this->isEmpty())
        {
            double* temp = new double[m_numCount + 1];
            for (i = 0; i < m_numCount; i++)
            {
                temp[i] = m_numbers[i];
            }
            m_numCount++;
            temp[m_numCount - 1] = add;
            delete[] m_numbers;
            m_numbers = temp;
            sort();
        }
        return *this;
    }
    std::ostream& Numbers::display(std::ostream& ostr)const
    {
        if (this->isEmpty())
        {
            ostr << "Empty list";
        }
        else
        {
            ostr << "=========================" << endl;
            if (!m_isOriginal)
            {
                ostr << "*** COPY ***" << endl;
            }
            else
            {
                ostr << this->m_filename << endl;
            }
            for (int i = 0; i < m_numCount; i++)
            {
                ostr << m_numbers[i];
                if (i != m_numCount - 1)
                {
                    ostr << ", ";
                }
            }
            ostr << endl;
            ostr << "-------------------------" << endl;

            ostr << "Total of " << m_numCount << " number(s)" << endl;
            ostr << "Largest number:  " << this->max() << endl;
            ostr << "Smallest number: " << this->min() << endl;
            ostr << "Average :        " << this->average() << endl;
            ostr << "=========================";
        }
        return ostr;
    }
    std::ostream& operator<<(std::ostream& os, const Numbers& N)
    {
        return N.display(os);
    }
    std::istream& operator>>(std::istream& istr, Numbers& N)
    {
        double num = 0;
        istr >> num;
        N += num;
        return istr;
    }
}