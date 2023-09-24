/*
Idea: (Using idea of having prefix sum array)
Using map to keep track of the cumulative sum of elements encountered so far and their frequencies.
incrementing  a count var- whenever the current cumulative sum matches a previous sum encountered,
effectively counting subarrays that sum to zero.
*/


#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

    long long findSubarray(vector<long long > arr, int n)
    {
        unordered_map<long long, long long > mp;

        long long  sum = 0;
        long long  count = 0;
        for (int i = 0;i < n;i++)
        {
            sum += arr[i];
            if (sum == 0) count++;

            // If the current cumulative sum has been seen before, it means there is a subarray
            // from a previous point to the current point that sums to 0.
            if (mp.find(sum) != mp.end())
                count += mp[sum];

            mp[sum]++;
        }

        return count;
    }
};


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n; //input size of array

        vector<long long int> arr(n, 0);

        for (int i = 0;i < n;i++)
            cin >> arr[i]; //input array elements
        Solution ob;
        cout << ob.findSubarray(arr, n) << "\n";
    }
    return 0;
}