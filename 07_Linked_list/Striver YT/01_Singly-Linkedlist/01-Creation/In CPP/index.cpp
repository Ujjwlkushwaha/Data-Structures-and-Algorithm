#include<iostream>
#include<vector>
using namespace std;

// creating a node structure
class Node{
    public:
         int data;
         Node* next ;

        // constructor to initialize object
         Node(int data){
             this->data = data;
             this->next = nullptr;
         }
};

int main()
{
    vector<int> arr  = {12,45,86,23,85};

    // creating a node obj dynamically
    Node* newNode = new Node(arr[0]);

    // accessing the data and pointer through pointer
    cout << newNode->data << "->" <<newNode->next << endl;
    
}