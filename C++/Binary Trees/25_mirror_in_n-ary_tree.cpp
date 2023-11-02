/*
Idea:
using map of stacks to store edges or tree,iterate 1st array to insert elements
and while iterating in 2nd array, pop if edges as equal from top of stack.
*/

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int checkMirrorTree(int n, int e, int A[], int B[])
    {
        // Create an unordered map to store edges for each node in tree A
        unordered_map<int, stack<int>> mp;
        // Store edges for tree A in the unordered map
        for (int i = 0; i < 2 * e; i += 2)
            mp[A[i]].push(A[i + 1]);

        // Check if the representations are mirrors
        for (int i = 0; i < 2 * e; i += 2)
        {
            // If the top element of stack for B[i] is not equal to B[i+1], they are not mirrors
            if (mp[B[i]].top() != B[i + 1])
                return 0;

            mp[B[i]].pop(); // Remove the top element from the stack for B[i]
        }
        return 1; // The representations are mirrors
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, e;

        cin >> n >> e;
        int A[2 * e], B[2 * e];

        for (int i = 0; i < 2 * e; i++)
            cin >> A[i];

        for (int i = 0; i < 2 * e; i++)
            cin >> B[i];

        Solution ob;
        cout << ob.checkMirrorTree(n, e, A, B) << endl;
    }
    return 0;
}
// } Driver Code Ends