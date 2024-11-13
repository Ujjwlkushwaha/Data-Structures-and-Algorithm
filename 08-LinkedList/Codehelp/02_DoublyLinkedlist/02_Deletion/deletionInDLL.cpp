#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *pre;
    node *next;

    node(int data)
    {
        this->data = data;
        this->pre = NULL;
        this->next = NULL;
    }
};

class DoublyLinkedList
{
    private : 
        node* head;
        node* tail;

    public:
        DoublyLinkedList(){
            this->head = NULL;
            this->tail = NULL;
        }

        int len(){
            int c = 0;
            node*temp = head;
            while(temp!=NULL){
                c++;
                temp = temp->next;
            }

            return c;
        }

        void insertAtEnd(int data){
            node * newNode = new node(data);

            if(head == NULL){
                head = newNode;
                tail = newNode;
                return;
            }

            node* temp = head;

            tail->next = newNode;
            newNode->pre = tail;
            tail = newNode;
        }

        void deleteFront(){


            if(head == NULL)return;

            if(head->next == NULL){
                delete head;
                return;
            }

            node* temp = head;

            head = head->next;
            head->pre = NULL;
            delete temp;
        }

        void deleteBack(){
            if(head == NULL)return;

            if(head->next == NULL){
                delete head;
                return;
            }

            node* temp = tail;
            tail = tail->pre;

            tail->next = NULL;
            delete temp;
        }

        void deletePos(int pos){
             if(head == NULL)return;

             if(pos > len()){
                cout<< "itne to element hi nhi hai !" << endl;
                return;
             }

             if(pos == 1){
                node* temp = head;
                head->pre = NULL;
                delete temp;
                return;
             }

             node* temp = head;
             int c = 0 ;
             while(temp != NULL and c<pos-1){
                temp = temp->next;
                c++;
             }

            //  cout << temp->data;
             temp->pre->next = temp->next;
             temp->next->pre = temp->pre;
             delete temp;
            
        }

        void printList(){
            node* temp = head;

            while(temp != NULL){
                cout << temp->data << "-> ";
                temp = temp->next;
            }

            cout << "NULL" << endl;
        }
};

int main()
{
    DoublyLinkedList l1;

    int arr[] = {1,2,3,4,5,6,7,8,9};
    int s = sizeof(arr)/sizeof(arr[0]);

    for(int i = 0 ; i<s ; i++){
        l1.insertAtEnd(arr[i]);
    }

    l1.printList();

    l1.deleteFront();
    l1.printList();

    l1.deleteBack();
    l1.printList();

    l1.deletePos(5);
    l1.printList();

    l1.deletePos(5);
    l1.printList();

    l1.deletePos(5);
    l1.printList();
}