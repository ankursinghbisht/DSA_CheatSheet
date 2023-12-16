/*
Idea:
Implementing sliding window technique, using Double ended Queue to keep track of the max element positions.
Inserting at the end, such that inserting element is greater than the end.
*/

//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int* arr, int n, int k)
    {
        vector<int> ans;
        deque<int> dq;

        // Process the first window separately
        for (int i = 0; i < k; i++)
        {
            while (!dq.empty() && arr[i] >= arr[dq.back()])
                dq.pop_back();
            dq.push_back(i);
        }

        // Process the remaining windows
        for (int i = k; i < n; i++)
        {
            ans.push_back(arr[dq.front()]);

            // Remove elements that are out of the current window
            while (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();

            // Remove smaller elements as they will not be the maximum
            while (!dq.empty() && arr[i] >= arr[dq.back()])
                dq.pop_back();

            dq.push_back(i);
        }

        // Add the maximum of the last window
        ans.push_back(arr[dq.front()]);

        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        int arr[n];
        for (int i = 0;i < n;i++)
            cin >> arr[i];
        Solution ob;
        vector <int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;

    }

    return 0;
}
// } Driver Code Ends