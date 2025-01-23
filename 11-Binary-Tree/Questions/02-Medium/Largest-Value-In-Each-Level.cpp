
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;

    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

vector<int> ans;
//===============✅ Solution using BFS algorithm=============
vector<int> largestValues(Node *root)
{
    if (root == nullptr)
    {
        return vector<int>{};
    }
    queue<Node *> queue;
    queue.push(root);

    while (!queue.empty())
    {
        int currentLength = queue.size();
        int currMax = INT_MIN;

        for (int i = 0; i < currentLength; i++)
        {
            Node *node = queue.front();
            queue.pop();
            currMax = max(currMax, node->data);

            if (node->left)
            {
                queue.push(node->left);
            }

            if (node->right)
            {
                queue.push(node->right);
            }
        }

        ans.push_back(currMax);
    }

    return ans;
}


// =============✅ Solution using DFS algorithm==========
// vector<int> largestValuesUsingDFS(Node* root)
// {
//     dfs(root, 0);
//     return ans;
// }

// void dfs(Node* node, int depth)
// {
//     if (node == nullptr)
//     {
//         return;
//     }

//     if (depth == ans.size())
//     {
//         ans.push_back(node->data);
//     }
//     else
//     {
//         ans[depth] = max(ans[depth], node->data);
//     }

//     dfs(node->left, depth + 1);
//     dfs(node->right, depth + 1);
// }

// ==========✅ Driver code ===========
Node *buildTree(Node *root)
{
    int data;
    cout << "Enter data (-1 for no node): ";
    cin >> data;

    root = new Node(data);

    if (data == -1)
        return NULL;

    cout << "Enter data in left of " << data << endl;
    root->left = buildTree(root->left);

    cout << "Enter data in right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

// 📌📌 level order traversal
void levelOrder(Node *root)
{
    if (root == NULL)
        return;

    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();

        if (temp == NULL)
        {
            cout << endl;

            q.pop();
            if (q.empty())
            {
                break;
            }
            else
                q.push(NULL);
        }
        else
        {
            cout << temp->data << " ";

            q.pop();
            if (temp->left)
                q.push(temp->left);

            if (temp->right)
                q.push(temp->right);
        }
    }
}

// 📌⭐ count number of nodes in the tree
int countNodes(Node *root)
{
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    // 1 3 5 -1 -1 3 -1 -1 2 -1 9 -1 -1

    cout << "Level order traversal of the tree: " << endl;
    levelOrder(root);

    // ✅ Largest Value in each level
    vector<int> ans = largestValues(root);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "Largest value of " << i << "th level is " << ans[i] << endl;
    }
}
