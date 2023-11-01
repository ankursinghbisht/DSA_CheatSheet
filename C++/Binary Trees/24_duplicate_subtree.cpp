/*
Idea:
serializing the subtree, after applying DFS, and using dictionary to keep track of subtrees,
if any encountered before, returning true.
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    char data;
    struct Node* left;
    struct Node* right;

    Node(char x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

struct Node* buildTree(string str)
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
class Solution {
public:
    unordered_map<string, int> subtree_frequency; // Map to store the frequency of subtrees

    // Serialize the binary tree
    string serialize_tree(Node* node)
    {
        if (!node)
            return "$";


        if (!node->left && !node->right)
            return to_string(node->data);


        string serialized_tree = serialize_tree(node->left) + "$" + to_string(node->data) + "$" + serialize_tree(node->right);

        subtree_frequency[serialized_tree] = subtree_frequency[serialized_tree] + 1;

        return serialized_tree;
    }

    // Function to find duplicate subtrees
    int dupSub(Node* root)
    {
        serialize_tree(root);

        for (auto const& x : subtree_frequency)
            if (x.second > 1)
                return 1; // Duplicate subtree found


        return 0; // No duplicate subtree found
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    //cout << t << "\n";
    while (t--)
    {
        string treeString;
        getline(cin >> ws, treeString);
        struct Node* root = buildTree(treeString);
        Solution ob;
        cout << ob.dupSub(root) << "\n";
    }
    return 0;
}
// } Driver Code Ends