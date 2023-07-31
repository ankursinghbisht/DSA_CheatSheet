/*
Idea:
The idea is to increase the first i towers by k and decrease the rest tower by k after sorting the heights,
then calculate the maximum height difference.

Steps:
-sort the array
-Try to make each height of the tower maximum by decreasing the height of all the towers to the right by k
and increasing all the height of the towers to the left by k.
Check whether the current index tower has the maximum height or not by comparing it with a[n]-k.
If the tower’s height is greater than the a[n]-k then it’s the tallest tower available.
-find the shortest tower and minimize the difference between these two towers.
*/

#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    int getMinDiff(int arr[], int n, int k)
    {
        sort(arr, arr + n);
        int minVal = arr[0], maxVal = arr[n - 1], result = maxVal - minVal;
        // setting up minimum difference & current min and max values of towers.
        for (int i = 1;i < n;++i)
        {
            //iterating through each element, and checking if value is potisive or not
            if (arr[i] - k < 0)
                continue;

            // replacing min value with first element of array as reference & same with max value
            minVal = min(arr[0] + k, arr[i] - k);
            maxVal = max(arr[i - 1] + k, arr[n - 1] - k);

            result = min(result, maxVal - minVal);
        }
        return result;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}