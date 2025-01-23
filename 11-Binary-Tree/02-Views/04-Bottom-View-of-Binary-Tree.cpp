#include<bits/stdc++.h>
using namespace std;


class TreeNode{
    public: 
        int data;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int data)
        {
            this->data = data;
            left = right = NULL;
        }
};

// ============✅ Bottom view =======================
void printBottomView(TreeNode* root)
{
    if( !root )
    {
        cout << "Error! : Tree is empty " << endl;
        return;
    }

    map<int,int> levelMap;
    queue<pair<TreeNode* , int>> q;
    
    q.push(make_pair(root , 0));

    while( !q.empty())
    {
        pair<TreeNode* , int > temp = q.front();
        q.pop();

        // extract data from pair
        TreeNode* node = temp.first;
        int level = temp.second;

        // override the values 
        levelMap[level] = node->data;

        // left bache ka dekho fir right ko dekhna
        if( node->left != NULL ) q.push(make_pair(node->left , level-1)); 
        if( node->right != NULL ) q.push(make_pair(node->right , level+1)); 
    }

    // printing map
    for( auto val : levelMap )
    {
        cout << val.second << " " ;
    }

}


// =============✅ Driver code =======================
TreeNode* builtTree()
{
    int data;
    cin>>data;

    if(data==-1){
        return NULL;
    }

    TreeNode* root = new TreeNode(data);

    cout << "Enter the left of " << data << endl ;
    root->left = builtTree();
    
    cout << "Enter the right of " << data << endl;
    root->right = builtTree();

    return root;

}

void levelOrderTraversal(TreeNode* root)
{
    if( !root )
    {
        cout << "ERROR! : Tree is empty" << endl;
        return ;
    }

    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);

    while( !q.empty())
    {
        TreeNode* temp = q.front();
        if( temp == NULL )
        {
            cout << endl;
            q.pop();
            if( !q.empty()) q.push(NULL);
        }else{
            cout << temp->data << " ";
            q.pop();

            if( temp->left ) q.push(temp->left);
            if( temp ->right ) q.push( temp->right); 
        }
    }
}
int main()
{

    TreeNode* root = builtTree() ;
    // 10 20 40 70 -1 -1 80 110 -1 -1 120 -1 -1 50 -1 -1 30 -1 60 90 -1 -1 100 -1 -1
    
    cout << "\n=> Printing tree using level order : " << endl;
    levelOrderTraversal(root);

    cout << "\n=> Print bottom view of binary tree :: " << endl;
    printBottomView(root);

}