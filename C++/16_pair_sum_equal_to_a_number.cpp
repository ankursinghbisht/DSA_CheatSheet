/*
Idea:
using unordered map to store elements
& checking if any element (int the map) adds with current element to form value 'k'

Steps:
-iterating through array
-checking if any element with value (k-arr[i]) is present in the map, if any, adds total count to answer
-adding the current element in map
*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int getPairsCount(int arr[], int n, int k)
    {
        unordered_map<int, int> m;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            //iterating through each value, and checking if elements in dictionary adds to k
            if (m.find(k - arr[i]) != m.end()) {
                count += m[k - arr[i]];
            }
            //if value is not present in dictionary, insert one, else add one to it's count
            m[arr[i]]++;
        }
        return count;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }

    return 0;
}