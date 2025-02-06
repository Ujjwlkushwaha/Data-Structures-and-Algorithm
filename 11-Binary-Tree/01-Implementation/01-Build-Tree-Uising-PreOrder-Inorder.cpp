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
Node *createTreeUsingPreOrderAndInorder(map<int,int>& inOrderMap , vector<int> preOrder, vector<int> inOrder, int &idx, int inStart, int inEnd)
{
    if (idx >= preOrder.size() or inStart > inEnd){
        return NULL; // base case
    }

    int rootData = preOrder[idx]; // getting ith root  
    idx++; // move forword

    // create node for ith element 
    Node *root = new Node(rootData);

    // ✅ inOrder me root ki position pta kro
    int positon = inOrderMap[rootData];

    // ✅ left wala part left me daal do
    root->left = createTreeUsingPreOrderAndInorder(inOrderMap ,preOrder, inOrder, idx, inStart, positon-1 );

    // ✅ right wala part right me daal do
    root->right = createTreeUsingPreOrderAndInorder(inOrderMap, preOrder, inOrder, idx, positon + 1, inEnd);

    return root;
}

// ==========✅ Driver code ===========

// 📌📌 level order traversal
void levelOrder(Node *root)
{
    if (root == NULL) // base case
        return;

    queue<Node *> q;
    q.push(root);
    q.push(NULL); // put for new line

    while (!q.empty())
    {
        Node *temp = q.front(); // popping the first element    
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
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

            if ( temp->left != NULL )
                q.push(temp->left); // putting left child into queue
            if ( temp->right != NULL )
                q.push(temp->right); // putting right child into queue
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

    vector<int> preOrder = {2, 8, 10, 6, 4, 12};
    vector<int> inOrder = {10, 8, 6, 2, 4, 12};

    cout << "Level order traversal of the tree: " << endl;
    int start = 0; // point starting index 
    int end = inOrder.size()-1; // point ending index
    
    int idx = 0; // point root node and monitor preOrder vector

    // ✅ make a map for inOrder elements :=> searching aasan krne le liye
    map<int , int> inOrderMap;
    for (int i = start; i <= end; i++)
    {
        inOrderMap[inOrder[i]] = i; // store index of every node 
        // taki baad me hm aasani se pta kr paye ki left me kitna part ayega or right me kitna part ayga
    }

    Node *root = createTreeUsingPreOrderAndInorder( inOrderMap ,preOrder, inOrder, idx, start, end);
    levelOrder(root);
}
