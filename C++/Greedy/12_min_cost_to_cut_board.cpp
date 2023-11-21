/*
Idea: (to cut board on edges with the highest cost.)
-sorting cost in ascending order , keeping track of cuts .adding cost from highest to lowest
*/

//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int minimumCostOfBreaking(vector<int> X, vector<int> Y, int M, int N)
    {
        //sorting both vectors in ascending order of edge cut cost
        sort(X.begin(), X.end());
        sort(Y.begin(), Y.end());

        int horizontalParts = 1, verticalParts = 1; // keeping track of part cut horizontally/ vertically
        int  i = X.size() - 1, j = Y.size() - 1, cost = 0;

        while (i >= 0 && j >= 0)

            if (X[i] >= Y[j])
            {
                horizontalParts++; // incrementing horizontal parts after it's cut horizontally
                cost += verticalParts * X[i--];
            }
            else
            {
                verticalParts++; // incrementing vertical parts after it's cut vertically
                cost += horizontalParts * Y[j--];
            }

        // adding cost of cutting remaning parts
        while (i >= 0)
            cost += verticalParts * X[i--];

        while (j >= 0)
            cost += horizontalParts * Y[j--];

        return cost;
    }
};



//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;
        vector<int>X(m - 1), Y(n - 1);
        for (int i = 0; i < m - 1; i++) {
            cin >> X[i];
        }
        for (int i = 0; i < n - 1; i++) {
            cin >> Y[i];
        }
        Solution ob;
        int ans = ob.minimumCostOfBreaking(X, Y, m, n);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends