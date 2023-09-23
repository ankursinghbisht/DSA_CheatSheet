/*
Idea:
Using static pointer 'i' for one element, and 2 variable pointers'low & high' for rest elements to count sum
If sum of 3 elements >= desired sum, decrease the high pointer, else increase count var
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long countTriplets(long long arr[], int n, long long sum)
    {
        int count = 0, low, high;
        sort(arr, arr + n);
        for (int i = 0;i < n - 2;++i)
        {
            // setting up 2 pointers to access rest 2 elements
            low = i + 1, high = n - 1;
            while (low < high)
                if (arr[i] + arr[low] + arr[high] >= sum)
                    // if sum> desired sum, decrease high pointer
                    high--;
                else
                {
                    //increasing count var as all elements below high will fulfill the condition
                    count += high - low;
                    low++;
                }
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
        long long sum;
        cin >> n >> sum;
        long long arr[n];
        for (int i = 0;i < n;i++) {
            cin >> arr[i];
        }
        Solution ob;
        cout << ob.countTriplets(arr, n, sum);
        cout << "\n";

    }
    return 0;
}
