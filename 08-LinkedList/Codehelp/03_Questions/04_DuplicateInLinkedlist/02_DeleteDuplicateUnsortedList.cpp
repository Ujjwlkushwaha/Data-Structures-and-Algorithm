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
    if (head == NULL) return;

    unordered_set<int> seen;
    Node* current = head;
    Node* prev = NULL;

    while (current != NULL) {
        // If current data is already seen, remove the node
        if (seen.find(current->data) != seen.end()) {
            prev->next = current->next;
            delete current;
        } else {
            seen.insert(current->data);
            prev = current;
        }
        current = prev->next;
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
    append(head,tail, 2);
    append(head,tail, 11);
    append(head,tail, 8);
    append(head,tail, 12);
    append(head,tail, 11);
    append(head,tail, 2);

    cout << "Original list: ";
    printList(head);

    removeDuplicatesHashing(head);

    cout << "List after removing duplicates: ";
    printList(head);
}
