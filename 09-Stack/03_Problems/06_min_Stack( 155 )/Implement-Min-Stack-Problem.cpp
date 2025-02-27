#include<bits/stdc++.h>
using namespace std;

// GFG :: https://www.geeksforgeeks.org/problems/get-minimum-element-from-stack/1

class StackImplementation{
    private:
        vector<pair<int,int>> st;
    
    public: 
        StackImplementation(){}

    void push( int x )
    {
        if( st.empty() ) 
            st.push_back({x , x});
        else{
            pair<int,int> temp  = st.back();
            st.push_back( { x , min(x, temp.second)});
        }
    }

    void printStack()
    {
        if( st.empty() ){
            cout <<" Stack is empty bro " <<endl;
            return;
        }

        cout << "Printing stack:: " << endl;
        for( auto val : st )
        {
            cout << val.first << " " << val.second << endl;
        }

        cout << endl;
    }

    void pop()
    {
        if( !st.empty())  st.pop_back();
    }

    int peek()
    {
        if( st.empty()) return -1;

        return st.back().first;
    }

    int getMin()
    {
        if( !st.empty())
            return st.back().second;
    }
};

int main(){
    StackImplementation s;

    s.push( 5);
    s.push( 15);
    s.push( 25);
    s.push( 35);
    s.push( 45);
    s.push( 55);

    s.printStack();

    cout << " The top element:: "<< s.peek() << endl;
    cout << " Minimum element in stack is :: " << s.getMin() << endl;
    s.pop();


    s.printStack();
}