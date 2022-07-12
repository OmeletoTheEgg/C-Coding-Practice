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
#include <set>
#include <tuple>

// to define the numbers only vectors, you might wanna find a way to define a vector of indices that is not existing to the indexX and indexPlus and so on.

using namespace std;

vector<int> range(int start, int end, int step) {
    vector<int> range;
    while (start <= end) {
        range.push_back(start);
        start += step;
    }
    return range;
}

vector<int> getStringVectorIndex(vector<string> v, string K) { 
    vector<int> indices;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == K) {
            indices.push_back(i);
        }
    }
    return indices;
} 

vector<string> stringToVector(string inputString, char separator) {
    vector<string> vecsWords;
    stringstream ss(inputString);
    string indvString;
    while(getline(ss, indvString, separator)) {
        vecsWords.push_back(indvString);
    }
    return vecsWords;
}

string vectorToString(vector<string> vString, char separator) {
    string joinedVector("");
    for(int i = 0; i < vString.size(); ++i) {
        joinedVector += vString[i] + separator;
    }
    return joinedVector;
}

vector<int> findSubstringMatches(string &wholeString, string findString) {
    vector<int> indices;
    int index = wholeString.find(findString, 0);
    while(index != string::npos) {
        indices.push_back(index);
        index = wholeString.find(findString, index + 1);
    }
    return indices;
}

string trimWhitespaceSides(string &trimString) {
    string whitespaces(" \n\t\r\f");
    trimString.erase(trimString.find_last_not_of(whitespaces) + 1);
    trimString.erase(0, trimString.find_first_not_of(whitespaces));

    return trimString;
}

string replaceSubstrings(string wholeString, string subString, string replacerString) {
    vector<int> indices = findSubstringMatches(wholeString, subString);
    if(indices.size() != 0) {
        int lengthDifference = replacerString.size() - subString.size();
        int timesLoop = 0;
        for(auto index: indices) {
            wholeString.replace(index + (timesLoop * lengthDifference), subString.size(), replacerString);
            timesLoop++;
        }
    }
    return wholeString;
}

void SolveForX(string equation) {
    vector<string> vecEquation = stringToVector(equation, ' ');
    vector<int> indexAll = range(0, vecEquation.size() - 1, 1);
    vector<int> indexX = getStringVectorIndex(vecEquation, "x");
    vector<int> indexPlus = getStringVectorIndex(vecEquation, "+");
    vector<int> indexEqual = getStringVectorIndex(vecEquation, "=");
    vector<int> indexNumbers;
    vector<int> notNumbers;
    
    copy(indexX.begin(), indexX.end(), back_inserter(notNumbers));
    copy(indexPlus.begin(), indexPlus.end(), back_inserter(notNumbers));
    copy(indexEqual.begin(), indexEqual.end(), back_inserter(notNumbers));
    set_difference(indexAll.begin(), indexAll.end(), notNumbers.begin(), notNumbers.end(),
                        inserter(indexNumbers, indexNumbers.begin()));
    
}

int main(int argc, char** argv) {
    
    cout << "Enter your equation: ";
    string equation;
    getline(cin, equation);
    SolveForX(equation);
    
}
    