/*
Idea:
The LPS is either of even length or odd length.
So the idea is to traverse the input string and for each character check
if this character can be the center of a palindromic substring of odd length or even length.
*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    string longestPalin(string s)
    {
        int n = s.length();
        int start = 0, end = 1;
        int low, high;

        // Traverse the input string
        for (int i = 0; i < n; i++)
        {
            // Find longest palindromic substring of even size
            low = i - 1;
            high = i;

            // Expand substring while it is palindrome and in bounds
            while (low >= 0 && high < n && s[low] == s[high])
            {
                // Update maximum length and starting index
                if (high - low + 1 > end)
                {
                    start = low;
                    end = high - low + 1;
                }
                low--;
                high++;
            }

            // Find longest palindromic substring of odd size
            low = i - 1;
            high = i + 1;

            // Expand substring while it is palindrome and in bounds
            while (low >= 0 && high < n && s[low] == s[high]) {
                // Update maximum length and starting index
                if (high - low + 1 > end)
                {
                    start = low;
                    end = high - low + 1;
                }
                low--;
                high++;
            }
        }
        return s.substr(start, end);
    }
};


int main()
{
    string S; cin >> S;

    int t; cin >> t;
    while (t--)
    {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.longestPalin(S) << endl;
    }
}