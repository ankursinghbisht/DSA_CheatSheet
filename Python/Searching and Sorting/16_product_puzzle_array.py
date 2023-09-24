"""
Idea:
computing the left products and right products of each element separately and
combining them to obtain the final product array.
"""


# User function Template for python3

class Solution:
    def productExceptSelf(self, nums, n):

        output = [1] * n

        # Calculate the left products
        left_product = 1
        for i in range(n):
            output[i] *= left_product
            left_product *= nums[i]

        # Calculate the right products
        right_product = 1
        for i in range(n - 1, -1, -1):
            output[i] *= right_product
            right_product *= nums[i]

        return output


if __name__ == '__main__':
    t = int(input())

    for _ in range(t):
        n = int(input())
        arr = [int(x) for x in input().split()]

        ans = Solution().productExceptSelf(arr, n)
        print(*ans)
