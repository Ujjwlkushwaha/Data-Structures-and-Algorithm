#include<iostream>
#include<stack>
using namespace std;

//  👺 minimum bracket reversal -> 
/*  
          
    1. Hme simply ak paranthesis ki string given hai and hme usko arrange krna hai proper 

    2. But jo pahle phle se hi arrange hai unko chhorke jo arrange nhi hai utna part arrange krege

    3. and hme return krna hai ki hmne kibaar me arrange kiyaa 


📌 Count the Reversals gfg

    💀💀 Difficulty: MediumAccuracy: 51.88%Submissions: 68K+Points: 4

Given a string S consisting of only opening and closing curly brackets '{' and '}', find out the minimum number of reversals required to convert the string into a balanced expression.
A reversal means changing '{' to '}' or vice-versa.

Example 1:

Input:
S = "}{{}}{{{"
Output: 3
Explanation: One way to balance is:
"{{{}}{}}". There is no balanced sequence
that can be formed in lesser reversals.
Example 2:

Input: 
S = "{{}{{{}{{}}{{"
Output: -1
Explanation: There's no way we can balance
this sequence of braces.
Your Task:
You don't need to read input or print anything. Your task is to complete the function countRev() which takes the string S as the input parameter and returns the minimum number of reversals required to balance the bracket sequence. If balancing is not possible, return -1. 

Expected Time Complexity: O(|S|).
Expected Auxiliary Space: O(1).

*/

int countRev(string s)
{
    if(s.length() & 1 )  return -1;

    int ans = 0 ;
    stack<char> st;

    for(char ch : s)
    {
        if(ch == '{') 
        {
            st.push(ch);
        } 
        else
        {
            // agar stack empty bhi na ho and uske top pe koi opening paranthesis pda ho 
            if(!st.empty() && st.top() == '{'){

                // pair mil gya pop kar do
                st.pop();
                 // pop karoo fir 
            }
            else
            {
                // pair nhi milaa push kro fir 
                st.push(ch);
            }
        }
    }

// if stack is still no empty
    while(!st.empty()){

        // stack me pahle do char uthaye unko match kraya
        char ch1 = st.top() ; 
        st.pop();

        char ch2 = st.top();
        st.pop();

    // agar vo same hai to 1  ko revese krna pdegaa
        if( ch1 == ch2){
            ans += 1;
        }else{

            // nhi to 2no ki reverse krna pdegaa
            ans += 2;
        }
    }

    return ans;
}

int main()
{

    string s = "}}}}}}{}{}}}{{}}}}{}}{{{}{}{}{}}{{{{}}}{}}";
    cout <<" Number of reversal :: " <<  countRev(s) << endl; // 3
    // ⭐⭐⭐⭐⭐    solved on gfg⭐ 
}
