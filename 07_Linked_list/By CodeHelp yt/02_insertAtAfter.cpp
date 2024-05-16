#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

class Linkedlist
{
    Node* head ;

    public:
        Linkedlist() : head(NULL){}

        void append(int data){
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

        int findPos(int key){
            Node* temp = head;
            int pos = 0;
            while(temp != NULL && temp->data != key){
                pos++;
                temp = temp->next;
            }
            
            if(pos >= size())return -1;

            pos++;
            return pos;

        }

         int size(){
            Node* temp = head;
            int count = 0;
            while(temp != NULL){
                count++;
                temp =temp->next;
            }

            return count;
        }

        void insertAfter(int data , int key){

            int pos = findPos(key) ;
            if( pos != -1 )
            {
                Node* newNode = new Node(data);

                if(pos == 1){
                    head = newNode;
                    return;
                }

                Node* temp = head;
                int c = 1;
                while(temp->next != NULL && c != pos-1){
                    
                }
            }
        }
};

int main()
{
    Linkedlist ls;
    ls.append(5);
    ls.append(10);
    ls.append(15);
    ls.append(20);
    ls.append(25);
    ls.append(30);

    cout << "Position of :: "<<ls.findPos(20);

}
