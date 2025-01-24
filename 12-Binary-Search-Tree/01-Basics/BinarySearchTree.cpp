#include<bits/stdc++.h>
using namespace std;

// binary search tree node
class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node( int data )
        {
            this->data = data;
            this->left = this->right=NULL;
        }
};

Node* insertIntoBinarySearchTree(Node* &root , int data)
{
    if( root == NULL ){
      root = new Node( data );
      return root ;
    }

    if( data > root->data )
    {
        root->right = insertIntoBinarySearchTree(root->right , data);
    }else{
        root->left = insertIntoBinarySearchTree( root->left , data );
    }

}

Node* createBinarySearchTree(Node* root)
{

    int d;
    cin >> d;

    while( d != -1 )
    {
        root = insertIntoBinarySearchTree( root , d );
        cin >> d ;
    }
}

void levelOrder(Node* root)
{
    
}

int main()
{

}