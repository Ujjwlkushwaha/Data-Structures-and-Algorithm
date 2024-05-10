#include<bits/stdc++.h>
using namespace std;

// linked list -> A singly linked list is a linear data structure in which the elements are 
//                not stored in contiguous memory locations and each element is connected only to its next element using a pointer.

// basic structure of node
class Node{
  public:
    int data ;
    Node* next;

	// initialize the constructor which default value;
    Node(int d ){
      this->data = d;
      this->next = NULL; 
    }
};

int main(){

// basic creation of nodes of linked list
  Node* x = new Node(5);
  
  Node* y = new Node(6);
  
// last node of the list always containing null ptr.
  Node* z = new Node(7);

// create connect b/w nodes
  Node* head = x;
  x->next = y;
  y->next = z;

// traverse the linked list
  Node* temp = head;
  while(temp != nullptr)
    {
    	// printing the every node of the list 
      cout<< temp->data <<" ";

      // used to jump one node to next node
      temp = temp->next;
    }
}
