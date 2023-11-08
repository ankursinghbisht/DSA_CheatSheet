/*
Idea:
using 2 vectors to store inorder traversal of both trees,
using 2 pointers ,one from start of one vector, and other on end of another vector.
checking if pair sums to 'x', else updating the pointers.
*/

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

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

            // Create the left child for the current Node
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
//User function Template for C++


class Solution
{
public:

    // Function to perform inorder traversal and store the elements in a vector
    void inOrder(Node* root, vector<int>& v) {
        if (root != NULL) {
            inOrder(root->left, v); // Traverse left subtree
            v.push_back(root->data); // Store the node data in the vector
            inOrder(root->right, v); // Traverse right subtree
        }
    }

    // Function to count the number of pairs whose sum is equal to a given value x
    int countPairs(Node* root1, Node* root2, int x)
    {
        vector<int> v1; // Vector to store elements from the first tree
        vector<int> v2; // Vector to store elements from the second tree
        inOrder(root1, v1); // Perform inorder traversal on the first tree
        inOrder(root2, v2); // Perform inorder traversal on the second tree

        int count = 0; // Variable to keep track of the count of pairs whose sum is x
        int i = 0; // Pointer for the first vector
        int j = v2.size() - 1; // Pointer for the second vector

        // Loop through both vectors and find pairs whose sum is x
        while (i < v1.size() && j >= 0)
        {
            int sum = v1[i] + v2[j]; // Calculate the sum of elements at current pointers
            if (sum == x)
            { // If the sum is equal to x, increment count and move pointers
                count++;
                i++;
                j--;
            }
            else if (sum > x)  // If the sum is greater than x, decrement the second vector pointer
                j--;
            else // If the sum is less than x, increment the first vector pointer
                i++;
        }

        return count; // Return the count of pairs whose sum is x
    }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string tree1, tree2;
        getline(cin, tree1);
        getline(cin, tree2);
        Node* root1 = buildTree(tree1);
        Node* root2 = buildTree(tree2);
        int x;
        cin >> x;
        cin.ignore();
        Solution ob;
        cout << ob.countPairs(root1, root2, x) << "\n";
    }
    return 0;
}

// } Driver Code Ends