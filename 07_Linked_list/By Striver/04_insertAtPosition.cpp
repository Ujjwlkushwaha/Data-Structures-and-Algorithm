#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node * next;

        // initialization List
        Node(int data) : data(data) , next(NULL) {}
};

class LinkedList{
    Node* head;

    public:
        LinkedList() : head(NULL){}

    // insert at the end of the linked list
        void append(int data)
        {
            Node* newNode = new Node(data);

            if(head == NULL){
                head = newNode;
                return;
            }

            Node* temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }

            temp->next = newNode;
        }

    // insert at the beginning of the linked list
         void insertAtbegining(int data)
         {
            Node* newNode = new Node(data);
            newNode->next = head;
            head = newNode;
       }

    //insert at given position in the linked list
        void insertAtPos(int data , int pos)
        {
            Node* newNode = new Node(data);

            if(pos ==  1){
                insertAtbegining(data);
                return;
            }

            if(pos == size()+1){
                append(data);
                return;
            }

            if(pos <= 0 || pos > size()+1){
                 cout << "invalid position !" << endl;
                 return;
            }

            Node *temp = head;
            int c = 1;
            while(temp->next != NULL && c != pos-1){
                c++;
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }

    // return size of the list
        int size(){
            Node* temp = head;
            int count = 0;
            while(temp != NULL){
                count++;
                temp =temp->next;
            }

            return count;
        }

    // printing the list
        void print_list(){
            Node* temp = head;
            while(temp!=NULL)
            {
                cout<<temp->data << "-> ";
                temp = temp->next;
            }

            cout << "NULL" << endl;
        }
};

int main()
{
    LinkedList ls; 
    ls.append(10);
    ls.append(20);
    ls.append(30);
    ls.append(40);
    ls.append(50);

    ls.print_list();

    // insert at position
    ls.insertAtPos(5 , 1);
    ls.print_list();

    ls.insertAtPos(1000 , 7);
    ls.print_list();
}