#include<iostream>
using namespace std;

// runtime POlymorphism

class Parent{
    public:
        void speak(){
            cout << "say Something! " << endl;
        }
};

class child : public Parent{
    public:
        void speak(){
            cout << "Child bolta hai" << endl;
        }

};

int main(){

    // Dynamically creating object

    Parent *p1 = new Parent();
    p1->speak(); // called parent function

    Parent *p2 = new child();
    p2->speak();  // called parent function

    child * ch1 = new child();
    ch1->speak(); // called child function

/*
a value of type "Parent ptr" cannot be used to initialize an entity of type "child ptr"

    child *ch2 = new Parent();         not valid
    ch2->speak();                     

*/

/*
  NOTE PLZ:-> if we are declaring and defining parent class methods without virtual keyword so jab bhi hm dynamically object create krge to ptr ka type decide krega function kiska call hogaaa 

  agar -> virtual keywords ka use kiya hai to object ka type decide krega ki kiska function call hoga ( next program)

*/

}