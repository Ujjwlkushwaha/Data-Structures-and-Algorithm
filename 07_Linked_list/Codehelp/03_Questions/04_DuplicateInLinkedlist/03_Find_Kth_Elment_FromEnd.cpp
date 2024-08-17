#include<iostream>
using namespace std;

// basic structure of nodes
class Node{
    public:
        int data;
        Node* next;

        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

void appendNode(Node* &head , Node* &tail , int data){
    // create a new Node
    Node* newNode = new Node( data );

    // if list is empty
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    tail = newNode;
}

void print(Node* head) {
        Node* temp = head;

        while(temp != NULL) {
                cout << temp -> data << " ";
                temp = temp -> next;
        }
        cout << endl;
}

void Element(Node* &head , int &ans , int &k)
{
    if(head == NULL ) return;

    Element(head->next , ans , k);

    if(k == 0){
        ans = head->data;
    }
    k--;
}


int kthElementFromEnd(Node* head , int k)
{
    int ans = -1;
    Element(head , ans , k);
    return ans;
}


int main(){

    Node* head = NULL;
    Node* tail = NULL;
    int arr[] = {1,2,3,4,5,6,5,4,3,2,1};
    
    int s = sizeof(arr)/sizeof(arr[0]);

    for(int i=0 ; i<s ; i++){
        appendNode(head , tail , arr[i]);
    }

    cout<< "Initial linkedlist" << endl;
    print(head);

    int k;
    cout << "Enter your kth term that you want to search :: ";
    cin >> k;

    cout  << "kth element from end :: " << kthElementFromEnd(head , k);
    

}