"""
Idea:
since we want less than N, subtracting & then finding square root gives values less than N
"""

import math


class Solution:
    def countSquares(self, N):
        return int(math.sqrt(N - 1))


if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        N = int(input())

        ob = Solution()
        print(ob.countSquares(N))
