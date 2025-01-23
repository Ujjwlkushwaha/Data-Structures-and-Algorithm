/*
    ✅✅ Clone List with Next and Random 📌 ( Difficulty: Hard )


        You are given a special linked list with n nodes where each node has two pointers-
            a next pointer that points to the next node of the singly linked list,
            a random pointer that points to the random node of the linked list.

        Construct a copy of this linked list.
             The copy should consist of the same number of new nodes, where each new node has the value corresponding to its original node.

             Both the next and random pointer of the new nodes should point to new nodes in the copied list, such that it also represent the same list state. None of the pointers in the new list should point to nodes in the original list.

        Return the head of the copied linked list.

        NOTE : Original linked list should remain unchanged.
*/

#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    int data;
    Node *next;
    Node *random;

    Node(int x)
    {
        data = x;
        next = NULL;
        random = NULL;
    }
};

// ✅ Method 1:  tc ->  O(n) sc-> O(n)   using map
Node *helper(Node *head, unordered_map<Node *, Node *> mp)
{
    if (!head)
        return NULL;

    Node *newNode = new Node(head->data);
    mp[head] = newNode;

    newNode->next = helper(head->next, mp);

    if (head->random)
    {
        newNode->random = mp[head->random];
    }
    return newNode;
}

Node *cloneLinkedList1(Node *head)
{
    // Write your code here
    unordered_map<Node *, Node *> mp;
    return helper(head, mp);
}




// ✅ method 2: tc-> O(n)  sc-> O(1)
Node *cloneLinkedList2(Node *head)
{
    // Write your code here
    if (head == NULL)
        return head;

    Node *temp = head;
    while (temp)
    {
        Node *newNode = new Node(temp->data);
        newNode->next = temp->next;
        temp->next = newNode;
        temp = newNode->next;
    }

    temp = head;
    Node *head2 = temp->next;
    while (temp != NULL)
    {
        if (temp->random == NULL)
        {
            temp->next->random = NULL;
        }
        else
        {
            temp->next->random = temp->random->next;
        }

        temp = temp->next->next;
    }

    temp = head;
    while (temp != NULL)
    {
        Node *temp2 = temp->next;
        temp->next = temp2->next;

        if (temp2->next)
            temp2->next = temp2->next->next;
        temp = temp->next;
    }

    return head2;
}
