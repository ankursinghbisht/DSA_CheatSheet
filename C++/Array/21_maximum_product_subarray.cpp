/*
Idea:
calculating product from first to last at each element & storing max value
,performing above step in both direction.
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    // Function to find maximum product subarray
    long long maxProduct(vector<int> arr, int n)
    {
        long long ans = INT_MIN, temp = 1;

        // Traverse the array from left to right
        for (int i = 0; i < n; ++i) {
            temp *= arr[i]; // Accumulate the product
            if (ans < temp)
                ans = temp; // Update the maximum product if needed
            if (temp == 0)
                temp = 1; // Reset temp if encountered zero
        }

        temp = 1; // Reset temp

        // Traverse the array from right to left
        for (int i = n - 1; i >= 0; --i) {
            temp *= arr[i]; // Accumulate the product
            if (ans < temp)
                ans = temp; // Update the maximum product if needed
            if (temp == 0)
                temp = 1; // Reset temp if encountered zero
        }
        return ans;
    }

};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}