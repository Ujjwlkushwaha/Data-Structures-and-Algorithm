#include <bits/stdc++.h>
using namespace std;

/*
    ✅ Implement Pow
        Difficulty: MediumAccuracy: 56.1%Submissions: 10K+Points: 4
        Implement the function power(b, e), which calculates b raised to the power of e (i.e. be).

Examples:

    Input: b = 3.00000, e = 5
    Output: 243.00000

    Input: b = 0.55000, e = 3
    Output: 0.16638

    Input: b = -0.67000, e = -7
    Output: -16.49971

Constraints:

    -100.0 < b < 100.0
    -109 <= e <= 109
    Either b is not zero or e > 0.
    -104 <= be <= 104

*/

class Solution
{
public:
    double power(double b, int e)
    {
        // base case
        if (e == 0)
            return 1;
        if (e < 0)
            return 1 / power(b, -e);

        double ans = power(b, e / 2);

        if (e % 2 == 0)
        {
            return ans * ans;
        }
        else
        {
            return ans * ans * b;
        }
    }
};


int main()
{

    double b;
    cin >> b;

    int e;
    cin >> e;

    Solution ob;
    cout << ob.power(b, e) << endl;
    cout << "~" << endl;
}