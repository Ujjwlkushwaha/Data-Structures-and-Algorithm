void preOrder(Node *root, vector<int> &ans)
{
    if (root == NULL)
    {
        ans.push_back(-1);
        return;
    }

    ans.push_back(root->data);
    preOrder(root->left, ans);
    preOrder(root->right, ans);
}

// Function to serialize a tree and return a list containing nodes of tree.
vector<int> serialize(Node *root)
{
    vector<int> ans;
    preOrder(root, ans);
    return ans;
}

// Function to deserialize a list and construct the tree.
Node *deSerialize(vector<int> &arr)
{

    int val = arr[i];
    Node *nn = new Node(val);
    i++;

    if (val == -1)
        return NULL;

    nn->left = deSerialize(arr);
    nn->right = deSerialize(arr);
    return nn;
}
