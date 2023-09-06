/*
Idea:
keeping track of opening and closing brackets, if closing exceeds opening, reverse it, and update values
*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev(string s);
int main()
{
    int t = 1; //cin >> t;
    while (t--)
    {
        string s = "}{{}}{{{"; //cin >> s;
        cout << countRev(s) << '\n';
    }
}


int countReversals(string s) {
    int n = s.size();
    int opening = 0, closing = 0, ans = 0;

    // If the string length is odd, it can't be balanced
    if (n % 2 != 0)
        return -1;

    for (int i = 0; i < n; ++i) {
        if (s[i] == '{')
            opening++;
        else
            closing++;

        // If there are more closing brackets than opening, reverse one of each
        if (closing > opening) {
            opening++;
            closing--;
            ans++;
        }
    }

    // Return the total number of reversals needed to balance
    return ans + (opening - closing) / 2;
}