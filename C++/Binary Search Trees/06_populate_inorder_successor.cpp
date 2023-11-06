/*
Idea:(using reverse inorder traversal)
Traversing the tree in reverse inorder traversal and keep track of previously visited node.
When a node is being visited, assign previously visited node as next.
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
    struct Node* next;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};

void printInorder(Node* node)
{
    if (node == NULL)
    {
        return;
    }
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
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
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

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
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

Node* Inorder(Node* root)
{
    if (root->left == NULL)
        return root;
    Inorder(root->left);
}


// } Driver Code Ends

class Solution
{
public:
    //Recursive function to populate the next pointer in the inorder traversal
    void populateNextRecur(Node* p, Node** next_ref)
    {
        //If p is not NULL
        if (p)
        {
            //Traverse to the right subtree first
            populateNextRecur(p->right, next_ref);

            //Set the next pointer of p to the current value of next_ref
            p->next = *next_ref;

            //Update the value of next_ref to p
            *next_ref = p;

            //Traverse to the left subtree
            populateNextRecur(p->left, next_ref);
        }
    }

    //Function to populate the next pointer in each node
    void populateNext(Node* root)
    {
        //Initialize next pointer as NULL
        Node* next = NULL;

        //Call the recursive function
        populateNextRecur(root, &next);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    scanf("%d", &t);
    cin.ignore();
    while (t--)
    {
        string treeString;
        getline(cin, treeString);
        Node* root = buildTree(treeString);
        Solution obj;
        obj.populateNext(root);
        Node* ptr = Inorder(root);
        while (ptr)
        {
            printf("%d->%d ", ptr->data, ptr->next ? ptr->next->data : -1);
            ptr = ptr->next;
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends