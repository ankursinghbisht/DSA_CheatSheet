"""
Idea:
Checking all test cases:
-if both elements are equal
-if common diff is 0
-if target is smaller than initial , but common diff > 0
-if target is greater than initial , but common diff < 0
"""


class Solution:
    def inSequence(self, A, B, C):
        if A == B:  # if both numbers are equal
            return 1
        if C == 0:  # if Common Difference is 0, elements must be equal
            if A == B:
                return 1
            return 0
        if (B - A) % C == 0:  # if difference between target and initial element is divisible by CD.

            # checking both test cases where target>initial and CD>0 & target<initial & CD<0
            if A < B and C > 0:
                return 1
            if A > B and C < 0:
                return 1
        return 0


if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        A, B, C = [int(x) for x in input().split()]

        ob = Solution()
        print(ob.inSequence(A, B, C))
