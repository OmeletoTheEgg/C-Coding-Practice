/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * new things here
 * 
 * - multidimensional vectors and arrays
 *
 * 
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
    /*
    vector<vector<int>> extendableMonitor(3);
    
    for (int x = 0; x < extendableMonitor.size(); ++x) {
        for (int y = 0; y < extendableMonitor.size(); ++y) {
            extendableMonitor[x][y] = 0;
            cout << extendableMonitor[0][y];
        }
        cout << extendableMonitor[x][0] << "\n";
    }
    */
    
    string inSize;
    cout << "How long you want your monitor would be?: ";
    getline(cin, inSize);
    int size = stoi(inSize);
    vector<vector<int>> array(size, vector<int> (size));
    
    for (int i = 0; i < array.size(); ++i) {
        for (int j = 0; j < array.size(); ++j) {
            array[i][j] = 0;
            cout << array[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}

