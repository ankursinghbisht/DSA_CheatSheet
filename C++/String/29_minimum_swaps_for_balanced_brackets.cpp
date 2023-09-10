/*
Idea:
keeping count of left & right brackets, and adding value of imbalance to ans
*/


#include<bits/stdc++.h> 
using namespace std;


class Solution {
public:
    int minimumNumberOfSwaps(string S)
    {
        int countLeft = 0, countRight = 0;
        int swap = 0, imbalance = 0;
        for (int i = 0; i < S.length(); i++)
        {
            if (S[i] == '[')
            {
                countLeft++;

                if (imbalance > 0)
                    // If there is an imbalance, we need to swap brackets
                    swap += imbalance--;
            }
            else if (S[i] == ']')
            {
                countRight++;
                imbalance = (countRight - countLeft);
            }
        }
        return swap;


    }
};


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.minimumNumberOfSwaps(S) << endl;
    }
    return 0;
}
