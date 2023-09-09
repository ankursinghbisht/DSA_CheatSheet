
/*
Idea:
Iterating each string & keeping temporary string to store common chars
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        int str_count = strs.size();
        string ans = strs[0]; // var to store  common prefix

        for (auto str : strs)
        {
            int i = 0;
            while (i < ans.length() && i < str.length() && ans[i] == str[i])
                i++;
            ans = ans.substr(0, i);
            if (ans.empty())
                return "";
        }
        return ans;
    }
};


int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> str;
        string s;
        for (int i = 0;i < n;++i)
        {
            cin >> s;
            str.push_back(s);
        }
        Solution ob;
        cout << ob.longestCommonPrefix(str) << endl;
    }
}
