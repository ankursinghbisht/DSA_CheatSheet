/*
Idea:
Finding elements from preorder traversal.
Check the element in preorder traversal,left part will be left subtree, right part will be right subtree.
Recursively calling the function for left and right parts.
*/

//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};


void printPostOrder(Node* root)
{
    if (root == NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}

// } Driver Code Ends


class Solution {
public:
    int preIndex = 0;
    Node* preTree(int in[], int pre[], int low, int high)
    {
        if (low > high) {
            return NULL;
        }

        // Create a new node using the current element in the preorder traversal
        Node* root = new Node(pre[preIndex]);
        preIndex++;

        // Find the index of the current element in the inorder traversal
        int inIndex = -1;
        for (int i = low; i <= high; ++i) {
            if (in[i] == root->data) {
                inIndex = i;
                break;
            }
        }

        // Construct left and right subtrees recursively using the left and right segments of inorder traversal
        root->left = preTree(in, pre, low, inIndex - 1);
        root->right = preTree(in, pre, inIndex + 1, high);

        return root;
    }
    Node* buildTree(int in[], int pre[], int n)
    {
        return  preTree(in, pre, 0, n - 1);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int inorder[n], preorder[n];
        for (int i = 0; i < n; i++)
            cin >> inorder[i];
        for (int i = 0; i < n; i++)
            cin >> preorder[i];
        Solution obj;
        Node* root = obj.buildTree(inorder, preorder, n);
        printPostOrder(root);
        cout << endl;
    }
}

// } Driver Code Ends