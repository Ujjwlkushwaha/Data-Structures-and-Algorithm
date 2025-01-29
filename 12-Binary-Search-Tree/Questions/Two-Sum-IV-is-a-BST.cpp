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


class Solution {
public:
    void traverse(TreeNode* root, vector<int>& ans) {
        if (!root) return;
        traverse(root->left, ans);  // Traverse left subtree
        ans.push_back(root->val);  // Store the node value
        traverse(root->right, ans); // Traverse right subtree
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> ans;
        traverse(root, ans);  // Get the sorted elements of the BST
        
        int left = 0, right = ans.size() - 1;  // Two-pointer initialization
        while (left < right) {
            int sum = ans[left] + ans[right];
            if (sum == k) return true;  // Found the pair
            else if (sum < k) left++;   // Increase the smaller pointer
            else right--;               // Decrease the larger pointer
        }
        return false;  // No pair found
    }
};