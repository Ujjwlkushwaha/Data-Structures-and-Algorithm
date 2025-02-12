#include<iostream>
using namespace std;

int digitSum( int n )
{
    int dSum = 0;

     // Calculate the digit sum of the current element
     for (int currValue = n; currValue != 0 ; currValue /= 10) {
        int currDigit = currValue % 10;
        dSum += currDigit;
    }

    return dSum;
}

int main(){
    int num = 123;

    cout << "Digit sum is :: " << digitSum( num ) << endl;
}