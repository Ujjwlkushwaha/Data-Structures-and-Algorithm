/*
   ✅  2415. Reverse Odd Levels of Binary Tree


    Given the root of a perfect binary tree, reverse the node values at each odd level of the tree.

    For example, suppose the node values at level 3 are [2,1,3,4,7,11,29,18], then it should become [18,29,11,7,4,3,1,2].
    Return the root of the reversed tree.

    A binary tree is perfect if all parent nodes have two children and all leaves are on the same level.

    The level of a node is the number of edges along the path between it and the root node.



Example 1:

    Input: root = [2,3,5,8,13,21,34]
    Output: [2,5,3,8,13,21,34]

Explanation:
    The tree has only one odd level.
    The nodes at level 1 are 3, 5 respectively, which are reversed and become 5, 3.

*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    //  ✅  Recursive Approach
    TreeNode *reverseOddLevels(TreeNode *root)
    {
        traverseDFS(root->left, root->right, 0);
        return root;
    }
    void traverseDFS(TreeNode *leftChild, TreeNode *rightChild, int level)
    {
        if (leftChild == nullptr || rightChild == nullptr)
        {
            return;
        }
        // If the current level is odd, swap the values of the children.
        if (level % 2 == 0)
        {
            int temp = leftChild->val;
            leftChild->val = rightChild->val;
            rightChild->val = temp;
        }

        traverseDFS(leftChild->left, rightChild->right, level + 1);
        traverseDFS(leftChild->right, rightChild->left, level + 1);
    }

    // ✅  Iterative Approach
    TreeNode *reverseOddLevels(TreeNode *root)
    {
        if (!root)
        {
            return nullptr; // Return null if the tree is empty.
        }

        queue<TreeNode *> q;
        q.push(root); // Start BFS with the root node.
        int level = 0;

        while (!q.empty())
        {
            int size = q.size();
            vector<TreeNode *> currentLevelNodes;

            // Process all nodes at the current level.
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                currentLevelNodes.push_back(node);

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            // Reverse node values if the current level is odd.
            if (level % 2 == 1)
            {
                int left = 0, right = currentLevelNodes.size() - 1;
                while (left < right)
                {
                    int temp = currentLevelNodes[left]->val;
                    currentLevelNodes[left]->val =
                        currentLevelNodes[right]->val;
                    currentLevelNodes[right]->val = temp;
                    left++;
                    right--;
                }
            }

            level++;
        }

        return root; // Return the modified tree root.
    }
};

// level order traversal
    void levelOrder(TreeNode *root)
    {
        if (root == nullptr)
            return;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            cout << node->val << " ";

            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        cout << endl;
    }

int main()
{
    // Test the solution with the given example.
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(3);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(8);
    root->left->right = new TreeNode(13);
    root->right->left = new TreeNode(21);
    root->right->right = new TreeNode(34);

    Solution solution;
    TreeNode *reversedRoot = solution.reverseOddLevels(root);
    levelOrder(reversedRoot);
    return 0;
    // Output: 2 5 3 8 13 21 34
}