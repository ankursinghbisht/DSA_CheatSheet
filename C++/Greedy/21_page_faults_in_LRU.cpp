/*
Idea:
using list/vector to simulate cache. iterating the array and counting total page faults with inserting new pages.
*/

//{ Driver Code Starts
// Initial Template for C++



#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int pageFaults(int N, int C, int pages[])
    {
        int pageFaultCount = 0;  // Counter for page faults
        vector<int> cache;  // Vector to simulate the cache

        for (int i = 0; i < N; i++)
        {
            // Check if the page is present in the cache
            auto cacheIterator = find(cache.begin(), cache.end(), pages[i]);

            // Page fault
            if (cacheIterator == cache.end())
            {
                pageFaultCount++;

                // If the cache is full, remove the page at the front
                if (cache.size() == C)
                    cache.erase(cache.begin());

                // Add the new page to the end of the cache
                cache.push_back(pages[i]);
            }
            else
            {
                // If the page is present, move it to the end of the cache
                cache.erase(cacheIterator);
                cache.push_back(pages[i]);
            }
        }

        return pageFaultCount;  // Return the total number of page faults
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, C;
        cin >> N;
        int pages[N];
        for (int i = 0;i < N;i++)
            cin >> pages[i];
        cin >> C;

        Solution ob;
        cout << ob.pageFaults(N, C, pages) << "\n";
    }
    return 0;
}
// } Driver Code Ends