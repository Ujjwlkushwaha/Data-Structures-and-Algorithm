#include<bits/stdc++.h>
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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {

        // base case
        if (root == NULL)
            return NULL;

        // case 1: -> p and q both are in left
        if (p->val < root->val and q->val < root->val)
        {
            TreeNode *leftAns = lowestCommonAncestor(root->left, p, q);
            return leftAns;
        }

        // case 2: -> p and q both are in right
        if (p->val > root->val and q->val > root->val)
        {
            TreeNode *rightAns = lowestCommonAncestor(root->right, p, q);
            return rightAns;
        }

        // case 3: p in left and q in right
        if (p->val < root->val and q->val > root->val)
        {
            return root;
        }

        return root;
    }
};