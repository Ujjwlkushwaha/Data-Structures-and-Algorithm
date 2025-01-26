// In this problem we find loop in a linkedlist and try to remove that loop

#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void printData(node *head)
{
    if (head == NULL)
    {
        cout << "list is empty!" << endl;
        return;
    }

    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "-> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

bool findLoopInLL(node *head)
{
    if (head == NULL)
        return false;

    node *slow = head;
    node *fast = head;

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
            return true;
        }
    }
    return false;
}

void deleteLoop(node *&head)
{
    if (head == NULL)
        return;

    node *slow = head;
    node *fast = head;

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

    node *pre = fast;
    while (fast != slow)
    {
        pre = fast;
        fast = fast->next;
        slow = slow->next;
    }

    pre->next = NULL;
}

// gfg solution
// Function to remove a loop in the linked list.
void removeLoop(node *head)
{
    // code here
    // if( !head) return ;

    node *slow = head, *fast = head;
    while (fast and fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow)
            break;
    }

    // if there is no loop
    if (!fast or !fast->next)
        return;

    // otherwise
    slow = head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    while (slow->next != fast)
    {
        slow = slow->next;
    }

    slow->next = NULL;
}

int main()
{

    node *head = NULL;

    // create a LL in which a loop exist
    node *fst = new node(5);
    head = fst;
    node *Snd = new node(6);
    fst->next = Snd;
    node *Trd = new node(7);
    Snd->next = Trd;
    node *Frth = new node(8);
    Trd->next = Frth;
    node *FFth = new node(9);
    Frth->next = FFth;
    node *Sth = new node(10);
    FFth->next = Sth;
    Sth->next = Frth;

    if (findLoopInLL(head))
        cout << "Loop exist in this list" << endl;
    else
        cout << "loop is not exitst" << endl;

    deleteLoop(head);

    if (findLoopInLL(head))
        cout << "Loop exist in this list" << endl;
    else
        cout << "loop is not exitst" << endl;

    printData(head);
}