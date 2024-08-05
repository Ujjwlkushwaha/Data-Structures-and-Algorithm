#include<iostream>
using namespace std;

// creating a node class
class Node{
    public:
        int data;
        Node* next;

        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

// creating Linkedlist
class LinkedList{
    Node* head = NULL;
    Node* tail = NULL;
    public:

        // Inserting element at the end of the linkedList
        void push_back(int data)
        {
            Node* newNode = new Node(data);

            if(head == NULL){
                head = newNode;
                tail = newNode;
                return;
            }
            Node* temp = head;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            tail = newNode;
        }

        void append(int data)
        {
            Node* newNode = new Node(data);
            if(head == NULL){
                head = newNode;
                tail = newNode;
                return;
            }
            tail->next = newNode;
            tail = newNode;
        }

        // Inserting element at beginning of linkedList
        void push_front(int data)
        {
            Node* newNode = new Node(data);
            newNode->next = head ;
            head = newNode;
        }

        // return the size of list
        int size(){
            int count = 0 ;
            Node* temp = head;

            while(temp != NULL){
                count++;
                temp = temp->next;
            }
            return count;
        }

        void print_list(){
            Node* temp = head;
            while(temp != NULL)
            {
                cout << "[ "<< temp->data<<" ]--> ";
                temp = temp->next; 
            }
            cout << endl;
        }

        void reverseList(){

            if(head == NULL){
                cout <<"warning!, List have np element for this tast !! :("<<endl;
                return;
            }

            Node* curr = head ;
            Node* pre = NULL;
            Node* next = NULL;

            while(curr != NULL )
            {
                next = curr->next; 
                curr->next = pre;

                pre = curr ;
                curr = next;
            }

            head = pre;
        }
};

int main()
{
    LinkedList lst;

    int num;
    cout << "Enter the number of element ::";
    cin >> num ;

    cout << "Put the number one by one -> "<< endl;
    for (int i = 0; i < num; i++)
    {
        int n;
        cin>>n;
        lst.push_back(n);
    }

    cout << "Your LinkedList :: " << endl;
    lst.print_list();
    
    lst.reverseList();
    lst.print_list();
}