#include<bits/stdc++.h>
using namespace std;


// Node 
class Node{
    public:
        int val;
        Node* next;
        
        Node(int data)
        {
            this->val = data;
            this->next = NULL;
        }
};

// insert into list
void insertIntoList(Node* &head , int data)
{
    Node* newNode = new Node( data );
    if( head == NULL )
    {
        head = newNode;
        return;
    }
    
    Node* temp = head;
    while( temp->next != NULL )
    {
        temp = temp->next;
    }
    
    temp->next = newNode;
}

// Print list 
void printList(Node* head)
{
    if( head == NULL )
    {
        cout<<"List is empty ! " << endl;
        return;
    }
    
    Node* temp = head;
    while( temp != NULL )
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    
    cout << endl;
}

// reverse linkedlist
void reverseLinkedlist( Node* &head )
{
    cout << "reverse cond 1 executed ! " << endl;
    if( !head ) 
    {
        cout << "List is empty ! " << endl;
        return;
    }
    
    Node* pre = NULL;
    Node* curr = head ;
    Node* nextNode =NULL;
    
    cout << "reverse loop started ! " << endl;
    while( curr != NULL )
    {
        nextNode = curr->next;
        curr->next = pre;
        pre = curr;
        curr = nextNode;
    }
    
    head = pre;
    cout << "loop is finished !" << endl;
}
int main()
{
    Node* head = NULL;
    vector<int> nodes = {2,7,10,9,8};
    for( int i=0 ; i<nodes.size() ; i++ )
    {
        insertIntoList(head , nodes[i]);
    }
   
    // print list
    printList(head);
    
    // reverse Node
    reverseLinkedlist(head);
    
    printList(head);
    
}