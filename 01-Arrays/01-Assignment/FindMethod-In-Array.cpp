#include <bits/stdc++.h>
using namespace std;

/*
    ✅⭐ Find() method in stl

    - In C++, the find() is a built-in function used to find the first occurrence of an element in the  given range.

   # Syntax of find()

        The find() is a C++ STL function defined inside <algorithm> header file.

        🗝️ find(first, last, val);


    ## Parameters:

        - first: Iterator to the first element of range.
        - last: Iterator to the theoretical element just after the last element of range.
        - val: Value to be searched.

    ## Return Value:

        - If the value is found in the range, returns an iterator to its position.
        - If the value is not found, returns an iterator to the end of the range.
*/

int getIndex(int *arr, int n, int key)
{
    // search element
    auto it = find(arr, arr + n, key);
    int index = distance(arr, it);

    if (index >= n)
    {
        return -1;
    }

    return index;
}

int isPresent(vector<int> arr, int val)
{
    // Search an element val
    auto it = find(arr.begin(), arr.end(), val);

    // Check if element is preset
    if (it != arr.end())
        return distance(arr.begin(), it);
    else
        return -1;
}

int main()
{
    // ✅ using static array

    int arr[5] = {1, 3, 6, 2, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Index is :: " << getIndex(arr, n, 6) << endl;
    cout << "Index is :: " << getIndex(arr, n, 8) << endl;

    // ✅ using vector array
    vector<int> v = {1, 3, 6, 2, 9};
    cout << "Index of 6 is " << isPresent(v , 6) << endl;;
}