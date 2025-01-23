#include<bits/stdc++.h>
using namespace std;

class Node{
    public: 
        int data;
        Node* left, *right;

    Node(int data){
        this->data = data;
        this->left = this->right = NULL;
    }
};

//=========✅ Solution=========

void helperFunction(Node* root , int targetSum , int sum , vector<vector<int>>&path ,vector<int> temp)
{
    // base case
    if( root == NULL ) return;

    // update sum
    sum += root->data;
    temp.push_back(root->data);

    // ✅ current node is leaf node
    if( root->left == NULL and root->right == NULL ) 
    {
        // check or validate
        if( sum == targetSum )  
        {
            // store the path2
            path.push_back(temp);
        }else{
            return;
        }
    }

    // check left and right subtree
    helperFunction(root->left, targetSum , sum , path , temp);
    helperFunction(root->right, targetSum , sum , path , temp);
}

vector<vector<int>> pathOfTargetSum(Node*root , int targetSum){

    int sum = 0;
    vector<vector<int>> path;
    vector<int> temp;
    helperFunction( root , targetSum , sum , path, temp);
    return path;
}

// ==========✅ Driver code ===========
Node* buildTree( Node* root)
{
    int data;
    cout << "Enter data (-1 for no node): ";
    cin >> data;

    root = new Node(data);

    if( data == -1)return NULL;

    cout << "Enter data in left of "<< data << endl;
    root->left = buildTree(root->left);

    cout << "Enter data in right of "<< data << endl;
    root->right = buildTree(root->right);

    return root;
}

// 📌📌 level order traversal 
    void levelOrder(Node* root)
    {
        if(root == NULL) return;

        queue<Node*> q;
        q.push(root);
        q.push(NULL);

        while(!q.empty())
        {
            Node* temp = q.front();
            if(temp == NULL)
            {
                cout << endl;
                q.pop();
                if(q.empty())
                {
                    break;
                }else{
                    q.push(NULL);
                }
            }else{
                cout << temp->data << " ";
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            
        }
    }

    // 📌⭐ count number of nodes in the tree
    int countNodes(Node* root)
    {
        if(root == NULL) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    int main()
    {
        Node* root = NULL;
        root = buildTree(root);

        cout << "Level order traversal of the tree: " << endl;
        levelOrder(root);

        cout << "\nNumber of nodes in the tree: " << countNodes(root);

        int targetSum = 24;
        vector<vector<int>> paths = pathOfTargetSum( root, targetSum) ;

        // printing the paths
        cout << "\nall paths: of target sum "<< targetSum << endl;
        for(auto path : paths)
        {
            for(auto num : path)
                cout << num << "-> ";
            cout << endl;
        }
    }
