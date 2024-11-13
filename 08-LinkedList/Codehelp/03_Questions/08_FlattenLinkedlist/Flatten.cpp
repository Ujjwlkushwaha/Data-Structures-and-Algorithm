#include<iostream>
using namespace std;


class Node{
    public:
        int data;
        Node* next;
        Node* bottom;

        Node(int val){
            data = val;
            next = NULL;
            bottom = NULL;
        }
};

// start----------------------------------------------------------------
Node* mergeList(Node* a, Node* b)
{
    if(a == NULL) return b;
    if(b == NULL) return a;

    Node*  ansList = NULL;

    if(a->data < b->data){
        ansList = a;
        ansList->bottom = mergeList(a->bottom, b);
    }
    else{
        ansList = b;
        ansList->bottom = mergeList(a, b->bottom);
    }

    return ansList;

}

Node* flattenList(Node* root)
{
    if(root==NULL)return NULL;

    return mergeList(root, flattenList(root->next));
}

// Done----------------------------------------------------------------
int main()
{
    

}