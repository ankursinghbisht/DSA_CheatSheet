/*
Idea:
( each digit is at 1st place only k/(n-1)! times) , placing each digit at a time and Recursively call the function to find the remaining digits

*/

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    //Function to solve for kth permutation.
    string solve(int n, int k, vector<int>& fact, vector<int>& nums)
    {
        //Base case, if n becomes 0, return empty string.
        if (n == 0)
            return "";

        //Calculating the number of sets in which the first digit can be placed.
        int c = k / fact[n - 1] + 1;

        //Creating an empty string to store the kth permutation.
        string str = "";
        for (int i = 0; i < nums.size(); i++)
        {
            //If the current number is not used in the permutation.
            c -= (nums[i] == 0);

            //If we found the number to be placed at the current position.
            if (c == 0 && nums[i] == 0)
            {
                //Marking the current number as used and adding it to the string.
                nums[i] = 1;
                str += to_string(i + 1);
                break;
            }
        }

        //Recursively finding the remaining digits in the kth permutation.
        return str + solve(n - 1, k % fact[n - 1], fact, nums);
    }

    //Function to find the kth permutation.
    string kthPermutation(int n, int k)
    {
        //Calculating the factorial of numbers from 1 to n.
        vector<int> fact(n + 1, 1);
        for (int i = 1; i <= n; i++)
            fact[i] = i * fact[i - 1];

        //Creating a vector to keep track of used numbers in the permutation.
        vector<int> nums(n, 0);

        //Calling the solve function to find the kth permutation.
        string s = solve(n, k - 1, fact, nums);

        //Returning the kth permutation.
        return s;
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
        Solution ob;
        string ans = ob.kthPermutation(n, k);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends