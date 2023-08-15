
/*
Idea:
Using 4 variables to store purchase and selling prices of each stock, for 2 transactions
-at each iteration, finding the lowest price to purchase first,
then checking if we make profit if selling, at that current point
, checking if purchasing at that current element, leads to the least loss
& finally finding max value of profit for last element to sell
 */
#include<bits/stdc++.h>
using namespace std;



int maxProfit(vector<int>& price)
{
    int first_buy = INT_MIN;
    int first_sell = 0;
    int second_buy = INT_MIN;
    int second_sell = 0;

    for (int i = 0;i < price.size();i++)
    {
        first_buy = max(first_buy, -price[i]);//we set prices to negative, so the calculation of profit will be convenient
        first_sell = max(first_sell, first_buy + price[i]);
        second_buy = max(second_buy, first_sell - price[i]);//we can buy the second only after first is sold
        second_sell = max(second_sell, second_buy + price[i]);
    }
    return second_sell;
}



int main() {
    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<int> price(n);
        for (int i = 0;i < n;i++) cin >> price[i];
        cout << maxProfit(price) << endl;
    }

}
