#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<int> nextSmallestElement(vector<int> arr) {
    stack<int> s;
    vector<int> ans(arr.size());

    s.push(-1);

    for (int i = arr.size()- 1; i >= 0; i--) 
    {
        while (s.top() >= arr[i])
         {
            s.pop();
        }
        ans[i] = s.top();
        s.push(arr[i]);
    }

    return ans;
}

int main() {
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    vector<int> result = nextSmallestElement(heights);
    
    for (int i = 0; i < result.size(); i++) 
    {
        cout << result[i] << " ";
    }  //1 -1 2 2 -1 -1 
    return 0;
}