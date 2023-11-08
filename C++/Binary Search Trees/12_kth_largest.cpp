/*
Idea:
using reverse inOrder traversal to start iterating from the largest element of BST,
and using list to store largest 'k' elements ,& returning the kth element.
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

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


// } Driver Code Ends


// return the Kth largest element in the given BST rooted at 'root'
class Solution
{
public:
    vector<int> vc; // Vector to store the node values
    int count; // Counter to keep track of k

    // Function to traverse the binary search tree in reverse order
    void reverseInorder(Node* root)
    {
        if (root)
        {
            reverseInorder(root->right); // Traverse right subtree
            if (!count) // If count is 0, return
                return;

            vc.push_back(root->data); // Store the node value in the vector
            count--; // Decrement count
            reverseInorder(root->left); // Traverse left subtree
        }
    }

    // Function to find the kth largest element in the BST
    int kthLargest(Node* root, int k)
    {
        count = k; // Set count to k
        reverseInorder(root); // Traverse the tree in reverse order
        return vc[k - 1]; // Return the kth largest element
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    getchar();

    while (t--)
    {
        string s;
        getline(cin, s);
        Node* head = buildTree(s);

        int k;
        cin >> k;
        getchar();

        Solution ob;
        cout << ob.kthLargest(head, k) << endl;
    }
    return 1;
}
// } Driver Code Ends