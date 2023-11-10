/*
Idea:
using BST: inserting value from vector backwards,as nodes. & keeping track of each node's successor
*/

//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//Back-end complete function Template for C++
// Define the Node structure representing a node in a binary search tree
struct Node
{
    int data;  // Data stored in the node
    Node* left;  // Pointer to the left child
    Node* right;  // Pointer to the right child

    // Constructor to initialize the Node with a value
    Node(int val)
    {
        data = val;  // Set the data to the provided value
        left = NULL;  // Initialize the left child as NULL
        right = NULL;  // Initialize the right child as NULL
    }
};

// Function to insert a node into the binary search tree
Node* insert(Node*& root, int val, Node*& succ)
{
    // If the root is NULL, create a new node and return it
    if (root == NULL)
        return root = new Node(val);

    // If the value is less than the root's data, go to the left subtree
    if (root->data > val)
    {
        succ = root;  // Set the current node as the successor
        root->left = insert(root->left, val, succ);  // Recursively insert into the left subtree
    }
    // If the value is greater than or equal to the root's data, go to the right subtree
    else if (root->data <= val)
        root->right = insert(root->right, val, succ);  // Recursively insert into the right subtree

    return root;  // Return the root of the updated tree
}

class Solution {
public:
    // Function to find the least greater element for each element in the array
    vector<int> findLeastGreater(vector<int>& arr, int n) {
        Node* root = NULL;  // Initialize the root of the binary search tree as NULL
        vector<int> ans(n, -1);  // Initialize the answer vector with -1 for all elements

        // Traverse the array in reverse order
        for (int i = n - 1; i >= 0; i--)
        {
            Node* succ = NULL;  // Initialize the successor as NULL
            root = insert(root, arr[i], succ);  // Insert the current element into the binary search tree
            if (succ != NULL)
                ans[i] = succ->data;  // If successor exists, update the answer vector
        }

        return ans;  // Return the answer vector containing the least greater elements
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int>arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.findLeastGreater(arr, n);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends