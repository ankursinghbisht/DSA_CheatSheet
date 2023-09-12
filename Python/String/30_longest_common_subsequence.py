"""
Idea:
iterating a string & comparing with each character of other string, if equal adds one to answer
& using DP to keep track of comparisons
"""


class Solution:

    # Function to find the length of longest common subsequence in two strings.
    def lcs(self, n, m, s1, s2):
        dp = [[0] * (m + 1) for _ in range(n + 1)]  # list to store comparison value

        for i in range(1, n + 1):
            for j in range(1, m + 1):
                if s1[i - 1] == s2[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1] + 1
                else:
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

        return dp[n][m]


if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases):
        x, y = map(int, input().strip().split())
        s1 = str(input())
        s2 = str(input())
        ob = Solution()
        print(ob.lcs(x, y, s1, s2))
