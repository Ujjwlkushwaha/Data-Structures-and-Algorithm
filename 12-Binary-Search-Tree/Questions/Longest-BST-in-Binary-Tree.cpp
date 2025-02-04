#include <bits/stdc++.h>
using namespace std;

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

//================Solution=====================

class NodeData{ // this node for store and manage ans
public:
    int size;
    int maxVal;
    int minVal;
    bool isValidBST;

    NodeData() {}

    NodeData(int s, int mx, int min, bool isValid)
    {                               // Every node return these four values
        this->size = s;             // size of longest BST
        this->maxVal = mx;          // maxValue of leftSubTree
        this->minVal = min;         // minVal of rightSubTree
        this->isValidBST = isValid; // It is part of BST or NOT
    }
};

NodeData findLongestBST( Node* root , int &ans){

    // base case
    if( !root )
    {
        NodeData temp(0 , INT_MIN , INT_MAX , true);
        return temp;
    }

    // check leftSubTree first
    NodeData leftAns = findLongestBST(root->left , ans);
    
    // check rightSubTree 
    NodeData rightAns = findLongestBST(root->right , ans);

    // now make NodeData for return 
    NodeData currNodeKaAns;

    currNodeKaAns.size = leftAns.size + rightAns.size + 1;
    currNodeKaAns.maxVal = min(root->data , rightAns.maxVal);
    currNodeKaAns.minVal = max(root->data , leftAns.minVal);

    // now check it is valid bst or not
    if( leftAns.isValidBST and rightAns.isValidBST and ( root->data > leftAns.maxVal and root->data < rightAns.minVal))
    {
        currNodeKaAns.isValidBST = true;
    }else{
        currNodeKaAns.isValidBST = false;
    }

    // save ans 
    if( currNodeKaAns.isValidBST)
    {
        ans = max(ans , currNodeKaAns.size);
    }

    return currNodeKaAns;

}

// 📌============== Diver code==================
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

int main()
{
    Node *root = NULL;
    root = buildTree(root);

    cout << " tree is : " << endl;
    // preorder(root);
    levelOrder(root);


    // largest bst
    int ans = 0;
    findLongestBST( root , ans );
    cout << "Size of longest BST :: " << ans << endl;
}