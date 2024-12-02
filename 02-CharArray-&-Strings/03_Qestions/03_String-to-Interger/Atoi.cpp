//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int myAtoi(char *s) {
        // Your code here
        int i=0;
        long ans = 0;
        int sign = 1;
        while(s[i] == ' ')i++;
        if( s[i] == '-' ){
            sign = -1;
            i++;
        }
        
        while( s[i] >= '0' and s[i] <= '9')
        {
            ans = ans*10+(s[i]-'0');
            if( sign*ans <= INT_MIN) return INT_MIN;
            if(sign*ans >= INT_MAX) return INT_MAX;
            i++;
        }
        
        return (int)sign*ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        char s[20];
        cout << "Enter a string :: ";  // Input string with leading/trailing spaces
        cin >> s;
        Solution ob;
        int ans = ob.myAtoi(s);
        cout <<"Your Number is :: " <<  ans << endl;
    }
}