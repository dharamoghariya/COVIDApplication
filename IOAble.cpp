/*
Name:           Dhara Moghariya
Student Number: 161449194
Email:          dmoghariya@myseneca.ca
Section:        NAA
Date:		    November 15, 2020
-----------------------------------------------------------
Final Project Milestone 2
Module: IOAble
Filename: IOAble.h
Version 0.9
Revision History
-----------------------------------------------------------
Date		Reason
2020/11/15  Initial Implementation
2020/11/15  Testing and Debugging
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#include <iostream>
#include "IOAble.h"
using namespace std;
namespace sdds {

	std::ostream& operator<<(std::ostream& ostr, const IOAble& IO) {
		IO.write(ostr);
		return ostr;
	}

	std::istream& operator>>(std::istream& istr, IOAble& IO) {
		IO.read(istr);
		return istr;
	}

}