#include<bits/stdc++.h>
using namespace std;


//✅ Structure of TreeNode
class TreeNode{
    public:
        int data;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int value){
            data = value;
            left = right = NULL;
        }
};

// ============✅ Left-View-of-Binary-Tree ==========
void leftViewOfBinaryTree(TreeNode* root , int level , vector<int>& leftViewArray)
{
    // ☑️  base case
    if(root == NULL) return;

    // ☑️ array ka size agar level ke equal hai to root ka data insert kar do 
    if(level == leftViewArray.size()) leftViewArray.push_back(root->data);

    leftViewOfBinaryTree(root->left, level + 1, leftViewArray);
    leftViewOfBinaryTree(root->right, level + 1, leftViewArray);
}


// ============ ✅ Driver Code ======================

// ✅ Create Binary Tree
TreeNode* createBinaryTree()
{
    int data;
    cin >> data;

    if(data == -1) return NULL;

    TreeNode* root = new TreeNode(data);

    cout << "Enter data for left child of " << data << ": ";
    root->left = createBinaryTree();

    cout << "Enter data for right child of " << data << ": ";
    root->right = createBinaryTree();

    return root;
}

//✅ Traversals of Binary Tree

void preOrderTraversal( TreeNode* root )
{
    if( !root ) return;

    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
} 

void inOrderTraversal( TreeNode* root )
{
    if(!root ) return;
    
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

void postOrderTraversal( TreeNode* root )
{
    if(!root ) return;
    
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

void levelOrderTraversal(TreeNode* root)
{
    if(!root ) return;

    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        TreeNode* temp = q.front();
        if(temp == NULL)
        {
            cout << endl;
            q.pop();
            if(!q.empty()) q.push(NULL);
        }
        else
        {
            cout << temp->data << " ";
            q.pop();
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
}


int main()
{
    TreeNode* root = createBinaryTree();

    cout << " LevelOrderTraversal :: " << endl;
    levelOrderTraversal(root);

    //✅  Left View of Binary Tree
    vector<int> leftViewArray;
    leftViewOfBinaryTree(root, 0, leftViewArray);
    cout << "\nLeft View of Binary Tree :: ";
    for(int i : leftViewArray) cout << i << " ";
}