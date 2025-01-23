// ✅ Balanced binary tree :- (hight of left - hight of right <= 1 )

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

// ✅ ============Solution==========

bool isBalanced(Node* root){
    if(root == NULL) return true;

    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    
    if(abs(leftHeight - rightHeight) <= 1 && isBalanced(root->left) && isBalanced(root->right))
    {
        return true;
    }
    else{
        return false;
    }
}

// ✅ ===========Driver Code=========

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

//📌📌 Height of the tree
int getHeight( Node* root)
{
    if( root == NULL ) return 0;

    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    int height = max(leftHeight, rightHeight)+1;
    return height;
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

    int main()
    {
        Node* root = NULL;
        root = buildTree(root);

        cout << "Level order traversal of the tree: " << endl;
        levelOrder(root);

        if( isBalanced )
        {
            cout << "Tree is balanced !" << endl;
        }else{
            cout << "Tree is not balanced !" << endl;
        }
    }
