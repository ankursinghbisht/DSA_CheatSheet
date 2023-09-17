/*
Idea:
iterating string & keeping track of each character, if it's already passed or not.
& keeping count of remaining computers, updating as character comes or leaves.
*/


#include<bits/stdc++.h>
using namespace std;



class Solution
{
public:
    int solve(int n, string seq)
    {
        // seen[i] = 0, indicates that customer 'i' is not in cafe
        // seen[1] = 1, indicates that customer 'i' is in cafe but computer is not assigned yet.
        // seen[2] = 2, indicates that customer 'i' is in cafe and  has occupied a computer.

        char seen[26] = { 0 }; // array to store entry/exit of chars
        int res = 0, occupied = 0;

        for (int i = 0; seq[i]; i++)
        {
            int ind = seq[i] - 'A';

            if (seen[ind] == 0) // if char hasn't entered
            {
                seen[ind] = 1;
                if (occupied < n) // if computers are available
                {
                    occupied++;
                    seen[ind] = 2;
                }
                else
                    res++;
            }
            else
            {
                if (seen[ind] == 2) // if char has left
                    occupied--;
                seen[ind] = 0;
            }
        }
        return res;
    }
};


int main() {
    int t;
    scanf("%d", &t);
    while (t--)
    {

        int n;
        scanf("%d", &n);


        cin.ignore();
        string s = ;
        getline(cin, s);

        Solution obj;
        int res = obj.solve(n, s);

        cout << res << endl;

    }
}

