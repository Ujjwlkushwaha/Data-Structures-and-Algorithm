#include<iostream>
using namespace std;

// create a class 

class Opt{

    int d1;
    int d2 ;
public:
    // parameterized constructor for initializing object
    Opt(int d1 , int d2){
        this->d1 = d1;
        this->d2 = d2;
    }

    // operator overloading 
// way -> 1
    void operator +(Opt &ob)
    {
        this-> d1 =  d1+ob.d1;
        this-> d2 =  d2+ob.d2;
    }
    
// way -> 2
    friend void operator -(Opt &ob1 , Opt &ob2);

    void getData(){
        cout << this->d1 << endl;
        cout << this->d2 << endl;
    }
};


void operator -(Opt & ob1 , Opt & ob2){
    ob1.d1 = ob1.d1 - ob2.d1;
    ob1.d2 = ob1.d2 - ob2.d2;
}

int main(){

    Opt ob1(4,5);
    Opt ob2(3,6);

// operator overloading

    // using normal member function 
    ob1+ob2;
    ob1.getData();

    // using friend function
    ob1-ob2;
    ob1.getData();
}

// ...............................................................

// C++ has the ability to provide the operators with a special meaning for a data type, this ability is known as operator overloading. 