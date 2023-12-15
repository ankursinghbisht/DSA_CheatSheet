/*
Idea:
Implementing sliding window technique using queue.
At each window, popping all positive elements till negative is at first.
inserting in answer array (if queue is empty, inserting 0 )
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
    long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K)
{
    vector<long long >ans;
    queue<long long>q;

    // Process the first window of size K
    for (long long i = 0; i < K; ++i)
        q.push(A[i]);

    // Find the first negative integer in the initial window
    while (!q.empty() && q.front() >= 0)
        q.pop();

    // Add the result to the answer vector
    ans.push_back((!q.empty()) ? q.front() : 0);

    // Process the remaining elements
    for (long long i = K; i < N; ++i)
    {
        // Add the current element to the window
        q.push(A[i]);

        // Remove elements from the front until a negative integer is encountered
        // or the window size is reduced to K
        while (!q.empty() && (q.front() >= 0 || q.size() > K))
            q.pop();

        // Add the result to the answer vector
        ans.push_back((!q.empty()) ? q.front() : 0);
    }

    return ans;
}