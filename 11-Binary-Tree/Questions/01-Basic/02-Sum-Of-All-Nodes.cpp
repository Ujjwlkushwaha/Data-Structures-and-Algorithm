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

//⭐ sum of all nodes of tree
int sumOfAllNodes(Node* root){
    if(root == NULL) return 0;
    return root->data + sumOfAllNodes(root->left) + sumOfAllNodes(root->right);
}


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
        cout << "\nSum of all nodes in the tree: " << sumOfAllNodes(root);
    }
