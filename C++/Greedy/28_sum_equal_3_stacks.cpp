/*
Idea:
summing all stacks individually, and removing elements till sums are equal
*/

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    // Function to find the maximum equal sum from three vectors
    int maxEqualSum(int N1, int N2, int N3, vector<int>& S1, vector<int>& S2, vector<int>& S3)
    {
        // Calculate the initial sum of each vector
        int sum1 = accumulate(S1.begin(), S1.end(), 0);
        int sum2 = accumulate(S2.begin(), S2.end(), 0);
        int sum3 = accumulate(S3.begin(), S3.end(), 0);

        // Initialize indices for each vector
        int i = 0, j = 0, k = 0;

        // Continue until one of the vectors is exhausted
        while (i < N1 && j < N2 && k < N3)
        {
            // If the sums of all three vectors are equal, return the sum
            if (sum1 == sum2 && sum2 == sum3)
                return sum1;

            // Update the sum of the vector with the maximum sum
            if (sum1 >= sum2 && sum1 >= sum3)
                sum1 -= S1[i++];
            else if (sum2 >= sum1 && sum2 >= sum3)
                sum2 -= S2[j++];
            else if (sum3 >= sum1 && sum3 >= sum2)
                sum3 -= S3[k++];
        }

        return 0; // Return 0 if no equal sum is found
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n1, n2, n3;
        cin >> n1 >> n2 >> n3;
        vector<int> s1(n1), s2(n2), s3(n3);
        for (int i = 0;i < n1;i++) {
            cin >> s1[i];
        }
        for (int i = 0;i < n2;i++) {
            cin >> s2[i];
        }
        for (int i = 0;i < n3;i++) {
            cin >> s3[i];
        }
        Solution ob;
        int ans = ob.maxEqualSum(n1, n2, n3, s1, s2, s3);
        cout << ans << endl;
    }

    return 0;
}
// } Driver Code Ends