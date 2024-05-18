#include <iostream>
using namespace std;

// creating a node structure
class Node
{
public:
    int data;
    Node *next;

    // initialize the node
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList
{
    Node *head;

public:
    LinkedList() : head(NULL) {}

    // insert a node at front of linkedlist
    void insert(int data)
    {
        // in case list is empty
        if(head==NULL){
            Node* newNode = new Node(data);
            head = newNode ;
            return;
        }

        // otherwise
        // 1. create a node
        Node* newNode = new Node(data);

        // 2. put the address in nextPtr that head have;
        newNode->next = head;

        // put the address of newNode to the head;
        head = newNode ;

        // now head is pointing to newnode
    }

    void print_list()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << "[ " << temp->data << " ]->";
            temp = temp->next;
        }
    }
};
int main()
{

    LinkedList lst;

    int arr[] = {3, 4, 6, 2, 4, 7};

    for (int i = 0; i < 6; i++)
    {
        lst.insert(arr[i]);
    }

    lst.print_list();
}