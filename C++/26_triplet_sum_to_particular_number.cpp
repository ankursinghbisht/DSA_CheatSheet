/*
Idea:
(while using map)
Iterating through each element, (assuming it being 1st element of 3sum)
-using loop after that element till array's end.
-checking if any element with value (k-arr[i]) is present in the map, if any, adds total count to answer
-adding the current element in map

(while using sorting)
-sorting the array
-iterating through the array, (assuming it being 1st element of 3sum)
-using another loop from i+1 to n-1
-checking if 2 pointers sum to ans
*/
#include <bits/stdc++.h>
using namespace std;


bool find3Numbers_usingMap(int arr[], int n, int X)
{
    for (int i = 0;i < n;++i)
    {
        map <int, int> nums;
        int sum = X - arr[i];
        for (int j = i + 1;j < n;++j)
            // iterating through each value, and checking if elements in dictionary adds to k
            if (nums.find(sum - arr[j]) != nums.end())
                return true;
            else
                //if value is not present in dictionary, insert one, else add one to it's count
                nums[arr[j]]++;
    }
    return false;
}

bool find3Numbers_usingSort(int arr[], int n, int X)
{
    sort(arr, arr + n);

    for (int i = 0;i < n;++i)
    {
        int front = i + 1, back = n - 1;
        while (front < back)
        {
            //if triplet found, return
            if (arr[front] + arr[back] == X - arr[i])
                return true;

            else if (arr[front] + arr[back] > X - arr[i])
                //if sum>ans, move pointer to front
                --back;
            else
                //If sum<ans, move pointer to the back
                ++front;

        }
        return false;
    }
}

int main()
{
    // int T;
    // cin >> T;
    // while (T--)
    // {
    //     int n, X;
    //     cin >> n >> X;
    //     int i, A[n];
    //     for (i = 0;i < n;i++)
    //         cin >> A[i];
    //     cout << find3Numbers_usingMap(A, n, X) << endl;
    // }

    int arr[] = { 1,2,2,1 };
    cout << find3Numbers_usingSort(arr, 4, 3);
}
