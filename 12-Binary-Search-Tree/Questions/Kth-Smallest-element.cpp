#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};

class Solution
{
public:
    int kthSmallest(TreeNode *root, int &k)
    {

        // base case
        if (!root)
            return -1;

        // move to left
        int leftAns = kthSmallest(root->left, k);
        if (leftAns != -1)
            return leftAns;

        // current Node
        k--;
        if (k == 0)
            return root->val;

        // move to right
        int rightAns = kthSmallest(root->right, k);

        return rightAns;
    }
};