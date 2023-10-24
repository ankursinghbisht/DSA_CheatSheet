/*
Idea:
finding left boundary nodes, then all bottom boundary leaf nodes, then reverse right boundary nodes.
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


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
    Node* root = newNode(stoi(ip[0]));

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
            currNode->left = newNode(stoi(currVal));

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
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}









// } Driver Code Ends


class Solution {
public:

    // function to check if a node is a leaf node or not
    bool isLeaf(Node* node)
    {
        if (node->left == NULL && node->right == NULL)
            return true;
        return false;
    }

    // function to find all leaf nodes at the bottom of the tree
    void leafNode(Node* root, vector<int>& ans)
    {
        if (!root)
            return;

        if (root->left)
            leafNode(root->left, ans);

        if (isLeaf(root))
            ans.push_back(root->data);

        if (root->right)
            leafNode(root->right, ans);
    }

    // function to find all left nodes
    void leftSubTree(Node* root, vector<int>& ans)
    {
        if (!root)
            return;

        // Check if the current node is not a leaf and add it to the answer
        if (!isLeaf(root))
            ans.push_back(root->data);

        // Traverse the left subtree first
        if (root->left)
            leftSubTree(root->left, ans);

        // If there is no left child, go to the right child
        else if (root->right)
            leftSubTree(root->right, ans);
    }

    // function to find all right nodes
    void rightSubTree(Node* root, vector<int>& ans)
    {
        if (!root)
            return;

        // Traverse the right subtree first
        if (root->right)
            rightSubTree(root->right, ans);

        // If there is no right child, go to the left child
        else if (root->left)
            rightSubTree(root->left, ans);

        // Check if the current node is not a leaf and add it to the answer
        if (!isLeaf(root))
            ans.push_back(root->data);
    }

    // Function to get the boundary traversal of the binary tree
    vector <int> boundary(Node* root)
    {
        vector<int> ans;
        ans.push_back(root->data); // Add the root data to the answer

        // Traverse the left subtree
        leftSubTree(root->left, ans);

        // Traverse the leaf nodes on the left and right subtrees
        leafNode(root->left, ans);
        leafNode(root->right, ans);

        // Traverse the right subtree
        rightSubTree(root->right, ans);

        return ans; // Return the final boundary traversal
    }
};


//{ Driver Code Starts.

/* Driver program to test size function*/

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--)
    {
        string s, ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.boundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends