/*
Idea:
assuming 2 cases:
if final string is 01010, or 10101, checking how many changes required to achieve, return min value
*/


#include<bits/stdc++.h>
using namespace std;

int minFlips(string s);
int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;

        cout << minFlips(s) << endl;
    }
}



int minFlips(string S)
{

    int count = 0, n = S.size();
    for (int i = 0; i < n; ++i)
        if ((i % 2) != (S[i] - '0'))
            count++;

    return min(count, n - count);

}