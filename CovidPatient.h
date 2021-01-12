/*
Name:           Dhara Moghariya
Student Number: 161449194
Email:          dmoghariya@myseneca.ca
Section:        NAA
Date:		    November 25, 2020
-----------------------------------------------------------
Final Project Milestone 4
Module: CovidPatient
Filename: CovidPatient.h
Version 0.9
Revision History
-----------------------------------------------------------
Date		Reason
2020/11/22  Initial Implementation
2020/11/22  Testing and Debugging
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SDDS_COVIDPATIENT_H_
#define SDDS_COVIDPATIENT_H_
#include "Patient.h"
namespace sdds {

	class CovidPatient : public Patient {
	public:
		CovidPatient();
		//~CovidPatient(); // This class does not need constructor
		char type() const;
		std::ostream& csvWrite(std::ostream& ostr)const;
		std::istream& csvRead(std::istream& istr);
		std::ostream& write(std::ostream& ostr)const;
		std::istream& read(std::istream& istr);
	};
}
#endif // !SDDS_COVIDPATIENT_H_



