/*
Idea:
finding min & max time required to cook all parathas.
using binary search to find optimum time to cook
with each 'mid' value, check if it's possible to cook in time limit.
returning minimum time value.
*/


#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    bool isPossible(const vector<int>& cookRanks, int P, int timeLimit)
    {
        int pratasCooked = 0;
        for (int rank : cookRanks)
        {
            int time = rank;
            int pratasCookedRank = 0;
            while (time <= timeLimit) // counting parathas cooked by a chef in certain time.
            {
                pratasCookedRank++;
                time += rank * pratasCookedRank;
            }
            pratasCooked += pratasCookedRank;
        }
        return pratasCooked >= P;
    }
    int minuteToCook(vector<int> chefs, int count)
    {
        sort(chefs.begin(), chefs.end());
        int n = chefs.size(), low = 0, high = chefs[chefs.size() - 1] * (n * n * (n - 1) / 2), mid;
        //setting low =0 & high as max time required to cook all parathas
        while (low <= high)
        {
            mid = low + (high - low) / 2;
            if (isPossible(chefs, count, mid)) // finding if current time is enough to cook parathas
                high = mid;
            else
                low = mid + 1;
        }
        return low;

    }
};


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int k, n;
        cin >> k >> n;

        vector<int>vc(n);
        for (int i = 0;i < n;i++)
            cin >> vc[i];
        Solution obj;
        cout << obj.minuteToCook(vc, n) << endl;
    }
    return 0;
}