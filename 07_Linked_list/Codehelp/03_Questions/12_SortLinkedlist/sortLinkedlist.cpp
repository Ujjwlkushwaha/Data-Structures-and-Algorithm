#include <iostream>
using namespace std;

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

void insertNode(Node *&head, int data)
{
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

void print(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *getMidNode(Node *head)
{

    if (head == NULL)
    {
        return NULL;
    }

    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL and fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

// Merge two sorted linkedlist
Node *mergeList(Node *head1, Node *head2)
{
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;

    Node *ans = new Node(-1);
    Node *ptr = ans;

    while (head1 != NULL and head2 != NULL)
    {

        if (head1->data <= head2->data)
        {
            ptr->next = head1;
            ptr = head1;
            head1 = head1->next;
        }
        else
        {
            ptr->next = head2;
            ptr = head2;
            head2 = head2->next;
        }
    }

    if (head1 != NULL)
    {
        ptr->next = head1;
    }

    if (head2 != NULL)
    {
        ptr->next = head2;
    }
    return ans->next;
}

Node *sortLinkedlist(Node *head)
{
    if (head == NULL or head->next == NULL)
        return head;

    // find mid and break linkedlist in two parts using mid;
    Node *mid = getMidNode(head);
    Node *left = head;
    Node *right = mid->next;
    mid->next = NULL;

    // recursive call
    left = sortLinkedlist(left);
    right = sortLinkedlist(right);

    // now merge the linkedlist;

    Node *SortedlistHead = mergeList(left, right);

    return SortedlistHead;
}

int main()
{

    Node *head1 = NULL;

    int arr1[] = {3, 10, 11, 1, 2};
    // int arr1[] = {4,2,1,3};
    int s1 = sizeof(arr1) / sizeof(arr1[0]);

    for (int i = 0; i < s1; i++)
    {
        insertNode(head1, arr1[i]);
    }

    cout << "List before sorting:: " << endl;
    print(head1);

    head1 = sortLinkedlist(head1);
    cout << "List after sorting ::  " << endl;
    print(head1);
}