/*
Idea:
using priority queue as MinHeap,storing all ropes, and updating PQ after joining of 2 ropes
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n)
    {
        //implementing MinHeap using priority queue.
        priority_queue<long long, vector<long long>, greater<long long> > pq(
            arr, arr + n);

        long long res = 0;

        //using a loop while there is more than one element in priority queue.
        while (pq.size() > 1)
        {
            //storing the first and second numbers from priority queue.
            long long first = pq.top();
            pq.pop();
            long long second = pq.top();
            pq.pop();

            //adding their sum in result.
            res += first + second;

            //pushing the sum of first and second numbers in priority queue.
            pq.push(first + second);
        }
        //returning the result.
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends