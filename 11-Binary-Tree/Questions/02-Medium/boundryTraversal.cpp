#include<bits/stdc++.h>
using namespace std;


class Node{
    public:
        int data;
        Node*left;
        Node* right;

        Node( int d )
        {
            this->data = d;
            this->left = this->right = NULL;
        }
};

class Solution {
  public:
  
        bool isLeaf(Node *node) {
        return node->left == nullptr && node->right == nullptr;
    }
    
    // Function to collect left boundary nodes
    // (top-down order)
    void collectBoundaryLeft(Node* root, vector<int>& res) {
          // exclude leaf node
        if (root == nullptr || isLeaf(root))
            return;
        
        res.push_back(root->data);
        if (root->left) 
            collectBoundaryLeft(root->left, res);
        
        else if (root->right)
            collectBoundaryLeft(root->right, res);
    }
    
    // Function to collect all leaf nodes 
    void collectLeaves(Node *root, vector<int> &res) {
        if (root == nullptr)
            return;
        
          // Add leaf nodes
        if (isLeaf(root)) {
            res.push_back(root->data);
            return;
        }
    
        collectLeaves(root->left, res);
        collectLeaves(root->right, res);
    }
    
    
    // Function to collect right boundary nodes
    // (bottom-up order)
    void collectBoundaryRight(Node* root, vector<int>& res) {
          // exclude leaf nodes
        if (root == nullptr || isLeaf(root)) 
            return;
    
        if (root->right)
            collectBoundaryRight(root->right, res);
    
        else if (root->left) 
            collectBoundaryRight(root->left, res);
        
        res.push_back(root->data);  
    }
    
    vector<int> boundaryTraversal(Node *root) {
         vector<int> res;

        if (!root)
            return res;
    
        // Add root data if it's not a leaf
        if (!isLeaf(root))
            res.push_back(root->data);
    
        // Collect left boundary
        collectBoundaryLeft(root->left, res);
    
        // Collect leaf nodes
        collectLeaves(root, res);
    
        // Collect right boundary
        collectBoundaryRight(root->right, res);
    }
};

