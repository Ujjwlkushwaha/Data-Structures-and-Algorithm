/*

    in This problems we can design a stack in which given operations are executed in constant time

        . push() in constant time
        . pop() in constant time
        . top() in constant time
        . getMinimumElement() in constant time

*/


#include<iostream>
#include<vector>
#include<utility>
using namespace std;

class MinStack{
    public:

        vector<pair<int , int>> st;

        // adds element to the stack (constant time)
        void push(int data)
        {
            // if stack is empty 
            if(st.empty())
            {
                st.push_back(make_pair(data,data));

            }else // if stack is not empty
            {
                int min_element = min(st.back().second,data);
                st.push_back(make_pair(data,min_element));
            }
        }

        // removes top element of the stack (constant time)
        void pop(){
            st.pop_back();
        }

        // returns top element of the stack without removing it  (constant time)
        int top(){
            return st.back().first;
        }

        // returns minimum element in the stack without removing it
        int getMin(){
            return st.back().second;
        }
};

int main(){

    MinStack minStack;
    minStack.push(5);
    minStack.push(1);
    minStack.push(5);
    minStack.push(8);
    minStack.push(9);
    minStack.push(13);

    cout<<"The top element is :: "<< minStack.top() << endl;
    cout << "Minimum element is: " << minStack.getMin() << endl;
}