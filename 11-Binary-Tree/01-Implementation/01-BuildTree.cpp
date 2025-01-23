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

// 📌📌 Building tree 
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

/*
    📌 there is three way of traversing binary tree

        1. inorder traversal
        2. preorder traversal
        3. postorder traversal
        4. level order traversal

 */

//📌📌  printing tree using inorder

    void inorder(Node* root)
    {
        if (root!= NULL)
        {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }

//📌📌  printing tree using preorder order
    void preorder(Node* root)
    {
        if (root!= NULL)
        {
            cout << root->data << " ";
            preorder(root->left);
            preorder(root->right);
        }
    }

// 📌📌 printing tree using postorder order

void postorder(Node* root)
{
    if (root!= NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
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
    
// Driver code
int main(){
    Node* root = NULL;
    root = buildTree(root);

    cout << " tree is : " << endl;
    // preorder(root);
    levelOrder(root);
}