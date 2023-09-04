"""
Idea:
Using Recursion & Dynamic Programming to calculate the minimum edit distance
(number of insertions, deletions, or substitutions) required to transform one string into another
"""


class Solution:

    def min_dis(self, s1, s2, n, m, dp):
        # Base cases
        if n == 0:
            return m
        if m == 0:
            return n

        # Check if the result for (n, m) has already been calculated
        if dp[n][m] != -1:
            return dp[n][m]

        # If characters are equal, recursively call with (n-1, m-1)
        if s1[n - 1] == s2[m - 1]:
            dp[n][m] = self.min_dis(s1, s2, n - 1, m - 1, dp)
        else:
            # Calculate three possible operations and choose the minimum
            insert = self.min_dis(s1, s2, n, m - 1, dp)
            delete = self.min_dis(s1, s2, n - 1, m, dp)
            replace = self.min_dis(s1, s2, n - 1, m - 1, dp)
            dp[n][m] = 1 + min(insert, min(delete, replace))

        return dp[n][m]

    def editDistance(self, s, t):
        m = len(s)
        n = len(t)
        dp = [[-1] * (n + 1) for _ in range(m + 1)]
        return self.min_dis(s, t, m, n, dp)


if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        s, t = input().split()
        ob = Solution();
        ans = ob.editDistance(s, t)
        print(ans)
