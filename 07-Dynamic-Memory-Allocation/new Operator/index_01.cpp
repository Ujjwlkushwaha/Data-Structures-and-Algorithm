// new operator =>

    /* 
        The new operator denotes a request for memory allocation on the Free Store. 
        If sufficient memory is available, a new operator initializes the memory and returns 
        the address of the newly allocated and initialized memory to the pointer variable. 
    */

// C++ program to demonstrate how to create dynamic variable
// using new
#include <iostream>
using namespace std;

int main()
{
    // pointer to store the address returned by the new
    int* ptr;
    // allocating memory for integer
    ptr = new int;

    // assigning value using dereference operator
    *ptr = 10;

    // printing value and address
    cout << "Address: " << ptr << endl;
    cout << "Value: " << *ptr;

    return 0;
}
