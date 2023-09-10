"""
Idea:
assuming 2 cases:
if final string is 01010, or 10101, checking how many changes required to achieve, return min value
"""


class Solution:
    def minFlips(self, S):
        n = len(S)
        count = 0
        for i in range(n):
            if i % 2 == int(S[i]):
                count += 1

        return min(count, n - count)


if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        S = input()
        Obj = Solution()
        ans = Obj.minFlips(S)
        print(ans)
