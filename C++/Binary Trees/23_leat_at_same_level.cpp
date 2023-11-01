/*
Idea:
Iterating the tree, and counting the position of leaf nodes, if any leaf node is not in same depth , return false.
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

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
    // Function to check if all leaf nodes are at the same level in a binary tree
    bool check(Node* root)
    {
        queue<Node*> q;  // Create a queue for level order traversal
        q.push(root);  // Push the root node into the queue

        int level = 0;  // Initialize the current level
        int leafLevel = -1;  // Initialize the leaf level as -1 (undefined)

        while (!q.empty())  // Continue traversal while the queue is not empty
        {
            int n = q.size();  // Get the current size of the queue (number of nodes at the current level)
            level++;  // Increment the level for each iteration

            for (int i = 0; i < n; ++i)  // Traverse through each node at the current level
            {
                Node* current = q.front();  // Get the front node from the queue
                q.pop();  // Remove the front node from the queue

                // If the current node is a leaf node
                if (!current->left && !current->right)
                    // If leafLevel is not set, set it to the current level
                    if (leafLevel == -1)
                        leafLevel = level;
                // If the current level is not equal to the leaf level, the leaf nodes are not at the same level
                    else if (level != leafLevel)
                        return false;

                // Push the left child into the queue if it exists
                if (current->left)
                    q.push(current->left);

                // Push the right child into the queue if it exists
                if (current->right)
                    q.push(current->right);
            }
        }
        return true;  // If all leaf nodes are at the same level, return true
    }
};

//{ Driver Code Starts.
// Driver program to test size function
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
        Solution obj;
        cout << obj.check(head) << endl;
    }
    return 0;
}

// } Driver Code Ends