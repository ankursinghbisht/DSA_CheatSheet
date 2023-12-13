/*
Idea:
inserting all elements in a vector & using 2 pointers, one from start and one from mid, appending the answer
*/

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    // Function to rearrange the elements of the queue
    vector<int> rearrangeQueue(queue<int>& q) {
        // Vector to store the rearranged elements
        vector<int> ans, temp;

        // Step 1: Move elements from the queue to a temporary vector
        while (!q.empty()) {
            temp.push_back(q.front());  // Store the front element of the queue in the temporary vector
            q.pop();  // Remove the front element from the queue
        }

        // Pointers i and j for traversing the temporary vector
        int i = 0, j = temp.size() / 2;

        // Step 2: Rearrange the elements in the temporary vector and store in the result vector
        while (j < temp.size()) {
            ans.push_back(temp[i++]);  // Append the i-th element to the result vector
            ans.push_back(temp[j++]);  // Append the j-th element to the result vector
        }

        // Return the rearranged vector
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        queue<int> q;
        for (int i = 0;i < n;i++) {
            int a;
            cin >> a;
            q.push(a);
        }
        Solution ob;
        vector<int> ans = ob.rearrangeQueue(q);
        for (int i = 0;i < ans.size();i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends