/*
Name:           Dhara Moghariya
Student Number: 161449194
Email:          dmoghariya@myseneca.ca
Section:        NAA
Date:		    November 20, 2020
-----------------------------------------------------------
Final Project Milestone 3
Module: Patient
Filename: Patient.h
Version 1.1
Revision History
-----------------------------------------------------------
Date		Reason
2020/11/19  Initial Implementation
2020/11/20  Testing and Debugging
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Patient.h"
#include "utils.h"
using namespace std;
namespace sdds {
	Patient::Patient(int ticketNum, bool fileIOflag) : m_ticket(ticketNum), IOflag(fileIOflag) {}

	Patient::~Patient() {
		delete[] m_patientName;
		m_patientName = nullptr;
	}

	bool Patient::fileIO() const {
		return IOflag;
	}

	void Patient::fileIO(bool fileIOflag) {
		IOflag = fileIOflag;
	}

	bool Patient::operator==(const char c) const {
		return c == (*this).type();
	}

	bool Patient::operator==(const Patient& p) const {
		return (*this).type() == p.type();
	}

	void Patient::setArrivalTime() {
		m_ticket.resetTime();
	}

	Patient::operator Time() const {
		return (Time)m_ticket;
	}


	int Patient::number() const {
		return m_ticket.number();
	}

	std::ostream& Patient::csvWrite(std::ostream& ostr)const {
		ostr << (*this).type() << ',' << m_patientName << ',' << m_OHIP << ',';
		return m_ticket.csvWrite(ostr);
	}

	std::istream& Patient::csvRead(std::istream& istr) {
		char Cstr[51] = { '\0' };
		istr.get(Cstr, 51, ','); //?? getline
		if (m_patientName != nullptr) {
			delete[] m_patientName;
			m_patientName = nullptr;
		}
		if (Cstr != NULL) {
			int size = strlen(Cstr) + 1;
			m_patientName = new char[size];
			strcpy(m_patientName, Cstr);
		}
		istr.ignore(256, ',');
		istr >> m_OHIP;
		istr.ignore();
		return m_ticket.csvRead(istr);
	}

	std::ostream& Patient::write(std::ostream& ostr)const {
		m_ticket.write(ostr);
		ostr << endl;
		ostr << m_patientName << ", OHIP: " << m_OHIP;
		return ostr;
	}

	std::istream& Patient::read(std::istream& istr) {
		char Cstr[51] = { '\0' };
		cout << "Name: ";
		istr.get(Cstr, 51, '\n');
		if (m_patientName != NULL) {
			delete[] m_patientName;
			m_patientName = nullptr;
		}
		if (Cstr != NULL) {
			int size = strlen(Cstr) + 1;
			m_patientName = new char[size];
			strcpy(m_patientName, Cstr);
		}
		istr.ignore(256, '\n');
		cout << "OHIP: ";
		m_OHIP = getInt(100000000, 999999999);
		return istr;
	}

}