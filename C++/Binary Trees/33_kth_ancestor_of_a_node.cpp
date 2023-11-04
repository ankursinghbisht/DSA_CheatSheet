/*
Idea:
using vector to keep track of the path from root to the desired node,
& returning the k-th value from last as answer.
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
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}
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
int kthAncestor(Node* root, int k, int node);

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {
        int k, node;
        scanf("%d ", &k);
        scanf("%d ", &node);
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        cout << kthAncestor(root, k, node) << endl;
    }
    return 0;
}

// } Driver Code Ends


//User function Template for C++

void solve(Node* root, int k, int val, vector<int>& vc, int& ans)
{
    if (!root)
        return;

    // If the target node is found, update the answer accordingly
    if (root->data == val)
    {
        if (k > vc.size())
            ans = -1;
        else
            ans = vc[vc.size() - k];

        return;
    }

    // Append the current node's data to the vector
    vc.push_back(root->data);

    // Check the left and right subtrees
    solve(root->left, k, val, vc, ans);
    solve(root->right, k, val, vc, ans);

    // Remove the last element (backtracking)
    vc.pop_back();
}

int kthAncestor(Node* root, int k, int val)
{
    vector<int> vc; // Vector to store the path
    int ans = 0;
    solve(root, k, val, vc, ans);
    return ans;
}