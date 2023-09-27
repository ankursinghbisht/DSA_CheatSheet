/*
Idea:
Sorting the array of structure in descending order of profit.
Then finding which slot can be taken using sorted array, inserting the first element first
Counting all profits from the slots taken, & returning.
*/

#include<bits/stdc++.h>
using namespace std;

// A structure to represent a job 
struct Job
{
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};

class Solution
{
public:
    static bool comparison(Job a, Job b)
    {
        return (a.profit > b.profit);
    }

    vector<int> JobScheduling(Job arr[], int n)
    {
        int res = 0, count = 0;

        sort(arr, arr + n, comparison);

        //array to store result (Sequence of jobs). 
        int result[n];
        //boolean array to keep track of free time slots.
        bool slot[n];

        //initializing all slots to free.
        for (int i = 0; i < n; i++)
            slot[i] = false;

        //iterating through all given jobs.
        for (int i = 0; i < n; i++)
        {
            //finding a free slot for current job (Note that we start from the last possible slot). 
            for (int j = min(n, arr[i].dead) - 1; j >= 0; j--)
            {
                //if free slot is found, we add current job to result array and make the current slot occupied. 
                if (slot[j] == false)
                {
                    result[j] = i;
                    slot[j] = true;
                    break;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            //if slot is occupied, we update the counter and  add its profit in final result.
            if (slot[i]) {
                count++;
                res += arr[result[i]].profit;
            }
        }

        //storing the count of jobs and max profit in a list and returning it.
        vector<int> ans;
        ans.push_back(count);
        ans.push_back(res);
        return ans;
    }
};

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
