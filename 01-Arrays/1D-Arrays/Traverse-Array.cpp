#include <bits./stdc++.h>
using namespace std;

// traverse array in different ways
void traverseArray(int arr[], int n)
{
    // Traverse array in forward direction
    cout << "Forward Direction: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Traverse array in reverse direction
    cout << "Reverse Direction: ";
    for (int i = n - 1; i >= 0; i--)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Traverse array in even index
    cout << "Even Index: ";
    for (int i = 0; i < n; i += 2)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Traverse array in odd index
    cout << "Odd Index: ";
    for (int i = 1; i < n; i += 2)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// 

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    traverseArray(arr, n);
    return 0;
}