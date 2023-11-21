/*
Idea:
1. Store amount of all persons to be settled in a set. If a person is in debt his amount will be negative else +ve.

2. Traverse until only 1 person is left to be settled.

3. Begin of set will be debit guy and end will be credit guy.

4. If debt is less then settle debit guy. Compute new credit by adding debit and store in set.

5. Else settle credit guy and compute new debit by adding credit and store in set.

6. Remember debit is -ve therefore adding credit will reduce debt. Similarly adding debt to credit will reduce credit.

*/


//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    struct cmp
    {
        bool operator()(pair<int, int> a, pair<int, int> b) const
        {
            if (a.first == b.first)
            {
                if (a.first < 0 && b.first < 0)
                    return a.second < b.second;
                return a.second > b.second;
            }
            return a.first < b.first;
        }
    };
    vector<vector<int>> minCashFlow(vector<vector<int>>& ts, int n)
    {
        set <pair<int, int>, cmp> s; // store amount of person i to be settled
        for (int i = 0;i < n;i++)
        {
            int a = 0;
            for (int j = 0;j < n;j++)
                a += ts[j][i] - ts[i][j];
            if (a) s.insert({ a,i }); // if amount to settle is not 0
        }
        vector <vector<int>> ans(n, vector<int>(n));

        while (s.size() > 1)
        {
            auto debit = s.begin(), credit = s.end(); // as debit will be -ve and credit will be +ve
            credit--;
            int ad = debit->first, ac = credit->first;
            int from = debit->second, to = credit->second;
            s.erase(debit);
            s.erase(credit);

            if (-ad <= ac)
            { // amount debit is less
                ans[from][to] = -ad; // settle debit
                ac += ad; // new amount of credit person
                if (ac) s.insert({ ac,to });
            }
            else
            { // amount credit is less
                ans[from][to] = ac; // settle credit
                ad += ac; // new amount of debit person
                if (ad) s.insert({ ad,from });
            }
        }
        return ans;
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
        vector<vector<int>> g(n, vector<int>(n));
        for (int i = 0;i < n;i++)
        {
            for (int j = 0;j < n;j++)
                cin >> g[i][j];
        }
        Solution s;
        vector<vector<int>> r = s.minCashFlow(g, n);
        for (auto j : r)
        {
            for (auto i : j)
                cout << i << " ";
            cout << endl;
        }
        // cout<<endl;
    }
    return 0;
}
// } Driver Code Ends