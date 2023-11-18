/*
Idea:
Sorting the vector in increasing order, we iterate over all the coin pile sizes,
and for the rest of the piles if the pile size is less than the current size then remove that pile entirely
otherwise if the pile size is greater than current pile size plus K then remove the excess coins.
The minimum number of coins removed in any of the turns is the answer.
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int minSteps(int A[], int N, int K)
    {
        //Creating a vector to store the sorted values of array A.
        vector<int> a(N), p(N, 0);
        for (int i = 0; i < N; i++)
            a[i] = A[i];

        //Sorting the array in ascending order.
        sort(a.begin(), a.end());

        //Calculating the prefix sum of the sorted array.
        p[0] = a[0];
        for (int i = 1; i < N; i++)
            p[i] = p[i - 1] + a[i];

        //Initializing the minimum steps required as maximum integer value.
        int ans = INT_MAX, prev = 0;

        //Iterating through the array to find the minimum steps.
        for (int i = 0; i < N; i++)
        {
            //Finding the position of the element greater than a[i]+K using binary search.
            int pos = upper_bound(a.begin() + i, a.end(), a[i] + K) - a.begin();

            //Checking if a[i] is different from the previous element.
            if (i > 0 && a[i] != a[i - 1])
                prev = p[i - 1];

            //Updating the minimum steps value.
            ans = min(ans, prev + p[N - 1] - p[pos - 1] - (N - pos) * (a[i] + K));
        }
        //Returning the minimum steps required.
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        int A[N];
        for (int i = 0; i < N; i++)
            cin >> A[i];

        Solution ob;
        cout << ob.minSteps(A, N, K) << endl;
    }
    return 0;
}
// } Driver Code Ends