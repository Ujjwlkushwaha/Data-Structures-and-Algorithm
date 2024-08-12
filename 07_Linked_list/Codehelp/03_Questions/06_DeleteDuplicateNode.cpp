#include<bits/stdc++.h>
using namespace std;

class Node {

public:
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

// Function to remove duplicates from the linked list using hashing
void removeDuplicatesHashing(Node* head) 
{
    //  1 . if list is empty
    if (head == NULL) return;

    // 2.  create a set container which contain value only on time, it does not contain duplicate values
    unordered_set<int> seen;

    // create var for traversing
    Node* current = head;
    Node* prev = NULL;


    // traverse until current gets NULL
    while (current != NULL) 
    {
        //3.  If current data is already seen, remove the node
        if (seen.find(current->data) != seen.end()) {
            prev->next = current->next;
            delete current;
        } 
        else 
        {
            // put the node into set container
            seen.insert(current->data);
            // move prev forword
            prev = current;
        }

        //4.  move current
        current = prev->next;
    }
}

// normal function for removing duplicates from sorted list
void removeDuplicate(Node* &head)
 {
    // list is empty or not
    if(head == NULL)return;
    if(head->next == NULL)return;

    // take a pointer that help in travercing list
    Node* curr = head;
    while(curr != NULL)
    {
        // check condition
        if( (curr->next != NULL) and (curr->data == curr->next->data))
        {
            Node* temp = curr->next;
            curr->next = curr->next->next;
            temp->next = NULL;
            delete temp;
        }
        else
        {
            curr = curr->next;
        }
    }
}


// Function to print the linked list
void printList(Node* head) {

    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout <<endl;
}

// Utility function to insert a new node at the end of the list
void append(Node* &head, Node* &tail , int new_data) {

    Node* new_node = new Node(new_data);

    if (head == NULL) {
        head = new_node;
        tail = new_node;
        return;
    }

    tail->next = new_node;
    tail = new_node;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    append(head,tail, 8);
    append(head,tail, 9);
    append(head,tail, 11);
    append(head,tail, 11);
    append(head,tail, 12);
    append(head,tail, 13);
    append(head,tail, 13);

    cout << "Original list: ";
    printList(head);

    // removeDuplicatesHashing(head);
    removeDuplicate(head);

    cout << "List after removing duplicates: ";
    printList(head);
}
