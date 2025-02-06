#include <bits/stdc++.h>
using namespace std;

/*
    https://www.geeksforgeeks.org/write-an-efficient-c-function-to-convert-a-tree-into-its-mirror-tree/

    📌Mirror Tree

        Given a binary tree, convert the binary tree to its Mirror tree.

        Mirror of a Binary Tree T is another Binary Tree M(T) with left and right children of all non-leaf nodes interchanged.     

Examples:

        Input: root[] = [1, 2, 3, N, N, 4]
        Output: [1, 3, 2, N, 4]


*/

class Node
{
public:
    int data;
    Node *left, *right;

    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

// 📌 swap children of nodes
void mirror(Node *root)
{
    if (root == nullptr)
        return;

    // Invert the left and right subtree
    mirror(root->left);
    mirror(root->right);

    // Swap the left and right subtree
    swap(root->left, root->right);
}


// 📌Driver code--------------------------------
Node *buildTree(Node *root)
{
    int data;
    cout << "Enter data (-1 for no node): ";
    cin >> data;

    root = new Node(data);

    if (data == -1)
        return NULL;

    cout << "Enter data in left of " << data << endl;
    root->left = buildTree(root->left);

    cout << "Enter data in right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

// 📌📌 level order traversal
void levelOrder(Node *root)
{
    if (root == NULL)
        return;

    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        if (temp == NULL)
        {
            cout << endl;
            q.pop();
            if (q.empty())
            {
                break;
            }
            else
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            q.pop();
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}

// Driver code
int main()
{
    Node *root = NULL;
    root = buildTree(root);

    cout << " tree is : " << endl;
    // preorder(root);
    levelOrder(root);

    mirror(root);
}