/*
Idea:
inorder traversal of BST will be in sorted manner,
To find the lowest height BST, inserting node in new BST using modified binary search method.
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};


// } Driver Code Ends


class Solution {
public:
    vector<int> val;
    // Perform in-order traversal on the binary tree and store values in a vector
    void inOrder(Node* root)
    {
        if (!root)
            return;
        inOrder(root->left);  // Traverse left subtree
        val.push_back(root->data);  // Store current node's data
        inOrder(root->right);  // Traverse right subtree
    }

    // Create a balanced BST from the sorted values
    Node* createTree(int low, int high)
    {
        if (high < low)  // Base case for recursion
            return nullptr;
        int ind = low + (high - low) / 2;  // Calculate the middle index
        Node* ans = new Node(val[ind]);  // Create a new node with the middle value
        // Recursively build the left and right subtrees
        ans->left = createTree(low, ind - 1);
        ans->right = createTree(ind + 1, high);
        return ans;
    }

    // Function returns the root of the modified BST
    Node* buildBalancedTree(Node* root)
    {
        inOrder(root);  // Perform in-order traversal
        Node* ans = createTree(0, val.size() - 1);  // Create a balanced BST
        return ans;
    }
};



//{ Driver Code Starts.

Node* insert(struct Node* node, int key) {
    if (node == NULL) return new Node(key);
    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
    return node;
}

void preOrder(Node* node)
{
    if (node == NULL)return;
    printf("%d ", node->data);
    preOrder(node->left);
    preOrder(node->right);
}

int height(struct Node* node)
{
    if (node == NULL)
        return 0;
    int lDepth = height(node->left);
    int rDepth = height(node->right);
    if (lDepth > rDepth)
        return(lDepth + 1);
    else
        return(rDepth + 1);
}
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

Node* buildBalancedTree(Node* root);

int main()
{
    int t;
    cin >> t;
    getchar();
    while (t--)
    {
        struct Node* root = NULL;
        int n, temp;
        string tree;
        getline(cin, tree);
        root = buildTree(tree);
        // cout<<height(root)<<endl;
        Solution obj;
        root = obj.buildBalancedTree(root);
        cout << height(root) << endl;
    }
    return 0;
}

// } Driver Code Ends