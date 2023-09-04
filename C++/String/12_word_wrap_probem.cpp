/*
Idea:
Using recursion (on 2 conditions-inserting words in same row OR in next row)
& using Matrix to store state of each word insertion.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mat[501][2001]; // martrix to store state values
    int ReccFunction(int i, int remainder, vector<int>& arr, int& k)
    {
        if (i == arr.size()) // base case
            return 0;

        if (mat[i][remainder] != -1) // if case is already explored, return the value
            return mat[i][remainder];

        int ans;
        if (arr[i] > remainder)
            // if word can't be inserted into same line, inserting word in next line 
            ans = (remainder + 1) * (remainder + 1) + ReccFunction(i + 1, k - arr[i] - 1, arr, k);
        else
        {
            // if we can insert word in same line, here are 2 cases
            int choice1 = ReccFunction(i + 1, remainder - arr[i] - 1, arr, k); // if word is inserted in same line
            int choice2 = (remainder + 1) * (remainder + 1) + ReccFunction(i + 1, k - arr[i] - 1, arr, k); // if word is inserted in new line
            ans = min(choice1, choice2);
        }
        mat[i][remainder] = ans; // storing value calculated for future use
        return mat[i][remainder];
    }
    int solveWordWrap(vector<int>nums, int k)
    {
        memset(mat, -1, sizeof(mat));
        return ReccFunction(0, k, nums, k);
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
    }
    return 0;
}