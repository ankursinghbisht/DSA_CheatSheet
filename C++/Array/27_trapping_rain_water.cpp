/*
IDea:
Iterating through each element, and finding max elements in both directions & storing in arrays
Now, total water collected will be water stored at each index.
So, using max values, selecting min & subtracting height of that index to find water there.
*/

#include<bits/stdc++.h>
using namespace std;


class Solution {

public:
    long long trappingWater(int arr[], int n)
    {
        long long total = 0;
        //setting up arrays to store max in both directions at each index
        int left_max[n], right_max[n];

        left_max[0] = arr[0];
        for (int i = 1; i < n; ++i) {
            // iterating left to right to find max 
            left_max[i] = max(left_max[i - 1], arr[i]);
        }

        right_max[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            \
                //iterating right to left to find max 
                right_max[i] = max(right_max[i + 1], arr[i]);
        }

        for (int i = 0; i < n; ++i)
        {
            // adding water at that index to total
            total += max(0, min(left_max[i], right_max[i]) - arr[i]);
        }
        return total;
    }

};


int main()
{

    // int t;
    // //testcases
    // cin >> t;

    // while (t--) {
    //     int n;

    //     //size of array
    //     cin >> n;

    //     int a[n];

    //     //adding elements to the array
    //     for (int i = 0;i < n;i++) {
    //         cin >> a[i];
    //     }
    //     Solution obj;
    //     //calling trappingWater() function
    //     cout << obj.trappingWater(a, n) << endl;

    // }
    int a[] = { 7,4,0,9 };
    Solution ob;
    cout << ob.trappingWater(a, 4);
    return 0;
}