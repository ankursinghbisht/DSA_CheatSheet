/*
Idea:
making a pair of end and start times, & sorting pairs basis on their end times.
Iterating the array of pairs, and choosing pairs whose start time is greater than last  selected pair's end time
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Create a vector of pairs to combine end and start times
        // The pair format is (end_time, start_time)
        std::vector<std::pair<int, int>> vc;
        for (int i = 0; i < n; ++i)
            vc.push_back({ end[i], start[i] });

        // Sort the vector of pairs based on end times in ascending order
        std::sort(vc.begin(), vc.end());

        // Initialize variables for counting meetings and tracking the ending time
        int count = 1;            // At least one meeting can be scheduled
        int ending = vc[0].first; // Ending time of the first meeting

        // Iterate through the sorted meetings
        for (int i = 1; i < n; ++i)
        {
            // If the start time of the current meeting is greater than the ending time
            // of the previous meeting, it can be scheduled, and update count and ending time
            if (vc[i].second > ending)
            {
                ++count;
                ending = vc[i].first;
            }
        }

        // Return the maximum number of non-overlapping meetings
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends