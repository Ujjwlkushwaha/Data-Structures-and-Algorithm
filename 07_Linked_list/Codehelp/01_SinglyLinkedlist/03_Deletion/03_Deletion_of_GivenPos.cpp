#include<iostream>
#include<vector>
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

void push_back(Node* &head , int data){
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

void printData(Node* &head){
    if(head == NULL){
        cout << "List is empty :( " << endl;
        return;
    }

    Node* temp = head;
    while(temp != NULL){
        cout<< temp->data << "-> ";
        temp = temp->next;
    }

    cout << "null" << endl;
}


void deleteFromPos(Node* &head , int pos){
    
    // firstly check list is empty or not
    if(head == NULL)
    {
        cout<<"No ferther element for deletion !" << endl;
        return;
    }

    if(pos == 1)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "The " << pos << " node is deleted Successfully !" << endl;
        return;
    }

    Node * curr = head;
    Node* pre = NULL;
    int c = 1;
    while( curr->next != NULL && c != pos)
    {
        pre = curr ;
        curr = curr->next;
        c++;
    }

    pre->next = curr->next;
    delete curr;
    cout << "The " << pos << " node is deleted Successfully !" << endl;
}



int main(){

    Node* head = NULL;
    vector<int> arr = {3,4,5,6,7};

    for(int a = 0 ; a<arr.size() ; a++){
        push_back(head , arr[a]);
    }

    printData(head);

    deleteFromPos(head , 5);
    printData(head);

}