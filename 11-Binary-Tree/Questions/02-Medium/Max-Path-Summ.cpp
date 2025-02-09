#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

int getMaxSum( Node* root , int &maxSum)
{
    // base case
    if( root == NULL ) return 0;

    // get sum of left subtree
    int l = max( 0 , getMaxSum( root->left , maxSum));

    // get sum of right subTree
    int r = max( 0 , getMaxSum( root->right , maxSum));

    // store maxSum 
    maxSum = max( maxSum , l + r + root->data );

    // Return the maximum path sum rooted at this node
    return root->data + max( l , r);
}

int maxPathSum(Node *root)
{
    int sum = root->data; // store max sum
    getMaxSum( root , sum );
}

// GFG : https://www.geeksforgeeks.org/problems/maximum-path-sum-from-any-node/1