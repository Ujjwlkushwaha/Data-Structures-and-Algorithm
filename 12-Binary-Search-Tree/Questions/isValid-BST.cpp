#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    bool helper(TreeNode *root, long long lowerBound, long long upperBound)
    {
        if (!root)
            return true;

        bool con1 = (lowerBound < root->val);
        bool con2 = (upperBound > root->val);

        bool lAns = helper(root->left, lowerBound, root->val);
        bool rAns = helper(root->right, root->val, upperBound);

        if (con1 and con2 and lAns and rAns)
            return true;
        else
            return false;
    }
    bool isValidBST(TreeNode *root)
    {
        /*
            Algo:-
                for valid bst
                    leftNode < root < rightNode
        */

        long long lowerBound = LONG_MIN;
        long long upperBound = LONG_MAX;

        return helper(root, lowerBound, upperBound);
    }
};