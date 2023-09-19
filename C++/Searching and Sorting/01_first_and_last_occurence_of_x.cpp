/*
Idea:
Using Modified binary search, finding 1st & last occurence of a number
*/


#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
    int findLeft(int arr[], int n, int x)
    {
        int low = 0, high = n - 1, result = -1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (arr[mid] == x)
            {
                result = mid;
                high = mid - 1; //  Look in the left subarray for the first occurrence
            }
            else if (arr[mid] < x)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return result;
    }

    int findRight(int arr[], int n, int x)
    {
        int low = 0, high = n - 1, result = -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (arr[mid] == x)
            {
                result = mid;
                low = mid + 1; //  Look in the right subarray for the last occurrence
            }
            else if (arr[mid] < x)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return result;
    }
    vector<int> find(int arr[], int n, int x)
    {
        vector<int>ans;
        ans.push_back(findLeft(arr, n, x));
        ans.push_back(findRight(arr, n, x));
        return ans;
    }
};



int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int arr[n], i;
        for (i = 0;i < n;i++)
            cin >> arr[i];
        vector<int> ans;
        Solution ob;
        ans = ob.find(arr, n, x);
        cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}


