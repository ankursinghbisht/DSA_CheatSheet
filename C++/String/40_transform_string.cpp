/*
Idea:
checking if A can be converted to B, by checking if count of all chars is equal
-then starting from last index, checking if chars match, else increase answer count till chars match
*/


#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;



class Solution
{
public:
    int transform(string A, string B)
    {
        int Asize = A.size(), Bsize = B.size(), i, j, ans = 0;
        if (Asize != Bsize)
            return -1;
        int count[256];
        memset(count, 0, sizeof(count));

        for (i = 0;i < Asize;++i)
            count[A[i]]++;
        for (i = 0;i < Bsize;++i) // checking if chars are equal in both string
        {
            if (count[B[i]] == 0)
                return -1;
            count[B[i]]--;
        }

        for (i = j = Asize;i >= 0;--i, --j)
            while (i >= 0 && A[i] != B[j])
            {
                // if chars don't match, decreasing the index of 1st string till chars match
                ++ans;
                --i;
            }
        return ans;

    }
};




int main()
{
    int t; cin >> t;
    while (t--)
    {
        string A, B;
        cin >> A >> B;
        Solution ob;
        cout << ob.transform(A, B) << endl;
    }
}
