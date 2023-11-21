"""
Idea:
sorting candies in increasing order, and calculating total candies to buy,
taking sum from start and end as answer
"""

import math


class Solution:
    def candyStore(self, candies, N, K):
        candies.sort()

        # Finding the minimum candies to buy
        candies_to_buy = math.ceil((N + K) / (K + 1))

        min_cost, max_cost = 0, 0

        # Finding the minimum and maximum cost to buy candies required
        for i in range(N):
            if candies_to_buy > 0:
                min_cost += candies[i]
                max_cost += candies[N - i - 1]
                candies_to_buy -= 1
            else:
                break

        return [min_cost, max_cost]


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == '__main__':

    t = int(input())

    for _ in range(t):
        N, K = [int(x) for x in input().split()]
        candies = [int(x) for x in input().split()]

        solObj = Solution()

        print(*solObj.candyStore(candies, N, K))
# } Driver Code Ends
