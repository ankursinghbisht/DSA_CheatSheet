/*
Idea:
using map to store count of each element , if count exceeds 1, print the answer.
*/

#include <bits/stdc++.h>
using namespace std;

void printDups(string str)
{
    unordered_map<char, int> mp;
    for (int i = 0;i < str.size();++i)
        mp[str[i]]++;

    for (auto it : mp)
        if (it.second > 1)
            cout << it.first << " ";
    cout << "\n";
}


int main()
{
    string str = "test string";
    printDups(str);
    return 0;
}
