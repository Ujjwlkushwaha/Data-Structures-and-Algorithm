// #include <iostream>
// #include <stack>
// using namespace std;

// struct ListNode {
//     int val;
//     ListNode* next;
//     ListNode(int x) : val(x), next(nullptr) {}
// };

// // Function to add two numbers represented by linked lists
// ListNode* addTwoNumbers(ListNode* num1, ListNode* num2) {
//     stack<int> s1, s2;

//     // Push all elements of num1 and num2 into stacks
//     while (num1) {
//         s1.push(num1->val);
//         num1 = num1->next;
//     }
//     while (num2) {
//         s2.push(num2->val);
//         num2 = num2->next;
//     }

//     ListNode* result = nullptr;
//     int carry = 0;

//     // Process the stacks
//     while (!s1.empty() || !s2.empty() || carry) {
//         int sum = carry;
//         if (!s1.empty()) {
//             sum += s1.top();
//             s1.pop();
//         }
//         if (!s2.empty()) {
//             sum += s2.top();
//             s2.pop();
//         }
//         carry = sum / 10;

//         // Create a new node for the current digit
//         ListNode* newNode = new ListNode(sum % 10);
//         newNode->next = result;
//         result = newNode;
//     }

//     return result;
// }

// // Function to print a linked list
// void printList(ListNode* head) {
//     while (head) {
//         cout << head->val;
//         if (head->next) cout << " -> ";
//         head = head->next;
//     }
//     cout << endl;
// }

// int main() {
//     // Example 1: num1 = 4 -> 5, num2 = 3 -> 4 -> 5
//     ListNode* num1 = new ListNode(4);
//     num1->next = new ListNode(5);

//     ListNode* num2 = new ListNode(3);
//     num2->next = new ListNode(4);
//     num2->next->next = new ListNode(5);

//     ListNode* result = addTwoNumbers(num1, num2);
//     printList(result);  // Output: 3 -> 9 -> 0

//     return 0;
// }






#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    if (arr.empty()) {
        return NULL;
    }
    int val = arr[0];
    int size = arr.size();

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 1; i < size; i++) {
        val = arr[i];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


class Solution {
  public:
  
  Node* createNode(int val) {
     Node* newNode = 
              (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}
        
        Node* reverse(Node* head) {
            Node* prev = NULL;
            Node* curr = head;
             Node* next = NULL;
        
            // Loop to reverse the linked list
            while (curr != NULL) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            return prev;
        }
        
        // function to trim leading zeros in linked list
        Node* trimLeadingZeros(Node* head) {
            while (head->next != NULL && head->data == 0)
                head = head->next;
            return head;
        }
      Node* addListRec(Node* num1, 
                            Node* num2, int* carry) {
        
          // Base case: If both lists are empty and no carry is left
        if (num1 == NULL && num2 == NULL && *carry == 0) {
            return NULL;
        }
    
        int sum = *carry;
    
        // Add the value from the first list if it exists
        if (num1 != NULL) {
            sum += num1->data;
            num1 = num1->next;
        }
    
        // Add the value from the second list if it exists
        if (num2 != NULL) {
            sum += num2->data;
            num2 = num2->next;
        }
    
        *carry = sum / 10;
        Node* result = createNode(sum % 10);
    
        // Recursively add remaining digits
        result->next = addListRec(num1, num2, carry);
    
        return result;
    }
    Node* addTwoLists(Node* num1, Node* num2) {
        // code here
        num1 = trimLeadingZeros(num1);
        num2 = trimLeadingZeros(num2);
      
          // Reverse both lists to start addition from the 
          // least significant digit
        num1 = reverse(num1);
        num2 = reverse(num2);
    
        int carry = 0;
        Node* result = addListRec(num1, num2, &carry);
    
        // If there's any carry left after the addition,
          // create a new node for it
        if (carry != 0) {
            Node* newNode = createNode(carry);
            newNode->next = result;
            result = newNode;
        }
    
        // Reverse the result list to restore the original order
        return reverse(result);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input

    while (t--) {
        Node* num1 = buildList();
        Node* num2 = buildList();
        Solution ob;
        Node* res = ob.addTwoLists(num1, num2);
        printList(res);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
