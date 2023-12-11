/*
Using 2 loops:one from left to right & other from right to left.
if left==right, setting answer to twice of left or right.
and resetting left and right if left> right on 1st traversal and on left<right on 2nd traversal
*/

//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for c++
class Solution {
public:
    int findMaxLen(string s)
    {
        int n = s.size();

        // Variables for left and right counter. maxlength to store the maximum length found so far
        int left = 0, right = 0, maxlength = 0;

        // Iterating the string from left to right
        for (int i = 0; i < n; ++i)
        {
            // If "(" is encountered, then left counter is incremented else right counter is incremented
            if (s[i] == '(')
                left++;
            else
                right++;

            // Whenever left is equal to right, it signifies that the subsequence is valid and
            if (left == right)
                maxlength = max(maxlength, 2 * right);

            // Reseting the counters when the subsequence becomes invalid
            else if (right > left)
                left = right = 0;
        }

        left = right = 0;

        // Iterating the string from right to left
        for (int i = n - 1; i >= 0; --i)
        {
            // If "(" is encountered, then left counter is incremented else right counter is incremented
            if (s[i] == '(')
                left++;
            else
                right++;

            // Whenever left is equal to right, it signifies that the subsequence is valid and
            if (left == right)
                maxlength = max(maxlength, 2 * left);

            // Reseting the counters when the subsequence becomes invalid
            else if (left > right)
                left = right = 0;
        }
        return maxlength;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}

// } Driver Code Ends