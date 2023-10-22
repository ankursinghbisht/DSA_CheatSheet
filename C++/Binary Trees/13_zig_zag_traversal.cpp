/*
Idea:
using level order, but with 2 stacks, traversing with one stack and inserting child in another one.
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

    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
        vector <int> res;

        //if root is null, we return the list.
        if (!root)return res;

        //declaring two stacks to store the current and new level.
        stack<struct Node*> currentlevel, nextlevel;

        //pushing the root in currentlevel stack.
        currentlevel.push(root);
        bool lefttoright = true;

        while (!currentlevel.empty())
        {
            //storing the top element of currentlevel stack in temp and popping it.
            Node* temp = currentlevel.top();
            currentlevel.pop();

            //if temp is not null, we store the data at temp in list.
            if (temp)
            {
                res.push_back(temp->data);

                //if lefttoright is true then it stores nodes from left to right  else from right to left in nextlevel stack.
                if (lefttoright)
                {
                    if (temp->left)
                        nextlevel.push(temp->left);
                    if (temp->right)
                        nextlevel.push(temp->right);
                }
                else
                {
                    if (temp->right)
                        nextlevel.push(temp->right);
                    if (temp->left)
                        nextlevel.push(temp->left);
                }
            }

            //if currentlevel stack is empty lefttoright is flipped to change the order of storing the nodes and both stacks are swapped.
            if (currentlevel.empty())
            {
                lefttoright = !lefttoright;
                swap(currentlevel, nextlevel);
            }
        }
        //returning the list.
        return res;
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

        vector<int> ans;
        Solution ob;
        ans = ob.zigZagTraversal(root);

        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";

        cout << endl;

    }
    return 0;
}

// } Driver Code Ends