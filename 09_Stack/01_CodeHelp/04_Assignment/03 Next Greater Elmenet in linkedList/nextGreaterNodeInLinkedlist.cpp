/*
    1019. Next Greater Node In Linked List
    ☠️ Medium

⭐     Hint 1
        We can use a stack that stores nodes in monotone decreasing order of value. When we see a node_j with a larger value, every node_i in the stack has next_larger(node_i) = node_j .

You are given the head of a linked list with n nodes.

For each node in the list, find the value of the next greater node. That is, for each node, find the value of the first node that is next to it and has a strictly larger value than it.

Return an integer array answer where answer[i] is the value of the next greater node of the ith node (1-indexed). If the ith node does not have a next greater node, set answer[i] = 0.



Example 1:


Input: head = [2,1,5]
Output: [5,5,0]
Example 2:


Input: head = [2,7,4,3,5]
Output: [7,0,5,5,0]


Constraints:

The number of nodes in the list is n.
1 <= n <= 104
1 <= Node.val <= 109


 */

#include <iostream>
#include<algorithm>
#include <vector>
#include <stack>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int val) : val(val), next(NULL) {}
};

void insertData(Node *&head, int data)
{
    Node *newNode = new Node(data);

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

vector<int> nextGreaterInLL(Node *head)
{

    vector<int> list;
    int nextGreater = 0;
    while (head)
    {
        list.push_back(head->val);
        head = head->next;
    }

    // vector for storing answer
    vector<int> ans(list.size());
    stack<int> st;

    for(int i= 0 ; i< list.size() ; i++)
    {
        // tastk 2 -> jaise hi grater mile to pop krte rho jab tak stack ka top current value se chhota hia 
        while(!st.empty() && list[i] > list[st.top()])
        {
            // index of top element
            int preElement = st.top();

            st.pop();

            // storing the ans 
            ans[preElement] = list[i];
        }

        // task 1 -> traverse kiya and index push krte jao jab tak greater na mile
        st.push(i);
        
    }

    return ans; // done🎉🎉 
}

int main()
{

    vector<int> LL = {1,7,5,1,9,2,5,1};
    Node *head = NULL;

    for (int i = 0; i < LL.size(); i++)
    {
        insertData(head, LL[i]);
        // cout << LL[i] << endl;
    }

    vector<int> res = nextGreaterInLL(head);

    for (auto ele : res)
    {
        cout << ele << " ";
    }


    //⭐⭐ solved
}