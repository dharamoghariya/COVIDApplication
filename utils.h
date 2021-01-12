/*
Name:           Dhara Moghariya
Student Number: 161449194
Email:          dmoghariya@myseneca.ca
Section:        NAA
Date:		    November 30, 2020
-----------------------------------------------------------
Final Project Milestone 1
Module: utils
Filename: utils.h
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

#ifndef SDDS_UTILS_H_
#define SDDS_UTILS_H_
#include <iostream>
namespace sdds {
    int getInt(int min, int max);
    int getInt();
    int getTime(); // returns the time of day in minutes

    extern bool debug; // this makes bool sdds::debug variable in utils.cpp global to 
                       // all the files which include: "utils.h" 
                       //(you will learn this in detail in oop345)

    // This template will be used to remove a Patient from the lineup when admitted.
    template <typename type>
    void removeDynamicElement(type* array[], int index, int& size) {
        delete array[index];
        for (int j = index; j < size; j++) {
            array[j] = array[j + 1];
        }
        size--;
    }

}
#endif // !SDDS_UTILS_H_

