// find mid element in the stack

#include<iostream>
#include<stack>

using namespace std;


void findMidElement(stack<int>&st , int &size)
{
        if(st.empty())return;

        if(st.size() == (size/2) + 1)
        {
            cout << "mid element:: " << st.top() << endl;
            return;
        }

        int temp = st.top();
        st.pop();

        findMidElement(st , size);

        st.push(temp);
}



int main(){

    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    // st.push(60);

    int size = st.size();
    findMidElement(st , size);


}