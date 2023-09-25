"""
Idea:
At each Iteration of BishuPower vector, iterating each of soldierPower element,
if previous is greater than later, add to answer. Output at each outer loop
"""


class Solution:
    def Solve(self, soldierPower, BishuPower):
        n = len(soldierPower)
        fights = len(BishuPower)
        for i in range(fights):
            sum_val = count = 0
            for j in range(n):
                if BishuPower[i] >= soldierPower[j]:  # if bishu is stronger than soldier
                    count += 1
                    sum_val += soldierPower[j]
            print(count, sum_val)


if __name__ == "__main__":
    n = int(input())
    nums = list(map(int, input().split()))
    t = int(input())
    pow = []
    for i in range(t):
        val = int(input())
        pow.append(val)
    obj = Solution()
    obj.Solve(nums, pow)
