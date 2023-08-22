"""
Idea:
Using 4 variables to store purchase and selling prices of each stock, for 2 transactions
-at each iteration, finding the lowest price to purchase first,
 then checking if we make profit if selling, at that current point
 , checking if purchasing at that current element, leads to the least loss
 & finally finding max value of profit for last element to sell
"""


def maxProfit(prices):
    first_buy = float('-inf')  # Initialize the variables for buying and selling prices
    first_sell = 0
    second_buy = float('-inf')
    second_sell = 0

    for price in prices:
        first_buy = max(first_buy, -price)  # Convert prices to negative for convenience in profit calculation
        first_sell = max(first_sell, first_buy + price)
        second_buy = max(second_buy, first_sell - price)  # We can buy the second only after the first is sold
        second_sell = max(second_sell, second_buy + price)

    return second_sell


if __name__ == '__main__':
    a = [2, 30, 15, 10, 8, 25, 80]
    ans = maxProfit(a)
    print(ans)
