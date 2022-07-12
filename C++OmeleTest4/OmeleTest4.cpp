
#include <cstdlib>
#include <string>
#include <vector>
#include <ctime>
#include <numeric>
#include <math.h>
#include <iostream>

/*
 * A class is a blueprint in which you are going to describe whatever type of real world object you want to create
 * every real world object class has two things: Attributes(name, height, weight), Capabilities(eat, run, make sounds)
 * 
 * the () in functions is called prototypes
 * 
 * sometimes you wanna keep things private, (so we use "private" statement), and the attributes/capabilities inside there will only be accessible inside our class
 * 
 * If you declare an object inside a static, it's only gonna be accessible through static, nothing else
 * 
 * -> is a pointer operator, used to accessed the object's fields/variables
 * 
 * if you wonder why in OOP it's okay to have multiple functions with the same name, that's what we call overload functions. That's why we can have multiple forms of functions sometimes like string(5, 'x');
 * 
 * so it's like, Class -> Functions and variables (which has private or public properties) -> 
 * 
 * protected gives a way for subclasses that asked inheritance to the main class to access
 * 
 * Every object should have it's own constructor, a function that defines generally the class, or not
 * 
 * polymorphism is a function outside any class that shares the common function/object inside main classes and it's inheritance. We put "virtual" inside of the main class in order to do so
 * 
 * Constructor has no return value, it just gets the value from main and put them either in the variable or not. It has the same name of the class.
 * 
 * anything that has # like #include is a preprocessor directive
 */
// the main class that has objects with attributes and capabilities inside

//continuous execution of classes example, and perspective based
//I didn't continue putting speed feature to this because this is another research
//you'll have to control the probability of repetition executing the fight 
class Warrior{
private:
    int attack;
    int block;
    int speed;
public:
    int health;
    std::string name;
    double getHealth(){return health;}
    Warrior(std::string, double, double, double, double);
    
    int Attack() {
        return std::rand() % this->attack;
    }
    int Block() {
        return std::rand() % this->block;
    }
    int numRepeat() {
        return floor((std::rand() % this->speed)/50);
    }
};
Warrior::Warrior(std::string name, double health, double attack, double block, double attackSpeed) {
    this->name = name;
    this->health = health;
    this->attack = attack;
    this->block = block;
    this->speed = attackSpeed;
}

class DickFight{
public:
    static void StartFight(Warrior &warrior1, Warrior &warrior2) {
        while(true) {        
            if(DickFight::GetAttackResult(warrior1, warrior2).compare("Game Over") == 0) {
                std::cout << "Game Over" << "\n";
                break;
            }
            if(DickFight::GetAttackResult(warrior2, warrior1).compare("Game Over") == 0) {
                std::cout << "Game Over" << "\n";
                break;
            }
        }
    }
    static std::string GetAttackResult(Warrior &warrior1, Warrior &warrior2 ) {//clever way to call the warrior constructor and define a new warrior with reference symbol
        int warrior1AttackAmt = warrior1.Attack();
        int warrior2BlockAmt = warrior2.Block();
        int damageWarrior2 = ceil(warrior1AttackAmt - warrior2BlockAmt);
        int warrior1prob = warrior1.numRepeat();
        damageWarrior2 = (damageWarrior2 <= 0) ? 0 : damageWarrior2;
        while(true) {
            warrior2.health -= damageWarrior2;
            printf("%s attacks and %s deals %d damage\n", warrior1.name.c_str(), warrior2.name.c_str(), damageWarrior2);
            warrior1prob -= 1;
            if (warrior1prob == 0) break;
        }
        
        
        warrior2.health = (warrior2.health <= 0) ? 0 : warrior2.health;
        printf("%s is down to %d health\n", warrior2.name.c_str(), warrior2.health);
        
        if(warrior2.health <= 0) {
            printf("%s died and %s is victorious!\n", warrior2.name.c_str(), warrior1.name.c_str());
            return "Game Over";
        } else {
            return "Fight Again";
        }
        
    }
};

int main() {
    srand(time(NULL));
    //warrior(name, health, attackDmg, blockAmt, attackSpeed)
    Warrior omele("Omelehandsome", 100, 30, 15, 100);
    Warrior cristan("Tanhandsome", 100, 30, 15, 110);
    
    DickFight::StartFight(omele, cristan);
}

/*class Animal{
    //objects inside private is only accessible through this class. In private we usually define normally our variable like that
private:
    std::string name;
    double height;
    double weight;
    
    static int numOfAnimals;
    //public can be accessed outside this class. In public we define the function version for those variable like below
public:
    std::string getName(){return name;} // this is the function you use to get the name by putting to int main() {getName();
    void setName(std::string name){this -> name = name;} // this is the function you EDIT to get the name by putting to int main() {getName();
    double getHeight() {return height;} 
    void setHeight(double height) {this -> height = height;} // notice their difference. Void used pointers because it always been if you input something with reference number. And it has prototype too that means its subject to change
    double getWeight() {return weight;}
    void setWeight(double weight) {this -> weight = weight;}
    
    // let's define other edit functions
    // this function below is another way to EDIT your animal, but those functions above is still useful when you want to edit only one.
    void setAll(std::string, double, double); //surprisingly you can disregard the names inside a function prototype because you're going to define them outside this class anyways
    Animal(std::string, double, double); // the function that new creates animal
    Animal(); // add a overload function just in case that there's nothing the user inputed, which you're gonna define outside this class anyways
    ~Animal(); // tilda is just to sign that this is a deconstructor function. You'll call this if you want your class to end and to be destroyed.
    static int getNumOfAnimal(){return numOfAnimals;} // static method/functions can only access static functions remember
    void toString(); // a function created to convert the animal's attributes and capabilities to string 
};// and yes we use semi colon for class function
//let's see if I can do define those functions myself

int Animal::numOfAnimals = 0;
void Animal::setAll(std::string name, double height, double weight) {
    this->name = name; // -> is used to point and edit the things inside private which is cool! whenever you want to access anything you can access through pointers and memory that's why they're cool
    this->height = height;
    this->weight = weight;
    Animal::numOfAnimals += 1; // this signifies that when you call this function setAll, it'll add one. Also see how Animal becomes like std, so which means std is a class. And it will open a lot of understandign of types fory ou 
    
}

Animal::Animal(std::string name, double height, double weight) {
    this -> name = name;
    this -> height = height;
    this -> weight = weight;
    Animal::numOfAnimals += 1;
}

Animal::Animal(){// this is the function that calls for default
    this -> name = "";
    this -> height = 0;
    this -> weight = 0;
}

Animal::~Animal() {
    std::cout << "Our animal " << this -> name << " is destroyed\n";
}

void Animal::toString() { // remember that what statement you define inside the class public function (in this case void) is what you put too outside when you define the function;
    std::cout << "Animal " << this -> name << " is " << this -> height << " cm tall and weighing " << this -> weight << "kg\n";
}
//I noticed you can also forget doing these functions i defined above, just define them inside the class

//creating a subclass

class Dog: public Animal{// it accessed through all the attributes of being an animal
private:
    std::string sound = "wooof";
public:
    void makeSound() {
        std::cout << this-> getName() << " says " << this->sound << "\n";
    }
    Dog(std::string, double, double, std::string);
    Dog(): Animal(){}; // passing attributes of animal to dog, and defined outside
    void toString(); //call functions are always having void or any statement yeah
    
};
Dog::Dog(std::string name, double height, double weight, std::string sound) : Animal(name, height, weight){ //passing the attributes of animal to dog
    this -> sound = sound; //adding the sound
}
void Dog::toString() {
    std::cout << "Animal " << this -> getName() << " is " << this -> getHeight() << " cm tall and weighing " << this -> getWeight() << "kg" << " and says " << this -> sound << "\n";
    // we use getName and such functions to indirectly, as we define getName in the Animal class. But we're able to get it directly if we set the private in Animal class as "protected"
}

int main(int argc, char** argv) {
    std::string name;
    std::cout << "What's you animal's name? : ";
    getline(std::cin, name);
    Animal omele;
    omele.setName(name);
    omele.setHeight(69);
    omele.setWeight(420);
    
    omele.toString();
    Animal tan;
    tan.setAll("Tan", 1, 1000);
    tan.toString();
    
    Dog Cristan("Cristan", 69, 420, "Anjing");// you can call the function straight like this, no need to use setAll actually that we've made
    Cristan.toString();
    
    
    std::cout << "There are " << Animal::getNumOfAnimal() << " number of animals overall.\n"; // static functions are just static can't be define by other. Static is good if you want a tally of the number of animals
    // When we declare a member of a class as static it means no matter how many objects of the class are created, there is only one copy of the static member
    
    
    
    return 0;
}

*/
