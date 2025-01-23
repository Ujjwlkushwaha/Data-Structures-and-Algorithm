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

// Top view👀 of binary treee  ✅
void topViewOfBinaryTree( TreeNode* root )
{
    // base case
    if( !root ) return ;
    
    // create a map for maintain and remember values and its horizontal Distence
    map<int,int> topNodeMap; 
    
    // this queue carried rootNode and its horizontal distance
    queue<pair<TreeNode*,int>> q;
    
    //  initial value 
    q.push(make_pair(root , 0));
    
    // traversing
    while( !q.empty() )
    {
        // get front value which is ( pair )
        pair<TreeNode*, int> pr = q.front();
        q.pop();
        
        // destructure the root and Horizontal distance from the pair
        TreeNode* temp = pr.first; // root
        int Hdistance = pr.second; // horizontal distance
        
        // now think isko answer map me store kru ki naa
        if( topNodeMap.find(Hdistance) == topNodeMap.end() )
        { 
            // iss distance ka koi element map pe present hai ya nhi 
            // agar nhi hai
            topNodeMap[Hdistance] = temp->val;
        }
        
        
        // Left right ko dekh lo 
        if( temp->left != NULL ) q.push(make_pair(temp->left , Hdistance-1));
        if( temp->right != NULL ) q.push(make_pair(temp->right , Hdistance+1));
    }
    
    
    // Printing top view of binary tree
    cout<< "Printing top view of binary tree :: " << endl;
    for( auto val:topNodeMap)
    {
        cout << val.second<<" " ;
    }
    
    cout << endl;
    
}

// create tree 
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
    
    // printing tree
    cout << "Final tree is ::  \n" << endl;
    printTree( root );
    
    // top view of binary tree
    cout << "\n Top-view is ::  \n";
    topViewOfBinaryTree(root);
    
}