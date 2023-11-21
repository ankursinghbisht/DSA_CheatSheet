"""
Idea:
sorting prices in increasing order , along with their buy limit, counting all stocks available till money is left.
"""

from typing import List


class Solution:
    def buyMaximumProducts(self, n: int, k: int, price: List[int]) -> int:
        # Create a list of tuples to store prices and their corresponding buy limits
        stocks = [(price[i], i + 1) for i in range(n)]

        # Sort the stocks based on their prices in ascending order
        stocks.sort()

        count = 0
        total_price = 0

        # Iterate through the sorted stocks
        for stock_price, buy_limit in stocks:
            # If buying all available stocks at the current price is within the budget
            if total_price + buy_limit * stock_price <= k:
                count += buy_limit
                total_price += buy_limit * stock_price
            else:
                # Else, find the maximum number of stocks available in the budget
                count += (k - total_price) // stock_price
                break

        return count


# code here


# {
# Driver Code Starts


class IntArray:
    def __init__(self) -> None:
        pass

    def Input(self, n):
        arr = [int(i) for i in input().strip().split()]  # array input
        return arr

    def Print(self, arr):
        for i in arr:
            print(i, end=" ")
        print()


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n, k = map(int, input().strip().split())

        price = IntArray().Input(n)

        obj = Solution()
        res = obj.buyMaximumProducts(n, k, price)

        print(res)

# } Driver Code Ends
