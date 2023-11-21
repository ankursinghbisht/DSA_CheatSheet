/*
Idea:
sorting prices in increasing order , along with their buy limit, counting all stocks available till money is left.
*/

//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int buyMaximumProducts(int n, int k, int price[])
    {
        vector<pair<int, int>>stocks;
        for (int i = 0;i < n;++i) // making vector pair to store prices and buy limit
            stocks.push_back({ price[i],i + 1 });

        sort(stocks.begin(), stocks.end()); // sorting

        int count = 0, sum = 0;
        for (auto it : stocks)
        {
            if (sum + it.second * it.first <= k) // if buy limit is lower than budget, counting all stocks as ans
            {
                count += it.second;
                sum += it.second * it.first;
            }
            else                                // else, finding total stocks available in budget
            {
                count += (k - sum) / it.first;
                break;
            }
        }
        return count;
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int price[n];
        for (int i = 0; i < n; i++) {
            cin >> price[i];
        }
        Solution ob;
        int ans = ob.buyMaximumProducts(n, k, price);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends