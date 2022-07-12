/*
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
#include <cstring>
#include <cctype>
#include <functional>
#include <fstream> 

#include <iterator>

#include <regex>

void PrintMatches2(std::string str, std::regex reg){
    std::sregex_iterator currentMatch(str.begin(),
            str.end(), reg); //defines iterator
    std::sregex_iterator lastMatch; //defines last iterator
    while(currentMatch != lastMatch){
        std::smatch match = *currentMatch; //* since iterators are pointers, gets the value of the current match
        std::cout << match.str() << "\n";
        currentMatch++;
    }
    std::cout << "\n";
}

void OperateAddSub(std::string &str, std::regex reg) {
    std::smatch match;
    std::smatch number;
    std::sregex_iterator currentMatch(std::sregex_iterator(str.begin(), str.end(), reg));
    std::regex regLeft ("(\\d+)");
    std::regex regRight ("(\\+\\d)");
    std::string newString;
    std::vector<double> sum;
    while(currentMatch != std::sregex_iterator()){
        double num1, num2;
        match = *currentMatch;
        newString = match.str();
        std::regex newReg("\\b[" + newString + "]\\b");
        
        if(std::regex_search(newString, number, regLeft)){
            std::cout << "Left Number: " << 
                    number.str() << "\n";
            num1 = std::stoi(number.str()); 
        }
        if(std::regex_search(newString, number, regRight)){
            std::cout << "Right Number: " << 
                    number.str() << "\n";
            num2 = std::stoi(number.str());
        }
        std::cout << num1 + num2 << "\n";
        sum.push_back(num1+num2);
        
        for(double s: sum){
            str = std::regex_replace(str, newReg, std::to_string(s));
        }
        currentMatch++;
    } 
}


int main(){
    std::string str1 = "5+4+6+7";
    std::regex reg1 ("\\b\\d[+]\\d\\b");
    OperateAddSub(str1, reg1);
    std::cout << str1;
    //PrintMatches2(str1, reg1);
}

/*void process_token(std::string s);
std::stack<double> st;

int main(int argc, char** argv) {
    
    std::string instr;
    std::string num_pattern("[0-9]+(\\.[0-9]*)?");
    std::string op_pattern("[+/*-]");
    std::regex re (num_pattern + "|" + op_pattern);
    while (true) {
        std::cout << "Enter expression (or ENTER to exit): ";
        getline(std::cin, instr);
        if (instr.length() == 0) { break; }
        std::sregex_iterator it(instr.begin(), instr.end(), re);
        std::sregex_iterator it_end;
        for (;it != it_end; ++it) {
            process_token(it->str());
            
        }
        if (!st.empty()) {
        std::cout << "The value is: " << st.top() << "\n";
            }
        }
    
    return 0;
}
void process_token(std::string s) {
    if (s.find_first_not_of("+/*-") != s.npos) {
        st.push(atof(s.c_str()));
    } else {
        double op2 = st.top(); st.pop();
        double op1 = st.top(); st.pop();
        switch(s[0]) {
            case '+': st.push(op1 + op2); break;
            case '-': st.push(op1 - op2); break;
            case '*': st.push(op1 * op2); break;
            case '/': st.push(op1 / op2); break;
        }
    }
}
*/

/*double OperateAddSub(std::string &str, std::regex reg) {
    std::smatch matches;
    std::smatch number;
    double num1, num2;
    if(std::regex_search(str, matches, reg)){
        std::string newString = matches.str();
        std::cout << newString << "\n";
        std::regex regLeft ("(\\d+)");
        std::regex regRight ("(\\+\\d)");
        
        if(std::regex_search(newString, number, regLeft)){
            std::cout << "Left Number: " << 
                    number.str() << "\n";
            num1 = std::stoi(number.str());
        }
        if(std::regex_search(newString, number, regRight)){
            std::cout << "Right Number: " << 
                    number.str() << "\n";
            num2 = std::stoi(number.str());
        }
        /*if(str.find(matches.str()) != std::string::npos) {
            str = str.replace(0, 
                    3,
                    std::to_string((double)num1 + (double)num2));
        }*/
        /*str = std::regex_replace(str, reg, std::to_string());*//*
        str = str.replace((str.find(newString)),
                str.find(newString) + sizeof(newString),
                    std::to_string((double)num1 + (double)num2));
    }
    std::cout << num1 + num2 << "\n";
    
}*/
