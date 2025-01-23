#include <bits/stdc++.h>
using namespace std;

// ✅ Construct tree using preOrder traversal and inOrder traversal

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

//=========✅ Solution=========
Node *createTreeUsingPreOrderAndInorder(map<int,int>& inOrderMap , int preOrder[], int inOrder[], int &idx, int inStart, int inEnd, int size)
{
    if (idx >= size or inStart > inEnd)
    {
        return NULL;
    }

    int element = preOrder[idx];
    idx++;
    Node *root = new Node(element);

    // ✅ inOrder me root ki position pta kro
    int positon = inOrderMap[element];

    // ✅ left wala part left me daal do
    root->left = createTreeUsingPreOrderAndInorder(inOrderMap ,preOrder, inOrder, idx, inStart, positon - 1, size);

    // ✅ right wala part right me daal do
    root->right = createTreeUsingPreOrderAndInorder(inOrderMap, preOrder, inOrder, idx, positon + 1, inEnd, size);

    return root;
}

// ==========✅ Driver code ===========

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

// 📌⭐ count number of nodes in the tree
int countNodes(Node *root)
{
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main()
{

    int preOrder[] = {2, 8, 10, 6, 4, 12};
    int inOrder[] = {10, 8, 6, 2, 4, 12};
    cout << "Level order traversal of the tree: " << endl;
    int start = 0;
    int end = 5;
    int idx = 0;

    // ✅ make a map for inOrder elements :=> searching aasan krne le liye
    map<int , int> inOrderMap;
    for (int i = start; i <= end; i++)
    {
        inOrderMap[inOrder[i]] = i;
    }

    Node *root = createTreeUsingPreOrderAndInorder( inOrderMap ,preOrder, inOrder, idx, start, end, 6);
    levelOrder(root);
}
