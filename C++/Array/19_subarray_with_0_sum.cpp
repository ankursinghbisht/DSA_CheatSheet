/*
Idea:
Iterating through each element of array & calculate Sum of each element
If number is 0 or is seen before, it means there exists a subarray with 0 sum.
*/


#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    bool subArrayExists(int arr[], int n)
    {
        //using set to find if there are 2 sums equal.
        unordered_set <int> sumSet;
        int sum = 0;
        for (int i = 0;i < n;++i)
        {
            //iterating through each element & finding if sum is seen before
            sum += arr[i];
            if (sum == 0 || sumSet.find(sum) != sumSet.end())
                return true;
            sumSet.insert(sum);
        }
        return false;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0;i < n;i++)
            cin >> arr[i];
        Solution obj;
        if (obj.subArrayExists(arr, n))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}