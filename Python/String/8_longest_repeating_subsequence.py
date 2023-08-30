"""
Idea:
find the LCS(str, str) where str is the input string with the restriction that when both the characters are same,
they shouldn’t be on the same index in the two strings.
"""


class Solution:
    def LongestRepeatingSubsequence(self, str):
        n = len(str)
        mat = [[0] * (n + 1) for _ in range(n + 1)]  # Create and initialize DP table

        for i in range(1, n + 1):
            for j in range(1, n + 1):
                #  If characters match and indexes are not same
                if str[i - 1] == str[j - 1] and i != j:
                    mat[i][j] = 1 + mat[i - 1][j - 1]
                else:
                    mat[i][j] = max(mat[i - 1][j], mat[i][j - 1])
        return mat[n][n]


if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        str = input()
        ob = Solution()
        ans = ob.LongestRepeatingSubsequence(str)
        print(ans)
