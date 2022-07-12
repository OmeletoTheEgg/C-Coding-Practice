
/*
 * All new things that is in this code:
 * 
 * - redoing pointers
 * - my interest bank calculator (wrongly done)
 * - making range function (not fully reliable)
 * - making tree generator
 *      - learned how to while loops
 *      - learned for(auto x: myVecs) is very useful for repeating actions as long as there's value to spit out
 *      - learned how to use range function
 *      - learned that you can do casting playing with string: string(4, x)
 * - Exception handlings, try, throw, then catch. Not so much a thing to memorize but you need it. THere are two types
 * - Making a guessing game
 *      - learned to generate random numbers
 *      - learned how to use modulus
 *      - learned do while loops
 *      - learned what's better than do while loops (just use break if the statement is met inside while() {}
 * - '\0' is a null
 * - Hell of ways how to play with strings
 *      - learned that strings is an array of char so you can call index of it as arrays
 *      - string str(""); 
 *      - string str2(str);
 *      - string str2(str, 4//start index);
 *      - string str2(4, 'x') //fill up to 4th index by x
 *      - string str2(str, `first index`, `last index`)
 *      - str.append("thing");
 *      - str.erase("thing");
 *      - str.length();
 *      - str.begin();
 *      - str.end();
 *      - str.find() (you need to add if (str.find() != std::npos) {} to make it safer)
 *      - str.front()
 *      - str.back()
 *      - str.find_not_last_of()
 *      - str.replace();
 *      - turning integers to string using to_string((int)x)
 *      - turning integers to characters simply by char vChar = vInt;
 * 
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
#include <ctime>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> range(int start, int end, int step) {
    vector<int> range;
    while (start <= end) {
        range.push_back(start);
        start += step;
    }
    return range;
}

//first try in exceptions and range

int main() {
    // Strings are flexible! Me playing with strings:
    // ASCII
    // a - z : 97 - 122
    // A - Z : 65 - 90
    
    //a machine that converts strings to ascii code (new use of for (char x:), to_string((int) ); 
    string normalStr, secretStr = "";
    cout << "What is your string? : ";
    getline(cin, normalStr);
    
    for (char x: normalStr) {
        secretStr += to_string((int)x - 23);
    }
    
    cout << secretStr << "\n";
    normalStr = "";
    
    for (int i = 0; i < secretStr.length(); i += 2) {
        string sCharCode = "";
        sCharCode += secretStr[i];
        sCharCode += secretStr[i+1];
        
        int nCharCode = stoi(sCharCode);
        nCharCode += 23;
        char chCharCode = nCharCode; //this is just how you convert integers to characters
        normalStr += chCharCode;
    }
    
    cout << normalStr << "\n";
    
    // big note that a string is an array of characters, so you can call them as array
    string testString = "test";
    cout << testString[1];
    cout << string (4, 'x');
    
    /*
    // converting string to ascii
    cout << (int)'a' << "\n";
    
    // convert integer to string
    string strNum = to_string(69);
    cout << strNum << endl;*/
    
    /*vector<string> strVec(10);
    string str("I'm a string");
    
    strVec[0] = str;
    
    //playing with begins and end of a string in character
    cout << str.front() << " " << str.back() << endl;
    
    //playing with str.length()
    cout << str.length() << endl;*/
    
    
    
    /*//playing with copy strings
    string str2(str);
    strVec[1] = str2;
    
    //choosing the a range of characters in a string, copy everything after the first (value) charcters
    string str3(str, 4);
    strVec[2] = str3;
    
    //repeat a char over and over in a certain value
    string str4(9, 's');
    strVec[3] = str4;
    
    // append a string inside, 2 ways
    strVec[4] = str.append(" fuck you");
    str += " fuck you too";
    
    // append/copy a certain range of string
    string str5(str, 1, 10);
    strVec[5] = str5;
    
    // erase a range of character
    str.erase(13, str.length() - 1);
    strVec[6] = str;
    
    //looping through all vector string made so far
    for(auto x: strVec) {
        cout << x << endl;
    }*/
    
    /*// str.find() finds first index of the string is being find
    if (str.find("string") != string::npos) {
        cout << "1st index " << str.find("string") << "\n";
        
    }
    
    // str.substr(index, value from index) 
    cout << str.substr(6, 6) << "\n";
    
    // me trying to mix substr and find
    if (str.find("string") != string::npos) {
        cout << str.substr(str.find("string")-2, 6) << "\n";
    }
    
    //reverse characters, and str.begin() and str.end() 
   
    reverse(str.begin(), str.end());
    cout << "Reverse " << str << "\n";
        
    // transform function, changes the range of string to a certain type (uppercase, lowercase, and others)
    
    string str2("Yee!");
    
    transform(str2.begin(), str2.end(), str2.begin(), ::toupper);
    cout << str2 << endl;
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    cout << str2 << endl;
    */
    
    
    //doing arrays with null character, and null characters will be included inside the size of
    /*char poop[] = {'p', 'o', 'o', 'p', '\0'};
    cout << "The size of poop is " << sizeof(poop) << "\n"; */
    
    //new way of doing string test, copy string:
    /*string stri("yes");
    string stri2(stri);
    cout << stri << " " << stri2;*/
    
    //guessing number game
    /*srand(time(NULL));
    int secretNumber = rand() % 50;
    int guessedNumber = 0;
    //alternative to do-while loop (better)
    while(true) {
        cout << "What is your number? : ";
        cin >> guessedNumber;
        if (guessedNumber < secretNumber) cout << "It so small!\n";
        if (guessedNumber > secretNumber) cout << "It too big!\n";
        if (secretNumber == guessedNumber) break;
    }*/
        
    //doing do-while loop
    /*srand(time(NULL));
    int secretNumber = rand() % 50;
    int guessedNumber = 0;
    
    do {
        cout << "What is your number? : ";
        cin >> guessedNumber;
        if (guessedNumber < secretNumber) cout << "It so small!\n";
        if (guessedNumber > secretNumber) cout << "It too big!\n";
        
    } while (guessedNumber != secretNumber);
    
    cout << guessedNumber << " is correct!";*/
    
    // once you throw the message, it breaks the whole code. So it's better to put them on a condition.
    // the good thing is you can insert a lot of throws on attempts for debugs
    /*try {
        string agreement;
        cout << "Should we throw the exception or not? (Yes/No): ";
        getline(cin, agreement);
        
        if (agreement == "Yes") {
            throw "You threw the exception";
        } else if (agreement == "No") {
            throw "You refuse to throw the exception";
        } else {
            throw runtime_error("Write the agreement according to what's written on the parentheses");
        }
    }
    catch (exception &exp) {
        cout << "Handled exception : " << exp.what() << "\n";
    }
    catch (const char *exp) {
        cout << "Handled exception : " << exp << "\n";
    }*/
    
    /*int num1, num2;
    cout << "Insert number 1: ";
    cin >> num1;
    cout << "Insert number 2: ";
    cin >> num2;
    
    try{
        if (num2 == 0) {
            throw "Division by zero is not possible";
        } else if (num1 == 0) {
            throw "Division by 0 is always 0 you dumb";
        } else {
            printf("%d + %d = %d", num1, num2, (num1 / num2));
        }
        
        
    }
    
    catch (const char* exp){
        cout << "Error : " << exp << "\n";
    }
    
    return 0;*/
}
/*
int main() {
    //remake the auto
    int spaces = 0, hashes = 1, trunkSpace = 0;
    string treeHeight;
    cout << "How tall is the fucking tree: ";
    getline(cin, treeHeight);
    int height = stoi(treeHeight);
    spaces = height - 1;
    trunkSpace = height - 1;
    while (height != 0) {
        for(auto x: range(1, spaces, 1)) {
            cout << " ";
        }
        for(auto x: range(1, hashes, 1)) {
            cout << "#";
        }
        cout << "\n";
        spaces -= 1;
        hashes += 2;
        height -= 1;
    }
    
    for(auto x: range(1, trunkSpace, 1)) {
        cout << " ";
    }
    cout << "#";
    
}

*/

/*
int main() {
    
    
    
    
    // This worked too, casting a string inside cout and doing indexing
    int height = 4;
    for (int i = 1; i <= height; ++i) cout << string(height - i, ' ') << string(i * 2 - 1, '#') << endl;
      
    
    
    // Tree generator (a way to repeat an action until it meets something within a range, combination of while loop and for with range function)
    int space = 0, hashes = 1, treeHeight = 0, stumpSpaces = 0;
    string treeHeightString;
    cout << "How tall is the tree? : ";
    getline(cin, treeHeightString);
    treeHeight = stoi(treeHeightString);
    space = treeHeight - 1;
    stumpSpaces = treeHeight - 1;
    
    while (treeHeight != 0) {
        for (auto x: range(1, space, 1)) {
            cout << " ";
        }
        
        for (auto x: range(1, hashes, 1)) {
            cout << "#";
        }
        cout << "\n";
                
        space -= 1;
        hashes += 2;
        treeHeight -= 1;
    }
    
    for(auto x: range(1, stumpSpaces, 1)) {
        cout << " ";
    }
    cout << "#" << "\n";
    
    
    
    // Tree thing attempt:
    
    string tallString;
    cout << "How tall is the christmas tree? : ";
    getline(cin, tallString);
    int tallInt = stoi(tallString);
    vector<int> treeLeavesWidth = range(1, 1 + (tallInt * 2), 2);
    vector<int> spaces = range(tallInt, 0, 1);
    int index = 1, j = 1;

    for (int i = 0; i < tallInt; ++i) {
        cout << spaces[i] << "\n";
        /*while (j <= treeLeavesWidth[i]) {
            
            cout << "#";
            if (j == treeLeavesWidth[i]) {
                j = 1;
                cout << "\n";
                break;
            }
            j += 1;
        }
    }
} 
*/
// Doing a range function
/*
vector<int> Range(int pStart, int pEnd, int pStep) {
    vector<int> values;
    int i = pStart;
    while (i <= pEnd) {
        values.push_back(i);
        i += pStep;
    }
    return values;
}

int main() {
    string invest, rate, years;
    cout << "How much you want to invest? : ";
    getline(cin, invest);
    cout << "What is the interest rate: ";
    getline(cin, rate);
    cout << "How many years you want the money to stay there? :";
    getline(cin, years);
    int investInt = stoi(invest);
    int rateInt = stoi(rate);
    int yearsInt = stoi(years);
    int finalRate = (rateInt * 0.01) * investInt;
    int finalEnd = (finalRate * yearsInt) + investInt;
    vector<int> range = Range(investInt, finalEnd, finalRate);
    cout << range[range.size() - 1] << "\n";
    
}

*/

/*
void AssignValue(int *pValue) {
    *pValue = 34;
}
void DoubleArray(int* arr, int size);

int main() {
    

    //redoing pointers
    int age = 18;
    int *pAge = &age;
    cout << &age << " " << *pAge << endl;
    // you can cycle through arrays using increment "pSize++ or --", stuffs is a bit different with arrays also "you don't put &"
    int size[] = {10, 18, 69};
    int *pSize = size;
    
    cout << pSize << *pSize << endl;
    pSize++;
    cout << pSize << *pSize << endl;
    // pointers using void (essential), make sure it's the same data type.
    int value = 69;
    AssignValue(&value);
    cout << value << endl;
  
    //arrays in functions
    int arr[] = {1,2,3,4};
    
    DoubleArray(arr, 4);
    
    for (int i = 0; i < 4; ++i) {
        cout << arr[i] << endl;
    }
}

void DoubleArray(int* arr, int size) {
    for(int i = 0; i < size; ++i) {
        arr[i] = arr[i] * ;
    }
}
        */