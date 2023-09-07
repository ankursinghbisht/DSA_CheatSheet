"""
Idea: using DP to store preprocessed values,
with each iteration, checking if current elements are equal, checking for next elements
"""


class Solution:

    def countPS(self, s):

        t = [[-1 for i in range(1001)] for i in range(1001)]
        # Modulus value for calculations.
        mod = 10 ** 9 + 7

        def solve(s, i, j, t):
            # Base cases: if the string has only one character or no characters.
            if i == j:
                return 1
            if i > j:
                return 0
            # If the result for the current subproblem has already been calculated, return it.

            if t[i][j] != -1:
                return t[i][j]
            # If the first and last characters of the string are the same.
            elif s[i] == s[j]:
                # Recursively calculate the result for the remaining string
                t[i][j] = 1 + solve(s, i + 1, j, t) % mod + solve(s, i, j - 1, t) % mod
                t[i][j] %= mod
                return t[i][j]
            else:
                # Recursively calculate the result for the remaining string
                t[i][j] = solve(s, i + 1, j, t) % mod + solve(s, i, j - 1, t) % mod - solve(s, i + 1, j - 1, t) % mod
                t[i][j] %= mod
                return t[i][j]

        # Starting point of the recursive function.
        return solve(s, 0, len(s) - 1, t)


import sys

sys.setrecursionlimit(10 ** 6)

if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        ob = Solution()
        print(ob.countPS(input().strip()))

