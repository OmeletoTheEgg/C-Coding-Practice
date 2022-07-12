
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <numeric>
#include <ctime>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cctype>
#include <functional>

/*
 *
 * 1. 2 * Menger(1.06666)
 * 2. 1.06666 * Menger(
 * 
 * 
 *  
 */
long double Menger(int index) {
    long double result = 1;
    for (int i = 1; i <= index; ++i) {
        result *= ((2.0f * i)/((2.0f * i) + 1.0f) * (2.0f * (i + 1.0f))/((2.0f * (i + 1.0f)) - 1.0f));
    }
    return 4 * result;
    
    /*if (index == 0) {
        return 1;
    } else {
        index -= 1;
        double result = number * Menger((2*index)/(2*index-1)*(2*index)/(2*index+1));
        return result;
    }*/
}

/*int Factorial(int number) {
    if(number == 1) {
        return 1;
    } else {
        return number * Factorial(number - 1);
    }
}*/
int main(int argc, char** argv) {
    std::cout << Menger(999999999) << "\n";
    return 0;
}

