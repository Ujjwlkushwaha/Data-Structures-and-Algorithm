#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int d)  {
            this->data = d;
            this->next = NULL;
        }
};

class Linkedlist
{
    private:
        Node* head;
        Node* tail;

    public:
        Linkedlist(){
            head = NULL;
            tail = NULL;
        }

        int len()
        {
            if(head != NULL){
                int count = 0 ;
                Node* temp  = head;
                while(temp != NULL){
                    count++;
                    temp = temp->next;
                }

                return count;
            }

            return 0;
        }

        void createList(int d)
        {
            Node* newNode = new Node(d);

            if(head == NULL){
                head = newNode;
                tail = newNode;
                return;
            }

            tail->next = newNode;
            tail = tail->next;
        }

        void printList(){
            
            if(head == NULL) return;

            Node* temp = head;
            while(temp != NULL){
                cout << temp->data << "-> ";

                temp = temp->next;
            }

            cout << "NULL" << endl;
        }

        void delete_Begin()
        {
            if(head == NULL){
                cout << "List is empty buddy :(" << endl;
                return;
            }else{
                Node* temp = head;
                head = head->next ;
                delete temp;
            }
        }


}; 


int main()
{
    Linkedlist l1;
    int arr[] = {3,4,5,6,7};

    for(int i = 0 ; i<5 ; i++){
        l1.createList(arr[i]);
    }
    l1.printList();
    cout << l1.len() << endl;


    l1.delete_Begin();
    l1.printList();
    cout <<  l1.len() << endl;;


    l1.delete_Begin();
    l1.printList();
    cout << l1.len() << endl;
}
