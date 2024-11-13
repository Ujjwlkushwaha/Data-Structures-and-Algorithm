#include <iostream>
#include<vector>
#include<stack>
#include<limits.h>
using namespace std;

/*

👺👺 HARD PROBLEM ON LEETCODE 
    given an histogram chart and array of height values

    we have to find the area of largest rectangle in the histogram

        1. we need two things to calculate area of largest rectangle

            height values and width values -> height values is given in the question but width values we have to calculate

            2. we will use two stack to find the next and previous smallest element in the array

            3. we will iterate the array in reverse order and calculate width values

            4. we will calculate the area of rectangle for each element and keep track of maximum area

            5. return the maximum area

 */



//📌 This function finds the index of the next smallest element for each element in the given array.
vector<int> nextSmallestElement(vector<int> arr) {
    stack<int> s;
    vector<int> ans(arr.size());

    s.push(-1);

    for (int i = arr.size()- 1; i >= 0; i--) 
    {
        while (s.top() != -1 && arr[s.top()] >= arr[i])
         {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }

    return ans;
}


//📌 This function finds the index of the previous smallest element for each element in the given array.
vector<int> previousSmallestElements(vector<int> &arr)
{
    vector<int> ans(arr.size());

    stack<int>st;
    st.push(-1);

    for( int i = 0; i < arr.size(); i++){

        while(st.top() != -1 && arr[st.top()] >= arr[i]){
            st.pop();
        }
        ans[i] = (st.empty()? -1 : st.top());
        st.push(i);

    }

    return ans;
}

//📌 when we find the index of the previous smallest element and next smallest element then we calculate exactly the width of the rectangle

int getMaxareaOfHistogram(vector<int> &heights)
{
    // 1️⃣ step 1
    vector<int> next = nextSmallestElement(heights);

    // 2️⃣ step 2
    vector<int> prev = previousSmallestElements(heights);

    // 3️⃣ Area 

    // this can store max area of the rectangle
    int maxArea = INT_MIN;

    // iterate the main array 
    for(int i=0 ; i<heights.size(); i++){

        // calculate the length of rectangle which is current height
        int length = heights[i];

        // jab bhi hme next[i] ki value -1 milegi to iska mtlb uske aage koi usse chhota element nhi hai to usme hm main array ka size put kar dege
        if(next[i] == -1){
            next[i] = heights.size();
        }

        // calculate exact width of rectangle
        int width =  next[i] - prev[i] - 1;

        // here is max area 
        maxArea = max(maxArea, length * width);
    }

    return maxArea;
}

// ⚔️⚔️⚔️⚔️⚔️⚔️⚔️⚔️⚔️⚔️⚔️⚔️⚔️⚔️⚔️⚔️⚔️⚔️⚔️⚔️⚔️⚔️⚔️⚔️⚔️⚔️⚔️⚔️⚔️⚔️⚔️
    int largestRectangleArea(vector<int>& nums) {
        int n = nums.size();
        vector<int> nsv(n), psv(n);

        stack<int> st;


    // find previous smallest element
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] >= nums[i]) st.pop();
                psv[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }


        // now clear the stack
        while (!st.empty()) st.pop();


    // find next largest element
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) st.pop();
                nsv[i] = st.empty() ? n : st.top();
            st.push(i);
        }

    // find max area
        int res = 0; 
        for (int i = 0; i < n; i++) {

            // find the length of rectangle
            int len = nsv[i] - psv[i] - 1; 
            res = max(res, len * nums[i]);
        }

        return res; 
    }

// ⚔️⚔️⚔️⚔️⚔️⚔️⚔️⚔️⚔️⚔️⚔️⚔️⚔️⚔️⚔️⚔️⚔️⚔️⚔️⚔️⚔️⚔️⚔️⚔️⚔️⚔️⚔️⚔️⚔️⚔️⚔️


int main()
{
    vector<int> arr = {2 , 4};

    int maxArea = getMaxareaOfHistogram(arr);
    cout << "Maximum area of histogram is -> " << maxArea;

    int maxArea2 = largestRectangleArea(arr);
    cout << "\nMaximum area of histogram is -> " << maxArea2;
    return 0;

}