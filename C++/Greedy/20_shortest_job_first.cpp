/*
Idea:
Loop till all processes are complete.
 use another loop to keep track of nodes with the shortest burst time that has arrived and not yet completed,
keep track of waiting & turnaround time of each process, and return average.
*/

//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

//Back-end complete function Template for C++

class Solution {
public:
    // Function to round a double to two decimal places
    double round(double var)
    {
        double value = (int)(var * 100 + .5);
        return (double)value / 100;
    }

    // Function to calculate average waiting time and average turnaround time
    vector<double> averageTimes(vector<int> arrivalTime, vector<int> burstTime, int n)
    {
        vector<int> completionTime(n);
        vector<int> turnAroundTime(n);
        vector<int> waitingTime(n);
        vector<int> completed(n);

        int systemTime = 0, totalProcesses = 0;
        double avgwaitingTime = 0, avgturnAroundTime = 0;

        // Initializing all processes as undone
        for (int i = 0; i < n; i++)
            completed[i] = 0;


        // Until all processes are done
        while (totalProcesses != n)
        {
            int check = n, min = INT_MAX;

            for (int i = 0; i < n; i++)
            {
                /*
                    If the process arrival time is less than the system time and it is not completed
                    and burstTime is smallest of this process, this process will be executed first
                */
                if ((arrivalTime[i] <= systemTime) and (completed[i] == 0) and (burstTime[i] < min))
                {
                    min = burstTime[i];
                    check = i;
                }
            }

            // No process in the queue.
            if (check == n)
            {
                systemTime++;
            }
            else
            {
                completionTime[check] = systemTime + burstTime[check];
                systemTime += burstTime[check];
                turnAroundTime[check] = completionTime[check] - arrivalTime[check];
                waitingTime[check] = turnAroundTime[check] - burstTime[check];
                completed[check] = 1;
                totalProcesses++;
            }
        }

        // Sum for calculating averages
        for (int i = 0; i < n; i++) {
            avgwaitingTime += waitingTime[i];
            avgturnAroundTime += turnAroundTime[i];
        }

        vector<double> ans(2);

        ans[0] = (double)(avgwaitingTime / n);
        ans[1] = (double)(avgturnAroundTime / n);

        double res1 = round(ans[0]);
        double res2 = round(ans[1]);
        return { res1, res2 };
    }
};



//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int>arrivalTime(n), burstTime(n);
        for (int i = 0; i < n; i++) {
            cin >> arrivalTime[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> burstTime[i];
        }
        Solution ob;
        vector<double> ans = ob.averageTimes(arrivalTime, burstTime, n);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends