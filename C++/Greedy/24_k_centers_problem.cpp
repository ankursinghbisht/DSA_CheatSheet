/*
Idea:
Recursively exploring all combination of ATMs and combination with least max distance from an ATM.
*/

//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
public:
    void kCenterHelper(int k, int n, int& result, vector<int>& selected, vector<vector<int>>& mat)
    {
        if (k == 0)
        {
            // Find maximum distance of city from server.
            int maxDist = 0;
            for (int i = 0; i < n; i++)
            {
                int minDistServer = INT_MAX;
                for (int j = 0; j < selected.size(); j++)
                {
                    minDistServer = min(minDistServer, mat[i][selected[j]]);
                }
                maxDist = max(maxDist, minDistServer);
            }
            result = min(result, maxDist);
        }
        else
        {
            int prev = (selected.size() > 0) ? selected.back() : -1;
            for (int i = prev + 1; i < n; i++)
            {
                selected.push_back(i);

                // Recursively find ways of selecting remaining cities.
                kCenterHelper(k - 1, n, result, selected, mat);

                // Backtrack to explore possible way of selection without city 'i'.
                selected.pop_back();
            }
        }
    }

    int selectKcities(int n, int k, vector<vector<int>>& mat)
    {
        vector<int> selected;
        int result = INT_MAX;

        // Recursively try all possible way of selecting 'K' cities.
        kCenterHelper(k, n, result, selected, mat);

        return result;
    }
};


//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> mat(n, vector<int>(n));
        for (int i = 0;i < n;i++) {
            for (int j = 0;j < n;j++) {
                cin >> mat[i][j];
            }
        }

        Solution obj;
        int ans = obj.selectKcities(n, k, mat);

        cout << ans << endl;
    }
}
// } Driver Code Ends