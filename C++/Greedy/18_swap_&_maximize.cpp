/*
Idea:
sorting array in ascending order, and using 2 pointer, from each end.
adding the difference between each pair of pointer values, (in case of odd length: adding remaining element)
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
long long int maxSum(int arr[], int n);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0;i < n;++i)
            cin >> arr[i];
        cout << maxSum(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends


long long int maxSum(int arr[], int n) {
    // Sort the array in ascending order
    sort(arr, arr + n);

    // Initialize variables
    int i = 0, j = n - 1, ans = 0;
    bool flag = true;

    // Iterate through the array
    while (i < j) {
        // If the flag is true, add the absolute difference between the last and first elements
        if (flag)
            ans += (arr[j] - arr[i++]);
        else
            // If the flag is false, add the absolute difference between the last and first elements
            ans += (arr[j--] - arr[i]);

        // Toggle the flag for the next iteration
        flag = !flag;
    }

    // If the array has an odd length, add the remaining element
    if (i == j)
        ans += arr[i] - arr[0];

    // Return the maximum sum
    return ans;
}