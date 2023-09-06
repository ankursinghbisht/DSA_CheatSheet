/*
Idea:
using vector to store length of longest prefix & suffix till that current index
'i' is used for suffix & 'j' for prefix
*/


#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int lps(string s)
    {
        int n = s.size();
        vector<int> vc(n, 0);

        int i = 1, j = 0;
        while (i < n)
        {
            // if both elements at i & j are equal, adding index value of prefix pointer
            if (s[i] == s[j])
                vc[i++] = ++j;
            else
                // else incrementing suffix intial index value to find equal suffix to prefix
                if (j == 0)
                    i++;
                else
                    j = vc[j - 1];// resetting the value of index of prefix 
        }
        return vc.back();
    }
};

int main()
{


    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--)
    {
        string str = "abab";
        cin >> str;

        Solution ob;

        cout << ob.lps(str) << "\n";
    }

    return 0;
}
