#include<iostream>
#include<vector>
#include<stack>
using namespace std;

// list of previous smallest elements in respect of all elements
vector<int> previousSmallestElements(vector<int> &arr)
{
    vector<int> ans(arr.size());

    stack<int>st;
    st.push(-1);

    for( int i = 0; i < arr.size(); i++){

        while(!st.empty() && arr[st.top()] >= arr[i]){
            st.pop();
        }
        ans[i] = (st.empty()? -1 : st.top());
        st.push(i);

    }

    return ans;
}
int main(){
    vector<int> arr = {5, 2, 8, 6, 1, 9, 3};
    vector<int> ans = previousSmallestElements(arr);
    
    cout << "Previous Smallest Elements: ";
    for(int i : ans){
        cout << i << " ";
    }
}