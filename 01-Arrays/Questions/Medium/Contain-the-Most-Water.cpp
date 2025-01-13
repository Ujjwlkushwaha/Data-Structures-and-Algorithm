#include <bits/stdc++.h>
using namespace std;

/*
    ✅📌 Container With Most Water ( Difficulty: Medium )


        Given an array arr[] of non-negative integers, where each element arr[i] represents the height of the vertical lines, find the maximum amount of water that can be contained between any two lines, together with the x-axis.

        Note: In the case of a single vertical line it will not be able to hold water.

Examples:

        Input: arr[] = [1, 5, 4, 3]
        Output: 6
    Explanation: 5 and 3 are 2 distance apart. So the size of the base is 2. Height of container = min(5, 3) = 3. So, total area to hold water = 3 * 2 = 6.
        
        Input: arr[] = [3, 1, 2, 4, 5]
        Output: 12
    Explanation: 5 and 3 are 4 distance apart. So the size of the base is 4. Height of container = min(5, 3) = 3. So, total area to hold water = 4 * 3 = 12.
 */


int maxWater(vector<int> &arr)
{
    int s = 0, e = arr.size() - 1, area = 0, maxArea = 0;
    while (s < e)
    {
        int len = min(arr[s], arr[e]);
        int height = abs(e - s);
        area = len * height;

        maxArea = max(area, maxArea);

        if (arr[s] < arr[e])
        {
            s++;
        }
        else
        {
            e--;
        }
    }
    return maxArea;
}
int main()
{

    vector<int> arr;
    string input;

    // Read first array
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number)
    {
        arr.push_back(number);
    }
    int res = maxWater(arr);

    cout << res << endl
         << "~" << endl;
}

// 193 69 80 103 197 43 94 107 128 126 159 71 102 122 178 68 119 53 55 95 189 196 78 61 12 134 77 91 138 77 29 69 185 18 119 77 155 8 147 102 174 44 154 73 64 19 37 120 28 181 108 66 189