#include<bits/stdc++.h>
using namespace std;

/*  
    ✅ Count Servers that Communicate

        You are given a map of a server center, represented as a m * n integer matrix grid, where 1 means that on that cell there is a server and 0 means that it is no server.
        
        Two servers are said to communicate if they are on the same row or on the same column.

    Return the number of servers that communicate with any other server.    

*/

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int count = 0;
        vector<int> rowCount(rows);
        vector<int> colCount(cols);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    rowCount[i]++;
                    colCount[j]++;
                    count++;
                }
            }
        }

        // calculating jo communicate nhi kar rhe
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    if (rowCount[i] == 1 and colCount[j] == 1) {
                        count--;
                    }
                }
            }
        }

        return count;
    }
};

int main()
{
    vector<vector<int>> grid = {{1,1,0,0},{0,0,1,0},{0,0,1,0},{0,0,0,1}};
    Solution obj;
    
    cout << "total 1's in a row and col is " << obj.countServers(grid) << endl;

    /*
        Output: 4
        Explanation:   
            The two servers in the first row can communicate with each other. 
            The two servers in the third column can communicate with each other. 
            The server at right bottom corner can't communicate with any other server.
    */
}