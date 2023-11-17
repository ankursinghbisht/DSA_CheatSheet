/*
Idea:
-Perform DFS from appropriate houses to find all different connected components.
The number of different connected components is our answer t.

-The next t lines of the output are the beginning of the connected component,
end of the connected component and the minimum diameter from the start to the end of the connected component in each line.

-Since, tanks can be installed only on the houses having outgoing pipe and no incoming pipe,
therefore these are appropriate houses to start DFS from i.e. perform DFS from such unvisited houses.
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:

    // number of houses and numberof pipes
    int n, p;
    // Array rd stores the ending vertex of pipe
    vector<int> rd;
    // Array wd stores the value of diameters between two pipes
    vector<int> wt;
    // Array cd stores the starting end of pipe
    vector<int> cd;
    int ans;

    int dfs(int w)
    {
        if (cd[w] == 0)
            return w;
        if (wt[w] < ans)
            ans = wt[w];
        return dfs(cd[w]);
    }

    vector<vector<int>> solve(int n, int p, vector<int> a, vector<int> b, vector<int> d)
    {
        this->n = n;
        this->p = p;
        rd = vector<int>(n + 1);
        wt = vector<int>(n + 1);
        cd = vector<int>(n + 1);
        vector<vector<int>> res;

        int i = 0;

        while (i < p)
        {

            int q = a[i], h = b[i],
                t = d[i];

            cd[q] = h;
            wt[q] = t;
            rd[h] = q;
            i++;
        }


        for (int j = 1; j <= n; ++j)

            //If a pipe has no ending vertex but has starting vertex i.e is an outgoing pipe then we need to start DFS with this vertex.
            if (rd[j] == 0 && cd[j]) {
                ans = 1000000000;
                int w = dfs(j);

                // We put the details of component in final output res array

                res.push_back({ j,w,ans });
            }

        return res;
    }
};


//{ Driver Code Starts.
int main()
{
    int t, n, p;
    cin >> t;
    while (t--)
    {
        cin >> n >> p;
        vector<int> a(p), b(p), d(p);
        for (int i = 0;i < p;i++) {
            cin >> a[i] >> b[i] >> d[i];
        }
        Solution obj;
        vector<vector<int>> answer = obj.solve(n, p, a, b, d);
        cout << answer.size() << endl;
        for (auto i : answer)
        {
            cout << i[0] << " " << i[1] << " " << i[2] << endl;
        }

    }
    return 0;
}
// } Driver Code Ends