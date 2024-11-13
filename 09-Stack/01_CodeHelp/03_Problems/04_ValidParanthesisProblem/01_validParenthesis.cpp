#include<iostream>
#include<stack>
using namespace std;

// in this problem we need to make sure  that the given bracket string is valid or not

bool isValid(string brackets)
{
    if(brackets.size() == 0)
    {
        return true;
    }

    stack<char> st;

    for(int i = 0 ; i < brackets.size() ; i++)
    {
        // means if brackets[i] is opening bracket then we will puch into the stack
        if(brackets[i] == '(' or brackets[i] == '{' or brackets[i] == '[')
        {
                st.push(brackets[i]);
        }else
        {
            if(!st.empty()){
                if(brackets[i] == ')' and st.top() == '(') 
                {
                        st.pop();
                }else if(brackets[i] == '}' and st.top() == '{')
                {
                    st.pop();
                }else if(brackets[i] == ']' and st.top() == '[')
                {
                    st.pop();
                }else{
                    return false;
                }
            }else{
                return false;
            }
        }
    }

     if(st.empty())
        {
            return true;
        }else{
            return false;
        }
}

int main()
{

    string brackets1 = "(){}[]"; // true
    string brackets2 = "()]";  // false
    string brackets3 = "(){}";  // true
    string brackets4 = "[{()}]"; //true
    string brackets5 = "(]"; // false
    string brackets6 = "{()]"; // false

    cout << isValid(brackets1) << endl;
    cout << isValid(brackets2) << endl;
    cout << isValid(brackets3) << endl;
    cout << isValid(brackets4) << endl;
    cout << isValid(brackets5) << endl;
    cout << isValid(brackets6) << endl;

}