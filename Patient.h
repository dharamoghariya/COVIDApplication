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

#include <iostream>
#include "IOAble.h"
#include "Ticket.h"
#ifndef SDDS_PATIENT_H_
#define SDDS_PATIENT_H_
namespace sdds {
	class Patient : public IOAble {
		char* m_patientName = nullptr;
		int   m_OHIP = 0;
		Ticket m_ticket;
		bool IOflag; // the file IO flag;
	public:
		Patient(int ticketNum = 0, bool fileIOflag = false);
		Patient(const Patient& p) = delete;	// Copy Constructor 
		Patient& operator=(const Patient& p) = delete;	// Copy Assignment Operator
		~Patient();
		virtual char type() const = 0;
		bool fileIO() const;
		void fileIO(bool fileIOflag);
		bool operator==(const char c) const;
		bool operator==(const Patient& p) const;
		void setArrivalTime();
		operator Time() const;
		int number() const;
		std::ostream& csvWrite(std::ostream& ostr)const;
		std::istream& csvRead(std::istream& istr);
		std::ostream& write(std::ostream& ostr)const;
		std::istream& read(std::istream& istr);
	};
}
#endif // !SDDS_PATIENT_H_


