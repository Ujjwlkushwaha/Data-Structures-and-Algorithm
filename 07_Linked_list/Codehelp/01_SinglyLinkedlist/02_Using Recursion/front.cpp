#include <iostream>
#include <vector>
using namespace std;

// creating node  [data , next]
class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class linkedlist
{
    Node *head;

public:
    linkedlist() : head(NULL) {}

    // create a list using recursion
    Node *createList(vector<int> arr, int i , Node* pre)
    {
        if (i == arr.size())
            return pre;

        Node *newNode = new Node(arr[i]);
        newNode->next = pre;
        return createList(arr, i + 1 , newNode);
    }

    void createList(vector<int> arr)
    {
        head = createList(arr, 0 , NULL);
    }

    // printing the linkedlist
    void printList()
    {
        if (head == NULL)
        {
            cout << "List is empty ! " << endl;
            return;
        }

        cout << "Printing the list :: " << endl;
        Node *temp = head;
        while (temp != NULL)
        {
            cout << "[ " << temp->data << " ]->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    linkedlist list;

    vector<int> arr = {3, 4, 5, 6, 7, 8, 9, 10};
    list.createList(arr);
    // these node are insert one by one at the end
    list.printList();
}