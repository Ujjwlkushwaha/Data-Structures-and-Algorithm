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

// ============✅ Right-View-of-Binary-Tree ==========
void rightViewOfBinaryTree(TreeNode* root , int level , vector<int>& rightViewArray)
{
    // ☑️  base case
    if(root == NULL) return;

    // ☑️ array ka size agar level ke equal hai to root ka data insert kar do 
    if(level == rightViewArray.size()) rightViewArray.push_back(root->data);

    rightViewOfBinaryTree(root->right, level + 1, rightViewArray);
    rightViewOfBinaryTree(root->left, level + 1, rightViewArray);
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
    // 10 20 40 70 -1 -1 80 110 -1 -1 120 -1 -1 50 -1 -1 30 -1 60 90 -1 -1 100 -1 -1

    cout << " LevelOrderTraversal :: " << endl;
    levelOrderTraversal(root);

    //✅  Left View of Binary Tree
    vector<int> rightViewArray;
    rightViewOfBinaryTree(root, 0, rightViewArray);
    cout << "\nRight View of Binary Tree :: ";
    for(int i : rightViewArray) cout << i << " ";
}