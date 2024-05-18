#include<iostream>
using namespace std;

// creating a node structure
class Node
{
    public:
        int data;
        Node* next;

        // initialize the node
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

class LinkedList{
    Node* head;

    public:
        LinkedList():head(NULL){}

        // insert a node at last of linkedlist
        void append(int data)
        {
            // create a node
            Node* newNode = new Node(data);

            // check if head is empty 
            if(head == NULL)
            {
                // put the address of newNode in head
                head = newNode;
                return;
            }

            // otherwise traverse until you reach on last node

            // we use this dummy temp pointer which contain the refence of head
            Node* temp = head;

            while(temp->next != NULL){
                temp =temp->next;
            }

            // we have reached on last node

            // put the address of newNode in last node->next
            temp->next = newNode;
        }

        void print_list(){
            Node* temp = head;
            while(temp != NULL){
                cout << "[ "<< temp->data <<" ]->";
                temp = temp->next; 
            }
        }
};
int main()
{

    LinkedList lst;

    int arr[] = {3,4,6,2,4,7};

    for(int i=0 ; i<6 ; i++){
        lst.append(arr[i]);
    }

    lst.print_list();   

}