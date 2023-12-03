/*
Idea:
sorting array in non-descending order.
using recursion at each element with backtracking(with 2 cases, to choose or not to choose the element)
*/

//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
    // Vector to store the final combinations
    vector<vector<int>> ans;

    // Recursive function to find combinations
    void solve(vector<int>& A, int B, vector<int> vc, int ind) {
        // Base cases
        if (ind == A.size() || B < 0)
            return;

        if (B == 0) {
            // If the target sum is reached, add the combination to the result
            ans.push_back(vc);
            return;
        }

        for (int i = ind; i < A.size(); ++i) {
            // Skip duplicates to avoid repeated combinations
            if (i > ind && A[i] == A[i - 1])
                continue;

            // Include the current element in the combination
            vc.push_back(A[i]);
            // Recursive call with updated target sum and index
            solve(A, B - A[i], vc, i);
            // Backtrack by removing the last added element
            vc.pop_back();
        }
    }

public:
    // Function to return a list of indexes denoting the required combinations whose sum is equal to the given number.
    vector<vector<int>> combinationSum(vector<int>& A, int B) {
        vector<int> vc;  // Vector to store the current combination
        // Sort the input array to handle duplicates and for optimization
        sort(A.begin(), A.end());
        // Call the recursive function to find combinations
        solve(A, B, vc, 0);
        return ans;  // Return the final result
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> A;
        for (int i = 0;i < n;i++) {
            int x;
            cin >> x;
            A.push_back(x);
        }
        int sum;
        cin >> sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
        if (result.size() == 0) {
            cout << "Empty";
        }
        for (int i = 0;i < result.size();i++) {
            cout << '(';
            for (int j = 0;j < result[i].size();j++) {
                cout << result[i][j];
                if (j < result[i].size() - 1)
                    cout << " ";
            }
            cout << ")";
        }
        cout << "\n";
    }
}
// } Driver Code Ends