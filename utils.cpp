/*
Name:           Dhara Moghariya
Student Number: 161449194
Email:          dmoghariya@myseneca.ca
Section:        NAA
Date:		    November 30, 2020
-----------------------------------------------------------
Citation and Sources...
Final Project Milestone 1
Module: utils
Filename: utils.cpp
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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "utils.h"
#include "Time.h"
using namespace std;
namespace sdds {
    bool debug = false;

    int getTime() {
        int mins = -1;
        if (debug) {
            Time t(0);
            cout << "Enter current time: ";
            do {
                cin.clear();
                cin >> t;
                if (!cin) {
                    cout << "Invlid time, try agian (HH:MM): ";
                    cin.clear();
                }
                else {
                    mins = int(t);
                }
                cin.ignore(1000, '\n');
            } while (mins < 0);
        }
        else {
            time_t t = time(NULL);
            tm lt = *localtime(&t);
            mins = lt.tm_hour * 60 + lt.tm_min;
        }
        return mins;
    }

    int getInt() {
        int value;
        bool badEntry;
        char nextChar;
        do {
            badEntry = false;
            cin >> value;
            if (cin.fail()) {
                cout << "Bad integer value, try again: ";
                cin.clear();
                cin.ignore(3000, '\n');
                badEntry = true;
            }
            else {
                nextChar = cin.get();
                if (nextChar != '\n') {
                    cout << "Only enter an integer, try again: ";
                    cin.ignore(3000, '\n');
                    badEntry = true;
                }
            }
        } while (badEntry);
        return value;
    }

    // Function will return valid value in Range.
    int getInt(int min, int max) {
        int value = 0;
        do {
            value = getInt();
            if (value > max || value < min) {
                cout << "Invalid value enterd, retry[" << min << " <= value <= " << max << "]: ";
            }
        } while (value > max || value < min);
        return value;
    }

    

}