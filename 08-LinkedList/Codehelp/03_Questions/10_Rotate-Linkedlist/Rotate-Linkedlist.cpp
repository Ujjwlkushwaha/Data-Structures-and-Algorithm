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

// rotate linkedlist to left k times
Node* rotate (Node* head, int k)
{
    // Your code here
     if (!head || k == 0) return head; // Handle edge cases: empty list or no rotations

    // Step 1: Find the length of the linked list
    int length = 1;
    Node* tail = head;
    while (tail->next) {
        tail = tail->next;
        length++;
    }

    // Step 2: Optimize k
    k = k % length; // If k >= length, we only need to perform k % length rotations
    if (k == 0) return head; // No rotations needed if k is a multiple of length

    // Step 3: Traverse to the (k-th) node to find the new tail
    Node* newTail = head;
    for (int i = 1; i < k; i++) {
        newTail = newTail->next;
    }

    // Step 4: Update pointers to form the new head and tail
    Node* newHead = newTail->next; // New head is the next node after the new tail
    newTail->next = nullptr;       // Disconnect the new tail from the rest of the list
    tail->next = head;             // Connect the old tail to the old head

    return newHead;
}

int main()
{
    Node* head = NULL;
    vector<int> nodes = {10,20,30,40};
    for( int i=0 ; i<nodes.size() ; i++ )
    {
        insertIntoList(head , nodes[i]);
    }
   
    // print list
    printList(head);
    
    // reverse Node
    // reverseLinkedlist(head);
    
    // rotate linkedlist
    head = rotate(head , 6);
    
    // printList(head);
    
}