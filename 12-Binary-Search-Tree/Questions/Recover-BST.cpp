#include<bits/stdc++.h>
using namespace std;

class Node{
  public:
    int data;
    Node* left;
    Node* right;
    
    Node(int x){
        data = x;
        left = right = nullptr;
    }
};

// Function to store the inorder 
// traversal of the tree in a vector
void findInorder(Node* curr, vector<int>&inorder){
    if(curr == nullptr) return;
  
      // Recursively store left subtree
    findInorder(curr->left, inorder);
  
      // Store the current node's data
    inorder.push_back(curr->data);
  
      // Recursively store right subtree
    findInorder(curr->right, inorder);
}

// Recursive function to correct the BST by replacing
// node values with sorted values
void correctBSTUtil(Node* root, vector<int> &inorder, int &index){
    if(root == nullptr) return;
      
      // Recursively fill the left subtree
    correctBSTUtil(root->left, inorder, index);
  
      // Replace the current node's data with 
      // the correct value from the sorted array
    root->data = inorder[index];
    index++;
      
      // Recursively fill the right subtree
    correctBSTUtil(root->right, inorder, index);
}

// Function to fix the given BST where two nodes are swapped.
void correctBST(Node* root){
  
    // Vector to store the inorder traversal of the tree
    vector<int> inorder;
    findInorder(root, inorder);
  
      // Sort the vector to get the correct order of 
      // elements in a BST
    sort(inorder.begin(), inorder.end());
  
    int index = 0;
    correctBSTUtil(root, inorder, index);
}

// Print tree as level order
void printLevelOrder(Node *root) {
    if (root == nullptr) {
        cout << "N ";
        return;
    }

    queue<Node *> qq;
    qq.push(root);
    int nonNull = 1;

    while (!qq.empty() && nonNull > 0) {
        Node *curr = qq.front();
        qq.pop();

        if (curr == nullptr) {
            cout << "N ";
            continue;
        }
        nonNull--;

        cout << (curr->data) << " ";
        qq.push(curr->left);
        qq.push(curr->right);
        if (curr->left)
            nonNull++;
        if (curr->right)
            nonNull++;
    }
}

int main(){
  
    // Constructing the tree with swapped nodes
    //       6
    //     /  \
    //    10   2
    //   / \  / \
    //  1  3 7  12
    // Here, 10 and 2 are swapped
  
    Node *root = new Node(6);
    root->left = new Node(10);
    root->right = new Node(2);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->right = new Node(12);
    root->right->left = new Node(7);

    correctBST(root);
    printLevelOrder(root);
 
    return 0;
}
