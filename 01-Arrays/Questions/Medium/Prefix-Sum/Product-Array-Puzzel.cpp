
/*

    ✅ Product array puzzle

        Given an array, arr[] construct a product array, res[] where each element in res[i] is the product of all elements in arr[] except arr[i]. Return this resultant array, res[].
        
        Note: Each element is res[] lies inside the 32-bit integer range.

Examples:

    Input: arr[] = [10, 3, 5, 6, 2]
    Output: [180, 600, 360, 300, 900]

 Explanation: For i=0, res[i] = 3 * 5 * 6 * 2 is 180.
    For i = 1, res[i] = 10 * 5 * 6 * 2 is 600.
    For i = 2, res[i] = 10 * 3 * 6 * 2 is 360.
    For i = 3, res[i] = 10 * 3 * 5 * 2 is 300.
    For i = 4, res[i] = 10 * 3 * 5 * 6 is 900.

Input: arr[] = [12, 0]
Output: [0, 12]
Explanation: For i = 0, res[i] is 0.
For i = 1, res[i] is 12.

*/

#include<bits/stdc++.h>
using namespace std;

/*

Approach 1: Brute Force

    Create an empty result array res[] of the same size as arr[].
    For each index i in arr[]:
        Calculate the product of all elements except arr[i] by iterating through the entire array and skipping arr[i].
        Store the result in res[i].
    Return res[].

*/

vector<int> productExceptSelf(vector<int>& arr) 
{
    // code here
    int n=arr.size();
    vector<int> res;
    
    for( int i=0 ; i<n ;i++ )
    {
        int product = 1;
        for( int j = 0 ;j < n ; j++ )
        {
            if( i != j)
            {
                product *= arr[j];
            }
        }
        res.push_back(product);
    }
    return res;
}

// otimized approach


vector<int> productExceptSelf2(vector<int>& arr) 
{
    // code here
    int n=arr.size();
    vector<int> res;
    int product = 1;
    
    int countZero = 0;
    
    for ( int i=0 ; i<n ; i++ )
    {
        if ( arr[i] == 0) 
            countZero++;
        else
            product *= arr[i];
    }
    
    
    cout << product << endl;
    
    for( int i = 0 ; i<n ; i++ )
    {
        if( countZero > 1)
        {
            res.push_back(0);
        }
        else if( countZero == 1)
        {
            if( arr[i] == 0 )
                res.push_back( product );
            else
                res.push_back( 0 );
        }else{
            int val = product / arr[i] ;
            res.push_back(val);
        }
    }
    
    return res;
}

int main() {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        while (ss >> number) {
            arr.push_back(number);
        }

        vector<int> res = productExceptSelf2(arr);

        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << endl;
        cout << "~\n";
    return 0;
}