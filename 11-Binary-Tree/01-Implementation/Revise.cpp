#include<bits/stdc++.h>
using namespace std;

class TreeNode{ // TreeNode class
    public:
        int data;
        TreeNode* left; 
        TreeNode* right;

        TreeNode( int data )
        {
            this->data = data;
            this->left = this->right = NULL;
        }
};

TreeNode* builtTree( TreeNode* root )
{
    int val;
    cout << "Enter -1 for putting null :: " <<  endl ;
    cin >> val;

    if( val == -1) return NULL;

    // create node
    root = new TreeNode(val);

    cout << "Enter left of " << val << endl;
    root->left = builtTree( root->left );  // recursive call for left node

    cout << "Enter right of " << val << endl;
    root->right = builtTree( root->right ); // recursive call for right node

    return root;
}

void preOrder(TreeNode* root){
    if( !root) return; // base case

    // NLR
    cout << root->data << " " ;
    preOrder( root->left );
    preOrder( root->right );
}

void postOrder(TreeNode* root){
    if( !root) return; // base case

    // LRN
    postOrder( root->left );
    postOrder( root->right );
    cout << root->data << " " ;
}

void inOrder( TreeNode* root )
{
    if( !root) return; // base case

    // LNR
    inOrder( root->left );
    cout << root->data << " " ;
    inOrder( root->right );
}

void levelOrder( TreeNode * root){

    if( !root ) return ; // base case

    // store data level wise
    queue<TreeNode*> q;
    q.push( root );
    q.push( NULL);

    while( !q.empty() )
    {
        // pick first node from queue
        TreeNode* temp = q.front();
        q.pop();

        if( temp == NULL )
        {
            cout << endl; // for new line
           if(q.empty())
                {
                    break;
                }else{
                    q.push(NULL);
                }
        }
        else{
            cout << temp->data<< " ";

            if( temp->left != NULL ) q.push( temp->left);
            if( temp->right != NULL ) q.push( temp->right);
        }
    }

}

int heightOfBinaryTree( TreeNode* root )
{
    if( !root ) return -1; // base case

    // get height of leftSubtree
    int leftAns = heightOfBinaryTree( root->left );
    
    // get height of leftSubtree
    int rightAns = heightOfBinaryTree( root->right );

    int ans = max( leftAns , rightAns ) + 1 ;

    return ans;
}


int main()
{
    TreeNode * root = NULL;
    root = builtTree(root);

    cout << "\nTree in preOrder :: " << endl;
    preOrder(root);

    cout << "\nTree in postOrder :: " << endl;
    postOrder(root);

    cout << "\nTree in inOrder :: " << endl;
    inOrder( root );

    cout << "\nTree in levelOrder :: " << endl;
    levelOrder( root );

    cout << "\n Height of tree :: " << heightOfBinaryTree( root )<< endl;


}