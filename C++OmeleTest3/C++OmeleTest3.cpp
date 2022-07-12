
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
 Use the for(auto thing if you want to pass the value of a vector to that new variable you'll define in a loop
 However if you want to have like by 1's or full control of your integration loop you could use the normal way of making lops
 * to do declaring a function without having var = function() we must use pointers, it's a bit tricky. Put & operator on the function(string &str);
 * we'll discover more about pointers don't worry
 * the things inside function() is called prototype
 * all about checking function (isalnum(), isalpha(), isupper(), islower(), isdigit(), isspace())
 * analogy for for() statement is just like putting multiple objects to newly named boxes, and loop/cycle through it. It's a conditional loop 
 * statements is the name of the things we call for, while, do, if, else, switch, try, except, auto, etc.
 * static_cast<char> converting vectors of ascii to letters.
 * If we're finding for some existing algorithm(e.g. finding which index of vector has string of (x)), why don't we make one?
 * "auto" is a data type, same as int, double, bool, float, short long lo
 * vector<data_type> must be something higher than data types
 * programming is prior to understanding the types, and when you do understand it's easy for you to know the rules, and speak fluently what you want to implement
 * randVal = min + rand() % ((max + 1) - min); is a clever way to do map
 * Recursion functions!
 * Recursive functions works if you call the function inside its function.
 * Overloaded functions, when there's two functions with the same name. You can just use if or switch conditional statements to use them.
 *  Lambda expressions and other functions built in cstlib
 * Lambda expressions mixed with cstlib is best if you wanna sort, or conditionalize a vector, like what derek did. ofc find out another ways how to use it
 * Iterators are like str.begin(), str.end() that's why they don't work on normal std::string. Iterators are the things inside for conditional loop statement or i.
 * Iterators like in for(auto i: vecVals) gets the value of the vector inside each boxes in loop
 * Conditional lambda is usually written like this: [] (int x, int y) {return x < y};
 * Ternary operator, a compact if and else statement
 * And a lambda function that is going to operate using a ternary operator
 * function<int(int)> is for recursive function in lambda expressions, however you have to #include functional
 * we can do "if(std::find(vec.begin(), vec.end(), search) != vec.end()) {do_that();} if we want to say "if this search is not existing to this vector
 * https://www.xspdf.com/resolution/50178820.html this site is full of vector and checking
 * 
 * Lambda expressions is when you want to make an anonymous function, when you want to treat your function a variable
 * [] in lambda expressions are called capture
 */
using namespace std;

/*vector<int> getStringVectorIndex(vector<string> v, string K) { 
    vector<int> indices;
    auto it = find(v.begin(), v.end(), K); 
    if (it != v.end()) { 
        indices.push_back(distance(v.begin(), it));
    } else { 
        indices.push_back(-1);
    }
    cout << indices[0];
    return indices;
   
} */

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

string CaesarCipher(string TheString, int Range, bool Caesarize) {
    string decrypted("");
    string encrypted("");
    if(Caesarize == true) {
        for(char characters: TheString) {
            //decrypted += to_string((int) characters + (int) Range);
            int ascii = characters + Range;
            char c = static_cast<char> (ascii);
            decrypted += c;
        }
        
        return decrypted;
    }/* else {
        for(char characters: TheString) {
            decrypted += to_string((int) characters + Range);
        }
        return encrypted;
    }*/
}
/*void SolveForX(string equation) {
    vector<string> vecEquation = stringToVector(equation, ' ');
    vector<int> xIndices = getStringVectorIndex(vecEquation, "x");
    int num1;
    for(auto x: xIndices) {
    }
    
    cout << num1;
}
*/

vector<int> generateRandomVector(int numGenNum, int min, int max) {
    vector<int> vecVals;
    srand(time(NULL));
    int i = 0, randVal = 0;
    while(i < numGenNum) {
        randVal = min + rand() % ((max + 1) - min); // Clever way to do mapping
        vecVals.push_back(randVal);
        i++;
    }
    return vecVals;
}

void BubbleSort(vector<int>& vecBubbles) {
    int i = vecBubbles.size() - 1;
    while (i >= 1) {
        int j = 0;
        while (j < i) {
            if(vecBubbles[j] >= vecBubbles[j+1]) {
                int temp = vecBubbles[j];
                vecBubbles[j] = vecBubbles[j+1];
                vecBubbles[j+1] = temp;
            } 
            j += 1;
        }
        i -= 1;
    }
}

/*int Fib(int index) {
    if (index < 2) {
        return index;
    } else {
        return Fib(index - 1) + Fib(index - 2);
    }
}*/

double Area(double radius) {
    return 3.14159 * pow(radius, 2);
}
double Area(double height, double weight) {
    return height * weight;
}

vector<int> generateFibonacci(int value) {
    function<int(int)> Fib = [&Fib](int n){return n < 2 ? n : Fib(n - 1) + Fib(n - 2);};
    vector<int> list;
    int i = 0;
    while (i <= value) {
        list.push_back(Fib(i));
        i += 1;
    }
    return list;
}

int main(int argc, char** argv) {
    
    // Lambda expressions and other functions built in cstlib
    
    // a lambda function that is going to operate using a ternary operator
    
    vector<int> FiboList = generateFibonacci(10);
    
    for(auto i: FiboList) {
        cout << i << "\n";
    }
    
    
    // ternary operator: compact if else statement
    
    /*int age = 23;
    bool canIvote = (age >= 18) ? true : false;
    cout.setf(ios::boolalpha);
    cout << "Can I vote? : " << canIvote << "\n";*/
    
    //playing with transform() algorithm function
    
    /*vector<int> vecList1 = {1, 2, 3, 4, 5};
    vector<int> vecList2 = {1, 2, 3, 4, 5};
    vector<int> vec3(5);
    
    transform(vecList1.begin(), vecList1.end(), vecList2.begin(), vec3.begin(), [](int x, int y){return x + y;}); //defining two or more values like in (int x, int y) shows that x and y's cycle through both vectors but they are different. I think this is a best alternative for the moving ascii code thing encrypting because you have to call each arrays of index of strings but they are different. 
    
    for (auto x: vec3) cout << x << "\n";*/
    
    // yeeting again with for each, here's a function that doubles  vector values. I think & inside [] is cleverly used to input any variables declared outside
    
    /*vector<int> vecVals = generateRandomVector(4, 1, 10);
    for (auto x: vecVals) cout << x << "\n";
    vector<int> doubledVec;
    cout << "\n";
    for_each(vecVals.begin(), vecVals.end(), [&](int x){doubledVec.push_back(x * 2);});
    
    for (auto x: doubledVec) cout << x << "\n";*/
    
    // copy_if with inputting the outside variable directly i still don't get it
    
    /*vector<int> vecVals = generateRandomVector(4, 1, 10);
    int divisor;
    vector<int> vecVals2;
    cout << "List of vectors that is divisble by : ";
    cin >> divisor;
    
    copy_if(vecVals2.begin(), vecVals2.end(), back_inserter(vecVals2),[divisor](int x){return (x % divisor) == 0;}); //[] i think is where you input your values in, but in this case it's being filled by the sort, copy_if, for_each
    for(auto x: vecVals2) cout << x << "\n";*/
    
    // for_each calling each values in an vector
    
    /*vector<int> vecVals = generateRandomVector(4, 1, 10);
    int sum = 0;
    for_each(vecVals.begin(), vecVals.end(), [&](int x){sum += x;}); // [&] is like using & to get the value outside by referencing. You need that if you wanna get something outside. It is called capture
    //for more explanations about capture[] see  https://en.cppreference.com/w/cpp/language/lambda
    
    cout << "sum of those random vector values " << sum << "\n";*/
    
    // copy_if and back_inserter() same as push.back() however it's an iterator
    
    /*vector<int> vecVals = generateRandomVector(4, 1, 10);
    vector<int> evenVecVals;
    
    copy_if(vecVals.begin(), vecVals.end(), back_inserter(evenVecVals), [](int x){return (x % 2) == 0;});
    for (auto yeet: evenVecVals) cout << yeet << "\n";*/
    
    // sort(begin, end, what lambda expression condition)
    
    /*vector<int> vecVals = generateRandomVector(4, 1, 10);
    for(auto val: vecVals) cout << val << "\n";
    sort(vecVals.begin(), vecVals.end(), [](int x, int y){return x < y;});
    for(auto val: vecVals) cout << val << "\n";*/
    
    // All about recursive functions and overloaded functions below
    
    /*char input;
    cout << "Area of Circle (c) or Rectangle (r) : ";
    cin >> input;
    
    switch(input){
        case 'c':
            double radius;
            cout << "Enter radius : ";
            cin >> radius;
            cout << Area(radius);
            break;
        case 'r':
            double height, weight;
            cout << "Enter height : ";
            cin >> height;
            cout << "Enter weight : ";
            cin >> weight;
            cout << Area(height, weight);
            break;
        default:
            cout << "Please enter only c or r.";
    }    
    */
    /*int index;
    cout << "How many fibonacci numbers you want to generate? : " << "\n";
    cin >> index;
    printf("Fib(%d) = %d", index, Fib(index));*/
    
   /* vector<int> random = generateRandomVector(3, 5, 50);
    for(int x = 0; x < random.size(); ++x) {
        cout << random[x] << "\n";
    }
    BubbleSort(random);
    
    for(auto x : random) {
        cout << x << "\n";
    }*/
    /*vector<int> vecVals = generateRandomVector(10, 5, 50);
    for(auto x : vecVals) {
        cout << x << "\n";
    }*/
    
    /*cout << "Enter your equation: ";
    string equation;
    getline(cin, equation);
    SolveForX(equation);*/
    
    /*string theString("Make me secret.");
    string encryptedString = CaesarCipher(theString, 5, true);
    string decryptedString = CaesarCipher(encryptedString, 5, false);
    
    cout << "Encrypted " << encryptedString << "\n";
    cout << "Decrypted " << decryptedString << "\n";*/
    
    /*char letterZ = 'z';
    char num3 = '3';
    char aSpace = ' ';
    
    cout << "Is z a letter or number??? " << isalnum(letterZ) << "\n";
    cout << "Is z a letter??? " << isalpha(letterZ) << "\n";
    cout << "Is z uppercase??? " << isupper(letterZ) << "\n";
    cout << "Is z lowercase??? " << islower(letterZ) << "\n";
    cout << "Is 3 a number??? " << isdigit(num3) << "\n";
    cout << "Is space a space??? " << isspace(aSpace) << "\n";*/
    
    /*cout << replaceSubstrings("to know and not to know", "know", "be") << "\n";
    
    string trimString("      YEEEEE    YEEEE\t YEEEE \f YEEEE     ");
    trimWhitespaceSides(trimString);
    cout << trimString << "\n";
    
    string phrase("To be or not to be");
    vector<int> matches = findSubstringMatches(phrase, "be");
    
    for(int i = 0; i < matches.size(); ++i) {
        cout << matches[i] << "\n";
    }
    
    vector<string> vCusts(3);
    vCusts[0] = "Omeleto";
    vCusts[1] = "Sam";
    vCusts[2] = "Thomas";
    
    string sCusts = vectorToString(vCusts, ' ');
    cout << sCusts << "\n";
    
    vector<string> vString = stringToVector("This is a fucking random string", ' ');
    
    for (int i = 0; i < vString.size(); ++i) {
        cout << vString[i] << "\n";
    }*/
    return 0;
}

