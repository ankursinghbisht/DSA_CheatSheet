/*
Idea:
Using map to store key value pair of each string
with key being sorted form of each string, and appending values to it's key each time a value is matched, returned the result
*/

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;



class Solution {
public:
    vector<vector<string> > Anagrams(vector<string>& str)
    {
        map<string, vector<string>> mp;
        vector<vector<string>> ans;

        for (string& s : str)
        {
            // inserting key value pairs in map
            string key = s;
            sort(key.begin(), key.end());
            mp[key].push_back(s);
        }

        for (auto it : mp)
            ans.push_back(it.second);
        return ans;

    }
};



int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin >> string_list[i];
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for (int j = 0; j < result[i].size(); j++)
            {
                cout << result[i][j] << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}

