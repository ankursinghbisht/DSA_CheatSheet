/*
Idea:
Iterating through array, storing sum of temporary subarray using 2 pointers,
& moving them if sum is higher or lower ( using sliding window technique)
*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:

    int smallestSubWithSum(int arr[], int n, int x)
    {
        int sum = 0, ans = n + 1, i = 0, j = 0;
        while (j < n && i < n)
        {
            //moving front & back pointer till we have sum > target
            while (sum <= x && j < n)
                sum += arr[j++];
            while (sum > x && i < n)
            {
                // checking if subarray is smaller than current one
                ans = min(ans, j - i);
                sum -= arr[i++];
            }
        }
        return ans <= n ? ans : 0;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int a[n];
        for (int i = 0;i < n;i++)
            cin >> a[i];
        Solution obj;
        cout << obj.smallestSubWithSum(a, n, x) << endl;
    }
    return 0;
}