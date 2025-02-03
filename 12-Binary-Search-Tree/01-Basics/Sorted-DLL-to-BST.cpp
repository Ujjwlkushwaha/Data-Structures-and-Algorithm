#include <iostream>
using namespace std;

// creating a node of doubly linkedlist
class Node
{
public:
    Node *pre;
    int data;
    Node *next;

    // initialization
    Node(int data)
    {
        this->pre = NULL;
        this->data = data;
        this->next = NULL;
    }
};

void createList(Node* &head , Node* &tail , int data)
{
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    newNode->pre = tail;

    tail = newNode;
}

void print_List(Node* head)
{
    cout << "Printing the list:) " << endl;
    Node *temp = head;
    while (temp != NULL)
    {
        cout << "[ " << temp->data << " ]<->";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

Node *findMid(Node* head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }

        if (fast == slow)
        {
            break;
        }
    }

    return slow;
}

Node *createBST(Node* head)
{
    if (!head)
        return NULL;

    Node *mid = findMid(head);
    cout << mid->data << endl;

    if( mid->next != NULL ) createBST( mid->next);
    // if( mid->pre != NULL ) createBST( mid->pre);

    return mid;
}


int main()
{

    Node* head = NULL;
    Node* tail = NULL;

    int arr[] = {4, 5, 6, 7, 8, 9, 10};

    for (int i = 0; i < 7; i++)
    {
        createList(head , tail, arr[i]);
    }

    print_List(head);

    cout << "Middle node of the linkedlist :: " << endl;
    Node *mid = findMid(head);
    cout << mid->data << endl;

    createBST(head);
}