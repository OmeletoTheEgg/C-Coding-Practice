
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

/* Iterators can be created outside loops
 * Iterators are pointers, so we call them with *
 * Regular Expressions
 * [^ ] need not 
 * ^ match for the beginning of the string
 * \ escape character that will convert reserved symbol to string
 * . any single character next
 * + additional
 * () enclosure 1
 * [] enclosure 2
 * * greedy symbol
 * *? lazy match
 * +? 
 * {n,} similar to *?
 * //btext//b
 * ? maybe, without this it requires that the statement should be what exactly stated on the left side
 * regex often starts like "(word([^ }+)?)" something like that
 */

 // Everything covered previously
    // [ ]   : Match what is in the brackets
    // [^ ]  : Match anything not in the brackets
    // .     : Match any 1 character or space
    // +     : Match 1 or more of what proceeds
    // \n    : Newline
    // \d    : Any 1 number
    // \D    : Anything but a number
    // \w    : Same as [a-zA-Z0-9_]
    // \W    : Same as [^a-zA-Z0-9_]
    // \s    : Same as [\f\n\r\t\v]
    // \S    : Same as [^\f\n\r\t\v]
    // {5}   : Match 5 of what proceeds the curly brackets
    // {5,7} : Match values that are between 5 and 7 in length
    // ()    : Return only what is between ()

void PrintMatches(std::string str, std::regex reg) {
    std::smatch matches; //this is where we put the stuffs that match, and look below how we call it, it's efficient
    std::cout << std::boolalpha;
    // this is like getline v
    while(std::regex_search(str, matches, reg)){ //std::regex_search(what whole string, match, regular expression)
        std::cout << "Is there a match : " <<
                matches.ready() << "\n";
        std::cout << "Are there no matches : " <<
                matches.empty() << "\n";
        std::cout << "Number of matches : " <<
                matches.size() << "\n";
        std::cout << matches.str() << "\n";
        str = matches.suffix().str(); // to get the match, using smatch
        std::cout << "\n";
    }
}

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
int main() {
    // -----REGEX2------
    
    //boundary //btext//b to only get the first
    std::string str5 = "5+5+5";
    std::regex reg5 ("\\b\\d[\\+]\\d\\b");
    PrintMatches(str5, reg5);
    
    //other ways to use greedy
    std::string str4 = "<name>Life On Mars<\name>"
            "<name>Freaks and Geeks<\name>";
    std::regex reg4 ("<name>(.*?)</name>");
    PrintMatches2(str4, reg4);  
    
    //getting \n but for \r maybe
    std::string str3 = "Just some words\n"
            "and some more\r\n"
            "and more\n";
    std::regex reg3 ("[\r]?\n");  // we don't know if \r, but match for \n
    std::string line = std::regex_replace(str3, reg3, " "); //line is matching the string with " ";
    std::cout << line << "\n\n";
    
    //about greedy symbol *
    std::string str2 = "doctor doctors doctor's";
    std::regex reg2 ("([doctor]+['s]*)"); //equivalent to "([doctor]+['s]{0,2})"
    PrintMatches2(str2, reg2); // i think * gets anything as long one character matches
    
    
    //more about []+
    std::string str1 = "cat cats catsu";
    std::regex reg1 ("([cat]+s?u?)"); //had a little experiment of this, so that's how you get extra numbers
    PrintMatches(str1, reg1); //get's proceeding matches but only with s
    
    // Everything covered previously
    // [ ]   : Match what is in the brackets
    // [^ ]  : Match anything not in the brackets
    // .     : Match any 1 character or space
    // +     : Match 1 or more of what proceeds
    // \n    : Newline
    // \d    : Any 1 number
    // \D    : Anything but a number
    // \w    : Same as [a-zA-Z0-9_]
    // \W    : Same as [^a-zA-Z0-9_]
    // \s    : Same as [\f\n\r\t\v]
    // \S    : Same as [^\f\n\r\t\v]
    // {5}   : Match 5 of what proceeds the curly brackets
    // {5,7} : Match values that are between 5 and 7 in length
    // ()    : Return only what is between ()
    // -----REGEX------
    /*std::string str = "The ape was at the apex";
    std::smatch matches; //smatch is a vector hmm
    // Describe what I'm looking for:
    //Create the pattern to search for which is
    // the letters ape followed maybe by anything
    // that is not a space
    std::regex reg("(ape[^ ]?)"); 
    PrintMatches(str, reg);
    
    std::string str2 = "I picked the pickle";
    std::regex reg2 ("(pick([^ ]+)?)"); // get without space, + one or more, maybe
    PrintMatches2(str2, reg2);
    
    std::string str3 = "Cat rat mat fat pat";
    std::regex reg3 ("([Crmfp]([^ ]+)?)"); //get stuffs that begins with crmfp and has at next
    PrintMatches2(str3, reg3);
    std::regex reg4 ("([C-Fc-f]at)"); // get stuffs that has Capital C to Capital F, or c to f, with at
    PrintMatches2(str3, reg4);
    std::regex reg5 ("([^Cr]at)"); // get stuffs that is not C or r, and next is at
    PrintMatches2(str3, reg5);
    std::regex reg6 ("([Cr]at)"); // get stuffs that is C or r, and next is at
    std::string owlFood = std::regex_replace(str3, reg6, "Owl"); // define owlFood as string with C at and r at replaced by owl
    std::cout << owlFood << "\n\n";
    
    // get strings that is not a space, and get's . (which is any single character) and \. where \ plays as escape string
    std::string str7 = "F.B.I. I.R.S. CIA";
    std::regex reg7 ("([^ ]\..\..\.)"); 
    PrintMatches2(str7, reg7);
    std::cout << "\n";
    
    // replace whitespaces / remove
    str::string str8 = "This is a\n multiline string\n"
            "that has many lines";
    std::regex reg8 ("\n");
    std::string noLBStr << "\n";
    std::cout << noLBStr << "\n";*/
    
    // You can also replace
    // \b : Backspace
    // \f : Form feed
    // \r : Carriage Return
    // \t : Tab
    // \v : Vertical Tab
    
    
    // ------ITERATORS---------
    
   /* std::vector<int> nums2 = {1, 2, 3, 4};
    std::vector<int>::iterator itr;
    for(itr = nums2.begin();
            itr < nums2.end();
            itr++) {
        std::cout << *itr << "\n"; //cycle through all iterators
    }
    
    std::vector<int>::iterator itr2 = nums2.begin(); //let's start at the beginning
    advance(itr2, 2); //advance the iterator 2 spaces from the beginning
    std::cout << *itr2 << "\n"; // outputs the thing that is 2 space away from beginning which is 3
    
    auto itr3 = next(itr2, 1); //itr3 is 1 next from itr2, we use auto for iterators
    std::cout << *itr3 << "\n";
    
    auto itr4 = prev(itr2, 1); // itr4 is one previous
    std::cout << *itr4 << "\n";
    std::cout << "\n";
    // insert a container to another container
    std::vector<int> nums3 = {1, 4, 5, 6};
    std::vector<int> nums4 = {2, 3};
    auto itr5 = nums3.begin(); // itr5 is iterator begin of nums 3
    advance(itr5, 1); // 
    copy(nums4.begin(), nums4.end(), inserter(nums3, itr5));
    for(int &i: nums3) { //we put & because nums3 is a iterator
        std::cout << i << "\n";
    }
    */
}

