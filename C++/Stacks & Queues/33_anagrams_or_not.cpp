/*
Idea:
Using map to store frequency of each node at each level.
Performing 2 separate level order traversal of both trees & updating map ,
checking if all map values are zero.
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
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


// } Driver Code Ends
//User function Template for C++

class Solution {

public:
    bool areAnagrams(Node* root1, Node* root2)
    {
        // Using a map to store the frequency of each node value at each level
        map<pair<int, int>, int> mp;

        // Queue for level order traversal
        queue<pair<Node*, int>> q;

        // If the first tree is not empty, enqueue its root with level 0
        if (root1)
            q.push({ root1, 0 });

        // Perform level order traversal for the first tree
        while (!q.empty())
        {
            Node* root = q.front().first;
            int level = q.front().second;

            // Increment the frequency of the current node value at the current level
            mp[{root->data, level}]++;

            q.pop();

            // Enqueue the left and right children with the incremented level
            if (root->left)
                q.push({ root->left, level + 1 });
            if (root->right)
                q.push({ root->right, level + 1 });
        }

        // If the second tree is not empty, enqueue its root with level 0
        if (root2)
            q.push({ root2, 0 });

        // Perform level order traversal for the second tree
        while (!q.empty())
        {
            Node* root = q.front().first;
            int level = q.front().second;

            // Decrement the frequency of the current node value at the current level
            mp[{root->data, level}]--;

            q.pop();

            // Enqueue the left and right children with the incremented level
            if (root->left)
                q.push({ root->left, level + 1 });
            if (root->right)
                q.push({ root->right, level + 1 });
        }

        // Check if all node values at all levels have zero frequency
        for (auto i : mp)
        {
            if (i.second != 0)
            {
                // If any frequency is non-zero, the trees are not anagrams
                return false;
            }
        }

        // If all frequencies are zero, the trees are anagrams
        return true;
    }

};

//{ Driver Code Starts.

/* Driver program to test size function*/
int main() {
    int t;
    scanf("%d\n", &t);
    while (t--) {
        string treeString1, treeString2;
        getline(cin, treeString1);
        Node* root1 = buildTree(treeString1);
        getline(cin, treeString2);
        Node* root2 = buildTree(treeString2);
        Solution ob;
        cout << ob.areAnagrams(root1, root2) << endl;
    }
    return 0;
}

// } Driver Code Ends