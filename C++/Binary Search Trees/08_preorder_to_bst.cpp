/*
Idea:
using each value from the vector and used the law of BST to insert it.
*/

// C++ Program for the same approach
#include <bits/stdc++.h>
using namespace std;


class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

static Node* node;

// This will create the BST
Node* createNode(Node* node, int data)
{
    if (node == NULL)
        node = new Node(data);

    if (node->data > data)
        node->left = createNode(node->left, data);
    if (node->data < data)
        node->right = createNode(node->right, data);

    return node;
}

// A wrapper function of createNode
void create(int data) { node = createNode(node, data); }
// A function to print BST in inorder
void inorderRec(Node* root)
{
    if (root != NULL) {
        inorderRec(root->left);
        cout << root->data << " ";
        inorderRec(root->right);
    }
}

// Driver code
int main()
{
    vector<int> nodeData = { 10, 5, 1, 7, 40, 50 };

    for (int i = 0; i < nodeData.size(); i++) {
        create(nodeData[i]);
    }
    inorderRec(node);
}

// This code is contributed by shinjanpatra
