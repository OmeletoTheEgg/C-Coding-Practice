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
#include <fstream> 

#include <iterator>

#include <regex>

int main() {
    double nominal;
    double rate;
    do {
        std::cin >> nominal;
        std::cin >> rate;
        std::cout << nominal - nominal*(rate*0.01) << "\n";
        std::cout << nominal + nominal*(rate*0.01) << "\n";
    } while (true);
    
}