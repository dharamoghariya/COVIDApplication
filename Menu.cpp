/*
Name:           Dhara Moghariya
Student Number: 161449194
Email:          dmoghariya@myseneca.ca
Section:        NAA
Date:		    November 13, 2020
-----------------------------------------------------------
Citation and Sources...
Final Project Milestone 1
Module: Menu
Filename: Menu.cpp
Version 1.0
Author	John Doe
Revision History
-----------------------------------------------------------
Date      Reason
2020/11/12  Initial Implementation
2020/11/13  Testing and Debugging
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "utils.h"
#include "Menu.h"
using namespace std;
namespace sdds {

    Menu::Menu(const char* text, int NoOfSelections) {
        m_noOfSel = NoOfSelections;
        m_text = new char[strlen(text) + 1];
        strcpy(m_text, text);
    }

    Menu::~Menu() {
        delete[] m_text;
    }

    std::ostream& Menu::display(std::ostream& ostr)const {
        ostr << m_text << endl;
        ostr << "0- Exit" << endl;
        ostr << "> ";
        return ostr;
    }

    int& Menu::operator>>(int& Selection) {
        display();
        Selection = getInt(0, m_noOfSel);
        return Selection;
    }


}