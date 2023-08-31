
/*
Idea:
Iterating each element, keeping count of 0's and 1's
Adding 1 to answer , each time count gets equal.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubStr(string str)
    {
        int n = str.size(), zeros = 0, ones = 0, ans = 0;

        for (int i = 0;i < n;++i)
        {
            //keeping count of 0 & 1
            if (str[i] == '0')
                ++zeros;
            else
                ++ones;

            if (zeros == ones)
                ans += 1;
        }
        //if count of 0 and 1 weren't equal, return -1, as condition isn't satisfied
        if (zeros != ones)
            return -1;
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution ob;
        int ans = ob.maxSubStr(str);
        cout << ans << endl;
    }
    return 0;
}
