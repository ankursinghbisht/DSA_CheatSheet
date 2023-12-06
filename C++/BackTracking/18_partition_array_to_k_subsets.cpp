/*
Idea:
calculating target sum of each subset, and using backtracking to find , if there exist any combination
where each subset sums to target value.
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution
{
public:
    // Function to check if it's possible to partition the array into k subsets with equal sum
    bool isKPartitionPossible(int a[], int n, int k)
    {
        // Calculate the total sum of the array elements
        int s = 0;
        for (int i = 0;i < n;++i)
            s += a[i];


        // If the sum is not divisible evenly by k, return false
        if (s % k != 0)
            return false;


        // Calculate the target sum for each subset
        int t = s / k;

        // Initialize an array to track the sum of elements in each subset
        vector<int> subset(k, 0);

        // Start the recursive function with initial parameters
        return fun(a, 0, n, subset, t);
    }

private:
    // Recursive function to explore different possibilities of partitioning
    bool fun(int a[], int idx, int n, vector<int>& subset, int t)
    {
        // If all elements are processed, return true
        if (idx == n)
            return true;


        // Try to add the current element to each subset
        for (int i = 0; i < subset.size(); ++i)
        {
            if (subset[i] + a[idx] <= t)
            {
                subset[i] += a[idx];

                // Recursively check the next element
                if (fun(a, idx + 1, n, subset, t))
                    return true;


                // Backtrack: undo the addition if it doesn't lead to a solution
                subset[i] -= a[idx];

                // Optimization: if the subset sum is 0, no need to try further
                if (subset[i] == 0)
                    break;

            }
        }

        // If no subset is found, return false
        return false;
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;

        cin >> n;
        int a[n];
        for (int i = 0;i < n;i++)
            cin >> a[i];
        int k;
        cin >> k;
        Solution obj;
        cout << obj.isKPartitionPossible(a, n, k) << endl;
    }
}
// } Driver Code Ends