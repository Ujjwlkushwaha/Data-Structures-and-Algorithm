#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    // this built in function return number of set bits 
    int numberOfSetbits = __builtin_popcount(n);

    cout << "Number of set bits in " << n << " is: " << numberOfSetbits << endl;
}