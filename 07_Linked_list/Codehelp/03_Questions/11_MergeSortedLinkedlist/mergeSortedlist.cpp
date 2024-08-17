#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int data){
            this->next = NULL;
            this->data = data;
        }
};

void insertNode(Node* &head , int data){
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


void print(Node* head) {
        Node* temp = head;

        while(temp != NULL) {
                cout << temp -> data << " ";
                temp = temp -> next;
        }
        cout << endl;
}

// Merge two sorted linkedlist
Node* mergeList(Node* head1 , Node* head2)
{
    if(head1 == NULL) return head2;
    if(head2 == NULL) return head1;

    Node* ans = new Node(-1);
    Node* ptr = ans;

    while(head1 != NULL and head2 != NULL){

        if(head1->data <= head2->data)
        {
            ptr->next = head1;
            ptr = head1;
            head1 = head1->next;
        }
        else{
            ptr->next = head2;
            ptr = head2;
            head2 = head2->next;
        }
    }

    if(head1 != NULL){
        ptr->next = head1;
    }

    if(head2 != NULL){
        ptr->next = head2;
    }
    return ans->next;
}


int main(){

    Node* head1 = NULL;
    Node* head2 = NULL;

    int arr1[] = {3,6,7,9,10,11};
    int arr2[] = {1,2,3,4,5,8};

    int s1 = sizeof(arr1)/sizeof(arr1[0]);
    int s2 = sizeof(arr2)/sizeof(arr2[0]);

    for(int i=0 ; i<s1 ; i++){
        insertNode(head1 , arr1[i]);
    }

    for(int i=0 ; i<s2 ; i++){
        insertNode(head2 , arr2[i]);
    }

    print(head1);
    print(head2);

    cout << "After merging both linkedlist :: " << endl;
    head1 = mergeList(head1 , head2);
    print(head1);
    

}