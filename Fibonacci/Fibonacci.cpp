/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Arjhi
 *
 * Created on October 10, 2020, 9:56 PM
 */

// have 1 the initial number
// have 1 the initial previous number
// add those two and name it new number
// name the current number previous number
// have the limit on how much numbers it would generate

#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <numeric>

using namespace std;


int main() {
    string inLimit;
    cout << "How much fibonacci numbers do you want: ";
    getline(cin, inLimit);
    int rangeNumber = stoi(inLimit);
    int index = 0;
    int prevNumber = 1;
    int newNumber = 0;
    
    while (index < rangeNumber) {
        index += 1;
        int shortcut = newNumber;
        newNumber += prevNumber;
        prevNumber = shortcut;
        cout << newNumber << endl;
    }
    return 0;
}
// ctrl + Shift down arrow to duplicate texts easily just a discovery

