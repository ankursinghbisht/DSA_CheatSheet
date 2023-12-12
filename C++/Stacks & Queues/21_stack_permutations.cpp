/*
Idea:
pushing elements from Array A to stack , and popping elements if top match index element of array B
If stack isn't empty, return false
*/

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    // Function to check if the given sequences A and B are stack permutations
    int isStackPermutation(int N, vector<int>& A, vector<int>& B)
    {
        // Create a stack to simulate the stack operations
        stack<int> st;

        // Index to keep track of the elements in sequence B
        int index = 0;

        // Iterate through each element in sequence A
        for (auto it : A)
        {
            // Push the current element onto the stack
            st.push(it);

            // Check if the top of the stack matches the current element in sequence B
            while (!st.empty() && st.top() == B[index++])
            {
                // Pop the element from the stack and move to the next element in sequence B
                st.pop();
                ++index;
            }
        }

        // If the stack is empty, it means sequences A and B are stack permutations
        if (st.empty())
            return 1; // Return 1 to indicate true
        else
            return 0; // Return 0 to indicate false
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0;i < n;i++) {
            cin >> a[i];
        }
        for (int i = 0;i < n;i++) {
            cin >> b[i];
        }
        Solution ob;
        cout << ob.isStackPermutation(n, a, b) << endl;
    }

    return 0;
}
// } Driver Code Ends