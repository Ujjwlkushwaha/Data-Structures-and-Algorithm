#include <bits/stdc++.h>
using namespace std;

// Node
class Node
{
public:
    int val;
    Node *next;

    Node(int data)
    {
        this->val = data;
        this->next = NULL;
    }
};

// Group reverse linkedlist
Node *reverseKGroup(Node *head, int k)
{
    // base case
    if (!head)
        return nullptr;

    Node *pre = nullptr;
    Node *curr = head;

    Node *nextNode = nullptr;
    int count = 0;

    while (curr != nullptr and count < k)
    {
        nextNode = curr->next;
        curr->next = pre;
        pre = curr;
        curr = nextNode;
        count++;
    }

    // agar hmari linkedlist bachi hai
    if (nextNode)
    {
        head->next = reverseKGroup(nextNode, k);
    }

    return pre;
}

// insert into list
void insertIntoList(Node *&head, int data)
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

// Print list
void printList(Node *head)
{
    if (head == NULL)
    {
        cout << "List is empty ! " << endl;
        return;
    }

    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main()
{
    Node *head = NULL;
    vector<int> nodes = {1, 2, 2, 4, 5, 6, 7, 8};
    for (int i = 0; i < nodes.size(); i++)
    {
        insertIntoList(head, nodes[i]);
    }

    // print list
    printList(head);

    // reverse K group
    head = reverseKGroup(head, 4);

    printList(head);
}