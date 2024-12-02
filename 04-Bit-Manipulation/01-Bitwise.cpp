#include<iostream>
using namespace std;

int main()
{
    // 📌 Revise bitwise operator
    /*
        there are mainly 5 bitwise operator used

            * bitwise AND ( & )
            * bitwise OR ( | )
            * bitwise XOR ( ^ )
            * bitwise left shift ( <<)
            * bitwise right shift ( >>)
    
    */


   int a = 5;
   int b = 3;

   // > 📌 Bitwise AND Operator 
   cout << "Bitwise AND of " << a << " and " << b << " is: " << (a & b) << endl; 

   // > 📌 Bitwise OR Operator 
   cout << "Bitwise OR of " << a << " OR " << b << " is: " << (a | b) << endl; 

   // > 📌 Bitwise XOR Operator 
   cout << "Bitwise XOR of " << a << " XOR " << b << " is: " << (a ^ b) << endl; 
/*
    👉 Explaination :

        5 ( 101 )
        3 ( 011 )    

        a     b     a & b     a|b   a ^ b
        0     0        0        0       0
        0     1        0        1       1              => according to this table => ( 101) & ( 011 ) = ( 001 ) => 1
        1     0        0        1       1              => according to this table => ( 101) | ( 011 ) = ( 111 ) => 7
        1     0        0        1       1              => according to this table => ( 101) ^ ( 011 ) = ( 110 ) => 6
        1     1        1        1       0

*/

// 📌📌 Now lets talk about shifting operator 

    // > �� Bitwise Left Shift Operator
   cout << "Bitwise Left Shift of " << a << " by 1 is: " << (a << 1) << endl;  // 101 << 1 = 1010 => 10

    // > �� Bitwise Right Shift Operator
   cout << "Bitwise Right Shift of " << a << " by 1 is: " << (a >> 1) << endl;  // 101 >> 1 = 50 => 5


}