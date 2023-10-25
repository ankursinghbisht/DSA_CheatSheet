/*
Idea:
extracting the number from string,  & recursively calling the function -
for '(' bracket, go to child of current node, and for')', returning the current node.
*/

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left
child and a pointer to right child */
class Node
{
public:
    int data;
    Node* left, * right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

/* This function is to print the inorder of the tree  */
void inorder(Node* root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}



// } Driver Code Ends
//User function Template for C++



class Solution
{
public:
    Node* constructtree(string s, int* start)
    {
        // Assuming there is/are no negative  character/characters in the string
        if (s.size() == 0 || *start >= s.size())
            return NULL;

        // constructing a number from the continuous digits
        int num = 0;
        while (*start < s.size() && s[*start] != '(' && s[*start] != ')')
        {
            num = num * 10 + (int)(s[*start] - '0');
            *start = *start + 1;
        }

        // creating a node from the constructed number from  above loop
        struct Node* root = NULL;
        if (num > 0)
            root = new Node(num);

        // As soon as we see first right parenthesis from the current node we start to construct the tree in the left
        if (*start < s.size() && s[*start] == '(')
        {
            *start = *start + 1;
            root->left = constructtree(s, start);
        }
        if (*start < s.size() && s[*start] == ')')
        {
            *start = *start + 1;
            return root;
        }

        // As soon as we see second right parenthesis from the current node we start to construct the tree in the right
        if (*start < s.size() && s[*start] == '(')
        {
            *start = *start + 1;
            root->right = constructtree(s, start);
        }
        if (*start < s.size() && s[*start] == ')')
            *start = *start + 1;

        return root;
    }

    Node* treeFromString(string str)
    {
        int start = 0;
        return constructtree(str, &start);
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution obj;
        Node* root = obj.treeFromString(str);
        inorder(root);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends