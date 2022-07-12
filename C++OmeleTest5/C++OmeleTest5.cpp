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
#include <fstream> //allow us to work with files


/*
 * Structs  group of data elements grouped together under one name, data elements: apple, orange, etc data structs: fruits
 * The only difference between a struct and class in C++ is the default accessibility of member variables and methods. In a struct they are public; in a class they are private.
 * Friend in classes, access even in private, if you declare it in private
 * Polymorphism allows objects to be treated similarly, at the same time they will be able to utilize their differences automatically for any methods that you mark as virtual
 * we used Protected so subsclasses that is going to inherit to the main class has access to it
 * So classes are naturally private. You should have call "public" first before defining functions. But struct is naturally public.
 * So objects is basically a thing, either state or behavior, first name, last name, password, location, photo. Then it's defined inside a class
 * Operators! operator conversion, stuffs
 * 
 */

//File I/O

/*int main() {
    std::ofstream writeToFile; //create stream that's used to write to our file
    std::ifstream readFromFile; //stream that's used to read from our file
    std::string txtToWrite = ""; //text to write to file
    std::string txtFromFile = ""; //text we read from file
    // ios::app Append to the end of the file
    // ios::trunc If the exists delete content
    // ios::in Open file for reading
    // ios::out Open file for writing
    // ios::ate Open writing and move to the end of the file
    
    // WRITING THE FILE(THEN DELETE) SECTION
    writeToFile.open("test.txt", std::ios_base::out | std::ios_base::trunc); //open file for writing, OR delete the same file out there if it exists, overwrite in other words
    if(writeToFile.is_open()) { //if file is open for writing
        writeToFile << "Beginning of File\n"; // notice it's a new thing of stream
        std::cout << "Enter data to write : ";
        getline(std::cin, txtToWrite); //Asking the user what to write in the file
        writeToFile << txtToWrite; // transferred typed text in the console to the file
        writeToFile.close(); //after writing we close
    }
    
    // READING THE FILE SECTION
    readFromFile.open("test.txt", std::ios_base::in); //let's open the file we created ^ for reading
    if(readFromFile.is_open()) { //if it's open?
        while(readFromFile.good()) { //continue reading as long as there's something to read
            getline(readFromFile, txtFromFile); //transferring read from file to text from file.
 *          std::cout << textFromFile << "\n";
        }
        std::vector<std::string> numberOfString;
        std::stringstream ss(txtFromFile);
        std::string count;
        while(getline(ss, count, ' ')) {
            numberOfString.push_back(count);
        }
        std::cout << numberOfString.size() << "\n";
        int ave = 0;
        for(auto word: numberOfString) {
            for(auto letter: word) {
                ave += 1;
            }
        }
        int avgNumChars = ave / numberOfString.size();
        std::cout << avgNumChars << "\n";
        readFromFile.close();
    }
}
*/
//Overloaded functions, very useful
/*class Box {
public:
    double length, width, breadth;
    std::string boxString;
    Box() {
        length = 1, width = 1, breadth = 1;
    }
    Box(double l, double w, double b) {
        length = l;
        width = w;
        breadth = b;
    }
    Box& operator ++ (){ //void way of doing operators
        length += 1;
        width += 1;
        breadth += 1;
        return *this;  // this is clever
    }
    operator const char*() {
        std::ostringstream boxStream; // and woah this is handy, ostringstream
        boxStream << "Box: " << length <<  // we can make our own cout, in other words, stream
                ", " << width <<
                ", " << breadth << "\n";
        boxString = boxStream.str();
        return boxString.c_str(); //let's know about c_str() in the future. It's probably just calling a string owned by an object in a class
    }
    Box operator + (const Box& box) {
        Box boxSum;
        boxSum.length = length + box.length;
        boxSum.width = width + box.width;
        boxSum.breadth = breadth + box.breadth;
        return boxSum;
    }
    double operator [] (int x) {
        if(x == 0) {
            return length;
        } else if (x == 1) {
            return width;
        } else if (x == 2) {
            return breadth;
        } else return 0;
    }
    bool operator == (const Box& box2) {
        return ((length == box2.length) && (width == box2.length)
                && (breadth == box2.breadth));
    }
    bool operator < (const Box& box2) {
        double boxfirst = length + width + breadth;
        double boxsecond = box2.length + box2.width + box2.breadth;
        return (boxfirst < boxsecond); 
    }
    bool operator > (const Box& box2) {
        double boxfirst = length + width + breadth;
        double boxsecond = box2.length + box2.width + box2.breadth;
        return (boxfirst > boxsecond); 
    }
    bool operator <= (const Box& box2) {
        double boxfirst = length + width + breadth;
        double boxsecond = box2.length + box2.width + box2.breadth;
        return (boxfirst <= boxsecond); 
    }
    bool operator >= (const Box& box2) {
        double boxfirst = length + width + breadth;
        double boxsecond = box2.length + box2.width + box2.breadth;
        return (boxfirst >= boxsecond); 
    }
    void operator = (const Box& boxToCopy) {
        length = boxToCopy.length;
        width = boxToCopy.width;
        breadth = boxToCopy.breadth;
    }
};

int main() {
    Box box(10, 10, 10); //btw, classes are like statements/datatypes
    ++box;
    std::cout << box << "\n";
    Box box2(5, 5, 5);
    std::cout << "Box1 + Box2 = " << box + box2 << "\n";
    std::cout << "Box Length : " << box[0] << "\n";
    std::cout << std::boolalpha;
    std::cout << "Is box1 and box2 equal: " << (box == box2) << "\n";
    std::cout << "Is box1 < box2: " << (box < box2) << "\n";
    std::cout << "Is box1 > box2: " << (box > box2) << "\n";
    box = box2;
    std::cout << box << "\n";
}*/

//Abstract Classes: putting "override" in series of subclasses that shares a function that is being called in a polymorphism, and using "final" if it's the final function
/*class Shape{ 
public:
    virtual double Area() = 0;
};
class Circle : public Shape {
protected:
    double length;
public:
    Circle(double l) {
        length = l;
    }
    double Area() override { //override
        return 3.14159 * std::pow(length, 2);
    }
};
class Rectangle : public Shape {
protected:
    double height, width;
public:
    Rectangle(double h, double w) {
        height = h;
        width = w;
    }
    double Area() override{
        return height * width;
    }
};
class Square : public Rectangle {
public:
    Square(double h, double w) : Rectangle(h, w) { // calling the function Rectangle(h, w) {} itself, and that's why we don't put anything inside the Square function because it is an inherit receiver function, and we get all what we need for square
        
    }
    double Area() override final{
        return height * width;
    }
    
};
// now lets polymorphism by making a global function that calls all those function inside the classes automatically;
void ShowArea(Shape& shape) {//we use referencing to store things in memory and so you can indirectly call it in int main()
    std::cout << "The Area is : " << shape.Area() << "\n";
}

int main() {
    Circle circle(10);
    //Shape we cannot define shape, the main class, because we didn't build a constructor from it
    Rectangle rectangle(10, 15);
    Square square(10, 10);
    ShowArea(circle);
    ShowArea(square);
    ShowArea(rectangle);
}
*/


// Polymorphism
/*class Shape {
protected:
    double height;
    double width;
public:
    Shape(double length) {
        height = length;
        width = length;
    }
    Shape(double l, double w) {//overloaded function
        height = l;
        width = w;
    }
    virtual double Area() {//virtual must be in the main class, and should have distribute this same function to the subclasses as you can see in the subclass below, creating a connection of the function between the two and so we can automatically choose which function of Area() to execute depending on what class you call in int main() e.g. Shape shape(10); <- this will use the function in the main class. or Circle circle(10), this will use the function inside the subclass
        return height * width;
    }
};

class Circle : public Shape {//so we can store bunch of shape objects even tho they we're cicles
public:
    Circle(double w) : Shape(w) { //w was defined by circle and used too in w
        //we won't put elements in this constructor
    }
    double Area() {
        return 3.1416 * std::pow(width/2, 2);
    }
};
//create function that receives shape, but it's going to use the correct area automatically, and that's what polymorphism is for
void ShowArea(Shape& shape) {
    std::cout << "The Area is : " << shape.Area() << "\n";
}
int main() {
    Shape shape(10);// here we define the ShowArea function
    Circle circle(10);
    ShowArea(shape);
    ShowArea(circle);//See how the circle defined was automatically known that it is belong to the subclass circle and it calls Area() function inside it
}
*/

//Friend Class
/*class Customer {
private:
    friend class GetCustomerData;
    std::string name;
public:
    Customer(std::string name) {
        this->name = name;
    }
};

class GetCustomerData {
public:
    static std::string GetName(Customer& customer) {
        return customer.name; // see it get access to Customer class
    }
};

int main() {
    Customer omele("Omele");
    GetCustomerData nameGetter; // its a bit confusing but nameGetter must be defined to get the name of the costumer, remember GetCustomerData is a separate class
    std::cout << nameGetter.GetName(omele);
}*/


// Structs
/*struct Shape {
    double length, width;
    Shape(double l = 1, double w = 1) { //so you can = inside the prototype for default values. In int main you'll type this prototype and that will be distributed inside the method, and so in the whole class.
        length = l;
        width = w;
    }
    double Area() { //caller and multiplier///// In polymorphism you should put virtual here, so you can define a function globally and call those function in int main()
        return length * width;
    }
private: // this is just temporary that we wont use.
    int id;
};
//create substruct for elaboration
struct Circle : Shape { // passing public properties of Shape to a circle
    // let's have width as radius
    Circle(double r) { // Every class has a constructor function, which simply has the exact copy of the name of the class, and it meant to distribute all the input values to the whole class
        this->width = r;
    }
    double Area() {
        return 3.1416 * std::pow(this->width, 2);
    }
    
};
int main(int argc, char** argv) {
    Shape square(10, 10);
    std::cout << "Area of Square is :" << square.Area() << "\n";
    Circle circle(10);
    std::cout << "Area of Circle is : " << circle.Area() << "\n";
    Shape rectangle{10, 15}; //aggregate: https://en.cppreference.com/w/cpp/language/aggregate_initialization
    std::cout << "Area of Rectangle is : " << rectangle.Area() << "\n";
    return 0;
}
*/
