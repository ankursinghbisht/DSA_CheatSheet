/*
Idea:
sorting intervals in descending order of start time & inserting in a stack.
Taking 2 top elements and merging (if required) & inserting in stack.
*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals)
    {
        vector<vector<int>>ans;
        sort(intervals.begin(), intervals.end());
        reverse(intervals.begin(), intervals.end());

        stack<vector<int>>s;
        for (auto it : intervals)
            s.push(it);

        while (s.size() > 1)
        {
            vector<int>t1 = s.top();
            s.pop();
            vector<int>t2 = s.top();
            s.pop();

            // Check for overlapping intervals
            if (t1[1] >= t2[0])
            {
                // Merge overlapping intervals
                vector<int> temp = { t1[0], max(t2[1], t1[1]) };
                s.push(temp);
            }
            else
            {
                // No overlap, add t1 to the result and push back t2 for further comparisons
                ans.push_back(t1);
                s.push(t2);
            }
        }

        ans.push_back(s.top());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>>Intervals(n);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            Intervals[i].push_back(x);
            Intervals[i].push_back(y);
        }
        Solution obj;
        vector<vector<int>> ans = obj.overlappedInterval(Intervals);
        for (auto i : ans) {
            for (auto j : i) {
                cout << j << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends