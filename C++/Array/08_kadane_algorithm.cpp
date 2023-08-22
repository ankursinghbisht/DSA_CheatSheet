/*
Idea:
set max and temp sum variable, set max to temp, if temp>max
& set temp=0 if temp goes below 0
*/

#include<bits/stdc++.h>
using namespace std;

int maxSubArray(int* arr, int len)
{
    int maxValue = INT_MIN, tempSum = 0;

    for (int i = 0;i < len;++i)
    {
        tempSum += arr[i];

        if (maxValue < tempSum)
            maxValue = tempSum;

        if (tempSum < 0)
            tempSum = 0;
    }
    return maxValue;
}

int main()
{
    int arr[] = { -2, -3, 4, -1, -2, 1, 5, -3 };
    int size = sizeof(arr) / sizeof(arr[0]);
    int ans = maxSubArray(arr, size);
    cout << ans;
    return 0;
}