/*
Idea:
not including 0s in answer, and if odd no. of negative elements, excluding the highest negative value
(special case, if only 1 negative element and all 0s, return 0)
else multiply all elements within limit of 1e9+7
*/

//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
const int MOD = 1e9 + 7;
class Solution {
public:
    long long int findMaxProduct(vector<int>& a, int n)
    {
        if (n == 1)
            return a[0];
        long long int maxNeg = INT_MIN, product = 1;
        int zeros = 0, negs = 0;

        for (int i = 0;i < n;++i) // looping to calc the product of non zero elements
        {
            if (a[i] == 0)
            {
                ++zeros;
                continue;
            }
            if (a[i] < 0)
            {
                ++negs;
                maxNeg = max(maxNeg, static_cast<long long int>(a[i]));
            }
            product = (product * a[i]) % MOD;
        }

        // Handle cases with all zeros and only one negative number
        if (zeros == n || (zeros == n - 1 && negs == 1))
            return 0;

        // Handle odd negative count
        if (negs & 1)
            product = (product / maxNeg + MOD) % MOD;

        return product;
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
        vector<int>arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        long long int ans = ob.findMaxProduct(arr, n);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends