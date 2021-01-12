/*
Name:           Dhara Moghariya
Student Number: 161449194
Email:          dmoghariya@myseneca.ca
Section:        NAA
Date:		    November 30, 2020
-----------------------------------------------------------
Final Project Milestone 1
Module: Time
Filename: Time.h
Version 1.0
Revision History
-----------------------------------------------------------
Date        Reason
2020/11/12  Initial Implementation
2020/11/13  Testing and Debugging
2020/11/30  Testing and Updating
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SDDS_TIME_H
#define SDDS_TIME_H
#include <iostream>
namespace sdds {
    class Time {
        unsigned int m_minutes;   // holds time in minutes 
    public:
        Time& reset();
        Time(unsigned int min = 0);
        std::ostream& write(std::ostream& ostr) const;
        std::istream& read(std::istream& istr);
        operator int()const;
        Time& operator *= (int val);
        Time& operator-=(const Time& D);

        Time operator-(const Time& ROperand); //
    };

    std::ostream& operator<<(std::ostream& ostr, const Time& D);
    std::istream& operator>>(std::istream& istr, Time& D);

}

#endif // !SDDS_TIME_H

