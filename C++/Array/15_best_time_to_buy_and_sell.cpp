/*
Remember one rule :- You can only buy one time & sell one time

Idea:
If we choose the minimum number at each element, and find the highest difference if sold at current element,
saving the highest difference will be the answer.
*/




#include<bits/stdc++.h>
using namespace std;


int maxProfit(vector<int>& prices) {
    int least = INT_MAX, result = 0, profit = 0;
    //setting up least value, result, and profit

    for (int i = 0;i < prices.size();++i)
    {
        if (prices[i] < least)
            //checking if current element is least of the vector
            least = prices[i];

        profit = prices[i] - least; //calculating the profit
        if (result < profit)
            // saving if profit is greater than max.
            result = profit;
    }
    return result;
}


int main()
{
    vector<int> prices;
    int t, temp;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0;i < n;i++)
        {
            cin >> temp;
            prices.push_back(temp);
        }
        int ans = maxProfit(prices);
        cout << ans;
    }
    return 0;
}