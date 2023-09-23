"""
Idea:
there are 2 options in a single element
-choose or not choose, if element is chosen, move the pointer 2 steps ahead, else only 1.
-using list to store current max sum till that element
"""


class Solution:

    def FindMaxSum(self, a, n):
        if n == 1:  # if array has only 1 element
            return a[0]

        dp = [0] * n
        dp[0] = a[0]
        dp[1] = max(a[0], a[1])  # setting up max with first 2 elements.
        for i in range(2, n):
            dp[i] = max(dp[i - 1], dp[i - 2] + a[i])
            # 2 cases, if element is added or not.
        return dp[n - 1]


if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases):
        n = int(input())
        a = list(map(int, input().strip().split()))
        ob = Solution()
        print(ob.FindMaxSum(a, n))
