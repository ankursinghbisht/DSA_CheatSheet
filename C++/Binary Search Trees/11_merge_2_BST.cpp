/*
Idea:
using 2 vectors to store inorder traversal of both BST,and merging 2 sorted arrays and returning.
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
class Solution {
public:
    vector<int> mergedList;

    // Perform in-order traversal on the binary tree and store values in a vector
    void inOrder(Node* root, vector<int>& vec)
    {
        if (!root)
            return;

        inOrder(root->left, vec); // Traverse left subtree
        vec.push_back(root->data); // Store current node's data
        inOrder(root->right, vec); // Traverse right subtree
    }

    // Function to return a list of integers denoting the node values of both the BSTs in a sorted order
    vector<int> merge(Node* root1, Node* root2)
    {
        vector<int> v1, v2;
        inOrder(root1, v1);
        inOrder(root2, v2);

        // Merge the two sorted lists into a single sorted list
        int i = 0, j = 0;
        while (i < v1.size() && j < v2.size())
            if (v1[i] <= v2[j])
                mergedList.push_back(v1[i++]);
            else
                mergedList.push_back(v2[j++]);

        // Append the remaining elements
        while (i < v1.size())
            mergedList.push_back(v1[i++]);
        while (j < v2.size())
            mergedList.push_back(v2[j++]);

        return mergedList;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--)
    {
        string s;
        getline(cin, s);
        Node* root1 = buildTree(s);

        getline(cin, s);
        Node* root2 = buildTree(s);

        // getline(cin, s);
        Solution obj;
        vector<int> vec = obj.merge(root1, root2);
        for (int i = 0;i < vec.size();i++)
            cout << vec[i] << " ";
        cout << endl;
        ///cout<<"~"<<endl;
    }
    return 0;
}
// } Driver Code Ends