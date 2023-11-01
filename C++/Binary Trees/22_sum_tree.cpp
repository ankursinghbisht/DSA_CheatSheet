/*
Idea:
recursively returning sum of left and right child,and checking if it's equal to the node itself.
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
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


// Should return true if tree is Sum Tree, else false
class Solution
{
public:
    bool ans = true;
    int SumTree(Node* node)
    {
        if (node == NULL)
            return 0;
        if (!node->left && !node->right)
            return node->data;

        // Recursively calculate the sum of left and right subtrees
        int left_sum = SumTree(node->left);
        int right_sum = SumTree(node->right);

        int old_data = node->data;
        if (node->data != left_sum + right_sum)
            ans = false;

        //returning with current node's data to the sum of its left and right subtrees
        return node->data + left_sum + right_sum;
    }

    bool isSumTree(Node* root)
    {
        int sum = SumTree(root);
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    scanf("%d ", &t);
    while (t--)
    {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.isSumTree(root) << endl;
    }
    return 1;
}
// } Driver Code Ends