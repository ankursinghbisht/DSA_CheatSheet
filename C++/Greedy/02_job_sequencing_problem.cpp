/*
Idea:
sorting the array in descending order of profit, and using list/vector to keep track of time slots
and updating the last possible time slot for a particular work's deadline.
*/

//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std;

// A structure to represent a job 
struct Job
{
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};


// } Driver Code Ends
bool compare(Job& a, Job& b)
{
    return a.profit > b.profit; // Sort in descending order of profit
}
class Solution
{
public:

    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n)
    {
        // your code here
        vector<int>ans(2, 0);
        sort(arr, arr + n, compare);

        int maxTime = 0;
        for (int i = 0;i < n;++i)
            maxTime = max(maxTime, arr[i].dead);

        vector<int>timeStamp(maxTime, -1);

        for (int i = 0;i < n;++i)
        {
            for (int j = arr[i].dead - 1;j >= 0;--j)
            {
                if (timeStamp[j] == -1)
                {
                    ++ans[0];
                    ans[1] += arr[i].profit;
                    timeStamp[j] = 0;
                    break;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
// Driver program to test methods 
int main()
{
    int t;
    //testcases
    cin >> t;

    while (t--) {
        int n;

        //size of array
        cin >> n;
        Job arr[n];

        //adding id, deadline, profit
        for (int i = 0;i < n;i++) {
            int x, y, z;
            cin >> x >> y >> z;
            arr[i].id = x;
            arr[i].dead = y;
            arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}



// } Driver Code Ends