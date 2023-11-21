/*
Idea:
sorting candies in increasing order, and calculating total candies to buy,
taking sum from start and end as answer
*/


//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        sort(candies, candies + N);

        int candies_to_buy = ceil((N + K) / (K + 1));// finding min candies to buy 

        int minCost = 0, maxCost = 0;


        for (int i = 0;i < N;++i) // finding min and max cost to buy candies required
        {
            if (candies_to_buy--)
            {
                minCost += candies[i];
                maxCost += candies[N - i - 1];
            }
            else
                break;
        }
        vector<int>ans = { minCost, maxCost };
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
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends