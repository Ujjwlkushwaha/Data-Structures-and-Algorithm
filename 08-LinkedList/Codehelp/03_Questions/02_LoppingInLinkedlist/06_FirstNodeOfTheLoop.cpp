#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        Node *next = NULL;
    }
};

// 📌  insert Node in the linkedlist
void insertIntoLL(Node *&head, int val)
{
    Node *newNode = new Node(val);
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

// 📌  function for creating loop in the linkedlist
void createLoopInLL(Node *&head, int place)
{
    // check list is empty of not
    if (!head)
    {
        cout << " List is empty" << endl;
        return;
    }

    Node *lastNode = head;
    Node *startLoopNode = head;
    int count = 1;
    while (lastNode->next != NULL or count < place)
    {
        lastNode = lastNode->next;
        if (count < place)
        {
            startLoopNode = startLoopNode->next;
            count++;
        }
    }

    if (count < place)
    {
        cout << "place is not exist" << endl;
        return;
    }

    lastNode->next = startLoopNode;
}

// 📌 printing LL
void printlist(Node *head)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    Node *temp = head;
    while (temp != NULL)
    {
        cout << "[" << temp->data << "] -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// 📌  find first node of the loop
Node *findFirstNodeOfLoop(Node *head)
{
    if (!head)
        return NULL;

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
            slow = head;
            break;
        }
    }

    if (fast == NULL)
    {
        return NULL;
    }

    while (fast != NULL and slow != NULL and fast != slow)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

int main()
{
    // Write C++ code here
    Node *head = NULL;
    vector<int> nodes = {1, 3, 2, 4, 5};
    for (int i = 0; i < nodes.size(); i++)
    {
        insertIntoLL(head, nodes[i]);
    }

    // print linkedlist
    printlist(head);

    // creating loop
    createLoopInLL(head, 2);

    // find first node of the loop;
    Node *loopStartNode = findFirstNodeOfLoop(head);
    if (loopStartNode != NULL)
    {
        cout << "Loop start from " << loopStartNode->data << endl;
    }
    else
    {
        cout << "Loop hi nhi hai LL me" << endl;
    }

    return 0;
}