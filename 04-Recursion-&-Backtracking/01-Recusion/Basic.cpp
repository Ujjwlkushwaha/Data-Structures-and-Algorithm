#include<iostream>
using namespace std;

// Print  N to 1 Numbers

void printNumber( int n ) {  // recursive function

    if( n == 1 ){   // base case 
        cout << n << " ";
        return;
    }

    cout << n << " ";
    printNumber( n-1 ); // recursive call
}

int main(){
    printNumber( 100 );
}