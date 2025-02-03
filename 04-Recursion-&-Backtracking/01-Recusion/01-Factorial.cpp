//   we are finding factorial using recursion

#include <iostream>
using namespace std;

int factorial(int n)
{
    if (n == 1 || n == 0)
        return 1;
        
    return n * factorial(n - 1);
}


int main()
{
    int n = 0;
    cout << "enter the number:: ";
    cin >> n;

    cout << n << "! =" << factorial(n) << endl;
}