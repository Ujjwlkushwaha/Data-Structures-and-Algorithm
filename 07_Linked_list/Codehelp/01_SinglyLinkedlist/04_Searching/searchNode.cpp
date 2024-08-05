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

class linkedlist{
    Node* head;

    public:
        linkedlist():head(NULL){}
};
int main(){

}