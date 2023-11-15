/*
Idea:
Creating a Huffman Tree from input characters. & traverse tree maintain an auxiliary array.
 While moving to the left child, write 0 to the array.

Creating the Huffman Tree:
-Create a leaf node for each unique character and build a min heap of all leaf nodes
(Min Heap is used as a priority queue. The value of frequency field is used to compare two nodes in min heap. Initially,
 the least frequent character is at root)

-Extract two nodes with the minimum frequency from the min heap.

-Create a new internal node with a frequency equal to the sum of the two nodes frequencies.
 Make the first extracted node as its left child and the other extracted node as its right child.
  Add this node to the min heap.

-Repeat previous 2 steps until the heap contains only one node.
 The remaining node is the root node and the tree is complete.
*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Node structure for the Huffman tree
    struct node
    {
        int value;
        char ch;
        node* left, * right;

        // Constructor for creating a node with default values
        node()
        {
            value = 0;
            ch = '\0';
            left = right = NULL;
        }

        // Constructor for creating a node with specified values
        node(int v, char c, node* l = NULL, node* r = NULL)
        {
            value = v;
            ch = c;
            left = l;
            right = r;
        }
    };

    // Comparator class for the priority queue
    class comp
    {
    public:
        // Comparison operator to determine the priority in the priority queue
        bool operator()(node* a, node* b)
        {
            return a->value > b->value;
        }
    };

    // Recursive function for traversing the Huffman tree and generating codes
    void preorder(node* root, string s, vector<string>& ans)
    {
        if (root == NULL)
            return;
        if (root->ch != '0')
            ans.push_back(s);
        preorder(root->left, s + '0', ans);
        preorder(root->right, s + '1', ans);
    }

    // Function to generate Huffman codes
    vector<string> huffmanCodes(string S, vector<int> f, int N)
    {
        // Priority queue for creating the Huffman tree
        priority_queue<node*, vector<node*>, comp> pq;
        node* root = NULL;

        // Create nodes for each character and frequency, and push them into the priority queue
        for (int i = 0; i < N; ++i)
        {
            node* n = new node(f[i], S[i]);
            pq.push(n);
        }

        // Build the Huffman tree by merging nodes in the priority queue
        while (pq.size() > 1)
        {
            node* l = pq.top();
            pq.pop();
            node* r = pq.top();
            pq.pop();
            node* rt = new node(l->value + r->value, '0', l, r);
            pq.push(rt);
        }

        // The top of the priority queue is the root of the Huffman tree
        root = pq.top();

        // Vector to store the generated Huffman codes
        vector<string> ans;

        // Generate Huffman codes using the recursive preorder function
        preorder(root, "", ans);

        // Return the generated Huffman codes
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--)
    {
        string S;
        cin >> S;
        int N = S.length();
        vector<int> f(N);
        for (int i = 0;i < N;i++) {
            cin >> f[i];
        }
        Solution ob;
        vector<string> ans = ob.huffmanCodes(S, f, N);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends