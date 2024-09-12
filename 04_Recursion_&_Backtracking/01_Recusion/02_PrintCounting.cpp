#include <iostream>
using namespace std;


void printCounting(int n)
{
    
    if( n == 1){
        cout << n << endl;
        return;
    }

    printCounting(n - 1);
    cout << n << endl;
}
int main()
{
    int n = 0 ;
    cout << "Kaha tak counting likhani haii:: ";
    cin >> n;

    printCounting(n);
}