#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;

        Node(int data){
            this->data = data;
            this->next = NULL;
        }

        ~Node(){
            int val = this->data ;

            // memory is free
            if(this->next != NULL){
                delete next;
                this->next = NULL;
            }
        }
};

// list create kar lo
void createList(Node* &head , int data)
{   
    Node * newNode = new Node(data);

    if(head == NULL){
        head = newNode;
        return;
    }

    Node* temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newNode ; // its done 
}

// displaying the data of the list
void displayList(Node* head)
{
    Node* temp = head;

    // tab tak bhago jab tak aakhri node na aa jaye jiske pass NULL hia 
    while(temp != NULL){
        cout << temp->data << " -> " ;
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

// Delete the node from the list
void deleteNode(Node* &head , int pos){
    if(pos < 1){
        cout << "Invalid Position! " << endl;
        return;
    }

    // deleting first node of the list
    if(pos == 1){
        head = NULL;
    }

    Node* temp = head;

    int i = 1;
    while( i < pos-1){
        temp = temp->next ;
        i++;
    }

    temp->next = temp->next->next;
}


int main(){

    Node * head = NULL;

    int arr[] = {2,5,8,4,9,3,12,14,15,10};

    // convert array in list
    for(int i = 0 ; i<10 ; i++){
        createList(head , arr[i]);
    }

    displayList(head);
    deleteNode(head , 2);    
    displayList(head);
}