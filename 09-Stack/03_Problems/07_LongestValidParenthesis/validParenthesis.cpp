#include<iostream>
#include<stack>
using namespace std;

int LongestValidParenthesis(string str)
{
    stack<int> st;
    st.push(-1);
    int maxLen = 0;

// for traversing the string
    for(int i = 0; i < str.length(); i++)
    {
        // check every character 
        if(str[i] == '(')
        {
            // if it is opening bracket  then directly push into the stack their index
            st.push(i);
        }
        else
        {

            // if it is closing bracket then pop from stack
            st.pop();

            // then check the index of top element for finding length 
            if(st.empty())
            {
                // if stack is empty then push current index into stack
                st.push(i);     
            }
            else
            {
                // if stack is not empty then calculate length and update maxLen if required
                int len = i - st.top();
                maxLen = max(maxLen, len);
            }
        }
    }

    // return the length of longest valid substring
    return maxLen;

}

int main()
{

    string str = "((())";
    cout << "Length of the longest valid parentheses substring is: " << LongestValidParenthesis(str) << endl;
}