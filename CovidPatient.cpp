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
2020/11/23  Testing and Debugging
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#include "CovidPatient.h"
using namespace std;
namespace sdds {
	int nextCovidTicket = 1;

	CovidPatient::CovidPatient() : Patient(nextCovidTicket) {
		nextCovidTicket++;
	}

	char CovidPatient::type() const {
		return 'C';
	}

	std::ostream& CovidPatient::csvWrite(std::ostream& ostr)const {
		Patient::csvWrite(ostr);
		return ostr;
	}

	std::istream& CovidPatient::csvRead(std::istream& istr) {
		Patient::csvRead(istr);
		nextCovidTicket = Patient::number() + 1;
		return istr;
	}

	std::ostream& CovidPatient::write(std::ostream& ostr)const {
		if (Patient::fileIO()) {
			csvWrite(ostr);
		}
		else {
			ostr << "COVID TEST" << endl;
			Patient::write(ostr);
			ostr << endl;
		}
		return ostr;
	}

	std::istream& CovidPatient::read(std::istream& istr) {
		if (Patient::fileIO()) {
			csvRead(istr);
		}
		else {
			Patient::read(istr);
		}
		return istr;
	}

}