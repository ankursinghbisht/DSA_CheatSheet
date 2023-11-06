/*
Idea:
Inorder traversal of BST is sorted, recursively iterating the tree,
 and checking if current element is smaller than last one, return false.
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


class Solution
{
public:
    // Helper function for inorder traversal to check if elements are in sorted order.
    bool isBSTUtil(Node* root, int& prev)
    {
        // If the current node is null, it's a valid case for BST.
        if (root == NULL)
            return true;

        // Traverse the left subtree
        if (!isBSTUtil(root->left, prev))
            return false;

        // Check if the current node's data is greater than the previous node's data.
        if (root->data <= prev)
            return false;

        // Update the previous node's data to the current node's data.
        prev = root->data;

        // Traverse the right subtree
        return isBSTUtil(root->right, prev);
    }

    // Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root)
    {
        // Initializing the previous node's data with the minimum possible value.
        int prev = INT_MIN;

        // Calling the helper function for inorder traversal.
        return isBSTUtil(root, prev);
    }
};




//{ Driver Code Starts.

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str; )
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

void inorder(Node* root, vector<int>& v)
{
    if (root == NULL)
        return;

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

int main() {

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--)
    {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        if (ob.isBST(root))
            cout << "1\n";

        else
            cout << "0\n";
    }
    return 0;
}


// } Driver Code Endss