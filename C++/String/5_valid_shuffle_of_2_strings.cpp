/*
Idea:
using map to store frequency of all characters in 2 strings
-checking if 2nd string has all elements with same frequency & if any element is extra.
*/


#include <bits/stdc++.h>
using namespace std;

bool validShuffle(string str1, string str2, string shuffle)
{
    int l1 = str1.size(), l2 = str2.size(), l3 = shuffle.size();
    if (l1 + l2 != l3)
        //checking if sum of lengths are equal
        return false;

    //appending frequencies of all characters
    unordered_map<char, int> freq;
    for (int i = 0;i < l1;++i)
        freq[str1[i]]++;

    for (int i = 0;i < l2;++i)
        freq[str2[i]]++;

    for (int i = 0;i < l3;++i)
    {   //checking if element is present in map or not
        if (freq.find(shuffle[i]) != freq.end() || freq[shuffle[i]] == 0)
            freq[shuffle[i]]--;
        else
            return false;
    }
    return true;
}

int main()
{
    string str1 = "BA", str2 = "XY", shuffle = "ABYX";

    (validShuffle(str1, str2, shuffle) == true)
        ? printf("YES")
        : printf("NO");
    cout << endl;

    return 0;
}
