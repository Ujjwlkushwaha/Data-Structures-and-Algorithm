#include <bits/stdc++.h>
using namespace std;

// Structure for a Node
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

Node *LCA(Node *root, Node *p, Node *q)
{
    // code here

    if (root == NULL)
        return NULL;

    if (root == p)
        return p;
    if (root == q)
        return q;

    // find in left side
    Node *leftAns = LCA(root->left, p, q);

    // find in right
    Node *rightAns = LCA(root->right, p, q);

    if (leftAns == NULL and rightAns == NULL)
    { // target not found
        return NULL;
    }
    else if (leftAns != NULL and rightAns == NULL)
    { // both occor in left side
        return leftAns;
    }
    else if (leftAns == NULL and rightAns != NULL)
    { // both occur in right side
        return rightAns;
    }
    else // occur in both side
        return root;
}

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

// Driver Code
int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(4);
    root->left->right = new Node(7);
    root->left->left = new Node(3);
    root->left->right->left = new Node(8);
    root->right = new Node(2);
    root->right->right = new Node(6);

}
