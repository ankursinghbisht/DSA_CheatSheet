/*
Idea:
using recursion to check all states for answers.
marking current location as visited (for not looping in same place) and after exploring all states ,
unmarking the current state.
*/

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
    vector <string> ans;
public:
    void solve(vector<vector<int>>& m, int n, int x, int y, string dir)
    {
        if (x == n || y == n || x < 0 || y < 0 || m[x][y] == 0)
            return;

        if (x == n - 1 && y == n - 1)
        {
            ans.push_back(dir);
            return;
        }

        int temp = m[x][y]; // storing value of current state
        m[x][y] = 0; // marking it as visited

        solve(m, n, x + 1, y, dir + "D");
        solve(m, n, x - 1, y, dir + "U");
        solve(m, n, x, y + 1, dir + "R");
        solve(m, n, x, y - 1, dir + "L");

        m[x][y] = temp; // reseting the value of state
    }
    vector<string> findPath(vector<vector<int>>& m, int n)
    {
        string dir = "";
        solve(m, n, 0, 0, dir);
        return ans;
    }
};




//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends