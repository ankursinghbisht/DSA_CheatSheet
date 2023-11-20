/*
Idea:
sorting both arrival and departure time in increasing order.
Total platforms at any time can be obtained by subtracting total departures from total arrivals by that time.
*/

//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        //sorting both arrival and departure time in sorted order
        sort(arr, arr + n);
        sort(dep, dep + n);

        int i = 0, j = 0, ans = 0, count = 0;

        while (i < n && j < n)
        {
            if (arr[i] <= dep[j])// if arrival time is smaller , i.e. train is arriving, ( we need a platform )
            {
                ++count;
                ++i;
            }
            else // if departure time is smaller, i.e train is leaving, ( we don't need a platform )
            {
                ++j;
                --count;
            }
            ans = max(count, ans);// keeping track of max platform required
        }
        return ans;

    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        int dep[n];
        for (int i = 0;i < n;i++)
            cin >> arr[i];
        for (int j = 0;j < n;j++) {
            cin >> dep[j];
        }
        Solution ob;
        cout << ob.findPlatform(arr, dep, n) << endl;
    }
    return 0;
}
// } Driver Code Ends