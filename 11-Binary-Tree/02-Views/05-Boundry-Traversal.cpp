// top view of binary tree
#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
        int val;
        TreeNode* left;
        TreeNode* right;
        
        TreeNode( int data )
        {
            this->val = data;
            this->left = this->right = NULL;
        }
};


// ✅ Boundry traversal

void printLeftBoundry( TreeNode* root )
{
    // base case 
    if( !root ) return;
    
    // leaf node condition
    if( root->left == NULL and root->right == NULL )
    {
        // we are on leaf node
        return ; 
    }
    
    cout << root->val << " ";
    
    if( root->left != NULL ){
        printLeftBoundry( root->left );
    }else{
        printLeftBoundry( root->right);
    }
}

void printRightBoundry( TreeNode* root )
{
    // base case 
    if( !root ) return;
    
    // leaf node condition
    if( root->left == NULL and root->right == NULL )
    {
        // we are on leaf node
        return ; 
    }
    if( root->right != NULL ){
        printRightBoundry( root->right );
    }else{
        printRightBoundry( root->left);
    }
    
    cout << root->val << " ";
}

void printLeafNodes( TreeNode* root )
{
    if( !root ) return;
    
    if( root->left == NULL and root->right == NULL )
    {
        cout << root->val << " ";
    }
    
    printLeafNodes( root->left );
    printLeafNodes( root->right );
}

void bountryTraversal( TreeNode* root)
{
    // base case
    if( !root ) return;
    
    // printleftBoundry -> printLeafBoudry-> printRightBoundry 
    printLeftBoundry(root);

    printLeafNodes( root );
    
    if( root->right != NULL )
    {
        printRightBoundry( root->right );
    }
}


// ✅create tree 
TreeNode* createBinaryTree()
{
    int val ; 
    cin >> val;
    
    if( val == -1 ) return NULL; 
    
    TreeNode* root = new TreeNode(val);
    
    cout << "Enter the data left-side of " << val << " " <<endl;
    root->left = createBinaryTree();
    
    cout << "Enter the data right-side of " << val << " " <<endl;
    root->right = createBinaryTree();
    
    return root;
}

void printTree( TreeNode* root )
{
    if( !root )
    {
        cout << "Tree is empty! " << endl;
        return;
    }
    
    // create queue and put initial value
    queue<TreeNode*> q;
    q.push( root );
    
    // push null for denoting level is finished;
    q.push( NULL );
    
    // traverse the tree
    while( !q.empty() )
    {
        // pop out the first element 
        TreeNode* temp = q.front();
        q.pop();
        
        if( temp == NULL )
        {
            cout <<endl;
            if(!q.empty()) q.push(NULL);
        }
        else{
            cout << temp->val << " ";
            
            if( temp->left != NULL )
            {
                q.push( temp->left);
            }
            
            if( temp->right != NULL )
            {
                q.push( temp->right );
            }
        }
    }
}

int main()
{
    cout << "Enter the root :: " ;
    TreeNode* root = createBinaryTree();
    // 10 20 30 40 -1 -1 50 60 -1 -1 70 -1 -1 80 -1 45 -1 -1 90 -1 82 -1 84 85 -1 -1 89 -1 -1
    
    // printing tree
    cout << "Final tree is ::  \n" << endl;
    printTree( root );
    
    
    cout << "\n Left Boundry is ::  \n";
    printLeftBoundry(root);
    
    cout << "\n right Boundry is ::  \n";
    printRightBoundry(root);
    
    cout << "\n After boundry traversal  ::  \n";
    bountryTraversal(root);
    
}

// 1, 2, N, 4, 9, 6, 5, N, 3, N, N, N, N 7, 8