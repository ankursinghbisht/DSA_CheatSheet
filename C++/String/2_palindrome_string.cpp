/*
Idea:
using for loop for each element for half-length & comparing it to its counterpart.
*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:


    int isPalindrome(string s)
    {
        for (int i = 0;i < s.size() / 2;++i)
            if (s[i] != s[s.size() - i - 1])
                return 0;
        return 1;
    }

};


int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        Solution ob;

        cout << ob.isPalindrome(s) << "\n";
    }

    return 0;
}