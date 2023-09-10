/*
Idea:
using map store frequencies of all strings
keeping track of highest & 2nd highest frequency value and string value .
*/


#include<bits/stdc++.h>
using namespace std;



class Solution
{
public:
    string secFrequent(string arr[], int n)
    {

        unordered_map <string, int> freq;

        for (int i = 0;i < n;++i)
            freq[arr[i]]++; // inserting in map 

        string first_max_str = "", second_max_str = "";
        int first_max = INT_MIN, second_max = INT_MIN;


        for (auto& entry : freq)
        {
            // finding max & 2nd max frequency strings
            if (entry.second > first_max)
            {
                second_max_str = first_max_str;
                second_max = first_max;

                first_max_str = entry.first;
                first_max = entry.second;
            }
            else if (entry.second > second_max && entry.first != first_max_str)
            {

                second_max_str = entry.first;
                second_max = entry.second;
            }
        }
        return second_max_str;
    }
};


int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.secFrequent(arr, n) << endl;
    }
}
