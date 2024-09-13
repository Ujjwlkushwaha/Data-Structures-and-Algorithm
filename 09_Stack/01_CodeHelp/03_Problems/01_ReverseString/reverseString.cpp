#include<iostream>
#include<stack>
using namespace std;

int main(){

    string name = "RAJAMOLA";

    cout << "Before reverse string :: " << name << endl;

    // create stack 
    stack<char> st;

    // putting value into the stack
    for(int i = 0; i <name.length(); i++){
        st.push(name[i]);
    }

    // clean the previous string
    name = "";

    // make a new reversed string
    while(!st.empty()){
        name += st.top();
        st.pop();
    }

    cout <<"After revesing the string:: " <<  name << endl;

}