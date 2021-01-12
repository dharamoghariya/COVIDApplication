/*
Name:           Dhara Moghariya
Student Number: 161449194
Email:          dmoghariya@myseneca.ca
Section:        NAA
Date:		    November 30, 2020
-----------------------------------------------------------
Citation and Sources...
Final Project Milestone 1
Module: Time
Filename: Time.h
Version 1.0
Revision History
-----------------------------------------------------------
Date        Reason
2020/11/12  Initial Implementation
2020/11/13  Testing and Debugging
2020/11/22  Testing and Updating
2020/11/30  Testing and Updating
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include "Time.h"
#include "utils.h"
using namespace std;
namespace sdds {

    Time& Time::reset() {
        m_minutes = getTime();
        return *this;
    }

    Time::Time(unsigned int min) {
        m_minutes = min;
    }

    std::ostream& Time::write(std::ostream& ostr) const {
        int hours = m_minutes / 60;
        int minutes = m_minutes % 60;
        ostr.width(2);
        ostr.fill('0');
        ostr << hours << ':';
        ostr.width(2);
        //ostr.fill('0');
        ostr << minutes;
        return ostr;
    }

    std::istream& Time::read(std::istream& istr) {
        int hours = 0, minutes = 0;
        char c = '\0';
        istr >> hours >> c >> minutes;
        if (c != ':') {
            istr.setstate(ios::failbit);
        }
        else {
            m_minutes = (hours * 60) + minutes;
        }
        return istr;
    }

    Time::operator int()const {
        return m_minutes;
    }

    Time& Time::operator *= (int val) {
        m_minutes *= val;
        return *this;
    }

    // if  LO is < RO => LO + 24:00
    Time& Time::operator-=(const Time& D) {
        if (D.m_minutes > m_minutes) {
            m_minutes += (24 * 60);
            m_minutes -= D.m_minutes;
        }
        else {
            m_minutes -= D.m_minutes;
        }
        return *this;
    }

    //
    Time Time::operator-(const Time& ROperand) {
        Time LOperand = *this;
        LOperand -= ROperand;
        return LOperand;
    }

    std::ostream& operator<<(std::ostream& ostr, const Time& D) {
        D.write(ostr);
        return ostr;
    }

    std::istream& operator>>(std::istream& istr, Time& D) {
        D.read(istr);
        return istr;
    }


}