#include <iostream>
#include <vector>
// #include <limits>
using namespace std;

int longestConsicutiveSubsequence(vector<int> arr)
{
    int frqArr[1000001] = {0};
    int maxEle = -1;
    int ans = -1;
    int count = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        frqArr[arr[i]]++;
        maxEle = max(maxEle, arr[i]);
    }

    for (int i = 0; i <= maxEle; i++)
    {
        if (frqArr[i] > 0){
            count++;
        }
        else
        {
            ans = max(ans, count);
            count = 0;
        }

        ans = max(ans, count);
    }

    cout << "Longest Consicutive SubSequence :: " << ans << endl;
    return ans;
}

int main()
{
    vector<int> arr = {15, 13, 12, 14, 11, 10, 9};
    cout << longestConsicutiveSubsequence(arr);
}