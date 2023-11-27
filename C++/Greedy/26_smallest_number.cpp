/*
Idea:
from right to left forming the number. As smallest no. is required, filling rightmost numbers to min( N, 9),till N is 0
*/

//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution {
public:
    // Function to generate the smallest number with sum S and D digits
    std::string smallestNumber(int S, int D)
    {
        // Check if it's possible to form a number with the given sum and digits
        if (S > D * 9)
            return "-1"; // Not possible, return invalid result


        // Initialize the result string with D digits, all set to '0'
        std::string ans(D, '0');

        // Set the first digit to '1' and decrement the sum
        ans[0] = '1';
        --S;

        // Distribute the remaining sum to the digits
        for (int i = D - 1; i > 0; --i)
        {
            // Choose the smaller of S and 9 to set the digit
            int digit = std::min(S, 9);
            ans[i] = static_cast<char>('0' + digit);
            S -= digit;

            // If remaining sum is zero, exit the loop
            if (!S)
                break;
        }

        // If there's still a remaining sum after distributing, update the first digit
        if (S)
            ans[0] = static_cast<char>('0' + S + 1);

        return ans; // Return the generated smallest number
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int S, D;
        cin >> S >> D;
        Solution ob;
        cout << ob.smallestNumber(S, D) << endl;
    }
    return 0;
}
// } Driver Code Ends