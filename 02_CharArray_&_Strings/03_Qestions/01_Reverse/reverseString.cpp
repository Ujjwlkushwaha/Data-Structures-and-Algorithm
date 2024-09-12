#include <bits/stdc++.h>
using namespace std;


int getLength( char* str)
{
    int len = 0;
    int i = 0;

    while(str[i]){
        len++;
        i++;
    }

    return len;
}
void reverseString(char*str)
{

    int s = 0;
    int e = getLength(str)-1;

    while(s < e){
        swap(str[s] , str[e]);
        s++;
        e--;
    }

    cout << "after reversing array ::"  << str << endl;

}

int main()
{
    char str[10] ="ujjwal";

    reverseString(str);
}