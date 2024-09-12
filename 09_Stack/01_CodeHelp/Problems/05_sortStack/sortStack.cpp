#include<iostream>
#include<stack>
using namespace std;

void sort(stack<int>& st , int data)
{

    if(st.empty()){
        st.push(data);
        return;
    }

    if(st.top() >= data){
        st.push(data);
        return;
    }

    int temp = st.top();
    st.pop();

    sort(st, data);

    st.push(temp);
}

void sortStack(stack<int>& stack)
{
    if(stack.empty())return;

    int temp = stack.top();
    stack.pop();

    sortStack(stack);

    sort(stack, temp);
}

void printStack(stack<int> s)
{
    while(!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}
int main()
{

    stack<int> st;
    st.push(30);
    st.push(20);
    st.push(50);
    st.push(23);
    st.push(43);
    st.push(56);
    st.push(70);
    st.push(40);

    cout << "Original Stack: ";
    printStack(st);

    sortStack(st);

    cout << "\nSorted Stack: ";
    printStack(st);

}