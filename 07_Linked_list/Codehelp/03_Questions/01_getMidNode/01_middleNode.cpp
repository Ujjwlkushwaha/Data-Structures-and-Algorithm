#include <iostream>
using namespace std;

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

class Linkedlist
{
private:
    Node *head;
    Node *tail;
    int len;

public:
    Linkedlist()
    {
        this->head = NULL;
        this->tail = NULL;
        this->len = 0;
    }

    void createAlist(int data)
    {
        Node *newNode = new Node(data);
        len++;
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }

        tail->next = newNode;
        tail = newNode;
    }

    // find middle of linkedlist (approach 1)
    int middleElement(){
        int mid = (len%2 == 0) ? len/2 : (len/2)+1;

        if(len == 0)return -1;
        if(len == 1)return head->data;


        int i = 1;
        Node* temp = head;
        while(temp->next != NULL and i< mid){
            temp = temp->next;
            i++;
        }
        return temp->data;
    }


    // approach 2
    int middleElement2()
    {
        // time conplexity -> O(n/2)
        if(head == NULL){
            return -1;
        }

        Node* slow = head;
        Node* fast = head->next;

        while(slow != NULL and fast != NULL){
            fast = fast->next;
            if(fast != NULL){
                fast = fast->next;
                slow = slow->next;
            }
        }

        return slow->data;
    }




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

        cout << "length is :: "<< len << endl;
    }
};
int main()
{
    Linkedlist l;
    int arr[] = {4, 5 , 34, 43 , 54 , 6, 9 , 7, 8, 3};
    int s = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < s; i++)
    {
        l.createAlist(arr[i]);
    }
    cout << "insertion is done" << endl;

    l.printList();
    cout << "Printing is done" << endl;

    cout <<"Middle element:: " << l.middleElement() << endl;

    cout <<"Middle element:: " << l.middleElement2() << endl;


}