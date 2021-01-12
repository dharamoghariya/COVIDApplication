/*
Name:           Dhara Moghariya
Student Number: 161449194
Email:          dmoghariya@myseneca.ca
Section:        NAA
Date:		    November 30, 2020
-----------------------------------------------------------
Final Project Milestone 5
Module: PreTriage
Filename: PreTriage.cpp
Version 1.0
Revision History
-----------------------------------------------------------
Date		Reason
2020/11/30  Initial Implementation
2020/12/01  Testing and Debugging
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include "PreTriage.h"
#include "utils.h"
#include "CovidPatient.h"
#include "TriagePatient.h"
using namespace std;
namespace sdds {

    PreTriage::PreTriage(const char* dataFilename) : m_appMenu("General Hospital Pre-Triage Application\n1- Register\n2- Admit", 2), m_pMenu("Select Type of Admittance:\n1- Covid Test\n2- Triage", 2) {
        m_dataFilename = new char[strlen(dataFilename) + 1];
        strcpy(m_dataFilename, dataFilename);
        m_averCovidWait = 15;
        m_averTriageWait = 5;
        load();
    }

    PreTriage::~PreTriage() {
        std::ofstream iFile(m_dataFilename);
        //if (iFile.is_open()) {}  ????
        //iFile << "Saving Average Wait Times, COVID Test :";
        m_averCovidWait.write(iFile);
        //iFile << ", Triage :";
        iFile << ",";
        m_averTriageWait.write(iFile);
        iFile << endl;

        cout << "Saving Average Wait Times," << endl;
        cout << "   COVID Test: ";
        m_averCovidWait.write(cout);
        cout << endl;
        cout << "   Triage: ";
        m_averTriageWait.write(cout);
        cout << endl;

        cout << "Saving m_lineup..." << endl; //?
        for (int i = 0; i < m_lineupSize; i++) {
            m_lineup[i]->csvWrite(iFile);
            cout << i + 1 << "- ";
            m_lineup[i]->csvWrite(cout);
            iFile << "\n";
            cout << endl;;
        }

        for (int i = 0; i < m_lineupSize; i++) {
            delete m_lineup[i];
        }
        delete[] m_dataFilename;
        cout << "done!" << endl;
    }

    const Time PreTriage::getWaitTime(const Patient& p)const {
        int numOfPatients = 0;
        for (int i = 0; i < m_lineupSize; i++) {
            if (m_lineup[i]->type() == p.type()) {
                numOfPatients++;
            }
        }
        Time waitTime; //??p type avg time???
        waitTime *= numOfPatients;
        return waitTime;
    }

    void PreTriage::setAverageWaitTime(const Patient& p) {
        // CT: Current Time
        int currentTime = getTime();
        // PTT : Patient's Ticket Time
        int patientTicketTime = int((Time)p);
        // PTN : Patient's Ticket Number
        int patientTicketNum = p.number();
        // AWT : Average Wait Time(Covid or Triage)
        // AWT = ((CT - PTT) + (AWT * (PTN - 1))) / PTN
        if (p.type() == 'C') {
            int avgWaitTime = int(m_averCovidWait);
            m_averCovidWait = ((currentTime - patientTicketTime) + (avgWaitTime * (patientTicketNum - 1))) / patientTicketNum;
        }
        else {
            int avgWaitTime = int(m_averTriageWait);
            m_averTriageWait = ((currentTime - patientTicketTime) + (avgWaitTime * (patientTicketNum - 1))) / patientTicketNum;
        }
        
    }

    //????
    void PreTriage::removePatientFromLineup(int index) {
        removeDynamicElement(m_lineup, index, m_lineupSize);
    }
    
    int PreTriage::indexOfFirstInLine(char type) const {
        int index = -1;
        for (int i = 0; i < m_lineupSize; i++) {
            if (m_lineup[i]->type() == type) {
                index = i;
                break;
            }
        }
        return index;
    }

    void PreTriage::load() {
        cout << "Loading data..." << endl;

        std::ifstream iFile(m_dataFilename);
        if (iFile.is_open()) {
            m_averCovidWait.read(iFile);
            iFile.ignore(1, ',');
            m_averTriageWait.read(iFile);
            iFile.ignore(1, '\n');
            Patient* patient = nullptr;
            char type; 
            while (!iFile.eof() && m_lineupSize < maxNoOfPatients) {
                type = iFile.get();
                iFile.ignore(1, ',');
                if (type == 'C' || type == 'T') {
                    if(type == 'C')
                        patient = new CovidPatient();
                    else
                        patient = new TriagePatient();

                    patient->fileIO(true);
                    patient->csvRead(iFile);
                    patient->fileIO(false);
                    m_lineup[m_lineupSize] = patient;
                    m_lineupSize++;
                    iFile.ignore(600, '\n');
                }
            }
            if (!iFile.eof()) {
                cout << "Warning: number of records exceeded " << maxNoOfPatients << endl;
            }
            cout << m_lineupSize << " Records imported..." << endl << endl;
        }
        else {
            cout << "No data or bad data file!" << endl << endl;
        }
    }

    void PreTriage::reg() {
        if ( m_lineupSize >= maxNoOfPatients) {
            cout << "Line up full!" << endl;
        }
        else {
            //m_pMenu.display();

            Patient* patient = nullptr; //??
            int selection;
            m_pMenu >> selection;
            if(selection == 1 || selection == 2) {
                if (selection == 1) {
                    patient = new CovidPatient();
                }
                else {
                    patient = new TriagePatient();
                }
                patient->setArrivalTime(); //set the patient's arrival time
                cout << "Please enter patient information: " << endl; //??
                patient->read(cin); //extract the patient from cin
                
                //??? extra
                m_lineup[m_lineupSize] = patient;
                m_lineupSize++;

                cout << endl;
                cout << "******************************************" << endl;
                patient->write(cout); //insert the patient into cout
                cout << "Estimated Wait Time: ";
                cout << getWaitTime(*patient) << endl; //print the return value of getWaitTime for the patient.
                cout << "******************************************" << endl << endl;
            }
        }
    }

    void PreTriage::admit() {
        //m_pMenu.display();
        char type='\0';
        int selection;
        m_pMenu >> selection;
        if (selection == 1) {
            type = 'C';
        }
        else if (selection == 2) {
            type = 'T';
        }

        // else turminate function
        if (selection != 0) {
            int index = indexOfFirstInLine(type);
            if (index != -1) {
                cout << endl;
                cout << "******************************************" << endl;
                cout << "Calling for ";
                m_lineup[index]->write(cout); //cout << m_lineup[index]; //insert the patient into cout
                cout << "******************************************" << endl << endl;
                setAverageWaitTime(*m_lineup[index]); //set Average Wait Time for the patient
                removePatientFromLineup(index); //remove the patient from the lineup.
            }
        }

    }
    
    void PreTriage::run(void) /*: m_appMenu.display(ostr)*/ {
        //m_appMenu.display();
        int selection;
        while (m_appMenu >> selection) {
            if (selection == 1) {
                reg();
            }
            else if (selection == 2) {
                admit();
            }
            else {
                break;
            }
        }
    }
}