"""
Idea: (for minimum no. of comparisons)
using min & max functions to find the rest element
"""


class Solution:
    def middle(self, A, B, C):
        smallest = min(A, B, C)
        largest = max(A, B, C)
        return A + B + C - smallest - largest


if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        A, B, C = map(int, input().strip().split())
        ob = Solution()
        print(ob.middle(A, B, C))
