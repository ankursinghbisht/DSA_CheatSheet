/*
Idea:
each overlapping case pair will have 2nd number greater than 1st number of other pair,
choosing other 2 elements as border elements will be the answer.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals)
    {
        //sorting the pairs for easy traversal
        sort(intervals.begin(), intervals.end());
        vector<vector<int>>ans;
        for (auto interval : intervals)
        {
            //checking if last element is smaller or not
            if (ans.empty() || ans.back()[1] < interval[0])
                ans.push_back(interval);
            else
                ans.back()[1] = max(ans.back()[1], interval[1]);
        }
        return ans;
    }
};

int main()
{
    int T, x, y, n;
    cin >> T;



    while (T--)
    {
        vector<vector<int>>nums;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> x >> y;
            vectorOfVectors.push_back({ x, y });
        }
        Solution obj;
        cout << obj.mergeIntervals(nums) << endl;
    }
}