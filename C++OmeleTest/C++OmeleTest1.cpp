    
/*
 * All new things that is in this code:
 * 
 * - getline(cin, var) codes
 * - if statements and conditions
 * - stoi(converting strings to integers)
 * - cout << var;
 * - arrays and vectors
 * - play with arrays and vectors
 * - stringstream ss(var) splitting strings
 * - using while(getline(ss, var, ' ')) { vecWords.push_back(var) to fill in the vector with stringstream or anything.
 * - push.back() extending vector
 * - for(auto x: var) new way of cycling through arrays/vectors
 * - var++ increment 
 * - my first calculator
 * - printf() and %d, %.1f, %.2f, %s 
 * - iota(start, end, newStart) and the step is 1
 * - pointers (*) that stores variables to memory address, and dereference symbol (&)
 * - functions, void that doesn't return value, but can used pointers to change values
 * - using pointers in functions
 * 
 * This is the website that wakes me up about bits and bytes and data types
 * https://www.geeksforgeeks.org/c-data-types/
 * 
 * - int is basically number without decimal. Double or float is numbers with decimal
 * - short int 0 - 65535 and beyond that it will be negative and going back. 
 * check my notes for full details of my understanding
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

double AddNumbers(double firstNumber, double secondNumber);
void AssignAge(int* age);

int main() {
    
    //getting values to the user (cin) using getline (which inputs the cin to a certain string) 
    //and stoi (which converts things to int)
    //cout << "Omelehandsome" << "\n";
    /*
    string Question ("How much liter is Omeleto's cum: ");
    string omeleCumLiter, tanCumLiter;
    cout << Question;
    getline(cin, omeleCumLiter);
    cout << "How much liter is Tan's cum: ";
    getline(cin, tanCumLiter);
    int omeleCum = stoi(omeleCumLiter);
    int tanCum = stoi(tanCumLiter);
    printf("The combination of "
            "Omeleto's cum and Tan's cum in liters is: %d\n", 
            (omeleCum + tanCum));
    */
    // simple way of getting values from the user
   /*
    int km;
    
    cout << "What is your kilometer?" << endl;
    cin >> km; 
    float cValue = km * 1.609344;
    cout << "Your kilometer is: " << cValue;
    * */
    
    // I've tried branchless programming, a * (a<b) + b * (b<=a) thing, I discovered that getline could also be endl, and printf %d thing will return
    // the value chronologically on the next values you'll input. You can also make new lines using \n.
    /*
    string aString, bString;
    cout << "Input 'a' :";
    getline(cin, aString);
    cout << "Input 'b' :";
    getline(cin, bString);
    
    int a = stoi(aString);
    int b = stoi(bString);
    
    printf("a is %d, b is %d\n", a, b);
    cout << "\n" << "The larger number is: " << endl;
    
    bool condition = (a < b);
    printf("%d", condition);
     * */
    
    // let me try to make the first step of making a graphing calculator, plotting the points.
    /*
    string functionQuestion ("What is your function: ");
    string inputFunction;
    cout << functionQuestion;
    getline(cin, inputFunction);
    char x = inputFunction.find('x');
    //int x = stoi(inputFunction);
    cout << x << endl;
    */
    /*
    string Age = "0";
    string AgeQuestion ("Welcome to earth education, Mr. Alien. To know your education level, how old are you? : ");
    cout << AgeQuestion;
    getline(cin, Age);
    int AgeInt = stoi(Age);
    
    if (AgeInt == 5) {
        printf("Go to fucking kindergarten.");
    } else if ((AgeInt >= 6) && (AgeInt <= 17)) {
        printf("Go to elementary or highschool.");
    } else if ((AgeInt > 17) && (AgeInt <= 23)) {
        printf("Go to college or not.");
    } else if (AgeInt > 23) {
        printf("You're too old for school. Want to reenter school?");
        string reenterAgree;
        getline(cin, reenterAgree);
        cout << reenterAgree << endl;
    } else { 
        printf("You're to young to school.");
    };
    */
    
    /////////////////////////////////////////////////////////
    //vector experiment
    /*
    vector<int> randNum(2);
    randNum[0] = 69;
    randNum[1] = 96;
    randNum.push_back(30);
    cout << randNum[3] << "\n";
    */
    //My attempt on making calculator myself
    /*
    string inputCalculation = "2 + 3";
    vector<string> vecWords;
    stringstream ss(inputCalculation);
    string indvString;
    
    while(getline(ss, indvString, ' ')) {
        vecWords.push_back(indvString);
    }
     int fNum = stoi(vecWords[0]);
    */
    /*
    double fNum = 0, sNum = 0;
    string midOp = "";
    string inputCalculation;
    vector<string> vecString;
    string Question = "Enter your calculation (example 2 + 3): ";
    cout << Question;
    getline(cin, inputCalculation);
    stringstream ss(inputCalculation);
    string Indv;
    while(getline(ss, Indv, ' ')){
        vecString.push_back(Indv);
    }
    fNum = stoi(vecString[0]);
    sNum = stoi(vecString[2]);
    midOp = vecString[1];
    
    if(midOp == "+") {
        cout << fNum + sNum << "\n";
    } else if (midOp == "-") {
        cout << fNum - sNum << "\n";
    } else if (midOp == "*") {
        cout << fNum * sNum << "\n";
    } else if (midOp == "/") {
        cout << fNum / sNum << "\n";
    } else {
        cout << "Please enter only +, -, *, /, %" << endl;
    }
    */
    
    // "Auto" and "iota"
    
    // you can also do for loops like this short "for (auto x: myVecs) cout << x << "\n";"
    // iota can be used to map the vector list with something provided by step
    /*
    vector<int> myVecs(100);
    iota(begin(myVecs), end(myVecs), 1);
    
    for (auto x: myVecs) {
        if ((x % 2) == 0) {
            cout << x << "\n";
            
        }
    }
    */ 
    /*
    double firstNumber, secondNumber;
    cout << "Enter First Number: ";
    cin >> firstNumber;
    cout << "Enter Second Number: ";
    cin >> secondNumber;
    
    printf("%.1f + %.1f = %.1f\n", firstNumber, secondNumber, AddNumbers(firstNumber, secondNumber));
    
    return 0;*/ //first time i tried functions
    /*
    int realNumber = 69;
    
    int* pointerThing = &realNumber;
    
    cout << pointerThing << " " << *pointerThing << "\n";
    
    int intArray[] = {1, 1, 2, 3, 5, 8};
    int* pIntArray = intArray;
    
    cout << pIntArray++ << " " << *pIntArray++ << "\n";
    */ //first time pointer
    /*
    int age = 18;
    AssignAge(&age);
    cout << age << "\n";
    //*/ //pointers with functions
    int a = 90;
    int *test = &a;
    cout << *test << "\n";
         
} 
/*
void AssignAge(int* age){
    *age += 9;
}
/**/
/*
double AddNumbers(double firstNumber, double secondNumber) {
    return firstNumber + secondNumber;
    
}
*/


 
 
 
