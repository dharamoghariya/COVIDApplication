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

#ifndef SDDS_IOABLE_H_
#define SDDS_IOABLE_H_
#include <iostream>
namespace sdds {
	class IOAble {
	public:
		// pure virtual functions
		virtual std::ostream& csvWrite(std::ostream& ostr) const = 0;
		virtual std::istream& csvRead(std::istream& istr) = 0;
		virtual std::ostream& write(std::ostream& ostr) const = 0;
		virtual std::istream& read(std::istream& istr) = 0;
		// an empty virtual destructor
		virtual ~IOAble() { }
	};

	std::ostream& operator<<(std::ostream& ostr, const IOAble& IO);
	std::istream& operator>>(std::istream& istr, IOAble& IO);

}
#endif // !SDDS_IOABLE_H_
