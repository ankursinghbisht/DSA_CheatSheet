/*
Idea:
(We've to find the partition which results in lowest subarray sum)
-declaring 2 vars low =max value in array, and high= sum of all elements( as it  is min& max sum of subarray )
-using binary search to assume 'mid' as feasible partition
(if yes, check for smaller partition), else increase the window.
*/


#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    // Function to check if partition is possible with given sum of subarray 
    long long isPossible(long long diff, int arr[], int n)
    {
        long long count = 1, sum = 0;
        for (int i = 0;i < n;++i)
        {
            // If sum above target, assuming it as a partition, & keeping tally of total partition
            if (sum + arr[i] <= diff)
                sum += arr[i];
            else
            {
                sum = arr[i];
                ++count;
            }
        }
        return count;
    }

    long long minTime(int arr[], int n, int k)
    {
        long long low = arr[0], high = arr[0];
        for (int i = 1;i < n;++i)
        {
            // finding max & sum of array
            low = max(low, (long long)arr[i]);
            high += arr[i];
        }
        while (low < high)
        {
            long long mid = low + (high - low) / 2;
            if (isPossible(mid, arr, n) <= k) // checking if partition is feasible
                high = mid; // if yes, finding smaller partition
            else
                low = mid + 1;// if no, increasing the ceiling.
        }
        return low;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int k, n;
        cin >> k >> n;

        int arr[n];
        for (int i = 0;i < n;i++)
            cin >> arr[i];
        Solution obj;
        cout << obj.minTime(arr, n, k) << endl;
    }
    return 0;
}
// } Driver Code Ends