#include<iostream>
using namespace std;

// creating a node of doubly linkedlist
class Node
{
    public:
        Node* pre;
        int data;
        Node* next;

        // initialization
        Node(int data){
            this->pre = NULL;
            this->data = data;
            this->next = NULL;
        }
};

class linkedlist
{
    private:
        Node* head;
        Node* tail;

    public:
        linkedlist(){
            head = NULL;
            tail = NULL;
        }

    void createList(int data)
    {
        Node* newNode = new Node(data);
        if(head == NULL){
            head = newNode;
            tail = newNode;
            return;
        }

        tail->next = newNode;
        newNode->pre = tail;

        tail = newNode;
    }

    void print_List()
    {
        cout << "Printing the list:) " << endl;
        Node *temp = head;
        while (temp != NULL)
        {
            cout << "[ " << temp->data << " ]<->";
            temp = temp->next;
        }

        cout<<"NULL"<<endl;
    }
};

int main()
{

    linkedlist list;

    int arr[] = {4,5,6,7,8,9,10};
    
    for(int i=0 ; i<7 ; i++){
        list.createList(arr[i]);
    }
    
    list.print_List();

}