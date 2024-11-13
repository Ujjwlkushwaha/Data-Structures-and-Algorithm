// check given linkedlist is circuler of not

#include <iostream>
using namespace std;

// structure of node {data , *next}
class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->next = NULL;
        this->data = data;
    }
};

// inserting a node in circuler linkedlist
void insertNode(Node *&head, int data)
{
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node *temp = head;

    while (temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
}

bool isCirculer(Node *head)
{
    if (head == NULL)
    {
        return false;
    }

    Node *temp = head;

    while (temp != NULL)
    {
        temp = temp->next;
        if (temp == head)
        {
            return true;
        }
    }

    return false;
}

Node *reverse(Node *head)
{
    Node *curr = head->next, *prev = head, *nxt = NULL;

    while (curr != head)
    {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }

    head->next = prev;
    return prev;
}

// Function to delete a node from the circular linked list
Node *deleteNode(Node *head, int key)
{
    // code here
    Node *temp = head->next, *prev = head;

    if (head->data == key)
    {
        while (temp != head)
        {
            prev = temp;
            temp = temp->next;
        }
    }
    else
    {
        while (temp != head and temp->data != key)
        {
            prev = temp;
            temp = temp->next;
        }
    }

    if (head->data == key or temp != head)
    {
        prev->next = temp->next;
    }

    return head->data == key ? prev->next : head;
}

int main()
{
    Node *head = NULL;
    int arr[] = {3, 4, 5, 6, 7, 8, 9, 10};

    int s = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < s; i++)
    {
        insertNode(head, arr[i]);
    }

    if (isCirculer(head))
    {
        cout << "List is circuler !" << endl;
    }
    else
    {
        cout << "List is not circuler" << endl;
    }
}