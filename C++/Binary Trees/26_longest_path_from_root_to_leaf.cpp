/*
Idea:
keeping track of the longest path and the height sum in longest path, and recursively iterating the tree to find the deepest node.
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

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
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


// } Driver Code Ends
//User function Template for C++


class Solution
{
public:
    //Utility function to calculate the sum of the longest root to leaf path
    void sumOfLongRootToLeafPathUtil(Node* root, int sum, int len, int& maxLen, int& maxSum)
    {
        //Base case: if the current node is null
        if (!root)
        {
            //Checking if the current path has a longer length and update maxLen and maxSum accordingly
            if (maxLen < len)
            {
                maxLen = len;
                maxSum = sum;
            }
            //If the lengths are equal, check if the current sum is greater and update maxSum if necessary
            else if (maxLen == len && maxSum < sum)
                maxSum = sum;
            return;
        }
        //Recursively calculating the sum of the left and right subtrees
        sumOfLongRootToLeafPathUtil(root->left, sum + root->data, len + 1, maxLen, maxSum);
        sumOfLongRootToLeafPathUtil(root->right, sum + root->data, len + 1, maxLen, maxSum);
    }

    //Function to calculate the sum of the longest root to leaf path
    int sumOfLongRootToLeafPath(Node* root)
    {
        //Base case: if the tree is empty
        if (!root)
            return 0;

        int maxSum = INT_MIN, maxLen = 0; //Initializing the variables to store the maximum length and sum
        sumOfLongRootToLeafPathUtil(root, 0, 0, maxLen, maxSum); //Calling the utility function
        return maxSum; //Returning the maximum sum
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
        int res = obj.sumOfLongRootToLeafPath(root);
        cout << res << "\n";
    }
    return 0;
}
// } Driver Code Ends