/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Arjhi
 *
 * Created on October 10, 2020, 11:22 PM
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <numeric>

using namespace std;

int main() {
    int size = 20;
    vector<vector<int>> array(size, vector<int> (size));
    
    for (int x = -1*(size / 2); x <= size - size/2; ++x) {
        int y = x;
        array[x + size/2][y + size/2] = 1;
        for (int i = 0; i < array.size(); ++i) {
            for (int j = 0; j < array.size(); ++j) {
                cout << array[i][j] << " ";
            }
            cout << "\n";
        }
    }
    
   
    
    
    return 0;
}

