/*
Idea:
Finding total sum of elements, if not even, returning false.
else: (finding elements which sum to half of total sum)
recursively calling the function over each element of array (with 2 conditions-take for sum or leave)
*/

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
    // Recursive function to check if it's possible to partition the array equally.
    bool solve(int arr[], int N, int total, int index, int sum)
    {
        // Base case: if we have reached the end of the array,
        // check if the current sum is equal to the total target sum.
        if (index == N)
        {
            return sum == total;
        }

        // If the current sum is greater than the total target sum, return false.
        if (sum > total)
            return false;

        // Recursive call to check if it's possible to partition the array
        // by either including the current element or excluding it.
        return solve(arr, N, total, index + 1, sum + arr[index]) || solve(arr, N, total, index + 1, sum);
    }

public:
    // Function to check if the array can be partitioned equally.
    int equalPartition(int N, int arr[])
    {
        // Calculate the total sum of the array elements.
        int sum = 0;
        for (int i = 0; i < N; ++i)
            sum += arr[i];

        // If the total sum is odd, it's not possible to divide equally.
        if (sum % 2 != 0)
            return 0;

        // Call the recursive function to check if equal partition is possible.
        return solve(arr, N, sum / 2, 0, 0) ? 1 : 0;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0;i < N;i++)
            cin >> arr[i];

        Solution ob;
        if (ob.equalPartition(N, arr))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
// } Driver Code Ends