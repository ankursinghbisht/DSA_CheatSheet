/*
Idea:
setup base case where if supply is less than demand, return -1.
else count days to buy to reach end goal
*/

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int minimumDays(int S, int N, int M)
    {
        // If we can not buy at least a week supply of food during the first week
        // OR We can not buy a day supply of food  on the first day then we can't survive.
        if (((N * 6) < (M * 7) && S > 6) || M > N)
            return -1;
        else
        {
            // If we can survive then we can buy ceil(A/N) times where A is total units of food required.
            int days = (M * S) / N;
            if (((M * S) % N) != 0)
                days++;
            return days;
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int S, N, M;
        cin >> S >> N >> M;

        Solution ob;
        cout << ob.minimumDays(S, N, M) << endl;
    }
    return 0;
}
// } Driver Code Ends