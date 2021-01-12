/*
Name:           Dhara Moghariya
Student Number: 161449194
Email:          dmoghariya@myseneca.ca
Section:        NAA
Date:		    November 25, 2020
-----------------------------------------------------------
Final Project Milestone 4
Module: TriagePatient
Filename: TriagePatient.h
Version 0.9
Revision History
-----------------------------------------------------------
Date		Reason
2020/11/22  Initial Implementation
2020/11/23  Testing and Debugging
2020/11/26  Testing and Debugging
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "TriagePatient.h"
using namespace std;
namespace sdds {
	int nextTriageTicket = 1;

	TriagePatient::TriagePatient() : Patient(nextTriageTicket) {
		m_triagePatientSymtoms = nullptr;
		nextTriageTicket++;
	}

	TriagePatient::~TriagePatient() {
		delete[] m_triagePatientSymtoms;
		m_triagePatientSymtoms = nullptr;
	}

	char TriagePatient::type() const {
		return 'T';
	}

	std::ostream& TriagePatient::csvWrite(std::ostream& ostr)const {
		Patient::csvWrite(ostr);
		ostr << ',' << m_triagePatientSymtoms;
		return ostr;
	}

	std::istream& TriagePatient::csvRead(std::istream& istr) {
		delete[] m_triagePatientSymtoms;
		m_triagePatientSymtoms = nullptr;
		//cin >> ws; // TODO: May be remove comemnt
		Patient::csvRead(istr);
		istr.ignore(1, ',');

		char Cstr[511] = { '\0' };
		istr.get(Cstr, 511, '\n');
		if (Cstr != NULL) {
			int size = strlen(Cstr) + 1;
			m_triagePatientSymtoms = new char[size];
			strcpy(m_triagePatientSymtoms, Cstr);
		}

		nextTriageTicket = Patient::number() + 1;
		return istr;
	}

	std::ostream& TriagePatient::write(std::ostream& ostr)const {
		if (Patient::fileIO()) {
			csvWrite(ostr);
		}
		else {
			ostr << "TRIAGE" << endl;
			Patient::write(ostr);
			ostr << endl;
			ostr << "Symptoms: ";
			ostr << m_triagePatientSymtoms;
			ostr << endl;
		}
		return ostr;
	}

	std::istream& TriagePatient::read(std::istream& istr) {
		if (Patient::fileIO()) {
			csvRead(istr);
		}
		else {
			delete[] m_triagePatientSymtoms;
			m_triagePatientSymtoms = nullptr;

			Patient::read(istr);
			cout << "Symptoms: ";

			char Cstr[511] = { '\0' };
			istr.get(Cstr, 511, '\n');
			if (Cstr != NULL) {
				int size = strlen(Cstr) + 1;
				m_triagePatientSymtoms = new char[size];
				strcpy(m_triagePatientSymtoms, Cstr);
			}
		}
		return istr;
	}

}