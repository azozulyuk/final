/* Citation and Sources...
-----------------------------------------------------------
Final Project Milestone 56
Module:56
Filename: Utils.cpp
-----------------------------------------------------------
Author: Anastasiya Zozulyuk
Student number: 139,230,247
Email: azozulyuk@myseneca.ca
Subject: BTP200NAA
-----------------------------------------------------------
Revision History
------- --------- ------------------------------------------
Version Date      Reason
V0.7    2025/04/1  Completing code
V0.8    2025/04/6  Debugged
V0.9    -         Asked prof for help for XYZ
V1.0    2026/04/7  Ready for submission
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my work for function main,ect.
-----------------------------------------------------------
*/

#define _CRT_SECURE_NO_WARNINGS
#include "Utils.h"
#include <cstring>
#include <iostream>
using namespace std;

namespace seneca {

    Utils ut;

    char* Utils::makeBillFileName(char* filename, size_t billNo) const {
        char billFileName[21] = "bill_";
        size_t temp = billNo;
        int cnt = 5;
        int length;

        do {
            cnt++;
            temp /= 10;
        } while (temp > 0);

        length = cnt;

        while (billNo > 0) {
            billFileName[--cnt] = (billNo % 10) + '0';
            billNo /= 10;
        }

        if (billFileName[cnt - 1] == '\0') {
            billFileName[--cnt] = '0';
        }

        for (int i = 0; ".txt"[i]; i++) {
            billFileName[length++] = ".txt"[i];
        }

        billFileName[length] = '\0';
        strcpy(filename, billFileName);
        return filename;
    }

    int Utils::getInt() const {
        int user_Input{};
        while (true) {
            if (cin.peek() == '\n') {
                cin.ignore(10000, '\n');
                cout << "You must enter a value: ";
            }
            else {
                cin >> user_Input;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Invalid integer: ";
                }
                else if (cin.get() != '\n') {
                    cin.ignore(10000, '\n');
                    cout << "Only an integer please: ";
                }
                else {
                    return user_Input;
                }
            }
        }
    }

    int Utils::getInt(int min, int max) const {
        int user_Input{};
        while (true) {
            user_Input = getInt();
            if (user_Input < min || user_Input > max) {
                cout << "Invalid value: [" << min << "<= value <=" << max << "], try again: ";
            }
            else {
                return user_Input;
            }
        }
    }
}
