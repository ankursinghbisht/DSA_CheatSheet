/*
Idea:
using for loop to iterate over each col of matrix of words,
and using recursion for each row
*/



#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    void solve(vector<vector<string>>& list, vector<vector<string>>& ans, int rowVal, string temp)
    {
        if (rowVal == list.size())// base case
        {
            temp.erase(temp.size() - 1);
            vector<string>t = { temp };
            ans.push_back(t);
            return;
        }

        int col = list[0].size();
        for (int i = 0;i < col;++i)
            solve(list, ans, rowVal + 1, temp + list[rowVal][i] + " ");
        // trying each word in a row and calling the function again

    }
    vector<vector<string>> sentences(vector<vector<string>>& list)
    {
        int row = list.size();
        vector<vector<string>>ans;
        solve(list, ans, 0, "");
        return ans;
    }
};



int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;
        vector<vector<string>>list(m, vector<string>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> list[i][j];
            }
        }
        Solution ob;
        vector<vector<string>>ans = ob.sentences(list);
        for (auto it : ans) {
            for (auto it1 : it) {
                cout << it1 << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
