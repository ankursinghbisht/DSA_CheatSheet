/*
Idea:
Sorting array in ascending order.
using one element from last and one from front, adding the difference to answer,
using 2 pointers-one from start and one from end.
*/

#include <bits/stdc++.h>
using namespace std;

// Function to find the maximum sum of absolute differences of array elements
long long int maxSum(int arr[], int n)
{
    // Sorting the array in non-decreasing order
    sort(arr, arr + n);

    // Initialize two pointers i and j at the two ends of the sorted array
    int i = 0, j = n - 1;

    // 'off' variable is used to alternate between incrementing i and decrementing j
    bool off = true;

    // Initialize the sum variable to store the maximum sum of absolute differences
    long long int sum = 0;

    // Loop until i and j cross each other
    while (i < j)
    {
        // Add the absolute difference of arr[i] and arr[j] to the sum
        sum += abs(arr[i] - arr[j]);

        // If 'off' is false, decrement j; otherwise, increment i
        if (!off)
            j--;
        else
            i++;

        // Toggle the 'off' variable
        off = !off;
    }

    // Add the absolute difference of arr[i] and arr[0] to the sum
    sum += abs(arr[i] - arr[0]);

    // Return the maximum sum of absolute differences
    return sum;
}

// Driver function
int main()
{
    int a[] = { 1, 2, 4, 8 };
    int n = sizeof(a) / sizeof(a[0]);

    cout << maxSum(a, n) << endl;
}
