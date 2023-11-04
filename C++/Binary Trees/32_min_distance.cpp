/*
Idea:
finding the lowest ancestor of 2 desired nodes, and finding distance between the nodes and the ancestor node,
return the sum of distances.
*/

//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

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
        if (i >= ip.size()) break;
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



class Solution {
public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root, int n1, int n2)
    {

        if (root == NULL)
            return NULL;

        //if either n1 or n2 matches with data at current node, we return root.
        // ( if a node is ancestor of other, then the ancestor nodenbecomes the lowest common ancestor).
        if (root->data == n1 || root->data == n2)
            return root;

        //calling the lca function recursively for left and right subtrees.
        Node* l = lca(root->left, n1, n2);
        Node* r = lca(root->right, n1, n2);

        //if both of the above calls return non-NULL value then one node is present in one subtree and other is present in another subtree. 
        //So, this node is the lowest common ancestor.
        if (l and r)
            return root;

        //else we check if left subtree or right subtree is the lowest common ancestor.
        return (l != NULL) ? l : r;
    }
    // Returns level of key k if it is present in  tree, otherwise returns -1
    int findLevel(Node* root, int k, int level)
    {
        if (root == NULL)
            return -1;
        if (root->data == k)
            return level;

        int left = findLevel(root->left, k, level + 1);
        if (left == -1)
            return findLevel(root->right, k, level + 1);
        return left;
    }
    /* Should return minimum distance between a and b in a tree with given root*/
    int findDist(Node* root, int a, int b) {
        // Your code here
        Node* temp = lca(root, a, b);

        int left = findLevel(temp, a, 0);
        int right = findLevel(temp, b, 0);
        return left + right;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/



int main() {


    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);

        Node* root = buildTree(s);
        int n1, n2;
        scanf("%d %d ", &n1, &n2);
        Solution ob;
        cout << ob.findDist(root, n1, n2) << endl;

    }
    return 0;
}

// } Driver Code Ends