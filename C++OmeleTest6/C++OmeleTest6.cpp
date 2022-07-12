
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

#include "OmeleTest6Header.h" //here's how we include our outside headers (in this case class)
#define PI 3.14159 // define, doing these are prioritizing the constants and things that is need to defined first
#define AREA_CIRCLE(radius) (PI * (std::pow(radius,2))) //function defining in preprocessors
// We use Template to create both functions and classes, that can work with many 
// with many different types
// Function overloading on the other hand, have multi functions that does similar things
// with different objects
// But a template instead does the same thing with different objects
//variable inside prototype 
/*template<typename T>
void Times2(T val){ 
    std::cout << val << "* 2 = " <<
            val * 2 << "\n";
}
*/
// function defined templates
template<typename T> 
T Add(T val, T val2) {
    return val + val2;
}
template<typename T>
T Max(T val, T val2) {
    return (val < val2) ? val2 : val;
}

//Template class
template<typename T, typename U> //create template storage
class Person{ // define function
    public: // indention act weirder
        T height;
        U weight;
        static int numOfPeople; //number of people, always static
        Person(T h, U w){ //constructor
            height = h, weight = w;
            numOfPeople++; //so you can increment like this like it shows how many person where you defined
        }
        void GetData(){ //function callout
            std::cout << "Height : " << height << " and Weight : " << weight << "\n";
        }
};
template<typename T, typename U> int Person<T,U>::numOfPeople; // I guess this is what we do to know the number of population of the class.


int main() {
    //This is how we call class template
    Person<double, int> mikeTyson(5.83, 216); // SO <> are template containers all this time, we just have to define the data types inside, and look how it's passed in the class.
    mikeTyson.GetData();
    std::cout << "Number of People : " << mikeTyson.numOfPeople << "\n";
    
    //see how we call a function with a return type of the typename
    //and see how it fits to different data types
    std::cout << "5 + 4 = " << 
            Add(5, 4) << "\n";
    std::cout << "5.5 + 4.6" << "\n";
    std::cout << "Max 4 or 8 = " << Max(4, 8) << "\n";
    std::cout << "Max A or B = " << Max('A', 'B') << "\n";
    std::cout << "Max Dog or Cat = " << Max("Dog", "Cat") << "\n";
    
    // see how we can put multiple types with it
   /* Times2(5); // integers
    Times2(5.3); // doubles, both work*/
}

/*int main() {
    
    
    OmeleTest6Header spot = OmeleTest6Header(); // dont be confused, this is just constructor passing.
    spot.name = "Spot";
    std::cout << "The Animal is named : " << spot.name << "\n";
    std::cout << AREA_CIRCLE(10) << "\n";
    
}*/


/*
 * in defining a function,
 * double Function <-this is what we call return type, (This is the function prototype, where different attributes comes in)
 * [ captures ] ( params ) -> ret { body }, < TEMPLATE parameters > this are the terminologies for closings yeah
 * Here we will know what function can further do
 * Advanced Functions:
 *  
 *      store function as variables! You can put a function in a variable auto var = func; 
 *      We're also able to receive other functions inside of a function, #include functional
 *      Store functions in a vector
 * .
 * Preprocessors and outside files
 * Preprocessors were executed first before the code was being compiled
 * Creating class header
 * So typename is what we call with the thing Animal 
 */



/*std::vector<char> GenerateHorT(std::vector<char> ht, int amount) {
    std::vector<char> headsAndTail;
    
    for(int i = 0; i < amount; ++i) {
        headsAndTail.push_back(ht[rand() % 2]);
    }
    return headsAndTail;
}

int GetNumberOfMatches(std::vector<char> HorTList, char thingToFind) {
    int numberOfMatches = 0;
    for (char c: HorTList) {
        if (c == thingToFind) {
            numberOfMatches++;
        }
    }
    return numberOfMatches;
}


int main() {
    srand(time(NULL));
    std::vector<char> possibleValues = {'H', 'T'};
    std::vector<char> HorTList = GenerateHorT(possibleValues, 100);
    std::cout << "Number of Heads : " << GetNumberOfMatches(HorTList, 'H') << "\n";
    std::cout << "Number of Tails : " << GetNumberOfMatches(HorTList, 'T') << "\n";
}*/
/*int GetNumberOfMatches(std::function<std::vector<char>(std::vector<char>, int)> List, char letter) {
 Very wrong   
}*/
/*double MultBy2(double num) {
    return num * 2;
}

double DoMath(std::function<double(double)> function, double num) { // Defined function inside see. double(double) is just data types without variable name, that is gonna receive double and it's gonna return double.
    return function(num);
} 

double MultBy3(double num) {
    return num * 3;
}

bool IsOdd(int num) {
    if ((num % 2) == 0) {
        return false;
    } else {
        return true;
    }
}*/

/*std::vector<int> ReturnOdd(std::function<std::vector<bool>(std::vector<int>)> funcPassed, 
        std::vector<int> list) {
    std::vector<int> oddList;
    for (int i: list) {
        if (funcPassed) {
            oddList.push_back(i);
        }
    }
    return oddList;
}*/ // ugly attempt

/*std::vector<int> ReturnOdd(std::function<bool(int)> funcPassed, std::vector<int> list) {
    std::vector<int> oddList;
    for (int i: list) {
        if (funcPassed(i)) {
            oddList.push_back(i);
        }
    }
    return oddList;
}

int main() {
    std::vector<int> list = {1, 2, 3, 4, 5};
    std::vector<int> oddList = ReturnOdd(IsOdd, list); // remember, defining a variable with a return type vector should be the same in the = sign
    for (int i: oddList) {
        std::cout << i << "\n";
    }
    /*int oddList = IsOdd(list);
    int oddValues = ReturnOdd(oddList, list);*/ // my ugly attempt

/*int main(int argc, char** argv) {

    auto times2 = MultBy2; //store function as variable
    std::cout << "5 * 2 = " << times2(5) << "\n"; 
    
    std::cout << "6 * 2 = " << DoMath(times2, 6) << "\n"; //receive other functions inside of a function
    
    std::vector<std::function<double(double)>> funcs(2); //Store functions in a vector
    funcs[0] = MultBy2; // simply here's how to restore functions
    funcs[1] = MultBy3; 
    std::cout << "10 * 2 or 3 = " << funcs[0](10) << "\n"; // that's how we call the function inside. This means [] is higher than (), and also calling a vector with index is like replacing the whole name there with what it is defined to which is MultBy 3 or 2
    
    
    
    
    return 0;
}*/

/* GENERAL NOTES and Philosophy, ONLY ON NOTE 6:
 * 
 * Usages of these different tools for programming is what matters the most
 * Only way we can learn is by doing it, because we active learning that way
 */