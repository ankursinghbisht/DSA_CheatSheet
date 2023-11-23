/*
Idea:
sorting in ascending order, and adding difference in each corresponding pair
*/

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    //Function to find the minimum sum of absolute differences between corresponding elements of two arrays.
    long long findMinSum(vector<int>& A, vector<int>& B, int N)
    {
        long long sum = 0;
        //sorting both arrays in ascending order.
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        //calculating sum of absolute differences of corresponding elements.
        for (int i = 0;i < N;i++)
            sum += abs(A[i] - B[i]);

        return sum;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> A(N), B(N);
        for (int i = 0;i < N;i++) {
            cin >> A[i];
        }
        for (int i = 0;i < N;i++) {
            cin >> B[i];
        }
        Solution ob;
        cout << ob.findMinSum(A, B, N) << endl;
    }
}
// } Driver Code Ends