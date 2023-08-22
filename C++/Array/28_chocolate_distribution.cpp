/*
Idea:
sorting & finding subarray which has the least difference between first & last element.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long findMinDiff(vector<long long> arr, long long n, long long m)
    {
        long long temp, ans = INT_MAX;
        sort(arr.begin(), arr.end());
        for (int i = 0;i < n - m;++i)
        {
            //calculating the difference between first & last element of subarray
            temp = arr[i + m - 1] - arr[i];
            ans = min(temp, ans);
        }
        return ans;
    }
};

int main() {
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        vector<long long> a;
        long long x;
        for (long long i = 0;i < n;i++)
        {
            cin >> x;
            a.push_back(x);
        }

        long long m;
        cin >> m;
        Solution ob;
        cout << ob.findMinDiff(a, n, m) << endl;
    }
    return 0;
}