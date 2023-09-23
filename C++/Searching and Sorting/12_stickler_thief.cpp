/*
Idea:
there are 2 options in a single element
-choose or not choose, if element is chosen, move the pointer 2 steps ahead, else only 1.
-using vector to store current max sum till that element
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Solution
{
public:
    int FindMaxSum(int arr[], int n)
    {
        if (n == 1)return arr[0]; // if array has only 1 element

        vector<int>dp(n, 0);
        dp[0] = arr[0];
        dp[1] = max(arr[0], arr[1]); // setting up max with first 2 elements.

        for (int i = 2; i < n; i++)
            dp[i] = max(dp[i - 1], dp[i - 2] + arr[i]);
        // 2 cases, if element is added or not.

        return dp[n - 1];
    }
};


int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while (t--)
    {
        //taking number of houses
        int n;
        cin >> n;
        int a[n];

        //inserting money of each house in the array
        for (int i = 0;i < n;++i)
            cin >> a[i];
        Solution ob;
        //calling function FindMaxSum()
        cout << ob.FindMaxSum(a, n) << endl;
    }
    return 0;
}
