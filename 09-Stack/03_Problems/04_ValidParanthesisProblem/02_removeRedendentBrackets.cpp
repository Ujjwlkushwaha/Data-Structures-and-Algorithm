// In this problem we have to remove need less brackets from an expression

// 👉  Simple si approach hai ki given expression me jan bhi hme open bracket y koi operator milega use hm stack me push kr denge
// 👉  Agrr close bracket mila to hm check krege ki stack ke top par koi operator hai ki nhi 
// 👉  Agar operator nhi hua to false return kra denge amd agat operator hua to pop krege jab tak opening bracket nhi aata


#include<iostream>
#include<stack>

using namespace std;


void handler(stack<char>& stack , char str)
{
     // khud kr lo

}

void removeRedendent(string &str)
{
    if(str.length() == 0)return;

    stack<char> st;

    for(int i = 0 ; i < str.size() ; i++)
    {
        // means if brackets[i] is opening bracket then we will puch into the stack
        if(str[i] == '(' or str[i] == '{' or str[i] == '[' or str[i] == '+' or str[i] == '-' or str[i] == '/' or str[i] == '*' or str[i] == '%' or str[i] == '^')
        {
                st.push(str[i]);
        }else
        {
            if(!st.empty()){
                if(str[i] == ')') 
                {
                        handler(st , str[i]);
                }else if(str[i] == '}' and st.top() == '{')
                {
                    st.pop();
                }else if(str[i] == ']' and st.top() == '[')
                {
                    st.pop();
                }else{
                    // return false;
                }
            }else{
                // return false;
            }
        }
    }
}
int  main()
{

    string str1 = "( a + B )";

    cout << "Original string : " << str1 << endl;
    removeRedendent(str1);
    cout << "After removing needless brackets :: "<<  str1 << endl;

}