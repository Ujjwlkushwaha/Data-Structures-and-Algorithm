#include<iostream>
#include<math.h>
using namespace std;

// find out the given number is prime of not

bool isPrime(int d)
{
    if(d <= 1) return false;

    // 👉  go up-to integer N -> O(n^(1/2)) >  O(sqrt(n))

    int range = sqrt(d);
    
    for(int i=2 ; i< range ; i++){
        if( d % 2 == 0){
            return false;
        }
    }
    return true;
}


int main(){

    int a ;
    cout << "Enter the number :: " ;
    cin >> a;

    if(isPrime(a))
        cout << "The number is prime number !"<<endl;
    else    
        cout << "The number is not prime number!!" << endl;

}